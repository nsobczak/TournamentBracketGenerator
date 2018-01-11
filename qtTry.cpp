//
// Created by nicolas on 11/01/18.
//

#include "qtTry.h"


/**
 * \fn
 * \brief
 */
void qtTry::tryQT(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget window;
//    window.setFixedSize(300, 150);


    QPushButton *button = new QPushButton("Hello World", &window);
    button->setGeometry(100, 20, 120, 30);
    button->setToolTip("A tooltip");

    window.show();
//    QFont font("Courier");
//    button.setFont(font);
//    button.setText("My text");
//    button.show();

    app.exec();
}

