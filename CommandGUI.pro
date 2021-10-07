QT       += core widgets
TARGET = CommandGUI
TEMPLATE = app 
SOURCES += main.cpp mainwindow.cpp commandclass.cpp  
HEADERS += mainwindow.h commandclass.h
LIBS += -lboost_thread -lpthread
