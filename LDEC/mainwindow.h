#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include <ldec.h>
#include <QInputDialog>

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
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

private:
    Ui::MainWindow *ui;
    lia::LDEC teste;
};
#endif // MAINWINDOW_H
