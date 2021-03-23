#include "DateFunctions.h"
#include<ctime>
using std::string;
using std::endl;
using std:: cout;
using std::to_string;

Date::Date(int year,int month,int day){
	this->year = year;

	if (month < 1)month = 1;
	if (month > 12)month = 12;
	this->month = month;

	if (day < 1)day = 1;
	if (day > getNumberOfDaysInMonth())day = getNumberOfDaysInMonth();
	this->day = day;
}
Date::Date(){
	year = 2020;
	month = 4;
	day = 26;
}


int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}

string Date::getMonthString() {
	switch (month) {
		case 1: return "January";
		case 2: return "Febuary";
		case 3: return "March";
		case 4: return "April";
		case 5: return "May";
		case 6: return "June";
		case 7: return "July";
		case 8: return "August";
		case 9: return "September";
		case 10: return "October";
		case 11: return "November";
		case 12: return "December";
		default: return "Date Error!!!";
	}
}
int Date::getNumberOfDaysInMonth(){
	switch (month) {
		case 1: return 31;
		case 2: return isLeapYear()? 29 : 28;
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
		default: return 0;
	}
}

bool Date::isLeapYear() {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

string Date::toString() {
	return getMonthString() + " " + to_string(day) + ", " + std::to_string(year);
}

void Date::display() {
	std::cout << toString() << endl;
}

int Date::getYearsUntil(Date date2) {
	return getDaysUntil(date2) / 365;
}
int Date::getMonthsUntil(Date date2) {
	return getDaysUntil(date2)/30;
}
int Date::getDaysUntil(Date date2) {
	int diffYears = (year < date2.year) ? date2.year - year : year - date2.year;
	int diffMonths = (year < date2.year) ? date2.month - month : month - date2.month;
	int diffMonthsTrue = (diffYears * 12) + diffMonths;
	int diffDays = (year < date2.year) ? date2.day - day : day - date2.day;
	int diffDaysTrue = (diffMonthsTrue * 30) + diffDays;
	return diffDaysTrue;
}

Date Date::todaysDate() {
	struct tm now;
	time_t nowTime = time(0);
	localtime_s(&now,&nowTime);
	Date today = Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
	return today;
}