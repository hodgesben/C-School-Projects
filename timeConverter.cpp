/********************************************************************
* HW3_Hodges (Time Converter)
* By Benjamin Hodges
* 
* This program converts time to and from 24 hour to 12 hour
* or visa versa based on user input
*********************************************************************/

#include <iostream>   // std::cerr, std::cout, std::endl
#include <string>

// Lits the options that the 
// user has to choose from
void choices();
// Pre: userChoice != 0
// Post: goes to next method in main

// Displays the menu based on the
// Choice made by the user
void menu(int userChoice/*IN*/);
// Pre: userChoice initialized.
//      userChoice == 1,2

// Takes hours and mins and am/pm
// Converts them to 24 hr time
void twelveToTwentyfour(int/*IN*/, int/*IN*/, char/*IN*/);
// Pre: hours, mins, AM/PM entered in menu
// Post: Turns them into 24 hour time format

// Takes hours and mins
// Converts them to 12 hour time with am/pm
void twentyfourToTwelve(int/*IN*/, int/*IN*/);
// Pre: hours, mins, AM_PM entered in menu
// Post: Turns hours, mins turns them into 12 hr time
// and gives it am or pm time of day

// turns passed in ints to strings
// Displays the time in a nice format
void results(int/*IN*/, int/*IN*/, std::string/*IN*/);
// Pre: gets ints hours, mins, and string AM/PM
// Post: Displays the time converted for user to see

//Gets user Int input
void getInputInt(int &userChoice);
// Pre: method is called
// Post: return entered in int

//Gets user char input
void getInputChar(char &A_P);
// Pre: method is called
// Post: return entered in char

int main()
{
  int userChoice = 1;  // Users choice they pick on choice screen

  while (userChoice != 0)
  {
    choices();
	getInputInt(userChoice);

	if (userChoice != 0)
	{
	  menu(userChoice);
	}
  } // end while
} // end main

//*******************************************************************

// This method displays the choices for the user to choose from

void choices()
{
  std::cout << "Options --" << std::endl;
  std::cout << "1: To convert time from 12-hour notation to 24-hour notation." << std::endl;
  std::cout << "2: To convert time from 24-hour notation to 12-hour notation." << std::endl;
  std::cout << "0: To quit the program." << std::endl;
  std::cout << "Choose: ";
} // end choices

//*******************************************************************

// This method asks the user to enter hours. mins. and AM/PM if user choice 12 to 24 hrs

void menu(int userChoice)
{
  int hours;       // hours enterd
  int mins;        // mins enterd
  char A_P = 'N';  // char enterd if userChoice = 1

  std::cout << std::endl;
  std::cout << "Enter hours: ";
  getInputInt(hours);
  std::cout << "Enter minutes: ";
  getInputInt(mins);

  if (userChoice == 1)
  {
	std::cout << "Enter AM/PM <A or P>: ";
	getInputChar(A_P);
	twelveToTwentyfour(hours, mins, A_P);
  }
  else
  {
	twentyfourToTwelve(hours, mins);
  }
} // end menu

//*******************************************************************

// This method converts 12 hour time to 24 hour time

void twelveToTwentyfour(int hours, int mins, char A_P)
{
  if ((A_P == 'a' || A_P == 'A') && (hours == 12))
  {
	hours -= 12;
  }
  else if ((A_P == 'p' || A_P == 'P') && (hours != 12))
  {
	hours += 12;
  }

  results(hours, mins, "");
} // end twelveToTwentyfour

//*******************************************************************

// This method converts 24 hour time to 12 hour time

void twentyfourToTwelve(int hours, int mins)
{
  std::string am_pmString;

  if (hours >= 12)
  {
	if (hours > 12)
	{
	  hours -= 12;
	}
  am_pmString = "PM";
  }
  else
  {
	if (hours == 0)
	{
	  hours += 12;
	}
  am_pmString = "AM";
  }

  results(hours, mins, am_pmString);
} // end twentyfourToTwelve

  //*******************************************************************

  // This method takes the hours mins and am/pm converts them to strings 
  // and displays them for the user to see the results 

void results(int hours, int mins, std::string am_pmString)
{
  std::string time = "";    // final time string displayed with nice format
  std::string hoursString;  // hour String made from int hours
  std::string minsString;   // mins String made from int mins

  minsString = std::to_string(mins);
  hoursString = std::to_string(hours);

  if (minsString.length() == 1)
  {
	minsString = "0" + minsString;
  }
  if (hoursString.length() == 1)
  {
	hoursString = "0" + hoursString;
  }

  time = hoursString + ":" + minsString + " " + am_pmString;

  std::cout << std::endl;
  std::cout << "The time is: " << time << std::endl;
  std::cout << std::endl;
} // end results

//*******************************************************************

// This method gets an int value entered in by the user

void getInputInt(int &userChoice)
{
  std::cin >> userChoice;
} // end getInput

//*******************************************************************

// This method gets a char value entered in by the user

void getInputChar(char &A_P)
{
  std::cin >> A_P; // user input char
} // end getInputChar 
