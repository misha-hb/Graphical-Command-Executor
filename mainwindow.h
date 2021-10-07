/**
 * Misha Butt
 * Header file for MainWindow
 * October 6 2021
 * **/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commandclass.h"
#include <vector>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QWidget>
#include <QListWidget>
#include <QPlainTextEdit>
#include <string>


namespace Ui {
  class MainWindow;
}
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = nullptr);
private slots:
  void handleInput();
  void handleHistory();
public:
  std::string input;
private:
  vector<commandclass> vectorOutput;
private:
  QString userInput;
private:
  QPushButton *myButton;
private:
  QLabel *myLabel;
private:
  QLabel *myLabel2;
private:
  QLabel *myLabel3;
private:
  QLabel *myLabel4;
private:
  QLabel *myLabel5;
private:
  QPlainTextEdit *myDisplay;
private:
  QListWidget *myList;
private:
  QGridLayout *myLayout;
private:
  QLineEdit *myText;
 private:
  QWidget *myWidget;
};
#endif // MAINWINDOW_H
