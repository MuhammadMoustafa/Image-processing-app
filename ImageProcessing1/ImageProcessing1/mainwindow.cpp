#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtGui>
#include <QtCore>
#include <QFileDialog>

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(int2str(int)));

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(image_threshold(int)));

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(str2int(QString)));

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(image_threshold(QString)));

    ui->rdbtn_histequ->setEnabled(false);
    ui->rdbtn_negation->setEnabled(false);
    ui->rdbtn_normalization->setEnabled(false);
    ui->btn_plot->setEnabled(false);
    //ui->btn_save->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->horizontalSlider->setEnabled(false);

    ui->widget_cdf->hide();
    ui->widget_hist->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::str2int(QString string){
    ui->horizontalSlider->setValue(string.toInt());
}

void MainWindow::int2str(int integer){
    ui->lineEdit->setText(QString::number(integer));
}

void MainWindow::image_threshold(int integer){

    if(ui->rdbtn_normalization->isChecked()){
        ui->rdbtn_normalization->setAutoExclusive(false);
        ui->rdbtn_normalization->setChecked(false);
        ui->rdbtn_normalization->setAutoExclusive(true);
    }

    integer = int(integer *100 /255.0)+1;
    Mat image_grayScaled;
    cvtColor(image, image_grayScaled, CV_BGR2GRAY);

    for(int i = 0; i < image_grayScaled.rows; i++){
        for(int j = 0; j < image_grayScaled.cols; j++){
            if(image_grayScaled.at<uchar>(i,j) > integer){
                image_grayScaled.at<uchar>(i,j) = 255;
            }
            else{
                image_grayScaled.at<uchar>(i,j) = 0;
            }
        }
    }
    QPixmap pixmap = QPixmap::fromImage(QImage(image_grayScaled.data, image_grayScaled.cols, image_grayScaled.rows, image_grayScaled.step, QImage::Format_Grayscale8));
    ui->lbl_imageThresholded->setPixmap(pixmap.scaled(ui->lbl_imageThresholded->size(), Qt::KeepAspectRatio));

}

void MainWindow::image_threshold(QString string){

    if(ui->rdbtn_normalization->isChecked()){
        ui->rdbtn_normalization->setAutoExclusive(false);
        ui->rdbtn_normalization->setChecked(false);
        ui->rdbtn_normalization->setAutoExclusive(true);
    }


    int integer = string.toInt();
    integer = int(integer *100 /255.0);
    Mat image_grayScaled;
    cvtColor(image, image_grayScaled, CV_BGR2GRAY);

    for(int i = 0; i < image_grayScaled.rows; i++){
        for(int j = 0; j < image_grayScaled.cols; j++){
            if(image_grayScaled.at<uchar>(i,j) > integer){
                image_grayScaled.at<uchar>(i,j) = 255;
            }
            else{
                image_grayScaled.at<uchar>(i,j) = 0;
            }
        }
    }
    QPixmap pixmap = QPixmap::fromImage(QImage(image_grayScaled.data, image_grayScaled.cols, image_grayScaled.rows, image_grayScaled.step, QImage::Format_Grayscale8));
    ui->lbl_imageThresholded->setPixmap(pixmap.scaled(ui->lbl_imageThresholded->size(), Qt::KeepAspectRatio));

}

