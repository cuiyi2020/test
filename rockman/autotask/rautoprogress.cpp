#include "rautoprogress.h"
#include "utils/rwait.h"
#include <unistd.h>
#include <QPushButton>
#include <QDebug>
#include <algorithm>

/*Class Rautoprogressitem Construct*/
Rautoprogressitem::Rautoprogressitem(QWidget *parent) : QWidget(parent){
    m_id = -1;
    m_state = AutoStateDone;
    m_pgitem = "";
    m_model = "";
    create_ui();
    create_connections();
}

void Rautoprogressitem::set_data(int id, const QString &pgitem, const QString &model, const QString &percent, int state){
    m_id = id;
    m_pgitem = pgitem;
    m_model = model;
    m_percent = percent;
    m_state = state;
    set_label();
    set_state_btn();
}

void Rautoprogressitem::set_state(int state){
    m_state = state;
}

void Rautoprogressitem::refresh_state_btn(){
    m_state_btn->setText("");
    this->set_state_btn();
}

int Rautoprogressitem::get_id(){
    return m_id;
}

void Rautoprogressitem::create_ui(){
    this->setFixedSize(390, 112);
    //this->setStyleSheet("background:#243043; border-radius:2px");

    QFont name_ft("黑体", 14, QFont::Normal);
    m_pg_lb = new QLabel(this);
    m_pg_lb->resize(80, 21);
    m_pg_lb->move(40, 32);
    m_pg_lb->setStyleSheet("color:white;background-color:transparent");
    m_pg_lb->setFont(name_ft);

    QFont info_ft("黑体", 12, QFont::Normal);
    m_model_lb = new QLabel(this);
    m_model_lb->resize(72, 16);
    m_model_lb->move(40, 70);
    m_model_lb->setStyleSheet("color:white;background-color:transparent");
    m_model_lb->setFont(info_ft);

    m_state_btn = new QPushButton(this);

    QLabel *down_lb = new QLabel(this);
    down_lb->resize(390, 1);
    down_lb->move(0, this->height()-1);
    down_lb->setStyleSheet("background-color:white");
    set_label();
    set_state_btn();
}

void Rautoprogressitem::create_connections(){
    connect(m_state_btn, &QPushButton::clicked, this, &Rautoprogressitem::slot_jump);
}

void Rautoprogressitem::slot_jump(){
    qDebug() << "m_id->" << m_id;
    this->m_state = AutoStateDone;
    m_state_btn->setText("");
    set_state_btn();
}

void Rautoprogressitem::set_label(){
    m_pg_lb->setText(m_pgitem);
    m_pg_lb->adjustSize();
    m_model_lb->setText(m_model);
    m_pg_lb->adjustSize();
}

void Rautoprogressitem::set_state_btn(){
    if (m_state == AutoStateDone){
        m_state_btn->resize(23, 23);
        m_state_btn->move(322, 48);
        m_state_btn->setStyleSheet("QPushButton{border-image: url(:/auto-btn-done.png);background-color:transparent}");
        m_state_btn->setDisabled(true);
    }
    else if (m_state == AutoStateJump){
        QFont jump_ft("黑体", 12, QFont::Normal);
        m_state_btn->resize(70, 30);
        m_state_btn->move(296, 40);
        m_state_btn->setText(tr("跳过"));
        m_state_btn->setFont(jump_ft);
        m_state_btn->setStyleSheet("QPushButton{border-image: url(:/恢复暂停.png); color:white;background-color:transparent}");
        m_state_btn->setDisabled(false);
    }
    else if (m_state == AutoStateWait){
        QFont wait_ft("黑体", 12, QFont::Normal);
        m_state_btn->resize(53, 17);
        m_state_btn->move(308, 46);
        m_state_btn->setText(tr("等待中"));//等待中
        m_state_btn->setFont(wait_ft);
        m_state_btn->setStyleSheet("color:gray; border:no;background-color:transparent");
        m_state_btn->setDisabled(true);
    }
    else{
        qDebug() << "No state." << m_state;
    }
}

