#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>

class QLabel;
class QPushButton;
class QTimer;
class Manualcontroller;

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = nullptr);
    ~Manual(){};
    void create_ui();
    void create_connections();
    QPushButton *get_brushup_btn(){
        return m_brushup_btn;
    }
    QPushButton *get_brushdown_btn(){
        return m_brushdown_btn;
    }

signals:
    void signal_faword();
    void signal_back();

private:
    QLabel *m_brush;
    QPushButton *m_brushup_btn;
    QPushButton *m_brushdown_btn;
    Manualcontroller *m_mcon;
    QTimer *m_timer;

};


#endif //MANUAL_H
