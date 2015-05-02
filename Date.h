/****************************************************************
File:             Date.h
Description:      class for storing info about a day

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

namespace Vids
{

	class Date	// represents year, month, day
	{
	public:
		Date()	// default gets all zeroes
		{
			year = 0;
			month = 0;
			day = 0;
		}	// default constructor
		
		Date(unsigned short yr, unsigned short mn, unsigned short dy)
		{
			year = yr;
			month = mn;
			day = dy;
		}	// parameterized constructor
		
		friend ostream& operator<<(ostream&out, const Date& date)
		{
			out << date.year << '/' << date.month << '/' << date.day << endl;
			return out;
		}	// << overload
		
		// no need for setters, dates shouldn't change once submitted
		
		unsigned short getYear() const { return year; }
		unsigned short getMonth() const { return month; }
		unsigned short getDay() const { return day; }
	
	private:
		unsigned short year, month, day;
		
	};	// end class Date

} // end namespace Video
#endif
