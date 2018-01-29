#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "client.h"
namespace Ui {
class Form;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_get_config_clicked();

private:
    void connect_server(QString ip)
    {
        clt.connect_to_server("192.168.1.216");

    }
    void get_config()
    {
          QByteArray cfg=clt.get_config();
    }

    Ui::Form *ui;
    Client clt;
};

#endif // MAINWINDOW_H
