// DynamicArryDriver.cpp 
// By Benjamin Hodges CS225
//
// HW10. a dynamic array based list type class with overloaded operators

#include <iostream>
#include "dynListType.h"

//------------------------------------------
// function declarations
//------------------------------------------

// promt user to search array for a number
// read in number and call listType search based on user input
void prmtSearch(int &userNum/*OUT*/, dynListType array/*IN*/);
// pre: passes in and updates user entered number & array being searched
// post: prints out found value from listType array.search(userNum);

// promt user to remove an index of the array
// read in number and call listType remove based on user input
void prmtRemove(int &userNum/*OUT*/, dynListType &array/*INOUT*/);
// pre: passes in and updates user entered number & array being searched
// post: prints updated array after index specified was removed

// promt user to remove an index of the array
// read in number and call listType remove based on user input
void prmtAt(int &userNum/*OUT*/, dynListType array/*IN*/);
// pre: passes in and updates user entered number & array being searched
// post: prints out the element at the userNum index pos.

//--------------------------------------------------------------

int main()
{
  int userNum = 0;    // user entered number
  bool again = true;  // User -1 to quit
  int search;         // number retreved from array
  int fixedNum = 0;

  std::cout << "Enter how many numbers you want to put into an array: ";
  std::cin >> userNum;
  std::cout << std::endl;
  dynListType array(userNum);
  array.fillArray();

  std::cout << "Enter how many numbers you want to put into the 2nd array: ";
  std::cin >> userNum;
  std::cout << std::endl;
  dynListType array2(userNum);
  array2.fillArray();

  std::cout << "list one: " << array;

  do {
	prmtSearch(userNum, array);

	if (userNum == -1)
	{
	  again = false;
	}
  } while (again);

  again = true;
  std::cout << std::endl << "list two: " << array2;

  do {
	prmtRemove(userNum, array2);

	if (userNum == -1)
	{
	  again = false;
	}
  } while (again);

  std::cout << std::endl << "list two: " << array2;

  std::cout << "Enter an index number to see Element in that location the Array: ";
  std::cin >> userNum;
  search = array2.at(userNum);
  std::cout << "The element at index location [" << userNum << "] is: " << search << std::endl << std::endl;

  if (array == array2)
  {
	std::cout << "one == two after one = two (assignment): 1" << std::endl;
	std::cout << "list one after one = two (assignment): " << array << std::endl;
  }
  else
  {
    std::cout << "one == two: 0" << std::endl;
  }

 // dynListType array3 (array + array2);
  array = array2;

  if (array == array2)
  {
    std::cout << "one == two after one = two (assignment): 1" << std::endl;
    std::cout << "list one after one = two (assignment): " << array << std::endl;
  }
  else
  {
	std::cout << "one == two: 0" << std::endl;
  }

  
  for (int i = 0; i < 5; i++)
  {
	array2.insert(0, fixedNum);
	std::cout << "We inserted the number " << fixedNum << " at the last index of your 2nd array." << array2 << std::endl;
	fixedNum += 20;
  }
  

  for (int i = 0; i < 5; i++)
  {
	array.insert(fixedNum);
    std::cout << "list three after insert (0, val): maxSize " << array.getMaxSize() << ",";
	std::cout << array << std::endl;
	fixedNum -= 10;
  }
  
  return 0;
} // end main

  //--------------------------------------------------------------

void prmtSearch(int &userNum, dynListType array)
{
  int search = 0;

  std::cout << "Enter a number to check if its in the Array (Enter -1 to stop searching): ";
  std::cin >> userNum;

  if (userNum != -1)
  {
	search = array.search(userNum);
	std::cout << "Is " << userNum << " in list one? Answer (-1 means no): " << search << std::endl << std::endl;
  }
} // end prmtSearch

  //--------------------------------------------------------------

void prmtRemove(int &userNum, dynListType &array)
{
  std::cout << "Enter an index number to remove from the Array (Enter -1 to stop removing): ";
  std::cin >> userNum;

  if (array.remove(userNum))
  {
	std::cout << "list two after removing index [" << userNum << "]: ";
	std::cout << array;
	std::cout << std::endl;
  }
} // end prmtRemove

  //--------------------------------------------------------------

void prmtAt(int &userNum, dynListType array)
{
  int search;

  std::cout << "Enter an index number to see Element in that location the Array (Enter -1 to stop At): ";
  std::cin >> userNum;

  if (userNum != -1)
  {
	search = array.at(userNum);
	std::cout << "The Element at index location [" << userNum << "] is: " << search;
	std::cout << std::endl;
  }

  std::cout << std::endl;
} // end prmtAt
