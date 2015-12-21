TEMPLATE = lib
CONFIG += staticlib
CONFIG += qt
QT+=widgets
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -std=c++11
HEADERS = MyWidget.hh
SOURCES = MyWidget.cpp
