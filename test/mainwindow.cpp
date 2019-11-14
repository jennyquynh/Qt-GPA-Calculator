#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //*************************************************** INITIAL COURSE BOX **************************************************************


    // a box to hold all our elements in
    QGroupBox *courseGroup = new QGroupBox();


    // course name field
    QLabel *courseLabel = new QLabel(tr("Course: "));
    QLineEdit *courseName = new QLineEdit;
    courseName->setPlaceholderText("Enter course name");


    // credit hours drop down
    QLabel *hoursLabel = new QLabel(tr("Credit Hours: "));
    QComboBox *hoursComboBox = new QComboBox;
    hoursComboBox -> addItem(tr("1"));
    hoursComboBox -> addItem(tr("2"));
    hoursComboBox -> addItem(tr("3"));
    hoursComboBox -> addItem(tr("4"));
    hoursComboBox -> addItem(tr("5"));


    // grade drop down
    QLabel *gradeLabel = new QLabel(tr("Grade: "));
    QComboBox *gradeComboBox = new QComboBox;
    gradeComboBox -> addItem(tr("A"));
    gradeComboBox -> addItem(tr("B"));
    gradeComboBox -> addItem(tr("C"));
    gradeComboBox -> addItem(tr("D"));
    gradeComboBox -> addItem(tr("F"));


    // add the grade dropdown element to a QList that holds QComboBoxes
    grades << gradeComboBox;

    // add the hours dropdown element to a QList that holds QComboBoxes
    hours << hoursComboBox;


    // always points to the first valid row in the gridLayout
    // (when you delete a row from a gridLayout, it will get rid of the element, but
    // it won't get rid of the space where it once was. I.e. if I delete the first row - row 0,
    // it will still exist as an empty space, so that the "first row" that exists now is in row 1.
    // this variable used to keep track of that updated "first row")
    firstRow = 0;


    // formatting the group box to be horizontally layed out
    QGridLayout *courseLayout = new QGridLayout;
    courseLayout -> addWidget(courseLabel, 0, 0);
    courseLayout -> addWidget(courseName, 0, 1);
    courseLayout -> addWidget(hoursLabel, 0, 2);
    courseLayout -> addWidget(hoursComboBox, 0, 3);
    courseLayout -> addWidget(gradeLabel, 0, 4);
    courseLayout -> addWidget(gradeComboBox, 0, 5);
    courseGroup -> setLayout(courseLayout);

    // add the group box to the window
    ui -> gridLayout -> addWidget(courseGroup);





    //*************************************************** CONNECTING SLOTS **********************************************************

    // if the Add Course button is pressed, it will trigger the addCourse() slot that adds another course box
    connect(ui->addCourse, SIGNAL(clicked()), this, SLOT(addCourse()), Qt::UniqueConnection);

    // if the Calculate GPA button is pressed, it will trigger the getGPA() slot that computes the user's GPA
    connect(ui->getGPA, SIGNAL(clicked()), this, SLOT(getGPA()), Qt::UniqueConnection);

    connect(ui->removeCourse, SIGNAL(clicked()), this, SLOT(removeCourse()), Qt::UniqueConnection);
}




MainWindow::~MainWindow()
{
    delete ui;
}





//*************************************************** ADD A COURSE BOX **************************************************************
void MainWindow::addCourse()
{
    // get the number of rows in the gridLayout, whether they are "dead" or not
    int rowCount = ui -> gridLayout -> rowCount();

    // subtract the total number of rows by the number of "dead rows" (which is tracked by the firstRow variable)
    // in order to get the total number of valid rows. If this row more than 9, then we don't want to add anymore courses.
    if((rowCount - firstRow) < 9)
    {

        // a box to hold all our elements in
        QGroupBox *courseGroup = new QGroupBox();


        // course name field
        QLabel *courseLabel = new QLabel(tr("Course: "));
        QLineEdit *courseName = new QLineEdit;
        courseName->setPlaceholderText("Enter course name");


        // credit hours drop down
        QLabel *hoursLabel = new QLabel(tr("Credit Hours: "));
        QComboBox *hoursComboBox = new QComboBox;
        hoursComboBox -> addItem(tr("1"));
        hoursComboBox -> addItem(tr("2"));
        hoursComboBox -> addItem(tr("3"));
        hoursComboBox -> addItem(tr("4"));
        hoursComboBox -> addItem(tr("5"));


        // grade drop down
        QLabel *gradeLabel = new QLabel(tr("Grade: "));
        QComboBox *gradeComboBox = new QComboBox;
        gradeComboBox -> addItem(tr("A"));
        gradeComboBox -> addItem(tr("B"));
        gradeComboBox -> addItem(tr("C"));
        gradeComboBox -> addItem(tr("D"));
        gradeComboBox -> addItem(tr("F"));


        // add the grade dropdown element to a QList that holds QComboBoxes
        grades << gradeComboBox;

        // add the hours dropdown element to a QList that holds QComboBoxes
        hours << hoursComboBox;


        // formatting the group box to be horizontally layed out
        QGridLayout *courseLayout = new QGridLayout;
        courseLayout -> addWidget(courseLabel, 0, 0);
        courseLayout -> addWidget(courseName, 0, 1);
        courseLayout -> addWidget(hoursLabel, 0, 2);
        courseLayout -> addWidget(hoursComboBox, 0, 3);
        courseLayout -> addWidget(gradeLabel, 0, 4);
        courseLayout -> addWidget(gradeComboBox, 0, 5);
        courseGroup -> setLayout(courseLayout);


        // add the group box to the window
        ui -> gridLayout -> addWidget(courseGroup);

    }
}





