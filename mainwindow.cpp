#include <QDebug>

#include "mainwindow.h"
#include "const.h"
#include "common.h"

using namespace Const;
using namespace Common;

void MainWindow::LoadStyleSheet(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        setStyleSheet(stream.readAll());
        qDebug() << "set style ok";
        qDebug() << styleSheet();
    } else {
        qWarning() << "Failed to open stylesheet file.";
    }
}

void MainWindow::InitUi()
{

    LoadStyleSheet(kQssPath);

    setWindowFlags(Qt::FramelessWindowHint);  // 无边框窗口
   // setWindowFlags(Qt::Window);

    qDebug() << "init ui begin";

    setMinimumSize(1200, 800);

    QWidget *centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);

    m_mainLayout = new QVBoxLayout(centralWidget);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);  // 去除边距
    m_mainLayout->setSpacing(0);                   // 控件间距为 0

    m_topLayout = new QHBoxLayout();
    m_navBar = new NavBar(this);
    m_navBar->setMinimumWidth(200);  // 最小宽度（固定值）
    m_navBar->setMaximumWidth(200);  // 最大宽度（固定值）


    // 左上角导航栏添加 1 : 4
    m_topLayout->addWidget(m_navBar, 1);


    // 右上角的内容
    auto rightTopLayout = new QVBoxLayout();



    m_toolBar = new ToolBar(this);
    m_toolBar->SetMainWindow(this);


    rightTopLayout->addWidget(m_toolBar, 1);



    m_mainContent = new QStackedWidget(this);
    // 添加示例页面
    for(int i = 0; i < 6; i++) {
        QLabel *page = new QLabel(QString("这是第 %1 个页面").arg(i+1), m_mainContent);
        page->setAlignment(Qt::AlignCenter);
        m_mainContent->addWidget(page);
    }
    rightTopLayout->addWidget(m_mainContent, 7);

    // 右上角导航栏添加 1 : 4
    m_topLayout->addLayout(rightTopLayout, 4);





    m_mainLayout->addLayout(m_topLayout, 7);


    // 下方的播放控制器
    m_playerControl = new PlayerControl(this);
    m_playerControl->setMaximumHeight(100);
     m_playerControl->setMinimumHeight(100);
    m_mainLayout->addWidget(m_playerControl, 1);


    qDebug() << "init ui end";


    // 拖动实现

    WindowDragHelper *dragHelper = new WindowDragHelper(this);
    dragHelper->BindToolBar(m_toolBar);
    dragHelper->AttachTo(m_toolBar, this);
    dragHelper->AttachTo(m_playerControl, this);




}

void MainWindow::InitSignal()
{
    // connect(m_navBar, &NavBar::WindowsSizeChange, this, &MainWindow::WindowsSizeChange);
   // connect(m_navBar, &NavBar::WindowsSizeChange, this, &MainWindow::WindowsSizeChange);
    // 连接导航栏的信号
    connect(m_navBar, &NavBar::CurrentRowChanged,
            m_mainContent, [this](int index){
            m_pageHistory.push_back(index);
            m_mainContent->setCurrentIndex(index);
    });

    connect(m_toolBar, &ToolBar::LastPage, this, [this](){
        m_pageHistory.pop_back();
        m_mainContent->setCurrentIndex(m_pageHistory.back());
    });

    connect(m_toolBar, &ToolBar::Minimize, this, &QMainWindow::showMinimized);
    connect(m_toolBar, &ToolBar::SizeChange, this, &MainWindow::WindowsSizeChange);
    connect(m_toolBar, &ToolBar::Close, this, &QMainWindow::close);



}

void MainWindow::WindowsSizeChange()
{
    if (this->isMaximized()) {
        this->showNormal();
    } else {
        this->showMaximized();
    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


   InitUi();

   InitSignal();

}


MainWindow::~MainWindow()
{
}

