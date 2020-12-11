#ifndef MSCROLLAREA_H
#define MSCROLLAREA_H

#include <QScrollArea>
#include <QObject>
#include <QMouseEvent>
#include <QScrollBar>

class MScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    MScrollArea(QWidget *parent = nullptr);
    ~MScrollArea(){}

signals:
    void reloading();

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    bool mMoveStart;
    bool mContinuousMove;
    QPoint mMousePoint;
    QScrollBar *scrollBar_x;
    QScrollBar *scrollBar_y;
};

#endif // MSCROLLAREA_H
