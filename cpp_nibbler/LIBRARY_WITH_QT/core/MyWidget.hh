//
// Widget.hh for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:48:39 2015 Nicolas Charvoz
// Last update Sun Apr  5 12:52:05 2015 Nicolas Charvoz
//

#ifndef MYWIDGET_HH_
# define MYWIDGET_HH_

#include <QObject>
#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLineEdit>
#include <QTextStream>
#include <QLabel>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class MyWidget : public QWidget {
Q_OBJECT
public:
  MyWidget(int score = 0, QWidget *parent = 0);

public slots:
  void getTextFromBox();

private:
  QLineEdit *_loginArea;
  QString _content;
  std::string _login;
  int _score;
};

#endif
