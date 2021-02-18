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
        lia::Ordenar num(ui->lineEdit->text().toInt());
        QString saida = "Lista gerada: \n" + num.vetorDesordenado();
        saida+= "\nLista ordenada: \n" + num.arrumar();
        ui->textEdit->setText(saida);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
