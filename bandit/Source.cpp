#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_SYMBOLS = 5;
const char SYMBOLS[NUM_SYMBOLS] = { 'A', 'B', 'C', 'D', 'E' };

void spinReel(char& reel) 
{
    int randomIndex = rand() % NUM_SYMBOLS;
    reel = SYMBOLS[randomIndex];
}

bool checkWin(char reel1, char reel2, char reel3) 
{
    return (reel1 == reel2 && reel2 == reel3);
}

void displayReels(char reel1, char reel2, char reel3) 
{
    cout << "Reels: [" << reel1 << " | " << reel2 << " | " << reel3 << "]" << endl;
}

int main() 
{
    srand(time(0));

    char reel1, reel2, reel3;

    cout << "Welcome to One-Armed Bandit!" << endl;
    cout << "Press Enter to spin the reels..." << endl;

    while (true) 
    {
        cin.get();

        spinReel(reel1);
        spinReel(reel2);
        spinReel(reel3);

        displayReels(reel1, reel2, reel3);

        if (checkWin(reel1, reel2, reel3)) 
        {
            cout << "Congratulations! You won!" << endl;
        }
        else 
        {
            cout << "Try again!" << endl;
        }

        cout << "Press Enter to spin again or type 'q' to quit..." << endl;
        char input = cin.get();
        if (input == 'q' || input == 'Q') 
        {
            break;
        }
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
