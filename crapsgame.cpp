/**
 * This program will simuluate a craps game.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    bool isGameRunning = true ,
         isGameWon = false,
         isRValid = false,
         isSecondRollValid = false ,
         NewGameValid = true;

    int dice; //to hold the dice rolls
    int point; // to hold the point
    char r; //to hold keyboard input and for rolls

    do
    {
       while (isRValid == false)
       {
           cout << "Please press R to roll the dice!\n";
           cin >> r;
           if (r == 'R' || r == 'r')
           {
               cout << "Dice Rolled!\n";
               isRValid = true;
           }
           else
           {
               cout << "Invalid Entry!\nPlease press R next time!\n";
           }
       }
       srand(time(0));
       dice = (1 + rand() % 6) + (1 + rand() %6);
       cout << "You rolled : " << dice << endl;
        if (dice == 7 || dice == 11)
        {
            cout << "Player Won!\n";
            isGameWon = true;
        }
        else if (dice == 2 || dice == 3 || dice == 12)
        {
            cout << "House Won!\n";
            isGameWon = true;
        }
        else
        {
            point = dice;
            isRValid = false;
            isSecondRollValid = true;
        }
       while (isSecondRollValid == true)
       {
           while (isRValid == false)
            {
                cout << "Please press R or to roll the dice!\n";
                cin >> r;
                if (r == 'R' || r == 'r')
                {
                    cout << "Dice Rolled!";
                    isRValid = true;
                }
                else
                {
                    cout << "Invalid Entry!\nPlease press R next time!\n";
                }
            }
            srand(time(0));
            dice = (1 + rand() % 6) + (1 + rand() %6);
            cout << "You rolled : " << dice << endl;
           if (dice == 7)
           {
               cout << "Player Loses!\n";
               isRValid = true;
               isGameWon = true;
               isSecondRollValid = false;
           }
           else if (point == dice)
           {
               cout << "Player Wins!!\n";
               isRValid = true;
               isGameWon = true;
               isSecondRollValid = false;
           }
           else
           {
               isRValid = false;
           }
       }
       NewGameValid = true;

       while (NewGameValid)
       {
           cout << "Would you like to play again?\n";
           cout << "Please Press Y or N.\n";
           cin >> r;
           if ( r== 'Y' || r == 'y')
           {
               cout << "new game!\n";
               isRValid = false;
               NewGameValid = false;
               isSecondRollValid = false;
           }
           else if ( r == 'n' || r == 'N')
           {
               cout << "Thank you for playing!\n";
               NewGameValid = false;
               isGameRunning = false;
           }
           else
           {
               cout << "Invalid Entry!\n";
               cout << "Please enter Y or N or y or n!\n";
           }

       }

    }
    while (isGameRunning);
    return 0;
}
