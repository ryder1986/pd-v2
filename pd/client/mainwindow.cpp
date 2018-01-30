#include "mainwindow.h"
#include "ui_form.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    connect(&clt,SIGNAL(msg_arrived(int,QByteArray)),this,SLOT(deal_client_msg(int,QByteArray)),Qt::DirectConnection);
  //   ui->treeWidget_devices;

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_pushButton_clicked()
//{

//}

//void MainWindow::on_pushButton_get_config_clicked()
//{
//    get_config();
//}

void MainWindow::on_pushButton_connect_clicked()
{
   connect_server(ui->lineEdit_connect->text());
}

void MainWindow::on_pushButton_get_clicked()
{
//   QThread *p=new QThread;
//   clt.moveToThread(p);
//   p->start();
   QByteArray cfg=clt.get_config();

}

void MainWindow::on_pushButton_search_clicked()
{

}

void MainWindow::on_treeWidget_devices_customContextMenuRequested(const QPoint &pos)
{
    current_dev->right_click(pos);
}
