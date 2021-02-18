#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    try {
        ED1::MudarBase teste;
        int numero = ui->lineEditNumero->text().toInt();
        int base = ui->lineEditBase->text().toInt();
        teste.setNumero(numero);
        teste.setBase(base);
        ED1::Pilha pilha;
        ui->textEdit->setText(teste.divisao());
    } catch (QString &erro) {
        QMessageBox::information(this,"CATCH",erro);
    }
}
