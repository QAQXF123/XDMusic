#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H


#include <QWidget>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QIcon>

class PlayerControl : public QWidget
{
private:

    // ui
    QHBoxLayout *m_mainLayout;

    QPushButton *m_songImgBtn;

    QVBoxLayout *m_songInfoLayout;
    QLabel *m_songNameLabel;
    QListWidget *m_singersListWidget;

    QPushButton *m_likeBtn;
    QPushButton *m_downBtn;
    QPushButton *m_commentBtn;

    QPushButton *m_lastSongBtn;
    QPushButton *m_stopBtn;
    QPushButton *m_nextSongBtn;

    QPushButton *m_playModeBtn;
    QPushButton *m_SoundControl;


    // member
    QIcon m_stopIcon;
    QIcon m_playIcon;

    bool m_isStop{true};



    void InitUi();
    void InitSignal();


public:
    PlayerControl(QWidget* parent = nullptr);
};

#endif // PLAYERCONTROL_H
