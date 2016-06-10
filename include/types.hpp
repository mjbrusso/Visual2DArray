//*************************************************************************
// File:        types.hpp
// Purpose:     Auxiliary Types
// Author:      Marcos José Brusso <mjbrusso@gmail.com>
// Created:     feb-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _TYPES_HPP_INCLUDED
#define _TYPES_HPP_INCLUDED

#include <string>
#include <sstream>
#include <map>

namespace visual2darray
{

//class ImageType;    // Forward declaration
//class CellType;     // Forward declaration

enum class MouseButton {
    Left,
    Middle,
    Right
};

enum class Key {
    Back = 8,
    Tab = 9,
    Enter = 13,
    Pause = 19,
    CapsLock = 20,
    Escape = 27,
    Space = 32,
    PageUp = 33,
    PageDown = 34,
    End = 35,
    Home = 36,
    Left = 37,
    Up = 38,
    Right = 39,
    Down = 40,
    Insert = 45,
    Delete = 46,
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
    G = 71,
    H = 72,
    I = 73,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    O = 79,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    U = 85,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,
    Num0 = 96,
    Num1 = 97,
    Num2 = 98,
    Num3 = 99,
    Num4 = 100,
    Num5 = 101,
    Num6 = 102,
    Num7 = 103,
    Num8 = 104,
    Num9 = 105,
//    Multiply = 106,
//    Add = 107,
//    Separator = 108,
//    Subtract = 109,
//    Decimal = 110,
//    Divide = 111,
    F1 = 112,
    F2 = 113,
    F3 = 114,
    F4 = 115,
    F5 = 116,
    F6 = 117,
    F7 = 118,
    F8 = 119,
    F9 = 120,
    F10 = 121,
    F11 = 122,
    F12 = 123,
//    NumLock = 144,
//    Scroll = 145,
//    ShiftLeft = 160,
//    ShiftRight = 161,
//    ControlLeft = 162,
//    ControlRight = 163,
//    AltLeft = 164,
//    AltRight = 165,
//    Windows = 91
    Unknown=9999
};

class AbstractVisual2DArray
{
public:
    virtual int rowCount() const = 0;
    virtual int colCount() const = 0;
    virtual void notifyMouseEvent(int row, int col, MouseButton b) = 0;
    virtual void notifyKeyboardEvent(Key k) = 0;
    virtual ~AbstractVisual2DArray() {}
};

}
#endif
