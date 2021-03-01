#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <opencv2/opencv.hpp>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}

//кнопка открыть изображение. Выбранное изображение помещается в лейбл input_image_label
void MainWindow::on_open_image_button_triggered()
{    
    QString image_file = QFileDialog::getOpenFileName(this,
         tr("Open Image"), "D:/Nadenenko/CProjects/QtProjects/fdeep/fdeep/", tr("Image Files (*.png *.jpg *.bmp *.tiff *.tif)"));
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
            ui->graphicsView->setScene(scene);
            scene->addItem(item);



}

void MainWindow::on_exit_button_triggered()
{
    QApplication::quit();
}

void MainWindow::on_zoom_in_button_triggered()
{
    double scaleFactor = 1.1;
    ui->input_image_label->resize(scaleFactor * ui->input_image_label->pixmap()->size());
}
