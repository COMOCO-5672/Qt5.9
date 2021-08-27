#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter    painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    int W = this->width();
    int H = this->height();
    QRect   rect(W/4,H/4,W/2,H/2);
    
    QPen    pen;
    pen.setWidth(3);    // 线宽
    pen.setColor(Qt::red);  //  划线颜色
    pen.setStyle(Qt::SolidLine);   // 线的样式
    pen.setCapStyle(Qt::RoundCap);    // 线端点的样式
    pen.setJoinStyle(Qt::BevelJoin);    // 线的连接点样式
    painter.setPen(pen);
    
    QBrush  brush;
    brush.setColor(Qt::yellow); // 画刷颜色
    brush.setStyle(Qt::SolidPattern); // 画刷填充样式
    painter.setBrush(brush);
    
    painter.drawRect(rect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

