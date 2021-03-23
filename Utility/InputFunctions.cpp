#include "InputFunctions.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::getline;

namespace userInput {
#pragma region readInt Functions
	int readInt()
	{
		int userInt;
		cin >> userInt;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n\t\tValue must be a whole number! Please try again : ";
			cin >> userInt;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return userInt;
	}

	int readInt(string instructions)
	{
		cout << instructions;
		return readInt();
	}

	int readInt(int min, int max)
	{
		int toReturn;
		cout << "("<< min << "-" << max <<") : ";
		toReturn = readInt();
		while (toReturn < min || toReturn > max)
		{
			cout << "\n\t\tError: number was outside limits. Try again : ";
			toReturn = readInt();
		};
		return toReturn;
	}

	int readInt(int min, int max, string instructions)
	{
		cout << instructions;
		return readInt(min, max);
	}
#pragma endregion

#pragma region readDouble Functions
	double readDouble()
	{
		double userDouble;
		cin >> userDouble;
		while (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n\t\tValue must be a real number! Please try again : ";
			cin >> userDouble;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return userDouble;
	}

	double readDouble(string instructions)
	{
		cout << instructions;
		return readDouble();
	}

	double readDouble(double min, double max)
	{
		double userDouble;
		cout << "between " << min << " and " << max << " : ";
		userDouble = readDouble();
		while (userDouble < min || userDouble > max)
		{
			cout << "\n\t\tError: number was outside limits. Try again : ";
			userDouble = readDouble();
		};
		return userDouble;
	}

	double readDouble(double min, double max, string instructions)
	{
		cout << instructions;
		return readDouble(min, max);
	}
#pragma endregion

#pragma region readChar Functions
	char readChar()
	{
		char userChar;
		cin >> userChar;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return userChar;
	}
	char readChar(string instructions)
	{
		cout << instructions;
		return readChar();
	}
#pragma endregion

#pragma region readString Functions
	string readWord()
	{
		string userString;
		cin >> userString;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return userString;
	}
	string readWord(string instructions)
	{
		cout << instructions;
		return readWord();
	}
	string readLine()
	{
		string userString;
		getline(cin, userString);
		return userString;
	}
	string readLine(string instructions)
	{
		cout << instructions;
		return readLine();
	}
#pragma endregion

#pragma region readBool Functions
	bool readBool()
	{
		int toReturn;
		int min = 0, max = 1;
		toReturn = readInt();
		while (toReturn < min || toReturn > max)
		{
			cout << "\n\t\tError: number was outside limits. Try again : ";
			toReturn = readInt();
		};
		return toReturn;
	}
	bool readBool(string instructions)
	{
		cout << instructions;
		return readBool();
	}
#pragma endregion
}