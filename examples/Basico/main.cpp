#include <visual2darray.hpp>

using namespace visual2darray;

void mousefn(Visual2DArray& tab)
{
    int c = tab.clickedCol();          // Coluna clicada
    int r = tab.clickedRow();          // Linha clicada
    // Inverte o valor
    if(tab[r][c] == 1)
        tab[r][c] = 0;
    else
        tab[r][c] = 1;
}

void startfn(Visual2DArray& tab)
{
    tab.fill(0);     // Preenche com 0's
    tab[0][0] = 1;
}

int main()
{
    Visual2DArray tab{2, 2};

    tab.title("Exemplo");
    tab.cellSize(200, 200);
    tab.borderSize(2);

    tab.setImage(0, "off.png");
    tab.setImage(1, "on.png");

    tab.cellColor(Color::White);
    tab.backgroundColor("#FF0000");

    tab.messageColor(00, 80, 80);
    tab << "Clique para ligar/desligar";

    tab.onStart(startfn);
    tab.onMouseClicked(mousefn);
    tab.run();                   // Exibe
}
