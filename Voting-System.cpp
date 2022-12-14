#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
using namespace std;

int john, mark, mary, susan, counter;        //GLOBAL VARIABLES TO PROTECT VARIRABLES FROM BEING REDECLARED AND WIPED DURING RECURSION
set<int> s;
int a[1000];

void endOfVote();

void NRCCheck()
{
    double NRC;

    cout << "\nEnter your NRC number to take part in this poll: ";
    cin >> NRC;

    if (to_string(int(NRC)).length() == 9)  //CHECKS TO SEE IF NRC HAS MET THE STANDARD NRC NUMBER LENGTH
    {
            a[counter] = NRC;       // [1] FROM HERE
            ++counter; //COUNTER CHECKS FOR THE NUMBER OF ELEMENTS IN THE ARRAY
            s.insert(NRC);

            if (counter != s.size())
            {
                --counter;
                a[counter] = 0;     //[2] TO HERE, THE PROGRAM CREATES A SET AND AN ARRAY. THEN IT WILL COMPARE THEIR LENGTHS TO PREVENT REPETITION
                cout << "This NRC number has already been used." << endl;
                NRCCheck();
            }
            else
            {
                cout << "Valid input.\n";
            }

    }
    else
    {
        cout << "Invalid input. Enter a valid NRC number." << endl;
        NRCCheck();
    }
}

void vote()
{
    int choice;

    cout << "\nChoose the candidate you wish to vote for by selecting the corresponding value below:" << endl;

    cout << "Enter '1' for John.\n"
         << "Enter '2' for Mark.\n"
         << "Enter '3' for Mary.\n"
         << "Enter '4' for Susan." << endl;

    cin >> choice;

    switch (choice)
    {
        case 1:
            ++john;
            break;
        case 2:
            ++mark;
            break;
        case 3:
            ++mary;
            break;
        case 4:
            ++susan;
            break;
        default:
            cout << "Invalid choice. Please enter a valid digit." << endl;
            vote();
            break;
    }

    endOfVote();
}


int main()
{
    cout << "Welcome to this poll. You will use this poll to vote for your desired student president." << endl;

    NRCCheck();
    vote();
    endOfVote();

    return 0;
}

void endOfVote()
{
    int choice2;
    cout << "\nWould you like to end the poll or allow another person to enter their vote?" << endl;
    cout << "Enter '0' to view total votes so far.\n"
         << "Enter '1' to allow another person to enter their vote.\n"
         << "Enter '2' to end the program." << endl;

    cin >> choice2;

    switch (choice2)
    {
        case 0:
            cout << "\nTotal votes for John: " << john
                 << "\nTotal votes for Mark: " << mark
                 << "\nTotal votes for Mary: " << mary
                 << "\nTotal votes for Susan: " << susan << "\n" << endl;
                 endOfVote();

        case 1:
            NRCCheck(); //ALLOWS ANOTHER USER TO VOTE ON POLL
            vote();

        case 2:         //ALLOWS USER TO LEAVE POLL
            cout << "\nTotal votes for John: " << john
                 << "\nTotal votes for Mark: " << mark
                 << "\nTotal votes for Mary: " << mary
                 << "\nTotal votes for Susan: " << susan << endl;
            exit(1);
    }
}

