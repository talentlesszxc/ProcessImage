#include "imageview.h"

imageview::imageview(QWidget *parent) : QGraphicsView(parent)
{
    setTransformationAnchor(AnchorUnderMouse);

    setDragMode(QGraphicsView::ScrollHandDrag);
}
//мастшаб колесом мыши
void imageview::wheelEvent(QWheelEvent *event)
{

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor = 1.15;

    if (event->delta() > 0)
    {
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        scale(1/scaleFactor, 1/scaleFactor);
    }
}
//вписывает все изображение в экран
void imageview::viewFit()
{
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}
//масштабирует область изображения по размеру экрана
void imageview::rectFit()
{
    QRectF exactRect(4000, 0, 1792, 1024); //(х_начала, у_начала, размер_х_прямоугольника, размер_у_прямоугольника)
    fitInView(exactRect);
}
//void imageview::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//    /* При нажатии мышью на графический элемент
//     * заменяем курсор на руку, которая держит этот элемента
//     * */
//    this->setCursor(QCursor(Qt::ClosedHandCursor));
//    Q_UNUSED(event);
//}

//зум+
void imageview::zoom_in()
{
    double scaleFactor = 1.15;
    scale(scaleFactor, scaleFactor);
}
//зум-
void imageview::zoom_out()
{
    double scaleFactor = 1.15;
    scale(1/scaleFactor, 1/scaleFactor);
}

