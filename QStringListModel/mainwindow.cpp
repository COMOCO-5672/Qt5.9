#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QStringList     theStrList;
    theStrList<<"北京"<<"上海"<<"天津"<<"河北"<<"山东"<<"四川"<<"重庆";
    model=new QStringListModel(this);
    model->setStringList(theStrList);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|
                                  QAbstractItemView::SelectedClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnListAppend_clicked()
{
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount()-1,0);
    model->setData(index,"new item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

void MainWindow::on_btnInsert_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->insertRow(index.row());
    model->setData(index,"inserted item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);
}

void MainWindow::on_btnListDelete_clicked()
{
    QModelIndex index = ui->listView->currentIndex();
    model->removeRow(index.row());
}

void MainWindow::on_btnListClear_clicked()
{
    model->removeRows(0,model->rowCount());
}

void MainWindow::on_btnTextImport_clicked()
{
    QStringList tmpList=model->stringList();
    ui->plainTextEdit->clear();
    for (int i=0;i<tmpList.count() ;i++ ) {
        ui->plainTextEdit->appendPlainText(tmpList.at(i));
    }
}
