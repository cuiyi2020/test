#include "rautodetail.h"
#include "utils/rtimer.h"
#include "utils/rwait.h"
#include <cmath>

Rautodetail::Rautodetail(QWidget *parent) : QWidget(parent){
    this->resize(1280, 800);
    create_ui();
    create_connections();
}

void Rautodetail::create_ui(){
//    m_map = new rrqt::MapWidget(this);
//    m_map->init();
//    m_map->resize(1280, 800);
//    m_map->lower();
    QWidget *wd = new QWidget();
    wd->resize(1280, 800);
    wd->lower();

    back_btn = new QPushButton(this);
    back_btn->resize(39, 39);
    back_btn->move(110, 101);
    back_btn->setStyleSheet("QPushButton{border-image: url(:/返回箭头.png)}");

    QFont task_name_ft("黑体", 24, QFont::Normal);
    title_name = new QLabel(this);
    title_name->move(511, 100);
    title_name->setText("一楼B区大厅清扫");
    title_name->setStyleSheet("color:white");
    title_name->setFont(task_name_ft);
    title_name->adjustSize();

    /*up section*/
    up_clean_describ = new QWidget(this);
    up_clean_describ->resize(390, 235);
    up_clean_describ->move(873, 49);
    up_clean_describ->setStyleSheet("border-radius:10px; background-color:#243043");

    up_spacing = new QLabel(up_clean_describ);
    up_spacing->move(0, 131);
    up_spacing->resize(up_clean_describ->width(), 1);
    up_spacing->setStyleSheet("background-color:gray");

    QFont stop_ft("黑体", 16, QFont::Normal);
    up_stop_reason = new QLabel(up_clean_describ);
    up_stop_reason->move(135, 34);
    up_stop_reason->setText("电量低 任务终止");
    up_stop_reason->setStyleSheet("color:white");
    up_stop_reason->setFont(stop_ft);
    up_stop_reason->adjustSize();

    up_stop_mark = new QLabel(up_clean_describ);
    up_stop_mark->resize(25, 25);
    up_stop_mark->move(98, 38);
    up_stop_mark->setStyleSheet("QLabel{border-image: url(:/终止原因.png);}");

    QFont user_ft("黑体", 13, QFont::Normal);
    up_user_name = new QLabel(up_clean_describ);
    up_user_name->move(131, 78);
    up_user_name->setText("操作人");
    up_user_name->setStyleSheet("color:white");
    up_user_name->setFont(user_ft);
    up_user_name->adjustSize();

    up_exec_time = new QLabel(up_clean_describ);
    up_exec_time->move(42, 165);
    up_exec_time->setAlignment(Qt::AlignHCenter);
    up_exec_time->setText(tr("<font style='font-size: 16px'>执行时间</font><br /><font style='font-size: 16px'>12 时 50 分</font>"));
    up_exec_time->setStyleSheet("color:white");
    up_exec_time->adjustSize();

    up_clean_times = new QLabel(up_clean_describ);
    up_clean_times->move(166, 165);
    up_clean_times->setAlignment(Qt::AlignHCenter);
    up_clean_times->setText(tr("<font style='font-size: 16px'>循环次数</font><br /><font style='font-size: 16px'> 3 次 </font>"));
    up_clean_times->setStyleSheet("color:white");
    up_clean_times->adjustSize();

    up_clean_model = new QLabel(up_clean_describ);
    up_clean_model->move(285, 165);
    up_clean_model->setAlignment(Qt::AlignHCenter);
    up_clean_model->setText(tr("<font style='font-size: 16px'>清扫模式</font><br /><font style='font-size: 16px'>推尘</font>"));
    up_clean_model->setStyleSheet("color:white");
    up_clean_model->adjustSize();

    QFont title_ft("黑体", 16, QFont::Normal);
    QFont content_ft("黑体", 12, QFont::Normal);

    /*down section*/
    down_clean_describ = new QWidget(this);
    down_clean_describ->resize(390, 488);
    down_clean_describ->move(873, 296);
    down_clean_describ->setStyleSheet("border-radius:10px; background-color:#243043");

    down_etime_title = new QLabel(down_clean_describ);
    down_etime_title->move(40, 45);
    down_etime_title->setText("执行时间");
    down_etime_title->setStyleSheet("color:white");
    down_etime_title->setFont(title_ft);

    down_start_time = new QLabel(down_clean_describ);
    down_start_time->move(40, 89);
    down_start_time->setAlignment(Qt::AlignLeft);
    down_start_time->setText(tr("开始<br />2020-11-11<br />12:50"));
    down_start_time->setStyleSheet("color:white");
    down_start_time->setFont(content_ft);
    down_start_time->adjustSize();

    down_stop_time = new QLabel(down_clean_describ);
    down_stop_time->move(264, 89);
    down_stop_time->setAlignment(Qt::AlignRight);
    down_stop_time->setText(tr("结束<br />2020-11-11<br />12:50"));
    down_stop_time->setStyleSheet("color:white");
    down_stop_time->setFont(content_ft);
    down_stop_time->adjustSize();

    down_spacing_1 = new QLabel(down_clean_describ);
    down_spacing_1->move(0, 185);
    down_spacing_1->resize(down_clean_describ->width(), 1);
    down_spacing_1->setStyleSheet("background-color:gray");

    down_area_title = new QLabel(down_clean_describ);
    down_area_title->move(40, 211);
    down_area_title->setText("清扫面积");
    down_area_title->setStyleSheet("color:white");
    down_area_title->setFont(title_ft);
    down_area_title->adjustSize();

    down_clean_area = new QLabel(down_clean_describ);//
    down_clean_area->move(227, 218);
    down_clean_area->setText(tr("3500 m<sup>2</sup> / 4000 m<sup>2</sup>"));
    down_clean_area->setStyleSheet("color:white");
    down_clean_area->setFont(content_ft);
    m_down_clean_area_x = 227;
    m_down_clean_area_y = 218;
    m_down_clean_area_width = down_clean_area->width();


    down_eff_title = new QLabel(down_clean_describ);
    down_eff_title->move(40, 254);
    down_eff_title->setText("清扫效率");
    down_eff_title->setStyleSheet("color:white");
    down_eff_title->setFont(title_ft);
    down_eff_title->adjustSize();

    down_eff_clean = new QLabel(down_clean_describ);
    down_eff_clean->move(275, 261);
    down_eff_clean->setText(tr("3500 m<sup>2</sup> / h"));
    down_eff_clean->setStyleSheet("color:white");
    down_eff_clean->setFont(content_ft);

    m_end_btn = new QPushButton(down_clean_describ);
    m_end_btn->resize(214, 72);
    m_end_btn->move(88, 375);
    m_end_btn->setStyleSheet("QPushButton{border-image: url(:/login-btn-login.png)}");
}

