#include <iostream>
#include <string>
#include <map>
using namespace std;

//Spotify Time Tracker
int main()
{
     //Keep count of how many times each genre is played
    map<string, int> genreCount =
    {
        {"Pop", 0},
        {"Rock", 0},
        {"Jazz", 0},
        {"Hip-Hop", 0}
    };

    int choice;         //To store what user selects
    string topGenre;    //To store the most listened genre
    int maxCount = 0;   //To store the highest play count

     // menu until user chooses option 6 which is Exit
    do
    {
        cout << "\n=== Spotify Genre Player ===\n";
        cout << "1. Play Pop Song \n";
        cout << "2. Play Rock Song \n";
        cout << "3. Play Jazz Song \n";
        cout << "4. Play Hip-Hop Song \n";
        cout << "5. Skip Song \n";
        cout << "6. Show Most Listened Genre & Exit \n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Now playing: Pop Song \n";
            genreCount["Pop"]++;
            break;
        case 2:
            cout << "Now playing: Rock Song \n";
            genreCount["Rock"]++;
            break;
        case 3:
            cout << "Now playing: Jazz Song \n";
            genreCount["Jazz"]++;
            break;
        case 4:
            cout << "Now playing: Hip-Hop Song \n";
            genreCount["Hip-Hop"]++;
            break;
        case 5:
            cout << "Skipped song \n";  //Nothing counted
            break;
        case 6:
            //Show all results
            cout << "\n=== Your Spotify Wrapped ===\n";
            for (auto &g : genreCount)
            {
                cout << g.first << ": " << g.second << " songs\n";
                if (g.second > maxCount)
                {
                    maxCount = g.second;    //Save highest number
                    topGenre = g.first;     //Save top genre
                }
            }
               //If no songs were played
            if (maxCount == 0)
            {
                cout << "You did not listen to any songs \n";
            }
            else
            {
                cout << "\nYour top genre is: " << topGenre
                     << " with " << maxCount << " songs!\n";
            }
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, try again.\n"; //Wrong input
        }
    }
    while (choice != 6);    //Stop only when user chooses 6

    return 0;
}