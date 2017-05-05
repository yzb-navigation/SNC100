#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "xjdk_serial.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new xjdk_serial();
}

MainWindow::~MainWindow()
{
    delete ui;
}