void Rautodetail::create_connections(){
    connect(back_btn, &QPushButton::clicked, [&](){emit backRecordW();});
}

//void Rautodetail::initInfo(const vector<roborock_app::CleanRecord> &detail_info, int index_){
//    m_content.clear();
//    m_content = detail_info;
//    if(!m_content.empty()){
//        title_name->setText(m_content.at(uint(index_)).sub_region_name.c_str());
//        title_name->adjustSize();
//        m_map->set_record_map(m_content.at(uint(index_)).id);
//        up_exec_time->setText(tr("<font style='font-size: 16px'>执行时间</font><br />" \
//                                 "<font style='font-size: 16px'>%1</font>").arg(transTime(m_content.at(uint(index_)).clean_duration)));
//        up_exec_time->adjustSize();
//        up_clean_model->setText(tr("<font style='font-size: 16px'>循环次数</font><br />" \
//                                   "<font style='font-size: 16px'>%1</font>").arg(transCleanConfig(m_content.at(uint(index_)).clean_config)));
//        up_clean_model->adjustSize();
//        down_start_time->setText(tr("开始<br />%1").arg(transDate(m_content.at(uint(index_)).clean_time)));
//        down_start_time->adjustSize();

//        down_clean_area->setText(tr("%1 m<sup>2</sup> / 4000 m<sup>2</sup>").arg(m_content.at(uint(index_)).clean_area));
//        down_clean_area->adjustSize();

//        down_eff_clean->setText(tr("%1 %").arg(m_content.at(index_).cover_rate));
//        down_eff_clean->adjustSize();
//    }
//}

void Rautodetail::test_fresh(float f){
    //float area = 80000.21f;
    if (down_clean_area == nullptr){
        qDebug() << "test_fresh.";
        return;
    }
    //down_clean_area->setText("test");
    //down_clean_area->setText(tr("%1 m<sup>2</sup> / 4000 m<sup>2</sup>").arg(m_content.at(0).clean_area));
    down_clean_area->setText(tr("%1 m<sup>2</sup> / 4000 m<sup>2</sup>").arg(f));
    down_clean_area->adjustSize();
    //int dwidth = down_clean_area->width() - m_down_clean_area_width;
//    qDebug() << "test_fresh width:" << m_down_clean_area_width << down_clean_area->width();
//    qDebug() << "test_fresh x:" <<down_clean_area->x() << m_down_clean_area_x << m_down_clean_area_x-dwidth;

    //down_clean_area->move(m_down_clean_area_x-dwidth, m_down_clean_area_y);
    down_clean_area->move(down_clean_describ->width()-down_clean_area->width(), m_down_clean_area_y);

//    down_eff_clean->setText(tr("%1 %").arg(m_content.at(0).cover_rate));
//    down_eff_clean->adjustSize();
}

auto Rautodetail::transTime(float time)->QString{
    if(time >= 1440){
        return QString("超过一天");
    } else {
        int h = time / 60;
        int m = floor(time-h);
        return QString(tr("%1 小时 %2 分钟").arg(h).arg(m));
    }
}

auto Rautodetail::transCleanConfig(int model_id)->QString{
    switch (model_id) {
    case 0:
        return QString("推尘模式");
    case 1:
        return QString("ECU模式");
    case 2:
        return QString("标准模式");
    case 3:
        return QString("自定义模式");
    default:
        return QString("未定义模式");
    }
}

//auto Rautodetail::transDate(const std_msgs::Time &time)->QString{
//    int a = static_cast<int>(time.data.toSec());
//    return QDateTime::fromSecsSinceEpoch(a).toString("yyyy-MM-dd<br />hh:mm");
//}

void Rautodetail::widget_test(){
    Rautodetail *rd = new Rautodetail();
    rd->show();
//    Rtimer *m_timer = new Rtimer(3*1000);
//    Rwait *m_wait = Rwait::get_instance();
//    float f = 80009.99f;
//    bool done = false;
//    m_timer->begin([&](){
//        done = true;
//    });
//    m_wait->start([&](){
//        while(true){
//            if (done)
//                break;
//        }
//    });
//    rd->test_fresh(f);
//    done = false;

//    m_timer->begin([&](){
//        done = true;
//    });
//    m_wait->start([&](){
//        while(true){
//            if (done)
//                break;
//        }
//    });

//    rd->test_fresh(666666.66f);

}
