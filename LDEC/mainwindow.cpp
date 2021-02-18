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


void MainWindow::on_pushButtonInserirInicio_clicked()
{
    try {
        int num = QInputDialog::getInt(this , "Inserir Inicio","Número: ");
        teste.inserirInicio(num);
        QString saida;
        saida = "Número inserido\n";
        saida += "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try {
        QString saida;
        saida = "Número " + QString::number(teste.retirarInicio()) + " retirado\n";
        saida += "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    try {
        int num = QInputDialog::getInt(this , "Inserir Fim","Número: ");
        teste.inserirFim(num);
        QString saida;
        saida = "Número inserido\n";
        saida += "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    try {
        QString saida;
        saida = "Número " + QString::number(teste.retirarFim()) + " retirado\n";
        saida += "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    try {
        int posicao=QInputDialog::getInt(this,"Inserir por Posição","Posição: ");
        int num=QInputDialog::getInt(this,"Inserir por Posição","Elemento: ");
        teste.inserirPosicao(posicao,num);
        QString saida = "Número inserido na posição[" + QString::number(posicao) + "]";
        saida += "\nLista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    try {
        int posicao = QInputDialog::getInt(this , "Retirar por Posição","Posição: ");
        QString saida = "Número " + QString::number(teste.retirarPosicao(posicao)) + " retirado na posição[" + QString::number(posicao) + "]";
        saida += "\nLista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    try {
        int num = QInputDialog::getInt(this , "Inserir ordenado","Elemento: ");
        teste.inserirOrdenado(num);
        QString saida = "Número inserido\n";
        saida += "Lista: \n";
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
        int num = QInputDialog::getInt(this , "Consulta por Posição","Posição: ");
        QString saida = "Numero na posição[" + QString::number(num) + "]: " + QString::number(teste.operator[](num))+"\n";
        saida += "Lista: \n";
        for(int i=0; i<teste.getQuantidade(); i++){
            saida+=QString::number(teste[i]) + " , ";
        }
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    try {
        int num = QInputDialog::getInt(this , "Girar sentido horário","Número de vezes: ");
        QString saida;
        saida = teste.girarHorario(num);
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_11_clicked()
{
    try {
        int num = QInputDialog::getInt(this , "Girar sentido anti-horário","Número de vezes: ");
        QString saida;
        saida = teste.girarAnti(num);
        ui->textEdit->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
