#include <visual2darray.hpp>

using namespace visual2darray;

// Mouse callback function
void mousefn(Visual2DArray& tab) 
{
    int c = tab.clickedCol();
    int r = tab.clickedRow();
    tab[r][c] = ~tab[r][c];
}

// Keyboard callback function
void kbdfn(Visual2DArray& tab)
{ 
    if (tab.lastKey() == Key::F1)
        tab.alert("High School USA Font by AbdulMakesFonts");
}

// Start callback function: on init or F2 key
void startfn(Visual2DArray& tab) 
{
    tab[0][0] = ~'H';
    tab[0][1] = ~'E';
    tab[0][2] = ~'L';
    tab[0][3] = ~'L';
    tab[0][4] = ~'O';
    tab[0][5] = ~',';
    tab[1][0] = ~'W';
    tab[1][1] = ~'O';
    tab[1][2] = ~'R';
    tab[1][3] = ~'L';
    tab[1][4] = ~'D';
    tab[1][5] = ~'!';
}

int main()
{
    Visual2DArray tab { 2, 6 }; // 2x2 board

    tab.title("Hello, Visual2DArray");
    tab.cellSize(60, 60); // 60px X 60px
    tab.borderSize(1); // 2px

    // Images in "img/" folder
    tab.setImage('H', "H.png");
    tab.setImage('E', "E.png");
    tab.setImage('L', "L.png");
    tab.setImage('O', "O.png");
    tab.setImage(',', "comma.png");
    tab.setImage('W', "W.png");
    tab.setImage('R', "R.png");
    tab.setImage('D', "D.png");
    tab.setImage('!', "exclamation.png");
    // Reversed
    tab.setImage(~'H', "blank.png");
    tab.setImage(~'E', "blank.png");
    tab.setImage(~'L', "blank.png");
    tab.setImage(~'O', "blank.png");
    tab.setImage(~',', "blank.png");
    tab.setImage(~'W', "blank.png");
    tab.setImage(~'R', "blank.png");
    tab.setImage(~'D', "blank.png");
    tab.setImage(~'!', "blank.png");

    tab.cellColor(Color::White); // Named colors
    tab.backgroundColor("#bababa"); // RGB hex

    tab.messageColor(0X02, 0x02, 0x02); // (R, G, B)
    tab << "Click to flip. F2: Restart"; // Show in status bar

    // Register calbacks
    tab.onStart(startfn);
    tab.onMouseClicked(mousefn);
    tab.onKeyPressed(kbdfn);

    // Show & go!
    tab.run();
}
