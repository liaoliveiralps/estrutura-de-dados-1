#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<llde.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>
//Biblioteca para tratamento de arquivos
#include<fstream>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonEngenharia_clicked();

    void on_pushButtonCiencia_clicked();

    void on_pushButtonAdm_clicked();

    void on_pushButtonPedagogia_clicked();

    void on_pushButtonTodos_clicked();

    void on_pushButtonLimparCaixa_clicked();

private:
    Ui::MainWindow *ui;
    ed1::LLDE teste;

};

#endif // MAINWINDOW_H

