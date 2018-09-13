
// Name: Meredith Tufton
// Date: 2/3/2014
// Class: CS142
// Pledge: I have neither given nor received unauthorized aid on this program.
// Description: This program allows 2 players to play Rock, Paper, Scissors, Lizard, Spock.
// Input: Prompts the user for a weapon either rock, paper, scissors, lizard, or Spock.
// Output: The two weapons will be compared to determine the winner (or a tie) and the results will be displayed by the program.


#include <iostream>
#include <string>
#include <array>

using namespace std;

void print_greeting () ;
void print_gestures () ;
int input_throw ( string thrower, string opponent );
int calc_winner (int throw1, int throw2);

const string gestures [5] = {"Rock", "Paper", "Scissors", "Lizard", "Spock"};

// Creates an array of wins and losses

int winloss [5][5] = {  {2, 0, 1, 1, 0},
    {1, 2, 0, 0, 1},
    {0, 1, 2, 1, 0},
    {0, 1, 0, 2, 1},
    {1, 0, 1, 0, 2}};


int main()
{
    
    print_greeting();
    
    
    string name1, name2;
    cout << "Please enter Player 1's name: " << endl;
    
    cin >> name1;
    
    cout << "Please enter Player 2's name: " << endl;
    
    cin >> name2;
    
    //input throws
    
    int throw1, throw2;
    
    throw1 = input_throw(name1,name2);
    
    throw2 = input_throw(name2, name1);
    
    //calculate winner
    
    int winner;
    
    winner = calc_winner(throw1,throw2);
    
    
    
    while (winner == 2)
    {
        cout<< "It's a tie; both players will throw again." << endl;
        
        int throw1, throw2;
        
        throw1 = input_throw(name1,name2);
        
        throw2 = input_throw(name2, name1);
        
        
        winner= calc_winner (throw1,throw2 );
        
        
    }
    
    if (winner == 1)
    {
        cout<< gestures[throw1] << " defeats " << gestures [throw2] << "." <<endl;
        
        cout<< name1 << " defeats " << name2 << "." << endl;
        
    }
    
    else
    {
        cout<< gestures[throw2] << " defeats " << gestures [throw1] << "." <<endl;
        
        cout<< name2 << " defeats " << name1 << "." << endl;
        
    }
    
    
    
    return 0;
}


// Prints a greeting.
// No parameters or return values.

void print_greeting ()
{
    cout << "Welcome to Rock-Paper-Scissors-Lizard-Spock! " << endl;
    
}

// Prints a list of all gestures.
// No parameters or return values.

void print_gestures ()
{
    cout << "Choices are: " << endl;
    
    cout << "(0) Rock, (1) Paper, (2) Scissors, (3) Lizard, (4) Spock" << endl;
    
}

// Lets the user type in a number between 0 and 5.
// No parameters.
// Returns the number typed.

int input_throw ( string thrower, string opponent )
{
    cout << "It is " << thrower <<"'s turn." << endl;
    
    print_gestures ();
    
    cout << "No peeking, " << opponent << "." << endl ;
    
    int the_throw;
    
    cout << thrower << ", what is your throw? " << endl;
    
    cin >> the_throw;
    
    while (the_throw  < 0  || the_throw  >= 5 )
    {
        cout << "Invalid choice; try again." << endl;
        
        int the_throw;
        
        cout << thrower << ", what is your throw? " << endl;
        
        cin >> the_throw;
        
    }
    
    cout << thrower << " throws " << gestures[the_throw] << "." << endl;
    
    return the_throw;
}
// Calculates the winner of one round of the game.
// No parameters.
// Returns the winner as an integer: 1 if player 1 wins,
// 0 if player 1 loses, 2 if they tie.

int calc_winner (int throw1, int throw2)
{
    return winloss[throw1][throw2];
}

