#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <qcustomplot.h>
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_browse_clicked();

    void str2int(QString string);

    void int2str(int integer);

    void image_threshold(int integer);

    void image_threshold(QString string);

    void on_btn_plot_clicked();

    void on_rdbtn_negation_clicked(bool checked);

    void on_rdbtn_histequ_clicked(bool checked);

    void on_rdbtn_normalization_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Mat image;
    QString imagePath;
    QVector<double> xxx;
};

#endif // MAINWINDOW_H
