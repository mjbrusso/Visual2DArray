//*************************************************************************
// File:        Fl_GameWindow.cpp
// Purpose:     Fl_Window Derived Class Implementation
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************
#include "Fl_GameWindow.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <string>

namespace visual2darray {

int Fl_GameWindow::handle(int event)
{
    switch (event) {
    case FL_KEYDOWN: // A key was pressed, then notify the game
        static_cast<AbstractVisual2DArray*>(this->user_data())->notifyKeyboardEvent(flKeyCode2Key(Fl::event_key()));
    }
    return Fl_Window::handle(event);
}

Key Fl_GameWindow::flKeyCode2Key(int keyCode)
{
    if (keyCode >= 'a' && keyCode <= 'z')
        return Key(keyCode - 32); // Letters
    if (keyCode >= '0' && keyCode <= '9')
        return Key(keyCode + 48); // Numbers
    if (keyCode >= 65361 && keyCode <= 65364)
        return Key(keyCode - 65324); // Arrows
    if (keyCode >= 65470 && keyCode <= 65481)
        return Key(keyCode - 65358); // Fn

    // Other keys
    switch (keyCode) {
    case 65288:
        return Key::Back;
    case 65289:
        return Key::Tab;
    case 65293:
        return Key::Enter;
    case 65299:
        return Key::Pause;
    case 65509:
        return Key::CapsLock;
    case 65307:
        return Key::Escape;
    case 32:
        return Key::Space;
    case 65365:
        return Key::PageUp;
    case 65366:
        return Key::PageDown;
    case 65367:
        return Key::End;
    case 65360:
        return Key::Home;
    case 65379:
        return Key::Insert;
    case 65535:
        return Key::Delete;
        // TODO
        //      case : return Key::Multiply;
        //      case : return Key::Add;
        //      case : return Key::Separator;
        //      case : return Key::Subtract;
        //      case : return Key::Decimal;
        //      case : return Key::Divide;
        //      case : return Key::NumLock;
        //      case : return Key::Scroll;
        //      case : return Key::ShiftLeft;
        //      case : return Key::ShiftRight;
        //      case : return Key::ControlLeft;
        //      case : return Key::ControlRight;
        //      case : return Key::AltLeft;
        //      case : return Key::AltRight;
        //      case : return Key::Windows;
    }
    return Key::Unknown;
}
}
