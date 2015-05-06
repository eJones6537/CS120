/****************************************************************
File:             project3.cpp
Description:      database for a movie library

Author:           David && Evan
Class:            CSCI 120
Date:             2015 May 13

We hereby certify that this program is entirely our own work.
*****************************************************************/

#include <algorithm> // std::copy
#include <fstream> // std::ifstream, std::ofstream
#include <iostream> // std::cout
#include <string> // std::string
#include <vector>

#include "Date.h"
#include "Person.h"
#include "Video.h"
#include "Movie.h"
#include "Television.h"
#include "Computer.h"

using namespace std;
using namespace Vids;

void display(vector<Video*> &videos) { // displays all objects in vector
	for (int i = 0; i < videos.size(); ++i) { videos.at(i)->display(); }
}	// display

void Search(vector<Video*> &videos, string target) {
	// note: to_string converts another type to type string
	bool found = false;
	int i = 0;
	string rel; // string form of released Date
	string view; // string form of viewed Date
	cout << "Searching..." << endl;
	for (i = 0; i < videos.size(); ++i) {
		rel = DateToString(videos.at(i)->getReleased());
		view = DateToString(videos.at(i)->getViewed());
		// checks every field
		if (videos.at(i)->getRuntimeMinutes.find(target) != string::npos
			|| videos.at(i)->getName().find(target) != string::npos
			|| videos.at(i)->getAudience() == target
			|| videos.at(i)->getLocation == target
			|| videos.at(i)->SearchPeople(target)
			|| rel.find(target) != string::npos
			|| view.find(target) != string::npos
			|| videos.at(i)->SearchMore(target)) {

// TODO: implement SearchMore in Video class (to derived classes) and add to if statement above
			found = true;
			videos.at(i)->displayAll(); // if target is found in any fields, print all information for index
		}
	}
	// if no matches are found, print message
	if (!found)
		cout << "No matches found for your entry." << endl;
} // print any found matches

// changes a Date into a string, with useful formatting
string DateToString(Date &given) {
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

void Remove(vector<Video*> &videos) {

}

int main(){

	Person newPerson;
	// Movie newMovie;
	// Television newTelevision;
	vector<Person> persons;
	vector<Video*> videos;
	string file_name = "videos.dat";
	string comm;
	string searchEntry;
	int i = 0;
   vector<string> temp(6);
   
   cout << "What name should the File have?" << std::endl;
   cin >> file_name;
	
	// open database file
   ifstream reader(file_name.c_str());
   if (!reader) {
      cout << "Error: Cannot open input file. =[ " << endl;
   
      #ifdef _WIN32
         system("pause");
      #endif
      
      return -1;
      
   }  // if
   // each line of input fills one object
   while (!reader.eof()) {
      getline(reader, temp.at(0), '\t');  // type
      if ( reader.eof() ) break;
      getline(reader, temp.at(1), '\t');
      getline(reader, temp.at(2), '\t');
      getline(reader, temp.at(3), '\t');
      getline(reader, temp.at(4), '\n');
      
      if (temp.at(0) == "Person") {
      	Person newPerson(temp.at(1), temp.at(3), temp.at(2), temp.at(4));
      	/* FIXME: following is debugging output
      	cout << "First: " << newPerson.getFirstName() << endl;
      	cout << "Middle: " << newPerson.getMiddleName() << endl;
      	cout << "Last: " << newPerson.getLastName() << endl;
      	cout << "Lineage: " << newPerson.getLineage() << endl;	*/
      }	// if Person
      else if (temp.at(0) == "Movie") {}
		/* newest.SetName(temp.at(0));
		newest.SetDirector(temp.at(1));
		newest.SetRelease(temp.at(2));
		newest.SetAudience(temp.at(3));
		newest.SetRuntime(temp.at(4));
		newest.SetShelf(temp.at(5)); */
		// push_back adds the new movie to the vector of movies
		// list.push_back(newest);
      i++;
   }  // while
   
   reader.close();	// close input file

	do {
	cout << "Enter a command (help = command list): ";
	cin >> comm; // choice of command
	
	if (comm == "help") { // help/display command list
		cout << "COMMANDS:" << endl;
		cout << "search help = gives format for search entries" << endl;
		cout << "search = search document for a given entry" << endl;
		cout << "add = add a new entry to list" << endl;
		cout << "remove = remove an item from the list" << endl;
		cout << "print = print entire list of Videos" << endl;
		cout << "quit = quit program" << endl;
		cout << "save = save changes to list of Videos to external file" << endl;
	}
	else if (comm == "add") { // add new entry
		// TODO add to videos
	}
	else if (comm == "search help") {
		cout << "Fields and format of entry while searching:" << endl;
		cout << "name - ";
		cout << "date - mm/dd/yy (leading zeros required)";
	}
	else if (comm == "search") { // search vectors for entries
		cout << "Enter something to search: ";
		cin.ignore();
		getline(cin, searchEntry);
		for (i = 0; i < videos.size(); ++i) {
			if (videos.at(i)->Search() == true) {
				videos.at(i)->displayAll();
			}
		}
	}
	else if (comm == "remove") {

	}
	else if (comm == "print") { // print videos
		display(videos); // FIXME: working?
	}
	else if (comm == "save") {
		// TODO: save list updates
	}
	else if (comm == "quit") {
		break; // quit program
	}
	else
		cout << "Input not recognized.\n";
	} while (comm != "quit"); // end loop
	// continue to allow input until user enters 'q' (quit)
   
   #ifdef _WIN32
      system("pause");
   #endif

   return 0;
}	// main()
