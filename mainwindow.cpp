#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QDebug>
const QString imagesPath = ":/images";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mySearch = NULL;
    toolBar = new QToolBar(this);
    this->setContextMenuPolicy(Qt::NoContextMenu);
    QAction* searchAction = new QAction(QIcon(imagesPath + "/search.png"),tr("查询单词"),this);
    QAction* userAction = new QAction(QIcon(imagesPath + "/user.png"),tr("用户管理"),this);
    toolBar->addAction(searchAction);
    toolBar->addAction(userAction);
    this->addToolBar(Qt::TopToolBarArea,toolBar);
    
    connect(searchAction,SIGNAL(triggered(bool)),this,SLOT(searchWord()));
    connect(userAction,SIGNAL(triggered(bool)),this,SLOT(userInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearUI()
{
    if(mySearch != 0)
    { 
        delete mySearch;
        mySearch = 0;
    }
}

QTcpSocket* MainWindow::getSocket()
{
     return socket;
}

void MainWindow::searchWord()
{
    qDebug() << "hh";
    clearUI();
    mySearch = new search(0,this);
}

void MainWindow::userInfo()
{
    clearUI();
}
