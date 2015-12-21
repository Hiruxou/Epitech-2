//
// MyWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Fri Apr 24 20:03:40 2015 Nicolas Charvoz
//

#include "MyWidget.hh"

MyWidget::MyWidget(float timeMul, int cooksPerKitchen,
		   int timeReplace, Reception *r, QWidget *parent)
  : QWidget(parent), _timeMul(timeMul), _cooksPerKitchen(cooksPerKitchen),
    _timeReplace(timeReplace), _r(r)
{
  setFixedSize(800, 600);

  _command = new QTextEdit(tr(""), this);
  _command->setGeometry(15, 15, 770, 500);
  _command->setFont(QFont("Calibri", 14, 0));

  QPushButton *order = new QPushButton(tr("Order"), this);
  order->setGeometry(15, 530, 770, 60);
  order->setFont(QFont("Calibri", 18, QFont::Normal));

  connect(order, SIGNAL(clicked()), this, SLOT(getOrder()));
}

void MyWidget::getOrder()
{
  MainClass *main;

  _content = _command->toPlainText();
  _command->clear();
  _contentString = _content.toUtf8().constData();
  main = new MainClass(_timeMul, _cooksPerKitchen,
		       _timeReplace, _contentString, _r);
  main->main();
}
