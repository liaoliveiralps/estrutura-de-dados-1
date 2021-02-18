#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "llde.h"
#include "aluno.h"
#include "curso.h"
#include "arquivo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonPedagogia_clicked();

    void on_pushButtonAdministracao_clicked();

    void on_pushButtonCienComputacao_clicked();

    void on_pushButtonEngComputacao_clicked();

    void on_pushButtonTodos_clicked();

private:
    Ui::MainWindow *ui;
    lula::LLDE<lula::Curso&> teste;
    void incluirAlunos();
};
#endif // MAINWINDOW_H
