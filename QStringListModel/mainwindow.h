#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
    QStringListModel* model;
    
private slots:
    void on_btnListAppend_clicked();
    
    void on_btnInsert_clicked();
    
    void on_btnListDelete_clicked();
    
    void on_btnListClear_clicked();
    
    void on_btnTextImport_clicked();
    
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