//*************************************************** COMPUTE GPA **************************************************************
void MainWindow::getGPA()
{

    //----------------------------------------------- initialize --------------------------------------------

    // holds the string value of each course box's grade
    QList<QString> gradeCharArray;

    // holds the double value of each course box's grade
    vector<double> gradeArray;

    // holds the int value of each course box's credit hours
    vector<int> hoursArray;

    // holds the sum of all credit hours
    double totalHours = 0;

    // holds the result of each course's credit hours * grade value, summed together
    double totalGradePoints = 0;




    //----------------------------------------- set up grade vector ----------------------------------------

    // cycle through the list of grade ComboBoxes and add their string values to an array (WORKS)
    foreach( QComboBox* grade, grades )  {
        gradeCharArray << grade -> currentText();
    }

    // cycle through the array of grade string values and convert them to their associated double values, adding them to an array (WORKS)
    foreach( QString grade, gradeCharArray)
    {
        if(QString::compare(grade, "A", Qt::CaseInsensitive) == 0)
            gradeArray.push_back(4.0);
        else if(QString::compare(grade, "B", Qt::CaseInsensitive) == 0)
            gradeArray.push_back(3.0);
        else if(QString::compare(grade, "C", Qt::CaseInsensitive) == 0)
            gradeArray.push_back(2.0);
        else if(QString::compare(grade, "D", Qt::CaseInsensitive) == 0)
            gradeArray.push_back(1.0);
        else
            gradeArray.push_back(0.0);
    }



    //----------------------------------------- set up hours vector ---------------------------------------

    // cycle through the list of hour ComboBoxes and add their int values to an array (WORKS)
    foreach( QComboBox* hour, hours )  {
        hoursArray.push_back(hour -> currentText().toInt());
    }



    //------------------------------------------- sum all credit hours -------------------------------------

    // sums all the credit hours together (WORKS)
    foreach( int hour, hoursArray )  {
        totalHours += hour;
    }



    //--------------------- multiply values in each vector (get total grade points) ------------------------


    for(int i = 0; i < gradeArray.size(); i++)
    {
        totalGradePoints += gradeArray[i] * hoursArray[i];
    }



    //--------------------------------- compute GPA and output to the screen -------------------------------

    ui -> GPA -> setText(QString::number( totalGradePoints/totalHours ));
}





//*************************************************** REMOVE COURSE **************************************************************
void MainWindow:: removeCourse()
{

    // get the number of rows in the gridLayout, whether they are "dead" or not
    int rowCount = ui -> gridLayout -> rowCount();



    // subtract the total number of rows by the number of "dead rows" (which is tracked by the firstRow variable)
    // in order to get the total number of valid rows. If this row is 1, then we don't want to delete anymore courses.
    if((rowCount - firstRow) > 1)
    {
        // get the first valid row
        QLayoutItem* item = ui -> gridLayout -> itemAtPosition( firstRow, 0 );

        // get the item from that row
        QWidget* itemWidget = item->widget();

        // if that item exits
        if( itemWidget )
        {
            // remove the item
            ui -> gridLayout -> removeWidget(itemWidget);

            // delete the widget
            delete itemWidget;

            // update the first valid row (and number of dead rows)
            firstRow++;
        }
    }
}
