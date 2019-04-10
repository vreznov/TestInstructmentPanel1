#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&tmr, &QTimer::timeout, this, &MainWindow::on_pushButton_clicked);
    tmr.setInterval(10);
    tmr.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->openGLWidget->elapsed += 5;
    ui->openGLWidget->update();
}
