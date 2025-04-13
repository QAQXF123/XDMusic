#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QPoint>
#include <QMouseEvent>

#include "navbar.h"
#include "toolbar.h"
#include "playercontrol.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:


    // ui
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_topLayout;
    QStackedWidget *m_mainContent;

    NavBar *m_navBar;
    ToolBar *m_toolBar;
    PlayerControl *m_playerControl;







    void LoadStyleSheet(const QString &filePath);
    void InitUi();
    void InitSignal();




private slots:  // 可选的 slots 修饰（Qt5/6 都可以）
    void WindowsSizeChange();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
