#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QtGui>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void mouseMoveEvent(QMouseEvent *event);
    ~MainWindow();

private slots:    
    void on_open_image_button_triggered();

    void on_exit_button_triggered();

    void on_zoom_in_button_triggered();

    void on_fit_button_triggered();

    void on_zoom_out_button_triggered();

    void on_fit_inv_button_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsItem *item;
    QGraphicsScene *scene;


};
#endif // MAINWINDOW_H
