TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LE:/ProgrammingStuff/C++/SFML/SFML-2.0/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += E:/ProgrammingStuff/C++/SFML/SFML-2.0/include
DEPENDPATH += E:/ProgrammingStuff/C++/SFML/SFML-2.0/include

HEADERS += battlefield.h
HEADERS += main_screen.h
HEADERS += menu.h
HEADERS += ship.h

SOURCES += main.cpp
SOURCES += battlefield.cpp
SOURCES += ship.cpp
