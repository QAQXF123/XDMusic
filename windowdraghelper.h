// windowdraghelper.h

#ifndef WINDOWDRAGHELPER_H
#define WINDOWDRAGHELPER_H

#include <QObject>
#include <QPointer>
#include <QSet>
#include <QMouseEvent>
#include <QMainWindow>

#include "toolbar.h"
class ToolBar;
class WindowDragHelper : public QObject
{
    Q_OBJECT
public:
    explicit WindowDragHelper(QObject *parent = nullptr);

    // 多次 attachTo 不会覆盖，支持多个控件
    void AttachTo(QWidget *dragWidget, QMainWindow *mainWindow);
    void BindToolBar(ToolBar *toolBar) {
        m_toolBar = toolBar;
    }

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QSet<QWidget*> m_dragWidgets;
    QPointer<QMainWindow> m_mainWindow;
    QPoint m_dragStartPos;
    bool m_dragging = false;
    ToolBar *m_toolBar;
};

#endif // WINDOWDRAGHELPER_H
