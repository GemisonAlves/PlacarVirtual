#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    contador=0;
    contador2=0;

    ui->setupUi(this);

    for (auto& item : QSerialPortInfo::availablePorts())
        ui ->box_serial->addItem(item.portName());

    for (auto& item : QSerialPortInfo::standardBaudRates())
        ui ->box_velocidade ->addItem(QString::number(item));

    connect(&serial,
            SIGNAL(readyRead()),
            this,
            SLOT(dadosRecebidos()));
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_abrir_conn_clicked()
{
    serial.setPortName(ui->box_serial->currentText());
    serial.setBaudRate(ui->box_velocidade->currentText().toInt());

    if(serial.open(QIODevice::ReadWrite)){
        ui->status_conexao->setText("Status: conectado");
    }
}

void MainWindow::on_fechar_conn_clicked()
{
    serial.close();
    ui->status_conexao->setText("Status: Desconectado");
}

void MainWindow::dadosRecebidos(){

    auto data = serial.readAll();
    auto dados = QJsonDocument::fromJson(data).object().toVariantMap();
    qDebug() << dados << endl;
        if(dados.contains("LED01")){
            contador++;
            ui ->casa_dados->setText(QString::number(contador));
        }
        if(dados.contains("LED02")){
            contador2++;
            ui->dados_visitante->setText(QString::number(contador2));
        }
}
