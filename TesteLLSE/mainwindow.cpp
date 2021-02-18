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
        //inserir inicio
        int num = QInputDialog::getInt(this , "Inserir Inicio","Número: ");
        teste.inserirInicio(num);
        QString saida;
        saida = "Número inserido\n";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    try {
        //inserir fim
        int num = QInputDialog::getInt(this , "Inserir Fim","Número: ");
        teste.inserirFim(num);
        QString saida;
        saida = "Número inserido\n";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    try {
        //retirar inicio
        QString saida;
        saida = "Número " + QString::number(teste.retirarInicio()) + " retirado\n";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    try {
        //retirar fim
        QString saida;
        saida = "Número " + QString::number(teste.retirarFim()) + " retirado\n";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    try {
        //consultar por posição
        int num = QInputDialog::getInt(this , "Consulta por Posição","Posição: ");
        QString saida = "Numero na posição[" + QString::number(num) + "]: " + QString::number(teste.operator[](num));
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    try {
        //mostrar lista
        QString saida = "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    try {
        //inserir por posição
        int posicao=QInputDialog::getInt(this,"Inserir por Posição","Posição: ");
        int num=QInputDialog::getInt(this,"Inserir por Posição","Elemento: ");
        teste.inserirPorPosicao(posicao,num);
        QString saida = "Número inserido na posição[" + QString::number(posicao) + "]";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    try {
        //retirar por posição
        int posicao = QInputDialog::getInt(this , "Retirar por Posição","Posição: ");
        QString saida = "Número " + QString::number(teste.retirarPorPosicao(posicao)) + " retirado na posição[" + QString::number(posicao) + "]";
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
