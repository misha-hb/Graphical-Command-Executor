/**
 * Misha Butt
 * Main function
 * October 6 2021
 * **/

#include "mainwindow.h"
#include <QApplication>
 
int main(int argc, char *argv[]) 
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  return app.exec();
}
