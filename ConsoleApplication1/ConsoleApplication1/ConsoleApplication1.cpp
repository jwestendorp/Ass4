// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

/************************************************************
*
*   framework for assignment 4 of IPC014
*
************************************************************/
bool is_leap_year(int year) {

	//check of het jaartal deelbaar door 4 is
	if (year % 4 == 0) {

		//check of het jaartal deelbaar is door 100
		if (year % 100 == 0) {

			//check of het jaartal deelbaar is door 400
			if (year % 400 == 0) {
				//cout << "schrikkeljaar"<<endl;
				return true;
			}

			else {
				//cout << "geen schrikkeljaar"<<endl;
				return false;
			}
		}

		//als het jaartal NIET deelbaar is door 100 (maar dus wel deelbaar door 4)
		else {
			//cout << "schrikkeljaar"<<endl;
			return true;
		}


	}

	// implement this function
}

string Month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int nr_of_days_in_month(int year, int month, bool leapyear)
{
	// implement this function

	//maanden met 31 dagen
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	}

	//maanden met 30, 29 of 28 dagen
	else
	{
		//Februari
		if (month == 2) {
			if (leapyear == 1) { return 29; }
			else { return 28; }
		}
		else {
			return 30;
		}
	}
}

//variables for easter date
int holy_year;
int holyDays;
int holyDays2;
int holyDays3;
bool holyleapyear;

void show_holy_days(int holy_year)
{
    int a = holy_year%19;
    int b = holy_year/100;
    int c = holy_year%100;
    int d = b/4;
    int e = b%4;
    int f = (b+8) / 25;
    int g = (b-f+1) / 3;
    int h = (19 * a + b - d - g + 15)%30;
    int i = c / 4;
    int k = c%4;
    int L = (32 + 2 * e + 2 * i - h - k)%7;
    int m = (a + 11 * h + 22 * L) / 451;
    int monthforeal = (h + L - 7 * m + 114) / 31;
    int dayforeal = ((h + L - 7 * m + 114)%31) + 1;
    int carnival_day;
    int carnival_month;
    int easterday = dayforeal;
    int eastermonth = monthforeal;
    cout << "easter is in month " << monthforeal << " and on day " << dayforeal << endl;
    holyleapyear = is_leap_year(holy_year);
    holyDays = nr_of_days_in_month(holy_year,monthforeal, holyleapyear);
    cout << "the month " << monthforeal << " has " << holyDays << " days" << endl;
    ///////////////////////////////////////////////////////////////////////////////////
    //                                                                               //
    //                         carnival part starts here                             //
    //                                                                               //
    ///////////////////////////////////////////////////////////////////////////////////
    // doe - laatste twee maanden en + in dagen
    // - de dagen
    // convert de rest naar maanden
    monthforeal = monthforeal - 2;
    dayforeal = (dayforeal + (nr_of_days_in_month(holy_year,monthforeal-1, holyleapyear)) + (nr_of_days_in_month(holy_year,monthforeal-2, holyleapyear)))-(7*7);
    if (dayforeal > (nr_of_days_in_month(holy_year,monthforeal-2, holyleapyear)))
    {
        //mod it once
        dayforeal = dayforeal%(nr_of_days_in_month(holy_year,monthforeal-2, holyleapyear));
        //add 1 month back
        monthforeal = monthforeal + 1;
        
        if (dayforeal > (nr_of_days_in_month(holy_year,monthforeal-1, holyleapyear)))
        {
            //mod it again
            dayforeal = dayforeal%(nr_of_days_in_month(holy_year,monthforeal-1, holyleapyear));
            //add 1 month back
            monthforeal = monthforeal + 1;
            carnival_day = dayforeal;
            carnival_month = monthforeal;
        }
        if (dayforeal < (nr_of_days_in_month(holy_year,monthforeal-1, holyleapyear)))
        {
            carnival_day=dayforeal;
            carnival_month=monthforeal;
        }
        
    }
    if (dayforeal < (nr_of_days_in_month(holy_year,monthforeal-2, holyleapyear)))
    {
        //we changed nothing
        carnival_day=dayforeal;
        carnival_month=monthforeal;
    }
    cout << "carnival is in month " << carnival_month << " and on day " << carnival_day << endl;
    ///////////////////////////////////////////////////////////////////////////////////
    //                                                                               //
    //                         good friday part starts here                          //
    //                                                                               //
    ///////////////////////////////////////////////////////////////////////////////////
    cout << "good friday is in month " << eastermonth << " and on day " << (easterday - 2) << endl;
    ///////////////////////////////////////////////////////////////////////////////////
    //                                                                               //
    //                         ascension day part starts here                        //
    //                                                                               //
    ///////////////////////////////////////////////////////////////////////////////////
    cout << "ascension day is in month " <<
    
    
    
}

