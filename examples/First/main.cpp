#include <visual2darray.hpp>

using namespace visual2darray;

void mousefn(Visual2DArray& tab) // Mouse callback function
{
    int c = tab.clickedCol(); 
    int r = tab.clickedRow();
    tab[r][c] = !tab[r][c];
}

void startfn(Visual2DArray& tab) // Start callback function: on init or F2 key
{
    tab.fill(0); // Fill w/ 0's
    tab[0][0] = 1;
}

int main()
{
    Visual2DArray tab { 2, 2 }; // 2x2 board

    tab.title("Hello, World!");
    tab.cellSize(200, 200); // 200px X 200px
    tab.borderSize(2); // 2px

    tab.setImage(0, "off.png"); // Images in "img/" folder
    tab.setImage(1, "on.png");

    tab.cellColor(Color::White); // Named colors
    tab.backgroundColor("#FF0000"); // RGB hex

    tab.messageColor(00, 0xF0, 0xF0); // (R, G, B)
    tab << "Click to turn on/off"; // Show in status bar

    // Register calbacks
    tab.onStart(startfn);
    tab.onMouseClicked(mousefn);

    // Show & go!
    tab.run();
}
