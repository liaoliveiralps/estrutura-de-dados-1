#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<arvore.h>
#include<QString>
#include <QMainWindow>
#include<QMessageBox>
#include<noarvore.h>
#include<QInputDialog>
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
    void on_pushButtonInserir_clicked();
    void on_pushButtonConsultar_clicked();
    void on_pushButtonAltura_clicked();
    void on_pushButtonPreesq_clicked();
    void on_pushButtonPredir_clicked();
    void on_pushButtonPosesq_clicked();
    void on_pushButtonPosdir_clicked();
    void on_pushButtoncentesq_clicked();
    void on_pushButtoncentdir_clicked();
private:
    Ui::MainWindow *ui;
    ed1::Arvore *teste;
    ed1::LDEC lista;
};
#endif // MAINWINDOW_H
