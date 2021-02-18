#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    incluirAlunos();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::incluirAlunos()
{
    try
    {
        dadosArquivo arquivo("ListaDeAlunosCurso.csv");
        QString saida("");
        QString auxCurso("");
        for (int j=0; j<arquivo.getTamanhoArquivo(); j++){
            lula::Aluno *novoAluno = new lula::Aluno
            (arquivo.getNomeAluno(j), arquivo.getCurso(j));
            lula::Curso *curso = new lula::Curso(lula::codigo(arquivo.getCurso(j)));
            if (teste.estaVazia()){
                teste.inserirInicio(*curso);
                curso->alunos.inserirOrdenado(*novoAluno);
                continue;
            }
            if (teste.ver(*curso)){
                teste[teste.consultar(*curso)].alunos.inserirOrdenado(*novoAluno);
                delete curso;
            }
            else{
                teste.inserirFim(*curso);
                curso->alunos.inserirOrdenado(*novoAluno);
            }
        }
        for (int i=0; i<teste.getQuantidade(); i++){
            for (int j=0; j<teste[i].alunos.getQuantidade(); j++){
                saida += QString::number(teste[i].getCursoAtual()) + " - "+ teste[i].alunos[j].getNome() + "\n";
                ui->tableWidgetSaida->insertRow(0);
            }
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonPedagogia_clicked()
{
    try {
        QString textoCurso = "Pedagogia";
        while (ui->tableWidgetSaida->rowCount() > 0)
            ui->tableWidgetSaida->removeRow(0);
        lula::Curso cursoAux(lula::pedagogia);
        int posicao=teste.consultar(cursoAux);
        for (int i=0; i<teste[posicao].alunos.getQuantidade(); i++)
            ui->tableWidgetSaida->insertRow(0);
        for (int i=0; i<teste[posicao].alunos.getQuantidade();i++){
            ui->tableWidgetSaida->setItem(i, 0, new QTableWidgetItem(textoCurso));
            ui->tableWidgetSaida->setItem(i, 1, new QTableWidgetItem(teste[posicao].alunos[i].getNome()));
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonAdministracao_clicked()
{
    try {
        QString textoCurso = "Administração";
        while (ui->tableWidgetSaida->rowCount() > 0)
            ui->tableWidgetSaida->removeRow(0);
        lula::Curso cursoAux(lula::administracao);
        int posicao=teste.consultar(cursoAux);
        for (int i=0; i<teste[posicao].alunos.getQuantidade(); i++)
            ui->tableWidgetSaida->insertRow(0);
        for (int i=0; i<teste[posicao].alunos.getQuantidade();i++){
            ui->tableWidgetSaida->setItem(i, 0, new QTableWidgetItem(textoCurso));
            ui->tableWidgetSaida->setItem(i, 1, new QTableWidgetItem(teste[posicao].alunos[i].getNome()));
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonCienComputacao_clicked()
{
    try {
        QString textoCurso = "Ciência da Computação";
        while (ui->tableWidgetSaida->rowCount() > 0)
            ui->tableWidgetSaida->removeRow(0);
        lula::Curso cursoAux(lula::cienciaDaComputacao);
        int posicao=teste.consultar(cursoAux);
        for (int i=0; i<teste[posicao].alunos.getQuantidade(); i++)
            ui->tableWidgetSaida->insertRow(0);
        for (int i=0; i<teste[posicao].alunos.getQuantidade();i++){
            ui->tableWidgetSaida->setItem(i, 0, new QTableWidgetItem(textoCurso));
            ui->tableWidgetSaida->setItem(i, 1, new QTableWidgetItem(teste[posicao].alunos[i].getNome()));
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonEngComputacao_clicked()
{
    try {
        QString textoCurso = "Engenharia da Computação";
        while (ui->tableWidgetSaida->rowCount() > 0)
            ui->tableWidgetSaida->removeRow(0);
        lula::Curso cursoAux(lula::engenhariaDaComputacao);
        int posicao=teste.consultar(cursoAux);
        for (int i=0; i<teste[posicao].alunos.getQuantidade(); i++)
            ui->tableWidgetSaida->insertRow(0);
        for (int i=0; i<teste[posicao].alunos.getQuantidade();i++){
            ui->tableWidgetSaida->setItem(i, 0, new QTableWidgetItem(textoCurso));
            ui->tableWidgetSaida->setItem(i, 1, new QTableWidgetItem(teste[posicao].alunos[i].getNome()));
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}

void MainWindow::on_pushButtonTodos_clicked()
{
    try
    {
        dadosArquivo arquivo("ListaDeAlunosCurso.csv");
        QString saida("");
        QString auxCurso("");
        for (int i=0; i<teste.getQuantidade(); i++){
            for (int j=0; j<teste[i].alunos.getQuantidade(); j++){
                saida += QString::number(teste[i].getCursoAtual()) + " - "+ teste[i].alunos[j].getNome() + "\n";
                ui->tableWidgetSaida->insertRow(0);
            }
        }
        for (int i=0, linha=0; i<teste.getQuantidade(); i++){
            for (int j=0; j<teste[i].alunos.getQuantidade(); j++, linha++){
                switch (teste[i].getCursoAtual()){
                    case lula::cienciaDaComputacao:
                        auxCurso = "Ciência da Computação";
                    break;
                    case lula::engenhariaDaComputacao:
                        auxCurso = "Engenharia da Computação";
                    break;
                    case lula::administracao:
                        auxCurso = "Administracao";
                    break;
                    case lula::pedagogia:
                        auxCurso = "Pedagogia";
                    break;
                }
                ui->tableWidgetSaida->setItem(linha, 0, new QTableWidgetItem(auxCurso));
                ui->tableWidgetSaida->setItem(linha, 1, new QTableWidgetItem(teste[i].alunos[j].getNome()));
            }
        }
    } catch (QString &erro){
        QMessageBox::information(this,"ERRO",erro);
    }
}
