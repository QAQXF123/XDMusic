#include <QStyle>
#include <QIcon>
#include <QColorDialog>
#include <QDebug>
#include <QMainWindow>

#include "toolbar.h"
#include "const.h"



using namespace Const;

ToolBar::ToolBar(QWidget *parent) : QWidget(parent)
{
    setObjectName("ToolBar");
    InitUi();
    InitSignal();
}

void ToolBar::InitUi()
{
    m_mainLayout = new QHBoxLayout(this);

    m_revokeBtn = new QPushButton(this);
    m_revokeBtn->setIcon(QIcon(kRevokeIconPath));

    m_refreshBtn = new QPushButton(this);
    m_refreshBtn->setIcon(QIcon(kRefreshIconPath));

    m_searchLineEdit = new QLineEdit(this);




    m_userImg = new QLabel(this);
    m_userName = new QLabel("用户",this);


    m_maximizeIcon = QIcon(kMaximizeIconPath);
    m_normalizationIcon = QIcon(kNormalizationIconPath);

    m_minSizeBtn = new QPushButton(this);
    m_minSizeBtn->setIcon(QIcon(kMinimizeIconPath));

    m_sizeChangeBtn = new QPushButton(this);
    m_sizeChangeBtn->setIcon(m_maximizeIcon);

    m_closeBtn = new QPushButton(this);
    m_closeBtn->setIcon(QIcon(kCloseIconPath));

    m_mainLayout->addWidget(m_revokeBtn);
    m_mainLayout->addWidget(m_refreshBtn);
    m_mainLayout->addWidget(m_searchLineEdit);

    auto colorBtn = new QPushButton("color",this);
    connect(colorBtn, &QPushButton::clicked, this, [this](){
        QColor color = QColorDialog::getColor(Qt::white, this, "选择颜色");
            if (color.isValid()) {
                qDebug() << "Selected color:" << color.name();
                // 可选：直接应用颜色到按钮背景

            }
     });

    m_mainLayout->addWidget(colorBtn);




    m_mainLayout->addStretch();





    m_mainLayout->addWidget(m_userImg);
    m_mainLayout->addWidget(m_userName);

    m_mainLayout->addWidget(m_minSizeBtn);
    m_mainLayout->addWidget(m_sizeChangeBtn);
    m_mainLayout->addWidget(m_closeBtn);



}

void ToolBar::InitSignal()
{

    connect(this->m_revokeBtn, &QPushButton::clicked, this, [this](){
       emit LastPage();
    });

    connect(this->m_minSizeBtn, &QPushButton::clicked, this, [this](){
        emit Minimize();
    });
    connect(this->m_sizeChangeBtn, &QPushButton::clicked, this, &ToolBar::WindowsSizeChange);

    connect(this->m_closeBtn, &QPushButton::clicked, this, [this](){
        emit Close();
    });

}

// 鼠标按下：记录起始位置
void ToolBar::WindowsSizeChange()
{
    if (m_normalSize) {
        m_normalSize = false;
        m_sizeChangeBtn->setIcon(m_normalizationIcon);
    } else {
        m_normalSize = true;
        m_sizeChangeBtn->setIcon(m_maximizeIcon);
    }
    emit SizeChange();

}


