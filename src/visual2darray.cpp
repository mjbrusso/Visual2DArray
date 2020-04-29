//*************************************************************************
// File:        visual2darray.cpp
// Purpose:     Visual2DArray class implementation
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#include <algorithm>
#include <initializer_list>
#include <string>
//#include <chrono>
//#include <thread>
#ifdef WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <stdexcept>

#include "types.hpp"
#include "visual2darray.hpp"

namespace visual2darray {

// Called every time the game is started/restarted
void Visual2DArray::restart()
{
    if (m_startHandler) { // If we have a callback function
        (*m_startHandler)(*this); // call it
        if (isRunning())
            redraw(); // update the UI
    }
}

// Fill matrix with value
void Visual2DArray::fill(int value)
{
    for (auto& row : m_data)
        std::fill(row.begin(), row.end(), value);
}

// Set all values from initializer_list
void Visual2DArray::copy(std::initializer_list<std::initializer_list<int>> values)
{
    int r { 0 };
    for (auto& row : values) { // For each row
        std::copy(row.begin(), row.end(), m_data[r].begin()); // Fill it
        r++;
    }
}

// Random shuffle
void Visual2DArray::shuffle()
{
    for (auto& row : m_data) // For each row
        for (auto& v : row) { // For each col
            std::swap(v, m_data[randomRow()][randomCol()]); // Random permutation
        }
}

// Assign image file name to a value
void Visual2DArray::setImage(int value, const std::string& fileName)
{
    m_ui->assignImage(value, fileName);
}

// Create and show the game window
void Visual2DArray::run()
{
    // try {
    restart();
    m_ui->create(); // Create UI window
    redraw(); // Update UI
    m_isRunning = true;
    m_ui->run(); // Show window
    // } catch(std::invalid_argument& e) {
    //     alert( e.what());
    // }
}

// Put the game to sleep for the specified number of milliseconds
void Visual2DArray::pause(int ms)
{
    redraw();
//  Sleeping thread freeze the UI !!!!!!!
#ifdef WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif // WIN32
    // std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// Close (exit) the game
void Visual2DArray::close()
{
    m_ui->close();
}

// The mouse button b was pressed in the cell[row][col]
void Visual2DArray::notifyMouseEvent(int row, int col, MouseButton b)
{
    // Set the position
    clickedRow(row);
    clickedCol(col);
    mouseButton(b); // Save the button
    if (m_mouseHandler) { // If we have a callback function
        (*m_mouseHandler)(*this); // call it
        redraw(); // update UI
    }
}

// A key was pressed
void Visual2DArray::notifyKeyboardEvent(Key k)
{
    lastKey(k);
    if (k == Key::Escape)
        close();
    else if (k == Key::F2)
        restart();
    else if (m_keyboardHandler) { // If we have a callback function
        (*m_keyboardHandler)(*this); // call it
        redraw(); // update UI
    }
}

// Draw the game window (update all cells)
void Visual2DArray::redraw()
{
    for (int i = 0; i < rowCount(); ++i) // For each row i
        for (int j = 0; j < colCount(); ++j) // For each col j
            m_ui->drawCell(i, j, m_data[i][j]); // draw cell[i][j]
    std::string msg(getMessage());
    m_ui->drawMessage(msg); // Update Message Bar
    m_ui->update(); // Update window
}

}
