#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <pilha.h>
#include <mudarbase.h>
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
        teste.divisao(numero, base);
        ED1::Pilha pilha(numero);
        QString saida;
        while (!pilha.estaVazio()) {
            saida +=  QString::number(pilha.consultar()) + "\n";
            pilha.consultar();
        }
        ui->textEditResult->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"CATCH",(erro));
    }
}
