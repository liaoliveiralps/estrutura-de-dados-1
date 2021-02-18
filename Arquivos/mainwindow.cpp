#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonLimparCaixa_clicked()
{
    ui->textEditSaida->clear();
}
void MainWindow::on_pushButtonTodos_clicked(){

}
void MainWindow::on_pushButtonEngenharia_clicked(){

}
void MainWindow::on_pushButtonCiencia_clicked(){

}
void MainWindow::on_pushButtonPedagogia_clicked(){

}
void MainWindow::on_pushButtonAdm_clicked(){

}
