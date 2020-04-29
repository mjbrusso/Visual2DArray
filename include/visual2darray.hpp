//*************************************************************************
// File:        visual2darray.hpp
// Purpose:     Visual2DArray class
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _VISUAL2DARRAY_HPP_INCLUDED
#define _VISUAL2DARRAY_HPP_INCLUDED

#include "abstractui.hpp"
#include "color.hpp"
#include "types.hpp"
#include <chrono>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <map>
#include <memory>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace visual2darray {
class Visual2DArray : public AbstractVisual2DArray {
    // Types ***************************************************************
public:
    typedef std::vector<int> row_type; // Matrix = vector<vector<int>>

private:
    typedef void (*EventHandler)(Visual2DArray&); // Callbacks

    // Fields ***************************************************************
    const int m_rowCount, m_colCount; // Array size
    std::vector<row_type> m_data; // Array data
    int m_clickedCol, m_clickedRow; // Last mouse click position
    MouseButton m_mouseButton; // Last clicked mouse button
    Key m_lastKey; // Last key pressed
    bool m_isRunning; // Is the game running?
    std::ostringstream m_messageBuffer; // String stream for messages
    std::default_random_engine m_randomGenerator; // Random number generator
    std::uniform_int_distribution<int> m_rowDistribution, m_colDistribution; // Random number distribution, for randomRow() and randomCol()
    EventHandler m_mouseHandler { nullptr }, m_keyboardHandler { nullptr }, m_startHandler { nullptr }; // Event callbacks
    std::unique_ptr<AbstractUI> m_ui; // UI Implementation

    // ctor/dtor ***************************************************************
public:
    Visual2DArray(int nrows, int ncols)
        : // Constructor
        m_rowCount { nrows }
        , m_colCount { ncols }
        , m_data(nrows, row_type(ncols, 0))
        , m_clickedCol {}
        , m_clickedRow {}
        , m_mouseButton {}
        , m_lastKey {}
        , m_isRunning { false }
        , m_messageBuffer {}
        , m_randomGenerator(std::chrono::system_clock::now().time_since_epoch().count())
        , m_rowDistribution(0, m_rowCount - 1)
        , m_colDistribution(0, m_colCount - 1)
        , m_ui { UIFactory::get(*this) }
    {
    }

    Visual2DArray(const Visual2DArray&) = delete; //delete copy constructor
    Visual2DArray& operator=(const Visual2DArray&) = delete; //delete copy assignment operator
    //Methods:   ***************************************************************
public:
    // Data access  methods
    row_type& operator[](int r) // Access a row
    {
        return m_data[r];
    }

    const row_type& operator[](int r) const // Access a row (const version)
    {
        return m_data[r];
    }

    int rowCount() const
    {
        return m_rowCount;
    }

    int colCount() const
    {
        return m_colCount;
    }

    int size() const
    {
        return m_rowCount * m_colCount;
    }

    // UI methods
    void title(const std::string& s)
    {
        m_ui->title(s);
    }

    void cellSize(int w, int h)
    {
        m_ui->cellSize(w, h);
    }

    void borderSize(int w)
    {
        m_ui->borderSize(w);
    }

    bool confirm(const std::string& msg)
    {
        if (isRunning())
            redraw();
        return m_ui->confirm(msg);
    }

    void alert(const std::string& msg)
    {
        if (isRunning())
            redraw();
        m_ui->alert(msg);
    }

    std::string input(const std::string& msg)
    {
        if (isRunning())
            redraw();
        return m_ui->input(msg);
    }

    void beep()
    {
        m_ui->beep();
    }

    void backgroundColor(const Color& color)
    {
        m_ui->backgroundColor(color);
    }

    void backgroundColor(const std::string& hexcode)
    {
        m_ui->backgroundColor(Color(hexcode));
    }

    void backgroundColor(int r, int g, int b)
    {
        m_ui->backgroundColor(Color(r, g, b));
    }

    void cellColor(const Color& color)
    {
        m_ui->cellColor(color);
    }

    void cellColor(const std::string& hexcode)
    {
        m_ui->cellColor(Color(hexcode));
    }

    void cellColor(int r, int g, int b)
    {
        m_ui->cellColor(Color(r, g, b));
    }

    void messageColor(const Color& color)
    {
        m_ui->messageColor(color);
    }

    void messageColor(const std::string& hexcode)
    {
        m_ui->messageColor(Color(hexcode));
    }

    void messageColor(int r, int g, int b)
    {
        m_ui->messageColor(Color(r, g, b));
    }

    // Random position or value generation
    int randomRow()
    {
        return m_rowDistribution(m_randomGenerator);
    }

    int randomCol()
    {
        return m_colDistribution(m_randomGenerator);
    }

    int randomValue(int inf, int sup)
    {
        std::uniform_int_distribution<int> distr(inf, sup);
        return distr(m_randomGenerator);
    }

    // Event data
    int clickedCol() const
    {
        return m_clickedCol;
    }

    int clickedRow() const
    {
        return m_clickedRow;
    }

    MouseButton mouseButton() const
    {
        return m_mouseButton;
    }

    Key lastKey() const
    {
        return m_lastKey;
    }

    // Events callbacks
    void onMouseClicked(EventHandler fn)
    {
        m_mouseHandler = fn;
    }

    void onKeyPressed(EventHandler fn)
    {
        m_keyboardHandler = fn;
    }

    void onStart(EventHandler fn)
    {
        m_startHandler = fn;
    }

    // Status
    bool isRunning() const // Is the game running?
    {
        return m_isRunning;
    }

    // Message bar
    template <typename T>
    Visual2DArray& operator<<(T val)
    {
        m_messageBuffer << val;
        return *this;
    }

    Visual2DArray& operator<<(std::ostream& (*os)(std::ostream&)__attribute__((unused))) // endl
    {
        m_messageBuffer << '\n';
        return *this;
    }

    void clearMessage()
    {
        m_messageBuffer.str(std::string());
        m_messageBuffer.clear();
    }

private:
    std::string getMessage()
    {
        return m_messageBuffer.str();
    }

    void lastKey(Key k)
    {
        m_lastKey = k;
    }

    void mouseButton(MouseButton b)
    {
        m_mouseButton = b;
    }

    void clickedRow(int row)
    {
        m_clickedRow = row;
    }

    void clickedCol(int col)
    {
        m_clickedCol = col;
    }

public:
    // not inline functions (implementation in .cpp file)
    void restart(); // Called every time the game is started/restarted
    void fill(int value); // Fill matrix with value
    void copy(std::initializer_list<std::initializer_list<int>> values); // Set all values from initializer_list
    void shuffle(); // Random shuffle
    void setImage(int value, const std::string& fileName); // Assign image file name to a value
    void run(); // Create and show the game window
    void pause(int ms); // Put the game to sleep for the specified number of milliseconds
    void close(); // Close (exit) the game
    void notifyMouseEvent(int row, int col, MouseButton b); // The mouse button b was pressed in the cell[row][col]
    void notifyKeyboardEvent(Key k); // A key was pressed
    void redraw(); // Draw the game window (update all cells)

    // TODO:
    //    void autoClose(bool yn)
    //    void autoRestart(bool yn)
    //    void startTimer(int interval)
    //    void stopTimer(int interval)
    //    float elapsedTime()   //sec
    //  Events://
    //    onTimer(EventHandler fn)
};

}
#endif
