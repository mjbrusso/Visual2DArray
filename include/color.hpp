//*************************************************************************
// File:        color.hpp
// Purpose:     RGB Color type
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#ifndef _COLOR_HPP_INCLUDED
#define _COLOR_HPP_INCLUDED

#include <cstdint>
#include <string>
#include <sstream>

namespace visual2darray
{

class Color
{
private:
    uint8_t m_r, m_g, m_b;          // RGB values

public:
    Color(uint8_t r, uint8_t g, uint8_t b):     // RGB 3 values constructor. Ex: Color(255, 0, 0)
        m_r{r},
        m_g{g},
        m_b{b}
    {
    }

    Color(): Color(0, 0, 0)     // Default constructor (no arguments): ex: Color()
    {
    }

    Color(std::string hexcode): Color(0, 0, 0)          // HTML like hexa string. Ex: Color("#FF0000");
    {
        int r{}, g{}, b{};
        if(hexcode.at(0) == '#') hexcode.erase(0, 1);  // Remove the number sign

        if(hexcode.size() >= 2) std::istringstream(hexcode.substr(0, 2)) >> std::hex >> r;
        if(hexcode.size() >= 4) std::istringstream(hexcode.substr(2, 2)) >> std::hex >> g;
        if(hexcode.size() >= 6) std::istringstream(hexcode.substr(4, 2)) >> std::hex >> b;
        m_r = r;
        m_g = g;
        m_b = b;
    }

    // Getters
    uint8_t r() const
    {
        return m_r;
    }

    uint8_t g() const
    {
        return m_g;
    }

    uint8_t b() const
    {
        return m_b;
    }

    // Colors constants declaration (HTML color names): See: www.w3schools.com/colors/colors_names.asp
    static const Color AliceBlue;
    static const Color AntiqueWhite;
    static const Color Aqua;
    static const Color Aquamarine;
    static const Color Azure;
    static const Color Beige;
    static const Color Bisque;
    static const Color Black;
    static const Color BlanchedAlmond;
    static const Color Blue;
    static const Color BlueViolet;
    static const Color Brown;
    static const Color BurlyWood;
    static const Color CadetBlue;
    static const Color Chartreuse;
    static const Color Chocolate;
    static const Color Coral;
    static const Color CornflowerBlue;
    static const Color Cornsilk;
    static const Color Crimson;
    static const Color Cyan;
    static const Color DarkBlue;
    static const Color DarkCyan;
    static const Color DarkGoldenRod;
    static const Color DarkGray;
    static const Color DarkGrey;
    static const Color DarkGreen;
    static const Color DarkKhaki;
    static const Color DarkMagenta;
    static const Color DarkOliveGreen;
    static const Color DarkOrange;
    static const Color DarkOrchid;
    static const Color DarkRed;
    static const Color DarkSalmon;
    static const Color DarkSeaGreen;
    static const Color DarkSlateBlue;
    static const Color DarkSlateGray;
    static const Color DarkSlateGrey;
    static const Color DarkTurquoise;
    static const Color DarkViolet;
    static const Color DeepPink;
    static const Color DeepSkyBlue;
    static const Color DimGray;
    static const Color DimGrey;
    static const Color DodgerBlue;
    static const Color FireBrick;
    static const Color FloralWhite;
    static const Color ForestGreen;
    static const Color Fuchsia;
    static const Color Gainsboro;
    static const Color GhostWhite;
    static const Color Gold;
    static const Color GoldenRod;
    static const Color Gray;
    static const Color Grey;
    static const Color Green;
    static const Color GreenYellow;
    static const Color HoneyDew;
    static const Color HotPink;
    static const Color IndianRed ;
    static const Color Indigo ;
    static const Color Ivory;
    static const Color Khaki;
    static const Color Lavender;
    static const Color LavenderBlush;
    static const Color LawnGreen;
    static const Color LemonChiffon;
    static const Color LightBlue;
    static const Color LightCoral;
    static const Color LightCyan;
    static const Color LightGoldenRodYellow;
    static const Color LightGray;
    static const Color LightGrey;
    static const Color LightGreen;
    static const Color LightPink;
    static const Color LightSalmon;
    static const Color LightSeaGreen;
    static const Color LightSkyBlue;
    static const Color LightSlateGray;
    static const Color LightSlateGrey;
    static const Color LightSteelBlue;
    static const Color LightYellow;
    static const Color Lime;
    static const Color LimeGreen;
    static const Color Linen;
    static const Color Magenta;
    static const Color Maroon;
    static const Color MediumAquaMarine;
    static const Color MediumBlue;
    static const Color MediumOrchid;
    static const Color MediumPurple;
    static const Color MediumSeaGreen;
    static const Color MediumSlateBlue;
    static const Color MediumSpringGreen;
    static const Color MediumTurquoise;
    static const Color MediumVioletRed;
    static const Color MidnightBlue;
    static const Color MintCream;
    static const Color MistyRose;
    static const Color Moccasin;
    static const Color NavajoWhite;
    static const Color Navy;
    static const Color OldLace;
    static const Color Olive;
    static const Color OliveDrab;
    static const Color Orange;
    static const Color OrangeRed;
    static const Color Orchid;
    static const Color PaleGoldenRod;
    static const Color PaleGreen;
    static const Color PaleTurquoise;
    static const Color PaleVioletRed;
    static const Color PapayaWhip;
    static const Color PeachPuff;
    static const Color Peru;
    static const Color Pink;
    static const Color Plum;
    static const Color PowderBlue;
    static const Color Purple;
    static const Color RebeccaPurple;
    static const Color Red;
    static const Color RosyBrown;
    static const Color RoyalBlue;
    static const Color SaddleBrown;
    static const Color Salmon;
    static const Color SandyBrown;
    static const Color SeaGreen;
    static const Color SeaShell;
    static const Color Sienna;
    static const Color Silver;
    static const Color SkyBlue;
    static const Color SlateBlue;
    static const Color SlateGray;
    static const Color SlateGrey;
    static const Color Snow;
    static const Color SpringGreen;
    static const Color SteelBlue;
    static const Color Tan;
    static const Color Teal;
    static const Color Thistle;
    static const Color Tomato;
    static const Color Turquoise;
    static const Color Violet;
    static const Color Wheat;
    static const Color White;
    static const Color WhiteSmoke;
    static const Color Yellow;
    static const Color YellowGreen;

};

}
#endif