void MainWindow::on_btn_browse_clicked()
{
    imagePath =QFileDialog::getOpenFileName(this,
                                                   tr("Open Image"), "./", tr("Image Files (*.png *.jpg *.bmp)"));;

    if(imagePath != ""){
        image = imread(imagePath.toStdString(), CV_LOAD_IMAGE_COLOR);

        Mat image_colored;
        cvtColor(image, image_colored, CV_BGR2GRAY);
        QPixmap pixmap = QPixmap::fromImage(QImage(image_colored.data, image_colored.cols, image_colored.rows, image_colored.step, QImage::Format_Grayscale8));
        ui->lbl_image->setPixmap(pixmap.scaled(ui->lbl_image->size(), Qt::KeepAspectRatio));

        ui->rdbtn_histequ->setEnabled(true);
        ui->rdbtn_negation->setEnabled(true);
        ui->rdbtn_normalization->setEnabled(true);
        ui->btn_plot->setEnabled(true);
        //ui->btn_save->setEnabled(true);
        ui->lineEdit->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);

        if (ui->rdbtn_histequ->isChecked()){
            ui->rdbtn_histequ->setAutoExclusive(false);
            ui->rdbtn_histequ->setChecked(false);
            ui->rdbtn_histequ->setAutoExclusive(true);
        }
        else if (ui->rdbtn_negation->isChecked()){
            ui->rdbtn_negation->setAutoExclusive(false);
            ui->rdbtn_negation->setChecked(false);
            ui->rdbtn_negation->setAutoExclusive(true);
        }
        else{
            ui->rdbtn_normalization->setAutoExclusive(false);
            ui->rdbtn_normalization->setChecked(false);
            ui->rdbtn_normalization->setAutoExclusive(true);

        }

        ui->horizontalSlider->setValue(0);
        ui->lineEdit->clear();
        ui->lbl_imageInverted->clear();
        ui->lbl_imageThresholded->clear();

        for (int i=0; i < ui->widget_cdf->plottableCount(); i++) ui->widget_cdf->removePlottable(i);

        //ui->widget_cdf->clearPlottables();
        //ui->widget_cdf->removeGraph(0);
        ui->widget_cdf->hide();
        ui->widget_hist->hide();
        //ui->widget_cdf->clearGraphs();
        //ui->widget_hist->clearGraphs();
    }
}


void MainWindow::on_btn_plot_clicked()
{
    ui->widget_cdf->show();
    ui->widget_hist->show();

    if (ui->rdbtn_histequ->isChecked()){
        ui->rdbtn_histequ->setAutoExclusive(false);
        ui->rdbtn_histequ->setChecked(false);
        ui->rdbtn_histequ->setAutoExclusive(true);
    }

    QVector<double> x_range(256), hist(256), cdf(256);
    Mat image_grayScaled;
    cvtColor(image, image_grayScaled, CV_BGR2GRAY);

    int histmax = 0;
    int value;
    for(int i = 0; i < image_grayScaled.rows; i++){
        for(int j = 0; j < image_grayScaled.cols; j++){
            value = image_grayScaled.at<uchar>(i,j);
            hist[value] +=1;
        }
    }


    for(int i = 0; i < 256; i++){
       x_range[i] = i;

       for(int j = 0; j <= i; j++){
            cdf[i] += hist[j];
        }

       if ( hist[i] > histmax){
           histmax = hist[i];
       }

    }

    ui->widget_hist->addGraph();
    ui->widget_hist->graph(0)->setData(x_range, hist);
    // give the axes some labels:
    ui->widget_hist->xAxis->setLabel("x");
    ui->widget_hist->yAxis->setLabel("frequency");
    // set axes ranges, so we see all data:
    ui->widget_hist->xAxis->setRange(0, 256);
    ui->widget_hist->yAxis->setRange(0, histmax + 1000);
    ui->widget_hist->replot();

    ui->widget_cdf->addGraph();
    ui->widget_cdf->graph(0)->setData(x_range, cdf);
    // give the axes some labels:
    ui->widget_cdf->xAxis->setLabel("x");
    ui->widget_cdf->yAxis->setLabel("cdf");
    // set axes ranges, so we see all data:
    ui->widget_cdf->xAxis->setRange(0, 256);
    ui->widget_cdf->yAxis->setRange(0, cdf.last() + 1000);
    ui->widget_cdf->replot();
}

void MainWindow::on_rdbtn_negation_clicked(bool checked)
{
    if (checked){
        Mat image_grayScaled;
        cvtColor(image, image_grayScaled, CV_BGR2GRAY);

        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                image_grayScaled.at<uchar>(i,j) = 255 - image_grayScaled.at<uchar>(i,j);
            }
        }

        QPixmap pixmap = QPixmap::fromImage(QImage(image_grayScaled.data, image_grayScaled.cols, image_grayScaled.rows, image_grayScaled.step, QImage::Format_Grayscale8));
        ui->lbl_imageInverted->setPixmap(pixmap.scaled(ui->lbl_imageInverted->size(), Qt::KeepAspectRatio));

    }
}

