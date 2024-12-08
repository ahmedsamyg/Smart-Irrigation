#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Client.h>
#include<QMetaEnum>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setBackgroundImage();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pbsenddata_clicked();

    void on_pbconnect_clicked();

    void on_pbdisconnect_clicked();

    void recieveOnConnect();
    void recieveDisConnect();
    void recieveOnError(QAbstractSocket::SocketError error);
    void recieveOnReadyread(QString data );
    void recieveOnStatechange(QAbstractSocket::SocketState state);
    void on_pbTemp_clicked();

    void on_pbOn_clicked();

    void on_pboff_clicked();

    void on_pbexit_clicked();

    void on_pbrain_clicked();

    void on_pbpumpoff_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pbpumplow_clicked();

    void on_pbpumpmed_clicked();

    void on_pbpumpmax_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
};
#endif // MAINWINDOW_H
