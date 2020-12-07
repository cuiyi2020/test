#ifndef REPITEMBASE_H
#define REPITEMBASE_H

#include <QListWidgetItem>

class Repitembase : public QWidget, public QListWidgetItem{

public:
    explicit Repitembase(QWidget *parent = nullptr) : QWidget(parent) {
    }
//    explicit Repitembase(QListWidget *view) :QListWidget(view){
//    }
    virtual ~Repitembase(){};

private:
};

#endif // REPITEMBASE_H
