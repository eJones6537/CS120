/****************************************************************
File:             Video.cpp
Description:      class definitions

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#include "Video.h"
#include <string>
#include <vector>

using namespace std;

namespace Vids
{
	Video::Video(){}
	Video::Video(string name, string audience, string location, vector<Person> directors,
		vector<Person> actors, Date released) {
		this->name = name;
		this->audience = audience;
		this->location = location;
		this->directors = directors;
		this->actors = actors;
		this->released = released;
	}	/* parameterized constructor */

	string Video::Truncate(string str, size_t width) { // shortens output
		if (str.length() > width)
			return str.substr(0, width) + "...";
		return str;
	}	// truncate
			// changes a Date into a string, with useful formatting
	string Video::dateToString(Date &given) {
		string monthStr;
		string dayStr;
		string yearStr;
		if (given.getMonth() < 10) // if month > 10 add zero for formating
			monthStr = "0" + to_string(given.getMonth());
		else // else add numbers as normal
			monthStr = to_string(given.getMonth());
		if (given.getDay() < 10) // if day > 10 add zero for formating
			dayStr = "0" + to_string(given.getDay());
		else // else add numbers as normal
			dayStr = to_string(given.getDay());
		if (given.getYear() < 10) // if year > 10 add zero for formating
			yearStr = "0" + to_string(given.getYear());
		else // else add numbers as normal
			yearStr = to_string(given.getYear());
		return monthStr + "/" + dayStr + "/" + yearStr;
	}
}