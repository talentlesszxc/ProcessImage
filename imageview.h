#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <QGraphicsView>
#include <QtWidgets>
#include <QWidget>

class imageview : public QGraphicsView
{
public:
    imageview(QWidget* parent = 0);
    void viewFit();
    void rectFit();
    void zoom_in();
    void zoom_out();
protected:
    virtual void wheelEvent(QWheelEvent *event);
    //virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // IMAGEVIEW_H
