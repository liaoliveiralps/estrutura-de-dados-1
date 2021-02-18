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

void MainWindow::on_pushButtonCriar_clicked()
{
    try
    {
        int aux = ui->lineEditTamanho->text().toInt();
        pilha = new lia::Ordenar(aux);
        QString saida;
        pilha->vetorDesordenado();
        saida = "Pilha: " + pilha->getVetor() + "\n";
        pilha->arrumar();
        saida += "Pilha ordenada: " + pilha->getVetor();
        ui->textEditCriar->setText(saida);
    }
    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
    }
}
