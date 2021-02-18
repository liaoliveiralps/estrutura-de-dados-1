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

void MainWindow::on_pushButtonAbrirArquivo_clicked()
{
    try {
        QString nomeDoArquivo = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt)");
        if(nomeDoArquivo.isEmpty()) throw QString("Arquivo nao foi selecionado");

        arquivo.open(nomeDoArquivo.toStdString().c_str());

        if(!arquivo.is_open()){
            throw QString("ERRO Arquivo nao pode ser aberto");
        }

        std::string linha;

        getline(arquivo,linha);

           while(!arquivo.eof()){
              teste.inserirOrdenado(QString::fromStdString(linha));

              getline(arquivo,linha);
           }
        QString saida;
        for(int a=0;a<teste.getQuantidade();a++)
        {
            saida+=teste[a]+"\n";
        }
        ui->textEditSaida->setText(saida);

    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
void MainWindow::on_pushButtonLimparCaixa_clicked()
{
    ui->textEditSaida->clear();
}

void MainWindow::on_pushButton_clicked()
{
    try {
        QString saida;
        for(int i=0;i<teste.getQuantidade();i++)
        {
            saida+=teste[i]+"\n";
        }
        ui->textEditSaida->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    try {
        QString saida;
        for(int i=teste.getQuantidade()-1;i>=0;i--)
        {
            saida+=teste[i]+"\n";
        }
        ui->textEditSaida->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}
