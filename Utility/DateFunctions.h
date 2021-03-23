#pragma once
#include<iostream>
#include<string>

class Date {
private:
	int year, month, day;
public:
	Date(int year,int month, int day);
	Date();

	int getYear();
	int getMonth();
	int getDay();

	int getYearsUntil(Date);
	int getMonthsUntil(Date);
	int getDaysUntil(Date);

	std::string getMonthString();
	int getNumberOfDaysInMonth();
	bool isLeapYear();

	std::string toString();
	void display();
	static Date todaysDate();
};