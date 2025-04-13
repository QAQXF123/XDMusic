#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>  // 添加鼠标事件支持
#include <QMainWindow>


#include "windowdraghelper.h"
class ToolBar : public QWidget
{
    Q_OBJECT
private:

    // ui
    QHBoxLayout *m_mainLayout;
    QPushButton *m_revokeBtn;
    QPushButton *m_refreshBtn;
    QLineEdit *m_searchLineEdit;
    QLabel *m_userImg;
    QLabel *m_userName;

    QPushButton *m_minSizeBtn;
    QPushButton *m_sizeChangeBtn;
    QPushButton *m_closeBtn;

    QIcon m_normalizationIcon;
    QIcon m_maximizeIcon;



    // member

    QMainWindow *m_mainWindows;

    bool m_normalSize{true};











//protected:
//    void mousePressEvent(QMouseEvent *event) override;  // 鼠标按下
//    void mouseMoveEvent(QMouseEvent *event) override;   // 鼠标移动
//    void mouseReleaseEvent(QMouseEvent *event) override; // 鼠标释放

    // bool m_isNormalSize{true};
public:
    ToolBar(QWidget *parent);
    void InitUi();
    void InitSignal();
    void SetMainWindow(QMainWindow *mainWindows) {
        m_mainWindows = mainWindows;
    }
    void WindowsSizeChange();
signals:


    void LastPage();

    void SizeChange();
    void Minimize();
    void Close();

};

#endif // TOOLBAR_H