/*******************************/
/*Class Rautoprogress Construct*/
/*******************************/
Rautoprogress::Rautoprogress(QWidget *parent) : QWidget(parent){
    create_ui();
    create_connections();
    init();
}

void Rautoprogress::init(){
    m_item_size = 100;
    //m_scroll_area->verticalScrollBar()->setRange(0, 910);
    add_items();
    //set_scrollpos(0);
}

void Rautoprogress::resume(int size){
    m_item_size = size;
    add_items();
    //set_scrollpos(0);
}

void Rautoprogress::create_ui(){
    this->resize(1280, 800);
    this->setStyleSheet("background-color:#FF101b2b");

    m_wd = new QWidget(this);
    m_wd->resize(390, 583);
    m_wd->move(873, 49);
    m_wd->setStyleSheet("background:#FF243043");

    QLabel *down_lb = new QLabel(m_wd);
    down_lb->resize(390, 1);
    down_lb->move(0, 246);
    down_lb->setStyleSheet("background-color:white");

    m_scroll_area = new MScrollArea(m_wd);
    m_scroll_area->move(0, 247);
    m_scroll_area->setGeometry(0, 247, 390, 800);
    m_scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_scroll_area->setFrameShape(QFrame::NoFrame);
    m_scroll_area->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    m_scroll_area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    m_scroll_area->setWidgetResizable(true);
    m_scroll_area->verticalScrollBar()->setMaximumHeight(1000);
    m_scrollbar_y = m_scroll_area->verticalScrollBar();

    m_total_widget = new QWidget(m_wd);
    m_scroll_area->setWidget(m_total_widget);
    m_total_widget->setGeometry(0, 0, 390, 614);
    m_total_widget->setStyleSheet("background-color:transparent");

    m_vlayout = new QVBoxLayout;
    m_vlayout->setSpacing(1);
    m_vlayout->setMargin(0);
    //m_vlayout->setContentsMargins(154,0,153,0);
    m_list_widget = new QWidget(m_total_widget);
    m_list_widget->move(0, 0);
    m_list_widget->setStyleSheet("background-color:transparent");
    m_list_widget->setLayout(m_vlayout);

    int h = m_wd->height();
    m_down_wd = new QWidget(this);
    m_down_wd->resize(390, 735-h);
    m_down_wd->move(873, 49+h);
    m_down_wd->setStyleSheet("background:#FF243043");

    m_task_btn = new QPushButton(m_down_wd);
    m_task_btn->resize(214, 72);
    m_task_btn->move(40, 622-h);
    m_task_btn->setStyleSheet("QPushButton{border-image: url(:/auto-btn-stop.png);background-color:transparent}");

    QFont end_ft("黑体", 12, QFont::Normal);
    m_end_btn = new QPushButton(m_down_wd);
    m_end_btn->setText(tr("结束"));
    m_end_btn->setFont(end_ft);
    m_end_btn->resize(73, 72);
    m_end_btn->move(278, 622-h);
    m_end_btn->setStyleSheet("QPushButton{border-image: url(:/结束按钮.png);background-color:transparent;color:white}");
}

void Rautoprogress::create_connections(){

}

void Rautoprogress::set_scrollpos(int k){
    int itemsize = 113;
    //The index of the item who's running is k.
    if (k <= 2){
        m_scrollbar_y->setValue(0);
        //qDebug() << "a"<<k << m_scrollbar_y->value();
    }
    else if(k >= m_item_size){
        m_scrollbar_y->setValue((m_item_size-3)*itemsize);
        //qDebug() << "b"<<k<< m_scrollbar_y->value();
    }
    else{
        m_scrollbar_y->setValue((k-2)*itemsize);
        //qDebug() << "c"<<k<< m_scrollbar_y->value();
    }
}

void Rautoprogress::clear_items(){
    for (auto it:m_total_items){
        //m_vlayout->removeWidget(it);
        if (it) delete it;
    }
    m_total_items.clear();

}

