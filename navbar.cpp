#include "navbar.h"
#include "const.h"

#include <QToolButton>
#include <QDebug>

#include <vector>



using namespace Const;

void NavBar::InitUi()
{




    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);  // 左 上 右 下


//    QToolButton *itemButton = new QToolButton(this);
//    itemButton->setIcon(QIcon(kLogoIconPath));
//    itemButton->setText(kProjectChName);
//    itemButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
//    m_mainLayout->addWidget(itemButton);


    // 导航栏
    m_topListWidget = new QListWidget(this);
    m_topListWidget->setSelectionMode(QAbstractItemView::SingleSelection); // 允许单选

    struct NavBarConfig {
        QString iconPath;
        QString ChName;
        QString EnName;
    };





    std::vector<NavBarConfig> listWidgtConfig {
     //   {kLogoIconPath, kProjectChName, kProjectEnName},
        {kMusciIconPath, kNavMusicChName, kNavMusicEnName},
        {kBookIconPath, kNavBookChName, kNavBookEnName},
        {kLiveIconPath, kNavLiveChName, kNavLiveEnName},
        {kFavortieIconPath, kNavFavoriteChName, kNavFavoriteEnName},
        {kDownLoadIconPath, kNavLocalDownloadChName, kNavLocalDownloadEnName},
      //  {":/resource/images/edit.svg", "载入样式", "load_qss"},
    };


    for (auto &config : listWidgtConfig) {

        auto item = new QListWidgetItem(QIcon(config.iconPath), config.ChName);

        m_topListWidget->addItem(item);
    }
    // m_topListWidget->setCurrentRow(2); // 默认选中第一项


    m_mainLayout->addWidget(m_topListWidget);
}

void NavBar::InitSignal()
{

    // 连接顶部列表的信号

    connect(m_topListWidget, &QListWidget::currentRowChanged, [this](int row){
        qDebug() << "row is" << row;
        emit CurrentRowChanged(row);  // 发射信号，通知主窗口切换页面
    });
    qDebug() << "navbar signal init ok!";


}

NavBar::NavBar(QWidget *parent) : QWidget(parent)
{
    InitUi();
    InitSignal();
}
