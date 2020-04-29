//*************************************************************************
// File:        AbstractUI.hpp
// Purpose:     User Interface Abstract Class & UIFactory definition
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************
#ifndef _ABSTRACTUI_HPP_INCLUDED
#define _ABSTRACTUI_HPP_INCLUDED

#include "color.hpp"
#include "types.hpp"
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace visual2darray {

class AbstractUI // Abstract class
{
private:
    const char* m_imagePath = "img/"; // Default image path
    std::string m_title; // Window title
    AbstractVisual2DArray& m_theGame; // Game
    int m_cellWidth, m_cellHeight, m_borderSize; // Size in pixels
    Color m_cellColor, m_backgroundColor, m_messageColor; // Colors
    int m_messageBarHeight; // Height in pixels
    std::map<int, std::string> m_fileNameCache; // Map: value => filename
    std::map<std::string, void*> m_imageCache; // Map: filename => image*
    std::vector<std::vector<void*>> m_cells; // m_cells[i][j] is a pointer to the cell widget @i,j

public:
    AbstractUI(AbstractVisual2DArray& g)
        : // Constructor
        m_title {}
        , m_theGame(g)
        , m_cellWidth { 100 }
        , m_cellHeight { 100 }
        , m_borderSize { 1 }
        , m_cellColor { Color::White }
        , m_backgroundColor { Color::Black }
        , m_messageColor { Color::Black }
        , m_messageBarHeight { 32 }
        , m_fileNameCache {}
        , m_imageCache {}
        , m_cells(g.rowCount(), std::vector<void*>(g.colCount()))
    {
    }

    virtual ~AbstractUI() // Virtual destructor
    {
    }

    AbstractUI(const AbstractUI&) = delete; //delete copy constructor
    AbstractUI& operator=(const AbstractUI&) = delete; //delete copy assignment operator

    // Set window title
    void title(const std::string& s)
    {
        m_title = s;
        setWindowTitle(s); // Call child function (UI implementation)
    }

    // Get window title
    const std::string& title() const
    {
        return m_title;
    }

    // Get window width
    int windowWidth() const
    {
        return (getGame().colCount() * cellWidth()) + ((getGame().colCount() + 1) * borderSize());
    }

    // Get window height
    int windowHeight() const
    {
        return (getGame().rowCount() * cellHeight()) + ((getGame().rowCount() + 1) * borderSize()) + messageBarHeight();
    }

    // Set cell size
    void cellSize(int w, int h)
    {
        m_cellWidth = w;
        m_cellHeight = h;
    }

    // Get cell width
    int cellWidth() const
    {
        return m_cellWidth;
    }

    // Get cell height
    int cellHeight() const
    {
        return m_cellHeight;
    }

    // Set border size
    void borderSize(int s)
    {
        m_borderSize = s;
    }

    // Get border size
    int borderSize() const
    {
        return m_borderSize;
    }

    // Get message bar height
    int messageBarHeight() const
    {
        return m_messageBarHeight;
    }

    // Set cell color
    void cellColor(const Color& color)
    {
        m_cellColor = color;
    }

    // Get cell color
    const Color& cellColor() const
    {
        return m_cellColor;
    }

    // Set border color
    void backgroundColor(const Color& color)
    {
        m_backgroundColor = color;
    }

    // Get border color
    const Color& backgroundColor() const
    {
        return m_backgroundColor;
    }

    // Set message color
    void messageColor(const Color& color)
    {
        m_messageColor = color;
    }

    // Get message color
    const Color& messageColor() const
    {
        return m_messageColor;
    }

    // Create window and cells
    void create()
    {
        createWindow();
        for (int i = 0; i < getGame().rowCount(); ++i) // For each row
            for (int j = 0; j < getGame().colCount(); ++j) { // For each col
                m_cells[i][j] = createCell(i, j);
            }
    }

    // Draw a cell
    void drawCell(int i, int j, int value)
    {
        auto file = m_fileNameCache.find(value); // Searches the file name cache
        auto img = (file == m_fileNameCache.end()) // Not found!
            ? assignImage(value, value2FileName(value)) // Load file and save image in cache
            : m_imageCache[file->second]; // Get from cache

        auto cell = m_cells[i][j]; // Get current cell
        if (img)
            drawImage(cell, img); // If image found, then draw image
        else
            drawValue(cell, value); // else draw text
    }

    // Load a image and assign to a value
    void* assignImage(int value, std::string fileName)
    {
        if (fileName.find(m_imagePath) == std::string::npos) // File name only (no path provided)
            fileName = m_imagePath + fileName; // Add path (folder name)

        m_fileNameCache[value] = fileName; // Save filename
        auto img = loadImage(fileName); // Load image (UI dependant)
        m_imageCache[fileName] = img; // Store image
        return img;
    }

protected:
    // Get current game (why not a singleton pattern ?)
    AbstractVisual2DArray& getGame() const
    {
        return m_theGame;
    }

private:
    // Get default image file name
    std::string value2FileName(int value) const
    {
        std::ostringstream oss; // Build file name
        oss << m_imagePath << value << ".png";
        return oss.str();
    }

public:
    // Abstract
    virtual void createWindow() = 0;
    virtual void beep() = 0; // Play an alert sound
    virtual bool confirm(const std::string& msg) = 0; // Show Yes/No choice dialog
    virtual void alert(const std::string& msg) = 0; // Show a message dialog
    virtual std::string input(const std::string& msg) = 0; // Show a dialog box that prompts the user for string
    virtual void drawMessage(std::string& str) = 0; // Display the text @ message bar
    virtual void update() = 0; // Update UI
    virtual void run() = 0; // Show window and enter loop events
    virtual void close() = 0; // Close window

protected:
    virtual void setWindowTitle(const std::string& title) = 0;
    virtual void* createCell(int i, int j) = 0; // Create a cell widget
    virtual void* loadImage(const std::string& fileName) = 0; // Load image file by name
    virtual void drawImage(void* cell, void* img) = 0; // Draw the image @ the cell
    virtual void drawValue(void* cell, int value) = 0; // Display the value @ the cell
    virtual void drawStr(void* cell, std::string& str) = 0; // Display the text @ the cell
    // virtual void createMessageBar(int h) = 0;                       // Create the message bar widget
};

class UIFactory {
public:
    static AbstractUI* get(AbstractVisual2DArray& g);
};

}

#endif
