/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *getGPA;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *GPA;
    QHBoxLayout *horizontalLayout;
    QPushButton *addCourse;
    QPushButton *removeCourse;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        getGPA = new QPushButton(centralwidget);
        getGPA->setObjectName(QString::fromUtf8("getGPA"));
        getGPA->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"min-height: 30px;\n"
"}"));

        verticalLayout->addWidget(getGPA);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        GPA = new QLineEdit(centralwidget);
        GPA->setObjectName(QString::fromUtf8("GPA"));
        GPA->setReadOnly(true);

        horizontalLayout_3->addWidget(GPA);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addCourse = new QPushButton(centralwidget);
        addCourse->setObjectName(QString::fromUtf8("addCourse"));
        addCourse->setMinimumSize(QSize(386, 32));
        addCourse->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"min-height: 30px;\n"
"}"));

        horizontalLayout->addWidget(addCourse);

        removeCourse = new QPushButton(centralwidget);
        removeCourse->setObjectName(QString::fromUtf8("removeCourse"));
        removeCourse->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"min-height: 30px;\n"
"}"));

        horizontalLayout->addWidget(removeCourse);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        getGPA->setText(QApplication::translate("MainWindow", "Calculate GPA", nullptr));
        label->setText(QApplication::translate("MainWindow", "GPA: ", nullptr));
        addCourse->setText(QApplication::translate("MainWindow", "Add Course", nullptr));
        removeCourse->setText(QApplication::translate("MainWindow", "Remove Course", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
