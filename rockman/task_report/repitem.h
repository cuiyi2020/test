#ifndef REPITEM_H
#define REPITEM_H

#include "repitembase.h"

class QLabel;
class QPushButton;

class Reptitleitem : public Repitembase{

    Q_OBJECT
public:
//    explicit Reptitleitem(QWidget *parent = nullptr) : Repitembase{parent} {
//    }
    virtual ~Reptitleitem() override{

    }
private:
    void create_ui(){}
    void create_connections(){}

private:
    QWidget *m_wd;
    QLabel  *m_area;
    QLabel  *m_duration;
    QLabel  *m_times;
    QPushButton *m_choose_btn;
};

struct Repitemtext;

class Repitem : public Repitembase{

    Q_OBJECT
public:
    explicit Repitem(QWidget *parent = nullptr);
    //Repitem();
    virtual ~Repitem() override;

private:
    void create_ui();
    void create_connections();
    void init();
    void set_text(Repitemtext *rhs);

private:
    QWidget *m_wd;
    Repitemtext *m_text;
    QLabel  *m_place;
    QLabel  *m_date;
    QLabel  *m_model;
    QLabel  *m_area;
    QLabel  *m_duration;
    QPushButton *m_detail_btn;
};


#endif // REPITEM_H
