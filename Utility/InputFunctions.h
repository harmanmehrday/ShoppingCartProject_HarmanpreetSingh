#pragma once
#include<iostream>
#include<string>

namespace userInput {

	int readInt();
	int readInt(std::string instructions);
	int readInt(int min, int max);
	int readInt(int min, int max, std::string instructions);

	double readDouble();
	double readDouble(std::string instructions);
	double readDouble(double min, double max);
	double readDouble(double min, double max, std::string instructions);

	char readChar();
	char readChar(std::string instructions);

	std::string readWord();
	std::string readWord(std::string instructions);

	std::string readLine();
	std::string readLine(std::string instructions);

	bool readBool();
	bool readBool(std::string instructions);
}