void MainWindow::on_rdbtn_histequ_clicked(bool checked)
{
    if (checked){
        ui->widget_cdf->show();
        ui->widget_hist->show();

        QVector<double> x_range(256), hist(256), cdf(256), histnorm(256), cdfnorm(256);
        Mat image_grayScaled;
        cvtColor(image, image_grayScaled, CV_BGR2GRAY);

        int histmax = 0;
        int value;
        int imagemax=0;

        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                value = image_grayScaled.at<uchar>(i,j);
                hist[value] +=1;

                if (value > imagemax) { imagemax = value;}
            }
        }


        for(int i = 0; i < 256; i++){
           x_range[i] = i;

           for(int j = 0; j <= i; j++){
                cdf[i] += hist[j];
            }

           if ( hist[i] > histmax){
               histmax = hist[i];
           }

        }

    /****/
        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                image_grayScaled.at<uchar>(i,j) = cdf[image_grayScaled.at<uchar>(i,j)] * imagemax / (image_grayScaled.rows * image_grayScaled.cols);
            }
        }


        QPixmap pixmap = QPixmap::fromImage(QImage(image_grayScaled.data, image_grayScaled.cols, image_grayScaled.rows, image_grayScaled.step, QImage::Format_Grayscale8));
        ui->lbl_imageThresholded->setPixmap(pixmap.scaled(ui->lbl_imageThresholded->size(), Qt::KeepAspectRatio));


        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                value = image_grayScaled.at<uchar>(i,j);
                histnorm[value] +=1;
            }
        }


        int histnormmax=0;

        for(int i = 0; i < 256; i++){
           x_range[i] = i;

           for(int j = 0; j <= i; j++){
                cdfnorm[i] += histnorm[j];
            }

           if ( histnorm[i] > histnormmax){
               histnormmax = histnorm[i];
           }
        }

        ui->widget_hist->addGraph();
        ui->widget_hist->graph(0)->setData(x_range, histnorm);
        // give the axes some labels:
        ui->widget_hist->xAxis->setLabel("x");
        ui->widget_hist->yAxis->setLabel("frequency");
        // set axes ranges, so we see all data:
        ui->widget_hist->xAxis->setRange(0, 256);
        ui->widget_hist->yAxis->setRange(0, histnormmax + 1000);
        ui->widget_hist->replot();

        ui->widget_cdf->addGraph();
        ui->widget_cdf->graph(0)->setData(x_range, cdfnorm);
        // give the axes some labels:
        ui->widget_cdf->xAxis->setLabel("x");
        ui->widget_cdf->yAxis->setLabel("cdf");
        // set axes ranges, so we see all data:
        ui->widget_cdf->xAxis->setRange(0, 256);
        ui->widget_cdf->yAxis->setRange(0, cdfnorm.last() + 1000);
        ui->widget_cdf->replot();

    }
}

void MainWindow::on_rdbtn_normalization_clicked(bool checked)
{
    if (checked){
        Mat image_grayScaled;
        cvtColor(image, image_grayScaled, CV_BGR2GRAY);

        int value;
        int imagemax=0;
        int imagemin=0;

        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                value = image_grayScaled.at<uchar>(i,j);
                if (value > imagemax) { imagemax = value;}
                if (value < imagemin) { imagemin = value;}
            }
        }

        int range = imagemax - imagemin;
        for(int i = 0; i < image_grayScaled.rows; i++){
            for(int j = 0; j < image_grayScaled.cols; j++){
                value = image_grayScaled.at<uchar>(i,j);

                image_grayScaled.at<uchar>(i,j) = (value - imagemin) * imagemax / range ;
           }
        }

        QPixmap pixmap = QPixmap::fromImage(QImage(image_grayScaled.data, image_grayScaled.cols, image_grayScaled.rows, image_grayScaled.step, QImage::Format_Grayscale8));
        ui->lbl_imageThresholded->setPixmap(pixmap.scaled(ui->lbl_imageThresholded->size(), Qt::KeepAspectRatio));

    }
}
