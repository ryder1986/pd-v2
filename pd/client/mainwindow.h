#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "client.h"
#include "ui_form.h"
namespace Ui {
class Form;
}


//p_item_device_root=new QTreeWidgetItem(QStringList(lst));
//window->treeWidget_devices->addTopLevelItem(p_item_device_root);
//for(int i=0;i<p_cfg->cfg.camera_amount;i++){
//    QTreeWidgetItem *itm1=new QTreeWidgetItem(QStringList(p_cfg->cfg.camera[i].ip));
//    p_item_device_root->addChild(itm1);
//       itm1->setFlags(Qt::ItemIsEditable | itm1->flags()) ;
//}

class CurrentDevice{
public:
    CurrentDevice(QTreeWidget *wgt,QJsonObject *cfg)
    {
        w=wgt;
        p_config=cfg;
        w->clear();
        QString dev_name=p_config->value("device_name").toString();
        QTreeWidgetItem *item_root=new QTreeWidgetItem(QStringList(dev_name));
        w->addTopLevelItem(item_root);
        QJsonArray cams=p_config->value("profile").toObject().value("cameras").toArray();
        QTreeWidgetItem *item;
        foreach (QJsonValue v,cams ) {
            QString url=v.toObject().value("url").toString();
//            prt(info,"%s",url.toStdString().data());
            item=new QTreeWidgetItem(QStringList(url));
            item_root->addChild(item);
        }
    }
    void right_click(QPoint p)
    {
         prt(info,"%d %d clicked",p.x(),p.y());

    }
    ~CurrentDevice()
    {
        w->clear();
    }

private:
    QTreeWidget *w;
    QJsonObject *p_config;
};

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void deal_client_msg(int cmd,QByteArray buffer)
    {
        switch(cmd){
            case Protocol::GET_CONFIG:
              {
                ui->lineEdit_get->setText(buffer);
                QJsonDocument doc=QJsonDocument::fromJson(buffer);
                config=doc.object();
                current_dev=new CurrentDevice(ui->treeWidget_devices,&config);
//                QString dev_name=config["device_name"].toString();
              }
            break;
        default:
            break;
        }
    }

 //   void on_pushButton_clicked();

   // void on_pushButton_get_config_clicked();

    void on_pushButton_connect_clicked();

    void on_pushButton_get_clicked();

    void on_pushButton_search_clicked();

    void on_treeWidget_devices_customContextMenuRequested(const QPoint &pos);

private:
    void connect_server(QString ip)
    {
        clt.connect_to_server("192.168.1.216");

    }
//    void tree_widget_add_devices()
//    {


//    }

//    QByteArray get_config()
//    {
//          QByteArray cfg=clt.get_config();
//          return cfg;
//    }

    Ui::Form *ui;
    Client clt;
    QJsonObject config;
    CurrentDevice *current_dev;
};

#endif // MAINWINDOW_H
