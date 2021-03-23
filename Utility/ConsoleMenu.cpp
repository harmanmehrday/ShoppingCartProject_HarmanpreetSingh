#include "ConsoleMenu.h"
using std::cout;
using std::endl;
using std::string;
using std::to_string;
using namespace userInput;
namespace consoleMenu
{
	// Static

	const string ConsoleMenu::separator = "";

	std::string ConsoleMenu::getSeparator()
	{
		return separator;
	}

	// Instance

	ConsoleMenu::ConsoleMenu(std::string title, std::string message, std::vector<std::string> options)
	{
		this->title = title;
		this->message = message;
		this->options = options;
	}

	string ConsoleMenu::getTitle()
	{
		return title;
	}

	string ConsoleMenu::getMessage()
	{
		return message;
	}

	string ConsoleMenu::getOption(int index)
	{
		if (index >= 0 && index < options.size())
			return options[index];
		else
			return string();
	}

	int ConsoleMenu::getSize()
	{
		return options.size();
	}

	void ConsoleMenu::setTitle(string title)
	{
		this->title = title;
	}

	void ConsoleMenu::setMessage(string message)
	{
		this->message = message;
	}

	void ConsoleMenu::setOptions(std::vector<std::string> options)
	{
		this->options = options;
	}

	void ConsoleMenu::displayTitle()
	{
		if (title.length() > 0)
			cout << title << endl << endl;
	}

	void ConsoleMenu::displayMessage()
	{
		if (message.length() > 0)
			cout << message << endl << endl;
	}

	void ConsoleMenu::displaySeparator()
	{
		cout << separator << endl;
	}

	void ConsoleMenu::displayOptions()
	{
		for (int i = 0; i < options.size(); i++)
			cout << "    " << (i + 1) << " - " << options[i] << endl;
		cout << endl;
	}

	int ConsoleMenu::displayAndGetSelection()
	{
		displaySeparator();
		displayTitle();
		displayOptions();

		int min = 1;
		int max = options.size();

		int userInt;
		if (message.length() > 0)
			userInt = readInt(min, max, message);
		else
			userInt = readInt(min, max);

		// return option number (one-based numbering)
		return userInt;
	}

	int ConsoleMenu::displayAndGetSelectionIndex()
	{
		// return option index (zero-based numbering)
		return displayAndGetSelection() - 1;
	}
}
