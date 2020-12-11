#pragma once

#include <QWidget>
#include <QLabel>
#include <QScroller>
#include <QScrollPrepareEvent>
#include <QScrollArea>
#include <QSizePolicy>
#include <QScrollEvent>
#include <QLayout>
#include <QDateTime>
#include <QSignalMapper>
#include <QPushButton>
#include "mscrollarea.h"

#define INCREASE_NUM 5;
#define START_INDEX 0;
#define INIT_SELECT_STATE false;

class Rautoprogress : public QWidget
{
    Q_OBJECT
public:
    explicit Rautoprogress(QWidget *parent = nullptr);
    ~Rautoprogress(){}

    void init();
    void initRecord();
    static void test_autoprogress();
//    void updateRecord();
//    void updateTitleWidget();
//    void refreshRecord(int &start_index, int &count, int move_ = 0);
//    auto transDate(const std_msgs::Time &time)->QString;
//    auto transCleanConfig(int model_id)->QString;
//    auto transTime(float time)->QString;

signals:
    //void recordToMain();
    //void recordToRDescribe(const vector<roborock_app::CleanRecord> &, int);

//public slots:
//    void reloaded();
//    void selectRefresh();
//    void clickSelectBtn(QWidget *btn);
//    void showDetail(int);
//    void showMain();

protected:
//    auto event(QEvent*)->bool;
private:
    void add_items();
private:
    QWidget *title_widget;
    QWidget *total_widget;
    QWidget *list_widget;
    QLabel *title_label;
    QLabel *total_clean_area;
    QLabel *title_total_area;
    QLabel *total_clean_duration;
    QLabel *title_total_duration;
    QLabel *total_clean_times;
    QLabel *title_total_times;
    QWidget *clean_record_item;
    QLabel *clean_area_name;
    QLabel *clean_date;
    QLabel *clean_model;
    QLabel *clean_area;
    QLabel *clean_time;
    QPushButton *detail_btn;
    QPushButton *select_delete_btn;
    QPushButton *select_btn;
    QPushButton *delete_btn;
    MScrollArea *scroll_area;
    QVBoxLayout *vLayout;
    QPushButton *back_btn;

    QWidget *m_rwd;


    int start_index;
    int count;
    bool select_state;

    QList<QWidget*>  total_item;
};

