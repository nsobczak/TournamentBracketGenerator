//
// Created by nicolas on 11/01/18.
//

#include "QTWindowTry.h"

QTWindowTry::QTWindowTry(QWidget *parent) :
        QWidget(parent)
{// Set size of the window
    setFixedSize(200, 500);

    // Create and position buttons
//    m_button->setCheckable(true);
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 100, 30);
//    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));

    m_quit_button = new QPushButton("Quit", this);
    m_quit_button->setGeometry(10, 40, 80, 30);
    connect(m_quit_button, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
}

//
//void QTWindowTry::slotButtonClicked(bool checked)
//{
//    if (checked)
//        m_button->setText("Checked");
//    else
//        m_button->setText("Hello World");
//}
