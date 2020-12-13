#include "mscrollarea.h"
#include <QDebug>

MScrollArea::MScrollArea(QWidget *parent)
    : QScrollArea (parent),
      mMoveStart(false),
      mContinuousMove(false),
      mMousePoint(QPoint(0,0))
{
    installEventFilter(this);
}

bool MScrollArea::eventFilter(QObject *obj, QEvent *evt){
    //int k=0;
    if(evt->type() == QEvent::MouseMove){
        QMouseEvent *me = static_cast<QMouseEvent *>(evt);
        if(me->buttons() & Qt::LeftButton){
            if(!mMoveStart){
                mMoveStart = true;
                mContinuousMove = false;
                mMousePoint = me->globalPos();
                //qDebug() << "最大值";
            } else {
                scrollBar_x = horizontalScrollBar();
                scrollBar_y = verticalScrollBar();
                QPoint p = me->globalPos();
                int offset_x = p.x() - mMousePoint.x();
                int offset_y = p.y() - mMousePoint.y();
                if(!mContinuousMove && (offset_x > -10 && offset_x < 10) && (offset_y > -10 && offset_y < 10)) {
                    //qDebug() << "out.";
                    return false;
                }

                mContinuousMove = true;
                scrollBar_x->setValue(scrollBar_x->value() - offset_x);
                scrollBar_y->setValue(scrollBar_y->value() - offset_y);
                //qDebug() << "scrollbar_y->" << scrollBar_y->value() << offset_y;
//                qDebug() << "最大值" << scrollBar_y->maximum();
                mMousePoint = p;
            }
            return true;
        }
    } else if (evt->type() == QEvent::MouseButtonRelease) {
        mMoveStart = false;
        scrollBar_y = verticalScrollBar();
        //qDebug() << "滚动条: " << scrollBar_y->maximum() << scrollBar_y->value();
        if(scrollBar_y->value() >= scrollBar_y->maximum()){
            emit reloading();
//                     update();
        }
    }
    return QObject::eventFilter(obj, evt);
}
