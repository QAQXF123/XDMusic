#include "playercontrol.h"
#include "const.h"

using namespace Const;

void PlayerControl::InitUi()
{
    m_mainLayout = new QHBoxLayout(this);

    m_songImgBtn = new QPushButton(this);
    m_songImgBtn->setIcon(QIcon(kDefaultSongImgPath));
    m_songImgBtn->setIconSize(QSize(80, 80));

    m_mainLayout->addWidget(m_songImgBtn);



    m_songInfoLayout = new QVBoxLayout();
    auto topLayout = new QHBoxLayout();
    auto botLayout = new QHBoxLayout();
    m_songNameLabel = new QLabel("kugou", this);
 //   m_singersListWidget = new QListWidget(this);
    topLayout->addWidget(m_songNameLabel);
  //  topLayout->addWidget(m_singersListWidget);
    m_songInfoLayout->addLayout(topLayout, 1);



    m_likeBtn = new QPushButton("like", this);
    m_downBtn = new QPushButton("down", this);
    m_commentBtn = new QPushButton("comment", this);

    botLayout->addWidget(m_likeBtn);
    botLayout->addWidget(m_downBtn);
    botLayout->addWidget(m_commentBtn);

    m_songInfoLayout->addLayout(botLayout, 1);

    m_mainLayout->addLayout(m_songInfoLayout);


    m_stopIcon = QIcon(kStopIconPath);
    m_playIcon = QIcon(kPlayIconPath);

    m_lastSongBtn = new QPushButton(this);
    m_lastSongBtn->setIcon(QIcon(kLastIconPath));
    m_lastSongBtn->setIconSize(QSize(35, 35));

    m_stopBtn = new QPushButton(this);
    m_stopBtn->setIcon(QIcon(kPlayIconPath));
    m_stopBtn->setIconSize(QSize(50, 50));

    m_nextSongBtn = new QPushButton(this);
    m_nextSongBtn->setIcon(QIcon(kNextIconPath));
    m_nextSongBtn->setIconSize(QSize(35, 35));

    m_playModeBtn = new QPushButton("playMode", this);
    m_SoundControl = new QPushButton("Sound", this);

    m_mainLayout->addStretch();

    m_mainLayout->addWidget(m_lastSongBtn);
    m_mainLayout->addWidget(m_stopBtn);
    m_mainLayout->addWidget(m_nextSongBtn);

    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_playModeBtn);
    m_mainLayout->addWidget(m_SoundControl);


}

void PlayerControl::InitSignal()
{
    connect(this->m_songImgBtn, &QPushButton::clicked, this, [this](){

    });

    connect(this->m_stopBtn, &QPushButton::clicked, this, [this](){
        if (m_isStop) {
            m_isStop = false;
            m_stopBtn->setIcon(m_stopIcon);
        } else {
            m_isStop = true;
            m_stopBtn->setIcon(m_playIcon);
        }
    });
}

PlayerControl::PlayerControl(QWidget *parent) : QWidget(parent)
{
    setObjectName("PlayerControl");
    InitUi();
    InitSignal();
}


