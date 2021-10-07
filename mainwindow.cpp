/**
 * Misha Butt
 * Main Window Class for GUI
 * October 6 2021
 * **/

#include "mainwindow.h"

/**
 * MainWindow constructor
 * Sets up user interface
 * gets a pointer to QWidget as parameter
 * no return type
 * **/
MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
{
  myWidget = new QWidget;

  //setting up graphical user interface
  myWidget->setWindowTitle("CommandGUI");

  myLayout = new QGridLayout;

  myLabel = new QLabel("Command:");
  myText = new QLineEdit("");
  myButton = new QPushButton("Execute");
  myLabel2 = new QLabel("Output");
  myLabel3 = new QLabel("Exit status:");
  myLabel4 = new QLabel("History:");
  myLabel5 = new QLabel("");

  myDisplay = new QPlainTextEdit();
  myDisplay->isReadOnly();
 
  myList = new QListWidget();

  //widgets are added and positioned
  myLayout->addWidget(myLabel, 0, 1);
  myLayout->addWidget(myText, 0, 2);
  myLayout->addWidget(myButton, 0, 3);
  myLayout->addWidget(myLabel2, 1, 1);
  myLayout->addWidget(myDisplay, 2,1,1,3);
  myLayout->addWidget(myLabel3, 3, 1); 
  myLayout->addWidget(myLabel5, 3, 2);
  myLayout->addWidget(myLabel4, 4, 1);
  myLayout->addWidget(myList, 5, 1, 1, 3);

  myWidget->setLayout(myLayout);

  myWidget->show();

  //if the user pushes the button then handleInput() is triggered
  connect(myButton, &QPushButton::released, this, &MainWindow::handleInput);

  //if the user clicks on an item in the list handleHistory() is triggered
  connect(myList, &QListWidget::currentItemChanged, this, &MainWindow::handleHistory);
}


 /**
  * handleInput() function
  * displays output of command entered by user after they push the execute button
  * No parameter or return 
  * **/
  void MainWindow::handleInput()
{
  //converting user input to string
  userInput = myText->text();
  input = userInput.toUtf8().constData();
 
  //command class object is created which is then converted to QString and displayed
  commandclass *commandObj = new commandclass(input);
  commandObj->execute();
  vectorOutput.push_back(*commandObj);
  QString qstr = QString::fromStdString(commandObj->getResult());
  myDisplay->setPlainText(qstr);
  
  //exit status is displayed
  QString num = QString::number(commandObj->getCode());
  myLabel5->setText(num);

  //appropriate output is displayed in the history box
  int numb = vectorOutput.size();
  string res = vectorOutput[vectorOutput.size()-1].getUnexecutedInput();
  QString qnum = QString::number(numb);
  QString q = QString::fromStdString(res);
  myList->addItem(qnum + ". " + q + " (" + num + ")"); 
}

  /**
   * handleHistory() function
   * displays the command selected by user in the history box
   * no parameter or return type
   * **/
  void MainWindow::handleHistory()
{
  //command which was clicked is displaued
  QString commandClicked = myList->currentItem()->text();
  QString index = commandClicked.at(0);
  int numindex = index.toInt();
  QString qres = QString::fromStdString(vectorOutput[numindex-1].getResult());
  myDisplay->setPlainText(qres);
  myLabel5->setText(QString::number(vectorOutput[numindex-1].getCode()));  

}


