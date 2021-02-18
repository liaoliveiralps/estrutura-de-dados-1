#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ordenar.h>
#include <pilha.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonCriar_clicked();

private:
    Ui::MainWindow *ui;
    lia::Ordenar *pilha;
};

#endif // MAINWINDOW_H
