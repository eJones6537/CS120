/****************************************************************
File:             Video.h
Description:      class declarations

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Date.h"

using namespace std;

enum kind {MOVIE, TELEVISION, COMPUTER};
// 'MOVIE' = standalone film of any length, whether it's part of a franchise or not
// 'TELEVISION' = episode from mini- or recurring series
// 'COMPUTER' = online or locally hosted files
/* If need be, we can extend this by adding something for analog home movies, 
i.e., camcorder tapes or 8mm film. */

namespace Vids
{

	class Video{
	
		public:
			Video(); // default constructor
			Video(string name, string audience, string location, vector<Person> directors,
				vector<Person> actors, Date released);
			virtual void display() = 0; // displays information for all objects of Video type
			virtual void displayAll() = 0; // displays all information for one object
			virtual bool searchBool();
			string getName() const { return name; }
			string getAudience() const { return audience; }
			string getLocation() const { return location; }
			Date getReleased() const { return released; }
			Date getViewed() const { return viewed; }
			string Truncate(string str, size_t width) { // shortens output
				if (str.length() > width)
					return str.substr(0, width) + "...";
				return str;
			}	// truncate
			
		protected:
			short runtimeMinutes;
			/* Theoretically runtime could be unsigned, but we might eventually 
			need negatives for special values.  I doubt we'll see one needing 
			more than 32K minutes, so no worry about overflow. */
			string name;	// title of movie
			string audience;	// PG = "Plenty Guns", PG-13 = "13 or more guns"
			string location;
			/* Location is a catch-all field for: URL, shelf disc is on, format 
			type, name of person it is loaned to, etc. */
			vector<Person> directors;
			/* David: I considered using other containers, but none of them 
			offered any obvious benefits over the vector. */
			vector<Person> actors;
			Date released;
			Date viewed;
			/* 'viewed' can be used to answer the question: "What haven't i 
			watched lately?" */
	
	};	// end class Video

} // end namespace Vids

#endif
