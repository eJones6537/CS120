/****************************************************************
File:             Television.cpp
Description:      class definitions

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#include "Television.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace Vids;

Television::Television() {
	season = 0;
	episode = 0;
}	// default constructor

Television::Television(unsigned int season, unsigned int episode) {
	this->season = season;
	this->episode = episode;
}	// parameterized constructor

void Television::display() { // order: name, audience, 1st director, 1st actor, runtime
	string shortName = name;
	string shortDirector = directors.at(0).getFirstName();
	string shortActors = actors.at(0).getFirstName();
	cout << left << fixed << setw(28) << Truncate(shortName, 24); // Truncate in Video class
	cout << left << fixed << setw(6) << audience;
	cout << left << fixed << setw(21) << Truncate(shortDirector, 17);
	cout << left << fixed << setw(12) << Truncate(shortActors, 12);
	cout << left << fixed << setw(4) << runtimeMinutes;
	cout << left << fixed << setw(3) << season;
}// displays information for all objects of Video type

void Television::displayAll() {
	cout << "Name: " << name << endl;
	cout << "Audience: " << audience << endl;
	cout << "Runtime Minutes: " << runtimeMinutes << endl;
	cout << "Total Seasons: " << season << endl;
	cout << "Episodes per Season: " << episode << endl;
	cout << "Location: " << location << endl;

	cout << "Director(s): ";
	for (int i = 0; i < directors.size(); ++i) { // directors
		cout << directors.at(i);
		if (i < directors.size())
			cout << ", "; // if multiple, seperate by comma
	}	// for directors
	cout << endl;

	cout << "Actor(s): ";
	for (int i = 0; i < actors.size(); ++i) { // actors
		cout << actors.at(i);
		if (i < actors.size())
			cout << ", "; // if multiple, seperate by comma
	}	//  for actors
	cout << endl;

	cout << "Date Released: " << released;
	cout << "Date Viewed: " << viewed;
}	// displayAll
