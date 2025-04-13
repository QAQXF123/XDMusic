// windowdraghelper.cpp

#include "windowdraghelper.h"

WindowDragHelper::WindowDragHelper(QObject *parent) : QObject(parent) {}

void WindowDragHelper::AttachTo(QWidget *dragWidget, QMainWindow *mainWindow)
{
    if (!dragWidget || !mainWindow) return;

    m_dragWidgets.insert(dragWidget);
    dragWidget->installEventFilter(this);

    if (!m_mainWindow)
        m_mainWindow = mainWindow;
}

bool WindowDragHelper::eventFilter(QObject *watched, QEvent *event)
{
    if (!m_mainWindow || !m_dragWidgets.contains(qobject_cast<QWidget *>(watched))) {
        return QObject::eventFilter(watched, event);
    }

    auto mouseEvent = static_cast<QMouseEvent *>(event);

    switch (event->type()) {
    case QEvent::MouseButtonDblClick:
        // 🟦 双击左键最大化 / 还原
        if (mouseEvent->button() == Qt::LeftButton) {
            m_toolBar->WindowsSizeChange();
            return true;  // 已处理事件，防止传递
        }
        break;

    case QEvent::MouseButtonPress:
        if (mouseEvent->button() == Qt::LeftButton) {
            m_dragStartPos = mouseEvent->globalPos();
            m_dragging = true;
        }
        break;

    case QEvent::MouseMove:
        if (m_dragging && (mouseEvent->buttons() & Qt::LeftButton)) {
            if (m_mainWindow->isMaximized()) {
                if (m_toolBar) m_toolBar->WindowsSizeChange();  // 恢复大小
                m_dragStartPos = QCursor::pos();  // 重设拖动起点
            } else {
                QPoint delta = mouseEvent->globalPos() - m_dragStartPos;
                m_mainWindow->move(m_mainWindow->pos() + delta);
                m_dragStartPos = mouseEvent->globalPos();  // 更新起点
            }
        }
        break;

    case QEvent::MouseButtonRelease:
        m_dragging = false;
        break;

    default:
        break;
    }

    return QObject::eventFilter(watched, event);
}

//bool WindowDragHelper::eventFilter(QObject *watched, QEvent *event)
//{
//    if (!m_mainWindow || !m_dragWidgets.contains(qobject_cast<QWidget *>(watched))) {
//        return QObject::eventFilter(watched, event);
//    }

//    auto mouseEvent = static_cast<QMouseEvent *>(event);

//    switch (event->type()) {
//    case QEvent::MouseButtonPress:
//        if (mouseEvent->button() == Qt::LeftButton) {
//            m_dragStartPos = mouseEvent->globalPos();
//            m_dragging = true;
//        }
//        break;

//    case QEvent::MouseMove:
//        if (m_dragging && (mouseEvent->buttons() & Qt::LeftButton)) {

//          //  QPoint delta = mouseEvent->pos() - m_dragStartPos;

//            if (m_mainWindow->isMaximized()) {
//                m_toolBar->WindowsSizeChange();
//                m_dragStartPos = QCursor::pos();  // 用 QCursor::pos() 更安全
//            } else {
//                QPoint delta = mouseEvent->globalPos() - m_dragStartPos;
//                m_mainWindow->move(m_mainWindow->pos() + delta);
//                m_dragStartPos = mouseEvent->globalPos();  // 重要！更新拖动基准点
//            }


//        }
//        break;

//    case QEvent::MouseButtonRelease:
//        m_dragging = false;
//        break;

//    default:
//        break;
//    }

//    return QObject::eventFilter(watched, event);
//}
