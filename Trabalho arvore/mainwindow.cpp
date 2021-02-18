#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    teste(0)
{
    ui->setupUi(this);
    teste= new ed1::Arvore();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete teste;
}
void MainWindow::on_pushButtonInserir_clicked(){
    try {
        teste->inserir(ui->lineEditElemento->text().toInt());
        ui->textEditArvore->setText(ui->lineEditElemento->text());
        } catch (QString &erro) {
        QMessageBox::information(this, "ERRO",erro);
        }
}
void MainWindow::on_pushButtonAltura_clicked(){
    try {
        QString saida;
        saida+=teste->profundidade();
        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtonConsultar_clicked(){
    try {
        QString saida;
        saida+=teste->consultar(ui->lineEditElemento->text().toInt());
        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRo",erro);
    }
}
void MainWindow::on_pushButtonPosdir_clicked(){
    try {
        QString saida;
        lista= teste->PreEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida +=""+QString::number(lista[i])+",";
        }

        ui->textEditArvore->setText(saida);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtonPosesq_clicked(){
    try {
        QString saida;
        lista = teste->PosEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(lista[i])+"]";
        }

        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }

}
void MainWindow::on_pushButtonPredir_clicked(){
    try {
        QString saida;
        lista = teste->PosEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(lista[i])+"]";
        }

        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtonPreesq_clicked(){
    try {
        QString saida;
        lista = teste->PosEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(lista[i])+"]";
        }

        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtoncentdir_clicked(){
    try {
        QString saida;
        lista = teste->PosEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(lista[i])+"]";
        }

        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtoncentesq_clicked(){
    try {
        QString saida;
        lista = teste->PosEsquerda();

        int tamanho = lista.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(lista[i])+"]";
        }

        ui->textEditArvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
