#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "InputFunctions.h"

namespace consoleMenu
{
	class ConsoleMenu
	{
	private:
		static const std::string separator;
	public:
		static std::string getSeparator();

	private:
		std::string title;
		std::string message;
		std::vector<std::string> options;

	public:
		ConsoleMenu(std::string title, std::string message, std::vector<std::string> options);

		std::string getTitle();
		std::string getMessage();
		std::string getOption(int index);
		int getSize();

		void setTitle(std::string title);
		void setMessage(std::string message);
		void setOptions(std::vector<std::string> options);

		void displayTitle();
		void displayMessage();
		void displaySeparator();
		void displayOptions();

		int displayAndGetSelection();
		int displayAndGetSelectionIndex();
	};
}
