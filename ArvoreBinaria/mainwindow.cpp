#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    teste = new lia::ArvoreBinaria1<int>;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete teste;
    delete ui;
}


void MainWindow::on_pushButton_InserirElemento_clicked()
{
    try {
        teste->inserir(ui->lineEdit_Elemento->text().toInt());
        ui->textEdit_Arvore->setText(ui->lineEdit_Elemento->text());
        }
    catch (QString &erro) {
        QMessageBox::information(this, "ERRO",erro);
    }
}

void MainWindow::on_pushButton_PreOrdem_clicked()
{
    try {
        QString saida;
        saida += "Exibindo Arvore em pre ordem a esquerda: ";
        listaArvore = teste->imprimirPreOrdemEsquerda();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
        }
    catch (QString &erro) {
          QMessageBox::information(this,"ERRO",erro);
        }
}

void MainWindow::on_pushButton_PreOrdemD_clicked()
{
    try {
        QString saida;
        saida += "Exibindo Arvore em ordem a esquerda: ";
        listaArvore = teste->imprimirPreOrdemDireita();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_InOrdem_clicked()
{
    try {
        QString saida;

        saida += "Exibindo Arvore em ordem a esquerda: ";
        listaArvore = teste->imprimirEmOrdemEsquerda();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_EmOrdemD_clicked()
{
    try {
        QString saida;

        saida += "Exibindo Arvore em ordem a esquerda: ";
        listaArvore = teste->imprimirEmOrdemDireita();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_PosOrdem_clicked()
{
    try {
        QString saida;

        saida += "Exibindo Arvore em pos ordem a esquerda: ";
        listaArvore = teste->imprimirPosOrdemEsquerda();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_PosOrdemD_clicked()
{
    try {
        QString saida;

        saida += "Exibindo Arvore em ordem a esquerda: ";
        listaArvore = teste->imprimirPosOrdemDireita();

        int tamanho = listaArvore.getQuantidade();
        for (int i=0;i<tamanho;i++) {
            saida += "["+QString::number(listaArvore[i])+"]";
        }

        ui->textEdit_Arvore->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_clicked()
{
    try {
        QString saida;
        saida = "Profundidade: " + QString::number(teste->profundidade());
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
