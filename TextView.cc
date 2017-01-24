#include "TextView.h"
#include "View.h"
#include "iostream"
using namespace std;

TextView::TextView(int rows, int columns) : rows(rows), columns(columns){
	for (int i = 0; i < rows; ++i)
	{
		vector<char>row;
		for (int j = 0; j < columns; ++j)
		{
			row.emplace_back(' ');
		}
		boardDisplay.emplace_back(row);
	}
}


void TextView::notify(int row, int column, char ch)
{
	boardDisplay[row][column] = ch;
}

void TextView::update(int level, int score, int hiScore, char ch){
	cout << "Level: " << level << endl;
	cout << "Score: " << score << endl;
	cout << "Hiscore: " << hiScore << endl;	
	cout << "____________" << endl;

	for(int i = 0; i < rows; ++i) // Displaying the boards
	{
		cout << "|";
		for(int j = 0; j < columns; ++j)
		{
			cout << boardDisplay[i][j];
		}
		cout << "|" << endl;
	}
	cout << "¯¯¯¯¯¯¯¯¯¯¯¯" << endl;
	cout << "Next:" << endl;

	if(ch == 'I') // printing out the next block
	{
		cout << "IIII" << endl;
	}
	else if(ch == 'J')
	{
		cout << "J" << endl;
		cout << "JJJ";
	}
	else if(ch == 'L')
	{
		cout << "  L" << endl;
		cout << "LLL";
	}
	else if(ch == 'O')
	{
		cout << "OO" << endl;
		cout << "OO";
	}
	else if(ch == 'S')
	{
		cout << " SS" << endl;
		cout << "SS";
	}
	else if(ch == 'T')
	{
		cout << "TTT" << endl;
		cout << " T";
	}
	else if(ch == 'Z')
	{
		cout << "ZZ" << endl;
		cout << " ZZ";
	}
	else if(ch == '*')
	{
		cout << "*" << endl;
	}
	else if(ch == 'N'){
		cout << "   N" << endl;
		cout << "  N" << endl;
		cout << " N" << endl;
		cout << "N" << endl;
	}
	else if(ch == 'C'){
		cout << " C" << endl;
		cout << "CCC" << endl;
		cout << " C" << endl;
	}
	else if(ch == 'E') 
	{
		cout << "No more blocks on this level" << endl; 
	}
	cout << endl;
}


