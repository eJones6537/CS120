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

int main(){

	Person newPerson;
	// Movie newMovie;
	// Television newTelevision;
	vector<Person> persons;
	vector<Video*> videos;
	string person_file_name = "Persons.dat";
	string video_file_name = "Videos.dat";
	string movie_delimiter = "<movie>";
	string templine;
	string comm;
	unsigned int stringPos = 0;
   vector<string> temp(5);
   
   //cout << "What name should the File have?" << std::endl;
   //cin >> file_name;
	
	// open Person file
   ifstream reader(person_file_name.c_str());
   if (!reader) {
      cout << "Error: Cannot open Person input file. =[ " << endl;
   
      #ifdef _WIN32
         system("pause");
      #endif
      
      return -1;
      
   }  // if
   // each line of input fills one object
   while (!reader.eof()) {
      getline(reader, temp.at(0), '\t');
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
   }  // while
   
   reader.close();	// close input file
	
	// open Video file
   ifstream reader(video_file_name.c_str());
   if (!reader) {
      cout << "Error: Cannot open Video input file. =[ " << endl;
   
      #ifdef _WIN32
         system("pause");
      #endif
      
      return -1;
      
   }  // if
   // each line of input fills one object
   while (!reader.eof()) {
      getline(reader, templine);
      if ( reader.eof() ) break;
      
      if (temp.at(0) == "Movie") {}
   }  // while
   
   reader.close();	// close input file

	do {
		cout << "Enter a command (help = command list): ";
		cin >> comm; // choice of command

		if (comm == "add") { // add new entry
		// TODO add to videos
		}
		else if (comm == "help") { // help/display command list
		// TODO
		}
		else if (comm == "print") { // print videos
			display(videos); // FIXME: working?
		}
		else if (comm == "quit"){
		 // quit program
		}
		else if (comm == "test"){
			
		}
		else
			cout << "Input not recognized.\n";
	} while (comm != "quit");
	// continue to allow input until user enters 'q' (quit)
   
   #ifdef _WIN32
      system("pause");
   #endif

   return 0;
}	// main()
