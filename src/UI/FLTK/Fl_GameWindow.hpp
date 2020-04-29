//*************************************************************************
// File:        Fl_GameWindow.hpp
// Purpose:     Fl_Window Derived Class
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _FL_GAMEWINDOW_HPP_INCLUDED
#define _FL_GAMEWINDOW_HPP_INCLUDED

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <string>
#include "types.hpp"

namespace visual2darray {

class Fl_GameWindow : public Fl_Double_Window {
public:
    Fl_GameWindow(int w, int h, const std::string& title)
        : Fl_Double_Window(w, h, title.c_str())
    {
    }

private:
    int handle(int event);
    Key flKeyCode2Key(int keyCode);
};

}
#endif
