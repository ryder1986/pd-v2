#include "mainwindow.h"
#include "ui_form.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   connect_server(ui->lineEdit->text());
}

void MainWindow::on_pushButton_get_config_clicked()
{
    get_config();
}