void Rautoprogress::add_items(){
    clear_items();
    for(int i=1; i<=m_item_size; i++){
        m_pgitem = new Rautoprogressitem(m_wd);
        m_pgitem->set_data(i, tr("进度项 %1").arg(i), "强力模式", "", 3);
        m_total_items.push_back(m_pgitem);
        m_vlayout->addWidget(m_pgitem);
    }
    if (m_total_items.empty())
        return;
    m_total_widget->setFixedSize(390, 279+m_item_size*(m_pgitem->height()+1)+181);
    m_list_widget->resize(390, m_total_widget->height()-279-181);
}

void Rautoprogress::set_item_state(vector<Sautodata*> &rhs){
    if (m_item_size != (int)rhs.size()){
        qDebug() << "The size of items is not matching.";
        return;
    }
    int jump_cnt = std::count_if(rhs.begin(), rhs.end(), [&](Sautodata* it){
        return it->m_state == AutoStateJump;
    });
    if (jump_cnt > 1){
        qDebug() << "The size of jump_cnt is->" << jump_cnt;
        return;
    }
    auto item = m_total_items.begin();
    int jump_id = 0;
    int done_cnt = 0;
    for (; item!=m_total_items.end(); ++item){
        auto itm = static_cast<Rautoprogressitem*>(*item);
        auto res_iter = std::find_if(rhs.begin(), rhs.end(), [&](Sautodata* it){
            return it->m_id == itm->get_id();
        });
        if (res_iter == rhs.end()){
            qDebug() << "The id of items is not matching.";
            break;
        }
        itm->set_state((*res_iter)->m_state);      
        if((*res_iter)->m_state == AutoStateDone){
            done_cnt++;
        }
        else if ((*res_iter)->m_state == AutoStateJump){
            jump_id = itm->get_id();
        }
    }
    if (item != m_total_items.end()){
        return;
    }
    std::for_each(m_total_items.begin(), m_total_items.end(), [&](QWidget* it){
        static_cast<Rautoprogressitem*>(it)->refresh_state_btn();
    });
    if (done_cnt != m_item_size){
        this->set_scrollpos(jump_id);
    }
    else{
        this->set_scrollpos(m_item_size);
    }
    qDebug() << "jump_id" << jump_id << jump_cnt;
}

void Rautoprogress::test_autoprogress(){
    Rautoprogress *pg = new Rautoprogress();
    pg->show();

    int nums = 10;
    vector<Sautodata *> vdata;
    for (int i=0; i<nums; ++i){
        Sautodata *st = new Sautodata(i+1);
        vdata.push_back(st);
    }
    pg->resume(nums);
//    vdata[0]->m_state = 2;//id:1
//    vdata[1]->m_state = 2;//id:2
//    vdata[2]->m_state = 2;//id:3
//    vdata[5]->m_state = 2;//id:6
//    vdata[7]->m_state = 2;//id:8
//    vdata[8]->m_state = 2;//id:9
    //vdata[9]->m_state = 2;//id:10
    pg->set_item_state(vdata);

    Rtimer *m_timer = new Rtimer(3*1000);
    Rwait *m_wait = Rwait::get_instance();
    bool done = false;
    for (int i=1; i<nums; ++i){
        //block code .
        done = false;
        m_timer->begin([&](){done = true;});
        m_wait->start([&](){while(true){if (done)break;}});
        //
        for (int j=0; j<i; ++j){
            vdata[j]->m_state = 1;//id:1
        }
        if (i != nums-1){
            vdata[i]->m_state = 2;
        }
        else{
            vdata[i]->m_state = 1;
        }
        pg->set_item_state(vdata);
    }

//    qDebug() << pg->m_vlayout->count();
//    pg->resume(nums);
//    qDebug() << pg->m_vlayout->count();
//    pg->set_scrollpos(5);
//    pg->resume(16);
//    qDebug() << pg->m_vlayout->count();
//    pg->set_scrollpos(12);
//    pg->resume(2);
//    qDebug() << pg->m_vlayout->count();
//    pg->set_scrollpos(1);
}
