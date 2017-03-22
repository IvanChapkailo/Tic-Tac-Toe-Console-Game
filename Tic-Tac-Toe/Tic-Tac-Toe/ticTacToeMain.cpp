//Tic-Tac-Toe
//This is simple console game Tic-Tac-Toe
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

void instructions();//displays the rules
char askYesNo(char question);//Takes question and return answer "yes" or "no"
int askNumber(string question, int hight, int low = 0);//asks a number of ranges and returns the number of ranges of low-hight
char humanPiece();//determine which figures will play user
char opponent(char piece); //knowing what figures will play the user and determines the shape computer figure
void displayBoard(const vector<char>& board);//displays field
char winner(const vector<char>& board);//determine who is winner, returns O, X, T (no winner) or N (two players have a chance to win)
bool isLegal(const vector<char>& board, int move);//determines whether the move made by the rules
int humanMove(const vector<char>& board, char human);//determine user's move. Takes field and figure of user, returns user's move
int computerMove(const vector<char>& board, char computer);//determine computer's move. Takes field and figure of computer, returns computer's move
void announceWinner(char winner, char computer, char human);//congratulates the winner. Takes winner's side, figure and computer's figure

int main()
{
	//TODO
}

void instructions()
{
	//TODO
}

char askYesNo(char question)
{
	//TODO
}

int askNumber(string question, int hight, int low = 0)
{
	//TODO
}

char humanPiece()
{
	//TODO
}

char opponent(char piece)
{
	//TODO
}

void displayBoard(const vector<char>& board)
{
	//TODO
}

char winner(const vector<char>& board)
{
	//TODO
}

bool isLegal(const vector<char>& board, int move)
{
	//TODO
}

int humanMove(const vector<char>& board, char human)
{
	//TODO
}

int computerMove(const vector<char>& board, char computer)
{
	//TODO
}

void announceWinner(char winner, char computer, char human)
{
	//TODO
}