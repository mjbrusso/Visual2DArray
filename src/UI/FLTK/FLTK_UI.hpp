//*************************************************************************
// File:        FLTK_UI.hpp
// Purpose:     FLTK UI Concrete Class
// Author:      Marcos José Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _FLTK_UI_HPP_INCLUDED
#define _FLTK_UI_HPP_INCLUDED

#include <stdexcept>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Shared_Image.H>
#include "FL/Enumerations.H"

#include <string>
#include <cstdio>

#include "types.hpp"
#include "abstractui.hpp"
#include "Fl_GameWindow.hpp"
#include "Fl_Cell.hpp"

namespace visual2darray
{

class FLTK_UI : public AbstractUI
{
private:
    Fl_GameWindow *m_window;
    Fl_Box* m_messageBar;
public:

    FLTK_UI(AbstractVisual2DArray& g): AbstractUI(g),
        m_window {nullptr}
    {
        fl_register_images();
    }

    FLTK_UI(const FLTK_UI&) = delete;                         //delete copy constructor
    FLTK_UI& operator = (const FLTK_UI &) = delete;           //delete copy assignment operator

    void setWindowTitle(const std::string &title)
    {
        if(m_window) m_window->copy_label(title.c_str());
    }

    // Load image file by name
    void* loadImage(const std::string& fileName)
    {
        return static_cast<void*>(Fl_Shared_Image::get(fileName.c_str()));
    }

    // Play an alert sound
    void beep()
    {
        fl_beep(FL_BEEP_NOTIFICATION);
    }

    // Show Yes/No choice dialog
    bool confirm(const std::string& msg)
    {
        return fl_choice("%s", "Yes", "No", 0, msg.c_str())==0;
    }

    // Show a message dialog
    void alert(const std::string& msg)
    {
       fl_alert("%s", msg.c_str());
    }

    // Show a dialog box that prompts the user for string
    std::string input(const std::string& msg)
    {
        auto txt = fl_input("%s", "", msg.c_str());
        if(txt) return std::string(txt);
        return std::string();
    }

    void update(){
        Fl::wait(0);
    }

    void createWindow();
    void* createCell(int i, int j);             // Create a cell widget
    void drawImage(void* cell, void* img);      // Draw the image @ the cell
    void drawValue(void* cell, int value);      // Display the value @ the cell
    void drawStr(void* cell, std::string &s);   // Display the text @ the cell
    void drawMessage(std::string &str);         // Display the text @ message bar
    void run();                                 // Show window and enter loop events
    void close();                               // Close window

private:
    Fl_Color Color2FlColor(Color c);            // Convert FLTK Color type to our color type
};

}
#endif
