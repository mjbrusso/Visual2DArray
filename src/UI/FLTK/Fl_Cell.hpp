//*************************************************************************
// File:        Fl_Cell.hpp
// Purpose:     Cell UI Class
// Author:      Marcos José Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _FL_CELL_HPP_INCLUDED
#define _FL_CELL_HPP_INCLUDED

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <string>
#include "types.hpp"

namespace visual2darray
{

class Fl_Cell : public Fl_Box
{
private:
    int m_row, m_col;       // Cell position

public:
    Fl_Cell(int i, int j, int borderSize, int w, int h) :   // Constructor
        Fl_Box(FL_FLAT_BOX, borderSize + j * (w + borderSize), borderSize + i * (h + borderSize), w, h, nullptr),
        m_row{i},
        m_col{j}
    {
    }
private:
    int handle(int event);                  // Virtual event handler
    MouseButton flMouse2Mouse(int mb);      // Convert FLTK mouse buttons to our buttons
};

}
#endif
