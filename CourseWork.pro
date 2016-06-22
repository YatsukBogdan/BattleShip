TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -LD:/SFML-2.3.1/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:/SFML-2.3.1/include
DEPENDPATH += D:/SFML-2.3.1/include

HEADERS += battlefield.h \
    button.h \
    screen.h \
    current_screen.h \
    exit_screen.h \
    screen_cache.h \
    play_screen.h \
    options_screen.h \
    game_vs_computer_screen.h \
    game_gui.h \
    your_field.h \
    enemy_field.h \
    field.h \
    ship.h \
    screen_cache_global.h \
    cell.h \
    banner.h \
    ship_cell.h \
    board_cell.h \
    cell_state.h \
    dead_cell_base.h \
    dead_cell_hover.h \
    alive_cell_base.h \
    alive_cell_hover.h \
    invisible_cell.h \
    error_cell.h \
    field_creator.h \
    ship_factory.h \
    shoot.h
HEADERS += main_screen.h

SOURCES += main.cpp \
    button.cpp \
    main_screen.cpp \
    screen.cpp \
    exit_screen.cpp \
    screen_cache.cpp \
    play_screen.cpp \
    options_screen.cpp \
    game_vs_computer_screen.cpp \
    game_gui.cpp \
    field.cpp \
    your_field.cpp \
    enemy_field.cpp \
    cell.cpp \
    ship.cpp \
    banner.cpp \
    ship_cell.cpp \
    board_cell.cpp \
    ship_4_cells.cpp \
    ship_3_cells.cpp \
    ship_2_cells.cpp \
    ship_1_cell.cpp \
    cell_state.cpp \
    dead_cel_base.cpp \
    dead_cell_hover.cpp \
    alive_cell_base.cpp \
    alive_cell_hover.cpp \
    invisible_cell.cpp \
    error_cell.cpp \
    field_creator.cpp \
    ship_factory.cpp \
    shoot.cpp
SOURCES += battlefield.cpp
