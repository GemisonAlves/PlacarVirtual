#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSerialPort serial;


    int contador;
    int contador2;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_abrir_conn_clicked();

    void on_fechar_conn_clicked();

    void dadosRecebidos();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
