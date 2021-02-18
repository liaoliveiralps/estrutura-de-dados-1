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
        int tamanho = ui->lineEdit->text().toInt();
        teste = new lia::Ordenar(tamanho);
        QString saida = "Fila: ";
        saida += teste->getVetor();

        teste->arrumarVetor();
        saida += "\nFila ordenada: ";
        saida += teste->getVetor();
        ui->textEdit->setText(saida);
    }
    catch (std::bad_alloc) {
        QMessageBox::information(this,"Erro","Fila não criada.");
    }
    catch (QString& erro) {
        QMessageBox::information(this,"Erro",erro);
    }
}
