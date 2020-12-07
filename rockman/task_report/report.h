#ifndef REPORT_H
#define REPORT_H

#include <QListWidget>

class Report : public QWidget {
    Q_OBJECT
public:
    explicit Report(QWidget *parent = nullptr);

private:
    void create_ui();
    void create_connections();
    void add_list_items();

private:
    QWidget *m_wd;
    QListWidget *m_list;
};

#endif // REPORT_H
