#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <arvorebinaria1.h>
#include <QMessageBox>

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
    void on_pushButton_InserirElemento_clicked();

    void on_pushButton_PreOrdem_clicked();

    void on_pushButton_PreOrdemD_clicked();

    void on_pushButton_InOrdem_clicked();

    void on_pushButton_EmOrdemD_clicked();

    void on_pushButton_PosOrdem_clicked();

    void on_pushButton_PosOrdemD_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    lia::ArvoreBinaria1<int> *teste;
    lia::LLDE<int> listaArvore;
};
#endif // MAINWINDOW_H
