TEMPLATE = app
SOURCES = main.cpp
SOURCES += Game.cpp
LIBS = ../core/libcore.a
LIBS += -ldl -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
LIBS += -lSDL -lGL -lGLU -lSDL_image
TARGET = ../nibbler
