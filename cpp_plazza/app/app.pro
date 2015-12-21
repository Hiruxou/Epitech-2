TEMPLATE = app
QMAKE_CXX = g++-4.9
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -std=c++11
QT+=widgets
SOURCES = main.cpp
SOURCES += Plazza.cpp
SOURCES += Interface.cpp
SOURCES += Parser.cpp
SOURCES += CheckArgs.cpp
SOURCES += MainClass.cpp
SOURCES += Cook.cpp
SOURCES += Kitchen.cpp
SOURCES += Reception.cpp
SOURCES += PipeClass.cpp
SOURCES += ./pizza/Margarita.cpp
SOURCES += ./pizza/Regina.cpp
SOURCES += ./pizza/Americaine.cpp
SOURCES += ./pizza/Fantasia.cpp
SOURCES += ./pizza/PizzaGenerator.cpp

SOURCES += ./ingredient/Doe.cpp
SOURCES += ./ingredient/Tomato.cpp
SOURCES += ./ingredient/Gruyere.cpp
SOURCES += ./ingredient/Ham.cpp
SOURCES += ./ingredient/Mushrooms.cpp
SOURCES += ./ingredient/Steak.cpp
SOURCES += ./ingredient/Eggplant.cpp
SOURCES += ./ingredient/Goatcheese.cpp
SOURCES += ./ingredient/Chieflove.cpp

LIBS = ../core/libcore.a
TARGET = ../plazza
