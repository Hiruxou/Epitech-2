//
// MyWidget.cpp for  in /home/nicolaschr/TP/qt
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Apr  4 20:51:15 2015 Nicolas Charvoz
// Last update Sun Apr  5 12:57:23 2015 Nicolas Charvoz
//

#include "MyWidget.hh"

MyWidget::MyWidget(int score, QWidget *parent) : QWidget(parent), _score(score)
{
  std::stringstream ss;
  QString Qstr;

  setFixedSize(640, 480);

  ss << "Score : " << _score;
  Qstr = QString::fromStdString(ss.str());

  QLabel *scoreLabel = new QLabel(Qstr, this);
  scoreLabel->setGeometry(250, 130, 320, 60);
  scoreLabel->setFont(QFont("Times", 18, QFont::Bold));

  _loginArea = new QLineEdit(tr(""), this);
  _loginArea->setGeometry(160, 190, 320, 60);
  _loginArea->setFont(QFont("Times", 18, QFont::Bold));


  QPushButton *save = new QPushButton(tr("Save"), this);
  save->setGeometry(160, 270, 320, 60);
  save->setFont(QFont("Times", 18, QFont::Bold));

  QPushButton *quit = new QPushButton(tr("Quit"), this);
  quit->setGeometry(160, 330, 320, 60);
  quit->setFont(QFont("Times", 18, QFont::Bold));

  connect(save, SIGNAL(clicked()), this, SLOT(getTextFromBox()));
  connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
}

void MyWidget::getTextFromBox()
{
  std::fstream myFile;

  myFile.open("score.txt", std::ios::app | std::ios::out);
  _content = _loginArea->text();
  _login = _content.toUtf8().constData();
  myFile << "Login : " << _login << " | Score : "
	 << _score << std::endl;
  myFile.close();
  exit(0);
}
