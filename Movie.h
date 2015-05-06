/****************************************************************
File:             Video.h
Description:      class declarations

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#ifndef MOVIE_H
#define MOVIE_H

#include "Video.h"

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

class Movie : public Vids::Video {
public:
	Movie();
	Movie(unsigned int series) {
		seriesNum = series;
	} // TODO: add parametized Video constructor
	void display() { // order: name, audience, 1st director, 1st actor, runtime
		string shortName = name;
		string shortDirector = directors.at(0).getFirstName();
		string shortActors = actors.at(0).getFirstName();
		cout << left << fixed << setw(28) << Truncate(shortName, 24); // Truncate in Video class
		cout << left << fixed << setw(6) << audience;
		cout << left << fixed << setw(21) << Truncate(shortDirector, 17);
		cout << left << fixed << setw(12) << Truncate(shortActors, 12);
		cout << left << fixed << setw(4) << runtimeMinutes;

	}// displays information for all objects of Video type
	void displayAll() {
		cout << "Name: " << name << endl;
		cout << "Audience: " << audience << endl;
		cout << "Runtime Minutes: " << runtimeMinutes << endl;
		cout << "Location: " << location << endl;

		cout << "Director(s): ";
		for (int i = 0; i < directors.size(); ++i) { // directors
			cout << directors.at(i);
			if (i < directors.size())
				cout << ", "; // if multiple, separate by comma
		}
		cout << endl;

		cout << "Actor(s): ";
		for (int i = 0; i < actors.size(); ++i) { // actors
			cout << actors.at(i);
			if (i < actors.size())
				cout << ", "; // if multiple, separate by comma
		}
		cout << endl;

		cout << "Date Released: " << released;
		cout << "Date Viewed: " << viewed;
	}
	/*
	bool SearchBool(string target) {
		bool found = false;
		string runMinStr = to_string(runtimeMinutes); // converts another type to string
		string relMonthStr = to_string(released.getMonth());
		string relDayStr = to_string(released.getDay());
		string relYearStr = to_string(released.getYear());
		string searchReleaseDate = relMonthStr + "/" + relDayStr + "/" + relYearStr; // puts date in correct form
		// search viewed date
		string viewMonthStr = to_string(released.getMonth());
		string viewDayStr = to_string(released.getDay());
		string viewYearStr = to_string(released.getYear());
		string searchViewDate = viewMonthStr + "/" + viewDayStr + "/" + viewYearStr;

		// TODO: date formated with leading zeros

		// searches directors for target
		for (int i = 0; i < directors.size(); ++i) {
			if (directors.at(i).getFirstName().find(target) != string::npos
				|| directors.at(i).getMiddleName().find(target) != string::npos
				|| directors.at(i).getLastName().find(target) != string::npos
				|| directors.at(i).getLineage().find(target) != string::npos)
				return true;
		}

		// searches actors for target
		for (int i = 0; i < actors.size(); ++i) {
			if (actors.at(i).getFirstName().find(target) != string::npos
				|| actors.at(i).getMiddleName().find(target) != string::npos
				|| actors.at(i).getLastName().find(target) != string::npos
				|| actors.at(i).getLineage().find(target) != string::npos)
				return true;
		}

		// searches data members for target
		if (name.find(target) != string::npos
			|| audience == target // if target matches an audience rating
			|| location.find(target) != string::npos
			|| searchReleaseDate == target // if released date matches target
			|| searchViewDate == target // if viewed date matches target
			|| runMinStr == target) // compare runtime to target
			return true;

		// if no matches are found, return false
		else
			return false;
	}  // SearchBool
	*/
private:
	unsigned int seriesNum;
};

#endif
