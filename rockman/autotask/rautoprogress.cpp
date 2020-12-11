#include "rautoprogress.h"
#include <QPushButton>
#include <QDebug>

Rautoprogress::Rautoprogress(QWidget *parent) : QWidget(parent){
    init();
    initRecord();
    add_items();
    scroll_area->verticalScrollBar()->setRange(0,310);
}

void Rautoprogress::test_autoprogress(){
    Rautoprogress *pg = new Rautoprogress();
    pg->show();
}

void Rautoprogress::init(){
    start_index = START_INDEX;
    count = INCREASE_NUM;
    select_state = INIT_SELECT_STATE;
}

void Rautoprogress::initRecord(){
    this->resize(1280, 800);
    this->setStyleSheet("background-color:#FF101b2b");

    m_rwd = new QWidget(this);
    m_rwd->resize(390, 583);
    m_rwd->move(873, 49);
    m_rwd->setStyleSheet("background-color:green");

    scroll_area = new MScrollArea(m_rwd);
    scroll_area->move(0, 247);
    scroll_area->setGeometry(0, 247, 390, 800);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll_area->setFrameShape(QFrame::NoFrame);
    scroll_area->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    scroll_area->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    scroll_area->setWidgetResizable(true);

    total_widget = new QWidget(m_rwd);
    scroll_area->setWidget(total_widget);
    total_widget->setGeometry(0, 0, 390, 614);
    total_widget->setStyleSheet("background-color:#FF101b2b");

    vLayout = new QVBoxLayout;
    vLayout->setSpacing(2);
    vLayout->setMargin(0);
    //vLayout->setContentsMargins(154,0,153,0);
    list_widget = new QWidget(total_widget);
    list_widget->move(0, 0);
    list_widget->setStyleSheet("background-color:transparent");
    list_widget->setLayout(vLayout);
}

void Rautoprogress::add_items(){
    int item_size = 150;
    total_item.clear();
    for(uint i = 0; i<item_size; i++){
        QString txt = tr("aaa%1").arg(i);
        clean_record_item = new QWidget(m_rwd);
        total_item.push_back(clean_record_item);
        clean_record_item->setFixedSize(390, 112);
        clean_record_item->setStyleSheet("background:#243043; border-radius:2px");

        QFont name_ft("黑体", 14, QFont::Normal);
        clean_area_name = new QLabel(clean_record_item);
        clean_area_name->move(40, 32);
        clean_area_name->setStyleSheet("color:white");
        clean_area_name->setText(txt);
        clean_area_name->setFont(name_ft);
        clean_area_name->adjustSize();

        QFont info_ft("黑体", 13, QFont::Normal);
        clean_date = new QLabel(clean_record_item);
        clean_date->move(40, 70);
        clean_date->setStyleSheet("color:white");
        clean_date->setText(txt);
        clean_date->setFont(info_ft);
        clean_date->adjustSize();

        clean_model = new QLabel(clean_record_item);
        clean_model->move(315, 47);
        clean_model->setStyleSheet("color:white");
        clean_model->setText(txt);
        clean_model->setFont(info_ft);
        clean_model->adjustSize();

        vLayout->addWidget(clean_record_item);
    }
//    total_widget->setFixedSize(390, 219+int(item_size)*(clean_record_item->height() + 20)+181);
    //list_widget->resize(390, total_widget->height()-219-181);
    total_widget->setFixedSize(390, 100+item_size*(clean_record_item->height()+2)+181);
    list_widget->resize(390, total_widget->height()-100-181);
}
