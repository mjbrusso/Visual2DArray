#include <visual2darray.hpp>

using namespace visual2darray;

int previousRow, previousCol, reversedCards, matchCount, attemptsCount;

void mousefn(Visual2DArray& game)
{
    int r = game.clickedRow();
    int c = game.clickedCol();

    if(game[r][c] < 10) {          // The card isn't flipped
        game[r][c] += 10;          // Flip it
        reversedCards++;
        if(reversedCards == 2) {
            attemptsCount++;
            game.clearMessage();
            game << attemptsCount << " tentativas";
            reversedCards = 0;
            if(game[r][c] == game[previousRow][previousCol]) {  //  if two cards are equals.
                matchCount += 2;
                if(matchCount == game.size()) {            // Game end
                    game.clearMessage();
                    game << "Você venceu com " << attemptsCount << " tentativas!\nF2: Jogar novamente";
                }
            } else {                                    // Not match: "un"flip both cards
                game.beep();
                game.pause(500);                       // Wait a second (1000 ms)
                game[r][c] -= 10;                      //
                game[previousRow][previousCol] -= 10;
            }
        }
        previousRow = r;                                // Save last position
        previousCol = c;
    }
}

void reset(Visual2DArray& game)
{
    game.copy({
        {1, 1, 2, 2},         // 1: show the reverse side, 11: front side, ...
        {3, 3, 4, 4},
        {5, 5, 6, 6},
        {7, 7, 8, 8}
    });
    game.clearMessage();
    game << "Boa sorte";
    game.shuffle();                     // Shuffle the deck
    reversedCards = matchCount = attemptsCount = 0;
}

int main()
{
    Visual2DArray game(4, 4);                    // 4x4

    game.title("Matching Game");               // Set window title
    game.setImage(1, "blank.png");
    game.setImage(2, "blank.png");
    game.setImage(3, "blank.png");
    game.setImage(4, "blank.png");
    game.setImage(5, "blank.png");
    game.setImage(6, "blank.png");
    game.setImage(7, "blank.png");
    game.setImage(8, "blank.png");
    game.backgroundColor(Color::Green);

    game.onStart(reset);                    // When game is started/restarted, the "reset" function is called automatically
    game.onMouseClicked(mousefn);           // The "mousefn" function is called when you click in a cell

    game.run();                               // Show the window and run the game
}
