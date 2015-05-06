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
}