#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QGroupBox>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // holds a list of all grade comboBoxes
    QList< QComboBox* > grades;

    // holds a list of all hours comboBoxes
    QList< QComboBox* > hours;

    //points to the first valid row in the gridLayout
    int firstRow;

private:
    Ui::MainWindow *ui;

public slots:

    // adds another course box group
    void addCourse();

    // computes the gpa
    void getGPA();

    // removes the top course box group
    void removeCourse();
};
#endif // MAINWINDOW_H
