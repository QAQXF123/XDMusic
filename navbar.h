#ifndef NAVBAR_H
#define NAVBAR_H

#include <QWidget>
#include <QLabel>

#include <QVBoxLayout>
#include <QListWidget>
#include <QToolButton>
#include <QMainWindow>

class NavBar : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *m_mainLayout;
    QLabel *m_titleLabel;
    QToolButton *m_titleToolBtn;
    QListWidget *m_topListWidget;
    QListWidget *m_botListWidget;

    QMainWindow *m_mainWindows;

    void InitUi();
    void InitSignal();

    //member

    QVector<int> m_pageHistory;





public:
    NavBar(QWidget *parent = nullptr);


signals:
    // void WindowsSizeChange();  // 点击后发出信号，告诉主控件切换第几个页面
    void CurrentRowChanged(int index);


};

#endif // NAVBAR_H
