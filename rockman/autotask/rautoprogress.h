#pragma once

#include "mscrollarea.h"
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
#include <vector>

using std::vector;

enum {
    AutoStateDone=1,
    AutoStateJump=2,//active
    AutoStateWait=3//waiting
};

typedef struct Sautodata_{
    Sautodata_(int id=0, int state=AutoStateWait) : m_id(id), m_state(state){}
    int m_id;
    int m_state;
}Sautodata;

class Rautoprogressitem : public QWidget{
  Q_OBJECT
public:
    explicit Rautoprogressitem(QWidget *parent = nullptr);
    ~Rautoprogressitem(){}
    void set_data(int id, const QString &pgitem, const QString &model, const QString &percent, int state);
    void refresh_state_btn();
    inline void set_state(int state);
    inline int get_id();
private slots:
    void slot_jump();
private:
    void create_ui();
    void create_connections();
    void set_label();
    void set_state_btn();

private:
    int m_id;
    int m_state;
    QString m_pgitem;
    QString m_model;
    QString m_percent;
    QLabel *m_pg_lb;
    QLabel *m_model_lb;
    QPushButton *m_state_btn;
};

class Rautoprogress : public QWidget
{
    Q_OBJECT
public:
    explicit Rautoprogress(QWidget *parent = nullptr);
    ~Rautoprogress(){}

    static void test_autoprogress();
    void resume(int);
    void set_item_state(vector<Sautodata*> &rhs);

private:
    void create_ui();
    void create_connections();
    void init();
    void add_items();
    void set_scrollpos(int k);
    void clear_items();

public:
    QVBoxLayout *m_vlayout;


private:
    QWidget *m_wd;
    QWidget *m_down_wd;
    QWidget *m_total_widget;
    QWidget *m_list_widget;
    QPushButton *m_task_btn;
    QPushButton *m_end_btn;
    MScrollArea *m_scroll_area;

    Rautoprogressitem *m_pgitem;
    QList<QWidget*> m_total_items;
    QScrollBar *m_scrollbar_y;
    int m_item_size;
};

