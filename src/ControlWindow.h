#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H
#include <QtWidgets>
#include <QPushButton>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextStream>
#include <QLineEdit>
#include <QPalette>
#include <QIcon>
#include <QSlider>
#include <QLCDNumber>
#include <QCloseEvent>
#include <string>
#include "RobotThread.h"

namespace server{

class ControlWindow : public QWidget
{
    Q_OBJECT

public:
    ControlWindow(int argc, char** argv, QWidget * parent = 0);
    Q_SLOT void updatePoseDisplay(double x, double y, double theta);
private:
    Q_SLOT void goForward();
    Q_SLOT void goForwardRight();
    Q_SLOT void goForwardLeft();
    Q_SLOT void goBackward();
    Q_SLOT void goBackwardLeft();
    Q_SLOT void goBackwardRight();
    Q_SLOT void goLeft();
    Q_SLOT void goRight();
    Q_SLOT void halt();
    Q_SLOT void displaySlider();

    void setButtons();
    void setWidgetsandLayouts();
    void setConnections();
    void closeEvent(QCloseEvent *);

    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *stopButton;
    QPushButton *upRightButton;
    QPushButton *upLeftButton;
    QPushButton *downLeftButton;
    QPushButton *downRightButton;
    
    QVBoxLayout *rightLayout;
    QHBoxLayout *layout;
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;
    QHBoxLayout *layout4;
    QHBoxLayout *layout5;
    QHBoxLayout *s_layout;

    QVBoxLayout *leftLayout;
    QHBoxLayout *p_xLayout;
    QHBoxLayout *p_yLayout;
    QHBoxLayout *p_aLayout;

    QLabel *p_xLabel;
    QLabel *p_yLabel;
    QLabel *p_aLabel;
    QLabel *p_scanLabel;
    QLabel *ls_label;
    QLabel *as_label;

    QLineEdit *p_xDisplay;
    QLineEdit *p_yDisplay;
    QLineEdit *p_aDisplay;

    QHBoxLayout *mainLayout;
    QPushButton *closeButton;

    QSlider *linearSlider;
    QSlider *angularSlider;

    QLCDNumber *linearLcd;
    QLCDNumber *angularLcd;

    RobotThread m_RobotThread;
};//end class ControlWindow
}//end namespace
#endif

