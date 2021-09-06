#include "ControlWindow.h"

namespace server{
ControlWindow::ControlWindow(int argc, char **argv, QWidget *parent)
    : QWidget(parent),
      m_RobotThread(argc, argv)
{
    /** Set up the GUI Tools **/
    setButtons();
    setWidgetsandLayouts();
    setConnections();

    m_RobotThread.init();
}//end constructor

void ControlWindow::setButtons(){
    /** Set up the Controls **/
    upButton = new QPushButton();
    downButton = new QPushButton();
    downLeftButton = new QPushButton();
    downRightButton = new QPushButton();
    leftButton = new QPushButton();
    rightButton = new QPushButton();
    upLeftButton = new QPushButton();
    upRightButton = new QPushButton();
    stopButton = new QPushButton(tr("Stop"));

    QPalette palette = rightButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    rightButton->setAutoFillBackground(true);
    rightButton->setFlat(true);
    rightButton->setPalette(palette);
    rightButton->setIcon(QIcon(":/images/right.png"));
    rightButton->setIconSize(QSize(50, 50));
    rightButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = leftButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    leftButton->setAutoFillBackground(true);
    leftButton->setFlat(true);
    leftButton->setPalette(palette);
    leftButton->setIcon(QIcon(":/images/left.png"));
    leftButton->setIconSize(QSize(50, 50));
    leftButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = upButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    upButton->setAutoFillBackground(true);
    upButton->setFlat(true);
    upButton->setPalette(palette);
    upButton->setIcon(QIcon(":/images/up.png"));
    upButton->setIconSize(QSize(50,50));
    upButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = upRightButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    upRightButton->setAutoFillBackground(true);
    upRightButton->setFlat(true);
    upRightButton->setPalette(palette);
    upRightButton->setIcon(QIcon(":/images/up_right.png"));
    upRightButton->setIconSize(QSize(65, 65));
    upRightButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = upLeftButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    upLeftButton->setAutoFillBackground(true);
    upLeftButton->setFlat(true);
    upLeftButton->setPalette(palette);
    upLeftButton->setIcon(QIcon(":/images/up_left.png"));
    upLeftButton->setIconSize(QSize(65, 65));
    upLeftButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = downButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    downButton->setAutoFillBackground(true);
    downButton->setFlat(true);
    downButton->setPalette(palette);
    downButton->setIcon(QIcon(":/images/down.jpg"));
    downButton->setIconSize(QSize(50, 50));
    downButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette = downLeftButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    downLeftButton->setAutoFillBackground(true);
    downLeftButton->setFlat(true);
    downLeftButton->setPalette(palette);
    downLeftButton->setIcon(QIcon(":/images/down_left.png"));
    downLeftButton->setIconSize(QSize(65, 65));
    downLeftButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    palette =  downRightButton->palette();
    palette.setColor(QPalette::Button,QColor(255,255,255));
    downRightButton->setAutoFillBackground(true);
    downRightButton->setFlat(true);
    downRightButton->setPalette(palette);
    downRightButton->setIcon(QIcon(":/images/down_right.png"));
    downRightButton->setIconSize(QSize(65, 65));
    downRightButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    downRightButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    stopButton->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
}

void ControlWindow::setWidgetsandLayouts(){

    linearSlider = new QSlider(Qt::Vertical);
    linearSlider ->setMaximum(10);
    linearSlider->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    angularSlider = new QSlider(Qt::Vertical);
    angularSlider -> setMaximum(10);
    angularSlider->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    linearLcd = new QLCDNumber(3);
    linearLcd->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    angularLcd = new QLCDNumber(3);
    angularLcd->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);

    leftLayout = new QVBoxLayout();
    p_xLayout = new QHBoxLayout();
    p_yLayout = new QHBoxLayout();
    p_aLayout = new QHBoxLayout();
    s_layout = new QHBoxLayout();

