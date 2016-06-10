//*************************************************************************
// File:        FLTK_UI.cpp
// Purpose:     FLTK UI Concrete Class Implementation
// Author:      Marcos José Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#include <stdexcept>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include "FL/Enumerations.H"

#include <string>
#include <cstdio>

#include "types.hpp"
#include "abstractui.hpp"
#include "FLTK_UI.hpp"
#include "Fl_GameWindow.hpp"
#include "Fl_Cell.hpp"

namespace visual2darray
{

AbstractUI* UIFactory::get(AbstractVisual2DArray& g)
{
    return new FLTK_UI(g);
}

void FLTK_UI::createWindow()
{
    m_window = new Fl_GameWindow(windowWidth(), windowHeight(), title());
    m_window->color(Color2FlColor(backgroundColor()));
    m_window->user_data(static_cast<void *>(&getGame()));
// Window background image (mudar cell para FL_NO_BOX
    //   auto img = loadImage("bg.png");
    //  auto bg = new Fl_Box(0, 0, style().width, style().height, nullptr);
    // bg->image(img);
    m_messageBar = new Fl_Box (FL_NO_BOX, 0, windowHeight()-messageBarHeight(), windowWidth(), messageBarHeight(), nullptr);
    m_messageBar->labelsize(12);
    m_messageBar->color(m_window->color());
    m_messageBar->labelcolor(Color2FlColor(messageColor()));
    m_window->add(m_messageBar);
}

// Show window and enter loop events
void FLTK_UI::run()
{
    m_window->show();
    Fl::run();
}

// Close window
void FLTK_UI::close()
{
    m_window->hide(); // FLTK will exit when all the windows are hidden
}

// Create a cell widget
void* FLTK_UI::createCell(int i, int j)
{
    auto p = new Fl_Cell(i, j, borderSize(), cellWidth(), cellHeight());        // Create widget
    m_window->add(p);                                                           // Add it to window
    p->color(Color2FlColor(cellColor()));                                       // Set color
    Color lc(~cellColor().r(), ~cellColor().g(), ~cellColor().b());   // Create high contrast color for cell labels
    p->labelcolor(Color2FlColor(lc));
    p->align(FL_ALIGN_IMAGE_BACKDROP);                                          // Draw the image in the cell background
    p->user_data(static_cast<void *>(&getGame()));                              // Pointer to the game
    return static_cast<void *>(p);
}

 // Draw the image @ the cell
void FLTK_UI::drawImage(void* cell, void* img)
{
    Fl_Cell* c = static_cast<Fl_Cell*>(cell);
    if(c->image() != img) {                                            // redraw if changed
        c->image(static_cast<Fl_Image*>(img));                         // set image
        c->label(nullptr);                                             // hide label
    }
}

// Display the value @ the cell
void FLTK_UI::drawValue(void* cell, int value)
{
    char s[20];
    sprintf(s, "%d", value);
    Fl_Cell* c = static_cast<Fl_Cell*>(cell);
    c->copy_label(s);                                       // set label
    c->image(nullptr);                                      // hide image
}

// Display the text @ the cell
void FLTK_UI::drawStr(void* cell, std::string &s)
{
    Fl_Cell* c = static_cast<Fl_Cell*>(cell);
    c->copy_label(s.c_str());                           // set label
    c->image(nullptr);                                  // hide image
}

// Display the text @ message bar
void FLTK_UI::drawMessage(std::string &str)
{
    m_messageBar->copy_label(str.c_str());
}

// Convert FLTK Color type to our color type
Fl_Color FLTK_UI::Color2FlColor(Color c)
{
    return fl_rgb_color(c.r(), c.g(), c.b());
}
}