/*
Month easter_month(int year)
{
	// implement this function
}

int easter_day(int year)
{
	// implement this function
}

int day_number_in_year(int day, Month month, int year)
{
	// implement this function
}

Month month_in_year_of_day_number(int day_number, int year)
{
	// implement this function
}

int day_in_month_of_day_number(int day_number, int year)
{
	// implement this function
}

void show_holy_days()
{
	// implement this function
}
*/


int main()
{
	//INTRO
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << endl;
	cout << "     /$$$$$$                     /$$                                                         /$$           /$$   /$$" << endl;
	cout << "    /$$__  $$                   |__/                                                        | $$          | $$  | $$" << endl;
	cout << "   | $$    $$  /$$$$$$$ /$$$$$$$ /$$  /$$$$$$  /$$$$$$$  /$$$$$$/$$$$   /$$$$$$  /$$$$$$$  /$$$$$$        | $$  | $$" << endl;
	cout << "   | $$$$$$$$ /$$_____//$$_____/| $$ /$$__  $$| $$__  $$| $$_  $$_  $$ /$$__  $$| $$__  $$|_  $$_/        | $$$$$$$$" << endl;
	cout << "   | $$__  $$|  $$$$$$|  $$$$$$ | $$| $$    $$| $$    $$| $$   $$   $$| $$$$$$$$| $$    $$  | $$          |_____  $$" << endl;
	cout << "   | $$  | $$  ____  $$ ____  $$| $$| $$  | $$| $$  | $$| $$ | $$ | $$| $$_____/| $$  | $$  | $$ /$$            | $$" << endl;
	cout << "   | $$  | $$ /$$$$$$$//$$$$$$$/| $$|  $$$$$$$| $$  | $$| $$ | $$ | $$|  $$$$$$$| $$  | $$  |  $$$$/            | $$" << endl;
	cout << "   |__/  |__/|_______/|_______/ |__/  ____  $$|__/  |__/|__/ |__/ |__/  _______/|__/  |__/    ___/              |__/ " << endl;
	cout << "                                     /$$    $$                                                                      " << endl;
	cout << "                                    |  $$$$$$/                                                                      " << endl;
	cout << "                                      ______/                                  All rights reserved: Jelmar Gerristen" << endl;
	cout << "                                                                                                    Jonas Westendorp" << endl;
	cout << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;


	//MENU
	cout << "Enter 'Q' for part 1" << endl;
	cout << "Enter 'W' for part 2.1" << endl;


	//string voor ingedrukte toets
	string toets;
	cin >> toets;


	//PART 1, toets Q
	if (toets == "q" || toets == "Q") {

		//VARIABLES
		int year;
		int month;
		bool leapyear;
		int MonthDays;


		//Enter a year
		cout << endl;   //enter
		cout << "1: Leap years, number of days in month" << endl;
		cout << "--------------------------------------" << endl;
		cout << "Enter a year: ";
		cin >> year;
		leapyear = is_leap_year(year);

		//Return if the year is a leapyear
		if (leapyear == true) {
			cout << year << " is a leapyear." << endl;
		}
		else {
			cout << year << " is not a leapyear." << endl << endl;
		}


		//Enter a month


		cout << "Enter a month number from 1 to 12, in the year " << year << ": ";
		cin >> month;

		MonthDays = nr_of_days_in_month(year, month, leapyear);
		cout << "The month " << Month[month -1]<< " has " << MonthDays << " days" << endl << endl;

	}


	// PART 2.1, Toets W
	if (toets == "w" || toets == "W") {
		cout << endl;   //enter
		cout << "Compute the prime-factors of natural number x" << endl;
		cout << "Enter a value for x: ";
		int n;
		cin >> n;
		//        factorize(n);
	}

	


	main();

	//OPDRACHT!!!


	//cout << leapyear<<endl;

}
