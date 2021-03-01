#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class imageview : public QGraphicsView
{
public:
    imageview(QWidget* parent = 0);
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // IMAGEVIEW_H
