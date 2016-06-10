#include <visual2darray.hpp>

using namespace visual2darray;

const int XPlayer = 1, OPlayer = 2;
int currentPlayer;

bool isGameOver(Visual2DArray& game)
{
    // Check rows
    if(game[0][0] != 0 && game[0][0] == game[0][1] && game[0][0] == game[0][2]) { // 1st row
        game[0][0] += 10;
        game[0][1] += 10;
        game[0][2] += 10;
        return true;
    }
    if(game[1][0] != 0 && game[1][0] == game[1][1] && game[1][0] == game[1][2]) { // 2nd row
        game[1][0] += 10;
        game[1][1] += 10;
        game[1][2] += 10;
        return true;
    }
    if(game[2][0] != 0 && game[2][0] == game[2][1] && game[2][0] == game[2][2]) { // 3rd row
        game[2][0] += 10;
        game[2][1] += 10;
        game[2][2] += 10;
        return true;
    }

    // Check columns
    if(game[0][0] != 0 && game[0][0] == game[1][0] && game[0][0] == game[2][0]) { // 1st col
        game[0][0] += 10;
        game[1][0] += 10;
        game[2][0] += 10;
        return true;
    }
    if(game[0][1] != 0 && game[0][1] == game[1][1] && game[0][1] == game[2][1]) { // 2nd col
        game[0][1] += 10;
        game[1][1] += 10;
        game[2][1] += 10;
        return true;
    }
    if(game[0][2] != 0 && game[0][2] == game[1][2] && game[0][2] == game[2][2]) { // 3rd col
        game[0][2] += 10;
        game[1][2] += 10;
        game[2][2] += 10;
        return true;
    }

    // Check diagonals
    if(game[0][0] != 0 && game[0][0] == game[1][1] && game[0][0] == game[2][2]) { //  \ diagonal
        game[0][0] += 10;
        game[1][1] += 10;
        game[2][2] += 10;
        return true;
    }
    if(game[2][0] != 0 && game[2][0] == game[1][1] && game[2][0] == game[0][2]) { //  / diagonal
        game[2][0] += 10;
        game[1][1] += 10;
        game[0][2] += 10;
        return true;
    }

    return false;
}

bool isACatGame(Visual2DArray& game)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(game[i][j] == 0) return false;

    return true;
}

void mousefn(Visual2DArray& game)
{
    int r = game.clickedRow();
    int c = game.clickedCol();
    if(game[r][c] != 0) {                // Clicked position is not empty
        game.beep();
        return;
    }

    game[r][c] = currentPlayer;         //

    game.clearMessage();
    if(isGameOver(game)) {
        game.alert("You Win!");
        game.restart();
    } else if(isACatGame(game)) {
        game.clearMessage();
        game << ("Cat game! We have a tie... F2: Play again");
    } else {
        if(currentPlayer == OPlayer) {
            currentPlayer = XPlayer;
            game << "It's player X turn";
        } else {
            currentPlayer = OPlayer;
            game << "It's player O turn";
        }
    }
}

void reset(Visual2DArray& game)
{
    game.fill(0);                       // Clear all cells
    currentPlayer = XPlayer;            // X starts
    game.clearMessage();
    game << "It's player X turn";                 // Show Message
}

int main()
{
    Visual2DArray game {3, 3};                 // 3x3

    game.title("TicTacToe");                // Set window title
    game.cellSize(100, 100);                // 100px x 100px
    game.cellColor(Color::BlueViolet);
    game.backgroundColor(Color::DarkRed);
    game.messageColor(Color::Yellow);
    game.borderSize(1);                     // 1px grid border (external & internal)
    // Set the image for each possible cell value
    game.setImage(0, "nada.png");      // If game[x][y]==0, show this image in x,y position
    game.setImage(1, "X.png");
    game.setImage(11, "Xwins.png");
    game.setImage(2, "O.png");
    game.setImage(12, "Owins.png");

    game.onMouseClicked(mousefn);            // The "mouse_function" function is called when you click the mouse
    game.onStart(reset);                    // When game is started/restarted

    game.run();                                      // Show the window and run the game
}

