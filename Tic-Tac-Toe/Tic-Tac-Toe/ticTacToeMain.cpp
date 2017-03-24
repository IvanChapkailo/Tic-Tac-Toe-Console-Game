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
char askYesNo(string question);//Takes question and return answer "yes" or "no"
int askNumber(string question, int hight, int low = 0);//asks a number of ranges and returns the number of ranges of low-hight
char humanPiece();//determine which figures will play user
char opponent(char piece); //knowing what figures will play the user and determines the shape computer figure
void displayBoard(const vector<char>& board);//displays field
char winner(const vector<char>& board);//determine who is winner, returns O, X, T (no winner) or N (two players have a chance to win)
bool isLegal(int move, const vector<char>& board);//determines whether the move made by the rules
int humanMove(const vector<char>& board, char human);//determine user's move. Takes field and figure of user, returns user's move
int computerMove(vector<char> board, char computer);//determine computer's move. Takes field and figure of computer, returns computer's move
void announceWinner(char winner, char computer, char human);//congratulates the winner. Takes winner's side, figure and computer's figure

int main()
{
	char playAgain = 'n';
	do
	{
		int move;
		const int NUM_SQUARES = 9;
		vector<char> board(NUM_SQUARES, EMPTY);
		instructions();
		char human = humanPiece();
		char computer = opponent(human);
		char turn = X;
		displayBoard(board);
		while (winner(board) == NO_ONE)
		{
			if (turn == human)
			{
				move = humanMove(board, human);
				board[move] = human;
			}
			else
			{
				move = computerMove(board, computer);
				board[move] = computer;
			}
			displayBoard(board);
			turn = opponent(turn);
		}
		announceWinner(winner(board), computer, human);
		//play again
		cout << "Play again? (y/n) - ";
		cin >> playAgain;
		if (playAgain == 'y')
		{
			system("cls");
		}
		else
			break;
	} while (playAgain == 'y');
	if (playAgain == 'n')
	{
		cout << "Goodbye, craven human." << endl;
		return 0;
	}
}

void instructions()
{
	cout << "\t\tWelcome to Tic-Tac-Toe Console Game" << endl;
	cout << "...and you will lose here" << endl;
	cout << "Make your move known by entering a number 0 - 8. The number corresponds to the desired board position, as illustrated:" << endl;
	cout << "\t\t 0 | 1 | 2 " << endl;
	cout << "\t\t-----------" << endl;
	cout << "\t\t 3 | 4 | 5 " << endl;
	cout << "\t\t-----------" << endl;
	cout << "\t\t 6 | 7 | 8 " << endl;
	cout << "Prepare youself, human. The battle is about to begin.\n" << endl;
}

char askYesNo(string question)
{
	char response;
	do
	{
		cout << question << "(y / n) - ";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int askNumber(string question, int hight, int low)
{
	int number;
	do
	{
		cout << question << "(" << low << "..." << hight << ") - ";
		cin >> number;
	} while (number > hight || number < low);
	return number;
}

char humanPiece()
{
	char goFirst = askYesNo("Do you require the first move? ");
	if (goFirst == 'y')
	{
		cout << "Then take the first move. You will need it." << endl;
		return X;
	}
	else
	{
		cout << "Your bravery will be your undoing. I will go first." << endl;
		return O;
	}
}

char opponent(char piece)
{
	if (piece == X)
		return O;
	else
		return X;
}

void displayBoard(const vector<char>& board)
{
	cout << "\t\t" << " " << board[0] << " | " << board[1] << " | " << board[2]  << endl;
	cout << "\t\t-----------" << endl;
	cout << "\t\t" << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
	cout << "\t\t-----------" << endl;
	cout << "\t\t" << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

char winner(const vector<char>& board)
{
	//all possible winning fields
	const int WINNING_ROWS[8][3] = { {0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6} };
	const int TOTAL_ROWS = 8;
	//if here is three equal values in some row (and it not equal EMPTY) the winner is defined
	for (int row = 0; row < TOTAL_ROWS; ++row)
	{
		if ((board[WINNING_ROWS[row][0]] != EMPTY) && (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]])
			&& (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]))
		{
			return board[WINNING_ROWS[row][0]];
		}
	}
	//if winner is not defined verify whether tie (if empty cells left on field)
	if (count(board.begin(), board.end(), EMPTY) == 0)
		return TIE;
	//if winner is not defined but it is not tie, game continue
	return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board)
{
	return (board[move] == EMPTY);
}

int humanMove(const vector<char>& board, char human)
{
	int move = askNumber("Where will you move?", (board.size() - 1));
	while (!isLegal(move, board))
	{
		cout << "\nThat square is already occupied, foolish human." << endl;
		move = askNumber("Where will you move?", (board.size() - 1));
	}
	cout << "Fine..." << endl;
	return move;
}

//strategy for computer moving operation:
//1. if computer can make winning move - do this move
//2. else if human can win in next move - block this move
//3. else occupy best cell (best - center cell, less the best - corner cells and other is worse)
int computerMove(vector<char> board, char computer)
{
	unsigned int move = 0;
	bool found = false;
	//1. if computer can make winning move - do this move
	while (!found && move < board.size())
	{
		if (isLegal(move, board))
		{
			board[move] = computer;
			found = winner(board) == computer;
			board[move] = EMPTY;
		}
		if (!found)
			++move;
	}
	//2. else if human can win in next move - block this move
	if (!found)
	{
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size())
		{
			if (isLegal(move, board))
			{
				board[move] = human;
				found = winner(board) == human;
				board[move] = EMPTY;
			}
			if (!found)
			{
				++move;
			}
		}
	}
	//3. else occupy best cell (best - center cell, less the best - corner cells and other is worse)
	if (!found)
	{
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4,0,2,6,8,1,3,5,7 };
		//choose optimal free cell
		while (!found && i < board.size())
		{
			move = BEST_MOVES[i];
			if (isLegal(move, board))
			{
				found = true;
			}
			++i;
		}
	}
	cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human)
{
	if (winner == computer)
	{
		cout << winner << "'s won!" << endl;
		cout << "As I predicted, human, I am triumphant once more -- proof that computers are superior to humans in all regards." << endl;
	}
	else if (winner == human)
	{
		cout << winner << "'s won!" << endl;
		cout << "No, no! It cannot be! Somehow you tricked me, human." << endl;
		cout << "But never again! I, the computer, so swear it! Get it, motherf***er?" << endl;
	}
	else
	{
		cout << "It's a tie." << endl;
		cout << "You were most lucky, human, and somehow manage to tie me." << endl;
		cout << "Celebrate for this the best you will ever achieve." << endl;
	}
}
