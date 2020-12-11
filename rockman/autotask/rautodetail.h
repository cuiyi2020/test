#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>

using std::vector;

class Rautodetail : public QWidget
{
    Q_OBJECT
public:
    explicit Rautodetail(QWidget *parent = nullptr);
    ~Rautodetail(){}
    void test_fresh(float);
    /*For test.*/
    static void widget_test();

signals:
    void backRecordW();

private:
    void create_ui();
    void create_connections();
    auto transTime(float time)->QString;
    auto transCleanConfig(int model_id)->QString;
    //auto transDate(const std_msgs::Time &time)->QString;

private:
    QWidget *up_clean_describ;
    QWidget *down_clean_describ;
    QLabel *title_name;
    QPushButton *back_btn;
    QLabel *up_spacing;
    QLabel *up_stop_mark;
    QLabel *up_stop_reason;
    QLabel *up_user_name;
    QLabel *up_exec_time;
    QLabel *up_clean_times;
    QLabel *up_clean_model;
    QLabel *down_etime_title;
    QLabel *down_spacing_1;
    QLabel *down_start_time;
    QLabel *down_stop_time;
    QLabel *down_area_title;
    QLabel *down_clean_area;
    QLabel *down_eff_title;
    QLabel *down_eff_clean;
    QPushButton *m_end_btn;
    int m_down_clean_area_x;
    int m_down_clean_area_y;
    int m_down_clean_area_width;
};
