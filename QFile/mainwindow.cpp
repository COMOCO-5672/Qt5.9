#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString curPath = QDir::currentPath();
    QString dlgTitle = "1111" ;
    QString filter = "程序文件(*.cpp *.h);;文本文件(*.txt);;所有文件(*.*)";
    QString aFileName = QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    if(aFileName.isEmpty())
        return;
    OpenTextByIODevice(aFileName);
}

bool MainWindow::OpenTextByIODevice(const QString &aFileName)
{
    QFile   aFile(aFileName);
    if(!aFile.exists())
        return false;
    if(!aFile.open(QIODevice::ReadOnly|QIODevice::Text))
        return false;
    ui->textEditDevice->setPlainText(aFile.readAll());
    aFile.close();
}

