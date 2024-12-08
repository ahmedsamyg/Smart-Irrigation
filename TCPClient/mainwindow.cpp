#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPixmap>
#include <QPalette>
#include <QPainter>
void MainWindow::setBackgroundImage()
{
    QPixmap pixmap("D://image.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, pixmap.scaled(this->size(), Qt::IgnoreAspectRatio));
    this->setPalette(palette);
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pixmap("D://image.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);
    QMainWindow::paintEvent(event);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&client,&Client::sendOnConnect,this,&MainWindow::recieveOnConnect);
    connect(&client,&Client::sendDisConnect,this,&MainWindow::recieveDisConnect);
    connect(&client,&Client::sendOnReadyread,this,&MainWindow::recieveOnReadyread);
    connect(&client,&Client::sendOnError,this,&MainWindow::recieveOnError);
    connect(&client,&Client::sendOnStatechange,this,&MainWindow::recieveOnStatechange);
    // QPixmap pix("C://Users//Abdallah Elaraby//Downloads//rr.png");
    // int w=ui->lbackground->width();
    // int h=ui->lbackground->height();
    // ui->lbackground->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pbconnect_clicked()
{
    QString ip=ui->lEip->text();
    qint32 port=ui->lEport->text().toInt();
    qDebug()<<"IP:>  "<<ip<<Qt::endl;
    qDebug()<<"port:>  "<<port<<Qt::endl;
    client.ConnectToHost(ip,port);


}


void MainWindow::on_pbdisconnect_clicked()
{
    client.DisConnect();
}

void MainWindow::recieveOnConnect()
{
    ui->lwConsle->addItem("Connected to Host");
}

void MainWindow::recieveDisConnect()
{
    ui->lwConsle->addItem("Disconnected from Host");
}

void MainWindow::recieveOnError(QAbstractSocket::SocketError error)
{
    QMetaEnum errorobj=QMetaEnum::fromType<QAbstractSocket::SocketError>();
    QString errorstring=errorobj.valueToKey(error);
    ui->lwConsle->addItem(errorstring);
}

void MainWindow::recieveOnReadyread(QString data)
{
    ui->lwData->addItem(data);
    qDebug()<<data<<Qt::endl;
    QStringList lines = data.split('\n', Qt::SkipEmptyParts);
    for (const QString &line : lines) {
        if (line.contains("Humidity") && line.contains("Temperature")) {
            QStringList params = line.split(',', Qt::SkipEmptyParts);
            for (const QString &param : params) {
                if (param.contains("Humidity:")) {
                    QString humidity = param.mid(param.indexOf(':') + 1).trimmed();
                    ui->lwHumidity->clear();
                    ui->lwHumidity->addItem("Humidity: " + humidity);
                } else if (param.contains("Temperature:")) {
                    QString temperature = param.mid(param.indexOf(':') + 1).trimmed();
                    ui->lwTemp->clear();
                    ui->lwTemp->addItem("Temperature: " + temperature);
                }
            }
        } else if (line.startsWith("Pump State:")) {
            QString pumpState = line.mid(line.indexOf(':') + 1).trimmed();
            if(pumpState=="0"){
                pumpState="OFF";
            }
            else if(pumpState=="1"){
                pumpState="Low Speed";
            }
            else if(pumpState=="2"){
                pumpState="Medium Speed";
            }
            else if(pumpState=="3"){
                pumpState="Max Speed";
            }else{
                qDebug() << "Unknown data format: " << line;
            }
            ui->lwPump->clear();
            ui->lwPump->addItem("Pump State: " + pumpState);
        } else if (line.startsWith("Soil Moisture level:")) {
            QString moistureLevel = line.mid(line.indexOf(':') + 1).trimmed();
            ui->lwMoisture->clear();
            ui->lwMoisture->addItem("Soil Moisture Level: " + moistureLevel);
        } else if (line.startsWith("Rain state:")) {
            QString rainState = line.mid(line.indexOf(':') + 1).trimmed();
            ui->lwRain->clear();
            ui->lwRain->addItem("Rain State: " + rainState);
        } else {
            qDebug() << "Unknown data format: " << line;
        }

}

}

void MainWindow::recieveOnStatechange(QAbstractSocket::SocketState state)
{
    QMetaEnum stateobject=QMetaEnum::fromType<QAbstractSocket::SocketState >();
    QString statestring=stateobject.valueToKey(state);
    ui->lwConsle->addItem(statestring);
}


void MainWindow::on_pbTemp_clicked()
{
    client.SendData("read_sensor");
}


void MainWindow::on_pbOn_clicked()
{
    client.SendData("on");
}


void MainWindow::on_pboff_clicked()
{
    client.SendData("off");
}


void MainWindow::on_pbexit_clicked()
{
    client.SendData("Quit");
}


void MainWindow::on_pbrain_clicked()
{
    client.SendData("check_rain");
}


void MainWindow::on_pbpumpoff_clicked()
{
    client.SendData("pump_off");
}




void MainWindow::on_pbpumplow_clicked()
{
    client.SendData("pump_low");
}


void MainWindow::on_pbpumpmed_clicked()
{
    client.SendData("pump_med");
}


void MainWindow::on_pbpumpmax_clicked()
{
    client.SendData("pump_max");
}


void MainWindow::on_pushButton_3_clicked()
{
    client.SendData("auto_control");
}

