//*************************************************************************
// File:        Fl_Cell.cpp
// Purpose:     Cell UI Class Implementation
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#include "Fl_Cell.hpp"
#include "types.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <string>

namespace visual2darray {
// Virtual event handler
int Fl_Cell::handle(int event)
{
    switch (event) {
    case FL_PUSH: // Mouse buttom pressed
        return 1;
    case FL_RELEASE: // Mouse buttom released
        static_cast<AbstractVisual2DArray*>(this->user_data())->notifyMouseEvent(m_row, m_col, flMouse2Mouse(Fl::event_button()));
        return 1;
    default:
        return Fl_Widget::handle(event);
    }
}

// Convert FLTK mouse buttons to our buttons
MouseButton Fl_Cell::flMouse2Mouse(int mb)
{
    switch (mb) {
    case FL_LEFT_MOUSE:
        return MouseButton::Left;
    case FL_MIDDLE_MOUSE:
        return MouseButton::Middle;
    }
    return MouseButton::Right;
}

}