    p_xLabel = new QLabel();
    p_xLabel->setText(tr("X:"));
    p_xLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    p_xDisplay = new QLineEdit();
    p_xDisplay->setText(tr("0.0"));
    p_xDisplay->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    p_yLabel = new QLabel();
    p_yLabel->setText(tr("Y:"));
    p_yLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    p_yDisplay = new QLineEdit();
    p_yDisplay->setText(tr("0.0"));
    p_yDisplay->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    p_aLabel = new QLabel();
    p_aLabel->setText(tr("Theta: "));
    p_aLabel->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    p_aDisplay = new QLineEdit();
    p_aDisplay->setText(tr("0.0"));
    p_aDisplay->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Fixed);

    ls_label = new QLabel();
    ls_label->setText(tr("  Linear Speed(m/s)"));
    ls_label->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    as_label = new QLabel();
    as_label->setText(tr("  Angular Speed(m/s)"));
    as_label->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    p_xLayout->addWidget(p_xLabel);
    p_xLayout->addWidget(p_xDisplay);
    p_yLayout->addWidget(p_yLabel);
    p_yLayout->addWidget(p_yDisplay);
    p_aLayout->addWidget(p_aLabel);
    p_aLayout->addWidget(p_aDisplay);
    s_layout->addWidget(ls_label);
    s_layout->addWidget(as_label);

    leftLayout->addLayout(p_xLayout);
    leftLayout->addLayout(p_yLayout);
    leftLayout->addLayout(p_aLayout);

    /** Set up the Layouts **/
    rightLayout = new QVBoxLayout();
    layout = new QHBoxLayout();
    layout2 = new QHBoxLayout();
    layout3 = new QHBoxLayout();
    layout4 = new QHBoxLayout();
    layout5 = new QHBoxLayout();

    mainLayout = new QHBoxLayout();

    layout->addWidget(upLeftButton);
    layout->addWidget(upButton);
    layout->addWidget(upRightButton);
    layout2->addWidget(leftButton);
    layout2->addWidget(stopButton);
    layout2->addWidget(rightButton);
    layout3->addWidget(downLeftButton);
    layout3->addWidget(downButton);
    layout3->addWidget(downRightButton);
    layout4->addWidget(linearLcd);
    layout4->addWidget(angularLcd);
    layout5->addWidget(linearSlider);
    layout5->addWidget(angularSlider);
    
    rightLayout->addLayout(layout);
    rightLayout->addLayout(layout2);
    rightLayout->addLayout(layout3);
    rightLayout->addLayout(s_layout);
    rightLayout->addLayout(layout4);
    rightLayout->addLayout(layout5);
    
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
   
    setLayout(mainLayout);
    show();
    setWindowTitle(tr("Robot Manual Control"));
    setStyleSheet("background-color:white;");
}

void ControlWindow::setConnections(){
    connect(upButton,    &QPushButton::clicked, this, &ControlWindow::goForward);
    connect(upRightButton, &QPushButton::clicked, this, &ControlWindow::goForwardRight);
    connect(upLeftButton, &QPushButton::clicked, this, &ControlWindow::goForwardLeft);
    connect(leftButton,  &QPushButton::clicked, this, &ControlWindow::goLeft);
    connect(rightButton, &QPushButton::clicked, this, &ControlWindow::goRight);
    connect(downButton,  &QPushButton::clicked, this, &ControlWindow::goBackward);
    connect(downLeftButton, &QPushButton::clicked, this, &ControlWindow::goBackwardLeft);
    connect(downRightButton, &QPushButton::clicked, this, &ControlWindow::goBackwardRight);
    connect(stopButton,  &QPushButton::clicked, this, &ControlWindow::halt);
    connect(linearSlider, SIGNAL(valueChanged(int)),linearLcd, SLOT(display(int)));
    connect(linearSlider,SIGNAL(valueChanged(int)), SLOT(displaySlider()));
    connect(angularSlider, SIGNAL(valueChanged(int)),angularLcd, SLOT(display(int)));
    connect(angularSlider,SIGNAL(valueChanged(int)), SLOT(displaySlider()));
    connect(&m_RobotThread, &RobotThread::newPose, this, &ControlWindow::updatePoseDisplay);
}


void ControlWindow::displaySlider(){
    linearLcd->display(linearSlider->value()*0.1);
    angularLcd->display(angularSlider->value()*0.1);
}

void ControlWindow::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "ROS Manual Control",
                                                                tr("Are you sure?"),
                                                                QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);
    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }
}

void ControlWindow::goForward(){m_RobotThread.SetSpeed(linearSlider->value()*0.1, 0);}
void ControlWindow::goForwardRight(){m_RobotThread.SetSpeed(linearSlider->value()*0.1, -angularSlider->value()*0.1);}
void ControlWindow::goForwardLeft(){m_RobotThread.SetSpeed(linearSlider->value()*0.1, angularSlider->value()*0.1);}
void ControlWindow::goBackward(){m_RobotThread.SetSpeed(-(linearSlider->value()*0.1), 0);}
void ControlWindow::goBackwardLeft(){m_RobotThread.SetSpeed(-linearSlider->value()*0.1, -angularSlider->value()*0.1);}
void ControlWindow::goBackwardRight(){m_RobotThread.SetSpeed(-linearSlider->value()*0.1, angularSlider->value()*0.1);}
void ControlWindow::goRight(){m_RobotThread.SetSpeed(0, -angularSlider->value()*0.1);}
void ControlWindow::goLeft(){m_RobotThread.SetSpeed(0, angularSlider->value()*0.1);}
void ControlWindow::halt(){ m_RobotThread.SetSpeed(0, 0);}

void ControlWindow::updatePoseDisplay(double x, double y, double theta)
{
    QString xPose, yPose, aPose;
    xPose.setNum(x);
    yPose.setNum(y);
    aPose.setNum(theta);

    p_xDisplay->setText(xPose);
    p_yDisplay->setText(yPose);
    p_aDisplay->setText(aPose);
}//update the display.
}
