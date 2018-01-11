//
// Created by nicolas on 11/01/18.
//

#ifndef TOURNAMENTBRACKETGENERATOR_QTWINDOWTRY_H
#define TOURNAMENTBRACKETGENERATOR_QTWINDOWTRY_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class QPushButton;

class QTWindowTry : public QWidget
{
//Q_OBJECT
public:
    explicit QTWindowTry(QWidget *parent = 0);

//private slots:
//    void slotButtonClicked(bool checked);

private:
    QPushButton *m_button;
    QPushButton *m_quit_button;
};


#endif //TOURNAMENTBRACKETGENERATOR_QTWINDOWTRY_H
