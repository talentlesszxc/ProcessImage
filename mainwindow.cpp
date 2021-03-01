#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <QMouseEvent>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    ui->label_coords->setText("X:"+QString::number(event->x())+", Y:"+QString::number(event->y()));
    ui->statusbar->showMessage("ready", 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//кнопка открыть изображение. Выбранное изображение помещается в лейбл input_image_label
void MainWindow::on_open_image_button_triggered()
{    
    QString image_file = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "D:/Nadenenko/CProjects/QtProjects/ProcessImage/ProcessImage/", tr("Image Files (*.png *.jpg *.bmp *.tiff *.tif)"));
        std::string image_path = image_file.toStdString();
        cv::Mat img_inp;
        img_inp = cv::imread(image_path);
        //int w = ui->input_image_label->width();
        //int h = ui->input_image_label->height();
        ui->input_image_label->setPixmap(
                    QPixmap::fromImage(QImage(img_inp.data, img_inp.cols, img_inp.rows,
                                                           img_inp.step, QImage::Format_RGB888)).scaled(256,128,Qt::KeepAspectRatio));
        //ui->scrollArea->setPixmap
        //ui->input_image_label->refreshLabel();

        //ui->input_image_label->adjustSize();
            //QImage imgz(img_inp.data, img_inp.cols, img_inp.rows);
            //QImage image("D:/z.png");
            //item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
            item = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(img_inp.data, img_inp.cols, img_inp.rows,
                                                                     img_inp.step, QImage::Format_RGB888)));
            scene = new QGraphicsScene(this);
            //scene->setSceneRect(500, 50, 50, 50);
            ui->graphicsView->setScene(scene);
            scene->addItem(item);



}

//при нажатии на зум+ выполняется функция zoom_in (описана в imageview.cpp, объявлена в заголовочном)
void MainWindow::on_zoom_in_button_triggered()
{    
    ui->graphicsView->zoom_in();
}

//при нажатии на зум- выполняется функция zoom_out (описана в imageview.cpp, объявлена в заголовочном)
void MainWindow::on_zoom_out_button_triggered()
{
    ui->graphicsView->zoom_out();
}

//при нажатии на кнопку фит выполняется функция viewFit (описана в imageview.cpp, объявлена в заголовочном)
void MainWindow::on_fit_button_triggered()
{
    ui->graphicsView->viewFit();

}

//при нажатии на кнопку фит_inv выполняется функция rectFit (описана в imageview.cpp, объявлена в заголовочном)
void MainWindow::on_fit_inv_button_triggered()
{
    ui->graphicsView->rectFit();
}

void MainWindow::on_exit_button_triggered()
{
    QApplication::quit();
}
