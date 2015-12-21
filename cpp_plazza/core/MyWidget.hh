//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Fri Apr 24 12:17:36 2015 Nicolas Charvoz
//

#ifndef MYWIDGET_HH_
# define MYWIDGET_HH_

#include <QApplication>
#include <QObject>
#include <QFont>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QTextStream>
#include <QLabel>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "../app/MainClass.hh"
#include "../app/Reception.hpp"

class MyWidget : public QWidget {
Q_OBJECT
public:
  MyWidget(float, int, int, Reception*, QWidget *parent = 0);

public slots:
  void getOrder();
private:
  float _timeMul;
  int _cooksPerKitchen;
  int _timeReplace;
  QTextEdit *_command;
  QString _content;
  std::string _contentString;
  Reception *_r;
};

#endif
