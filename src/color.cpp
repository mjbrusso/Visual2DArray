//*************************************************************************
// File:        color.hpp
// Purpose:     RGB Color type implementation
// Author:      Marcos Jos� Brusso <mjbrusso@gmail.com>
// Created:     mar-2016
// Copyright:   mjbrusso
// Licence:     GNU LGPLv3
//*************************************************************************

#include "color.hpp"

namespace visual2darray {

// Colors constants definition (HTML color names): See: www.w3schools.com/colors/colors_names.asp
const Color Color::AliceBlue(240, 248, 255);
const Color Color::AntiqueWhite(250, 235, 215);
const Color Color::Aqua(0, 255, 255);
const Color Color::Aquamarine(127, 255, 212);
const Color Color::Azure(240, 255, 255);
const Color Color::Beige(245, 245, 220);
const Color Color::Bisque(255, 228, 196);
const Color Color::Black(0, 0, 0);
const Color Color::BlanchedAlmond(255, 235, 205);
const Color Color::Blue(0, 0, 255);
const Color Color::BlueViolet(138, 43, 226);
const Color Color::Brown(165, 42, 42);
const Color Color::BurlyWood(222, 184, 135);
const Color Color::CadetBlue(95, 158, 160);
const Color Color::Chartreuse(127, 255, 0);
const Color Color::Chocolate(210, 105, 30);
const Color Color::Coral(255, 127, 80);
const Color Color::CornflowerBlue(100, 149, 237);
const Color Color::Cornsilk(255, 248, 220);
const Color Color::Crimson(220, 20, 60);
const Color Color::Cyan(0, 255, 255);
const Color Color::DarkBlue(0, 0, 139);
const Color Color::DarkCyan(0, 139, 139);
const Color Color::DarkGoldenRod(184, 134, 11);
const Color Color::DarkGray(169, 169, 169);
const Color Color::DarkGreen(0, 100, 0);
const Color Color::DarkKhaki(189, 183, 107);
const Color Color::DarkMagenta(139, 0, 139);
const Color Color::DarkOliveGreen(85, 107, 47);
const Color Color::DarkOrange(255, 140, 0);
const Color Color::DarkOrchid(153, 50, 204);
const Color Color::DarkRed(139, 0, 0);
const Color Color::DarkSalmon(233, 150, 122);
const Color Color::DarkSeaGreen(143, 188, 143);
const Color Color::DarkSlateBlue(72, 61, 139);
const Color Color::DarkSlateGray(47, 79, 79);
const Color Color::DarkTurquoise(0, 206, 209);
const Color Color::DarkViolet(148, 0, 211);
const Color Color::DeepPink(255, 20, 147);
const Color Color::DeepSkyBlue(0, 191, 255);
const Color Color::DimGray(105, 105, 105);
const Color Color::DodgerBlue(30, 144, 255);
const Color Color::FireBrick(178, 34, 34);
const Color Color::FloralWhite(255, 250, 240);
const Color Color::ForestGreen(34, 139, 34);
const Color Color::Fuchsia(255, 0, 255);
const Color Color::Gainsboro(220, 220, 220);
const Color Color::GhostWhite(248, 248, 255);
const Color Color::Gold(255, 215, 0);
const Color Color::GoldenRod(218, 165, 32);
const Color Color::Gray(128, 128, 128);
const Color Color::Green(0, 128, 0);
const Color Color::GreenYellow(173, 255, 47);
const Color Color::HoneyDew(240, 255, 240);
const Color Color::HotPink(255, 105, 180);
const Color Color::IndianRed(205, 92, 92);
const Color Color::Indigo(75, 0, 130);
const Color Color::Ivory(255, 255, 240);
const Color Color::Khaki(240, 230, 140);
const Color Color::Lavender(230, 230, 250);
const Color Color::LavenderBlush(255, 240, 245);
const Color Color::LawnGreen(124, 252, 0);
const Color Color::LemonChiffon(255, 250, 205);
const Color Color::LightBlue(173, 216, 230);
const Color Color::LightCoral(240, 128, 128);
const Color Color::LightCyan(224, 255, 255);
const Color Color::LightGoldenRodYellow(250, 250, 210);
const Color Color::LightGray(211, 211, 211);
const Color Color::LightGreen(144, 238, 144);
const Color Color::LightPink(255, 182, 193);
const Color Color::LightSalmon(255, 160, 122);
const Color Color::LightSeaGreen(32, 178, 170);
const Color Color::LightSkyBlue(135, 206, 250);
const Color Color::LightSlateGray(119, 136, 153);
const Color Color::LightSteelBlue(176, 196, 222);
const Color Color::LightYellow(255, 255, 224);
const Color Color::Lime(0, 255, 0);
const Color Color::LimeGreen(50, 205, 50);
const Color Color::Linen(250, 240, 230);
const Color Color::Magenta(255, 0, 255);
const Color Color::Maroon(128, 0, 0);
const Color Color::MediumAquaMarine(102, 205, 170);
const Color Color::MediumBlue(0, 0, 205);
const Color Color::MediumOrchid(186, 85, 211);
const Color Color::MediumPurple(147, 112, 219);
const Color Color::MediumSeaGreen(60, 179, 113);
const Color Color::MediumSlateBlue(123, 104, 238);
const Color Color::MediumSpringGreen(0, 250, 154);
const Color Color::MediumTurquoise(72, 209, 204);
const Color Color::MediumVioletRed(199, 21, 133);
const Color Color::MidnightBlue(25, 25, 112);
const Color Color::MintCream(245, 255, 250);
const Color Color::MistyRose(255, 228, 225);
const Color Color::Moccasin(255, 228, 181);
const Color Color::NavajoWhite(255, 222, 173);
const Color Color::Navy(0, 0, 128);
const Color Color::OldLace(253, 245, 230);
const Color Color::Olive(128, 128, 0);
const Color Color::OliveDrab(107, 142, 35);
const Color Color::Orange(255, 165, 0);
const Color Color::OrangeRed(255, 69, 0);
const Color Color::Orchid(218, 112, 214);
const Color Color::PaleGoldenRod(238, 232, 170);
const Color Color::PaleGreen(152, 251, 152);
const Color Color::PaleTurquoise(175, 238, 238);
const Color Color::PaleVioletRed(219, 112, 147);
const Color Color::PapayaWhip(255, 239, 213);
const Color Color::PeachPuff(255, 218, 185);
const Color Color::Peru(205, 133, 63);
const Color Color::Pink(255, 192, 203);
const Color Color::Plum(221, 160, 221);
const Color Color::PowderBlue(176, 224, 230);
const Color Color::Purple(128, 0, 128);
const Color Color::RebeccaPurple(102, 51, 153);
const Color Color::Red(255, 0, 0);
const Color Color::RosyBrown(188, 143, 143);
const Color Color::RoyalBlue(65, 105, 225);
const Color Color::SaddleBrown(139, 69, 19);
const Color Color::Salmon(250, 128, 114);
const Color Color::SandyBrown(244, 164, 96);
const Color Color::SeaGreen(46, 139, 87);
const Color Color::SeaShell(255, 245, 238);
const Color Color::Sienna(160, 82, 45);
const Color Color::Silver(192, 192, 192);
const Color Color::SkyBlue(135, 206, 235);
const Color Color::SlateBlue(106, 90, 205);
const Color Color::SlateGray(112, 128, 144);
const Color Color::Snow(255, 250, 250);
const Color Color::SpringGreen(0, 255, 127);
const Color Color::SteelBlue(70, 130, 180);
const Color Color::Tan(210, 180, 140);
const Color Color::Teal(0, 128, 128);
const Color Color::Thistle(216, 191, 216);
const Color Color::Tomato(255, 99, 71);
const Color Color::Turquoise(64, 224, 208);
const Color Color::Violet(238, 130, 238);
const Color Color::Wheat(245, 222, 179);
const Color Color::White(255, 255, 255);
const Color Color::WhiteSmoke(245, 245, 245);
const Color Color::Yellow(255, 255, 0);
const Color Color::YellowGreen(154, 205, 50);

}
