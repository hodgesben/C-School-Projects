// HW10_Hodges.cpp 
// By Benjamin Hodges CS225
//
// HW10. a dynamic array based list type class with overloaded operators

#include <iostream>
#include <cassert>
#include "dynListType.h"

dynListType::dynListType(int max)
{
  if (max <= 0)
  {
	maxSize = 5;
  }
  else
  {
	maxSize = max;
  }
  dataPtr = new int[max];
  size = 0;
} // end constructor

  //------------------------------------------------------------

dynListType::dynListType(const dynListType& otherObject)
{
  maxSize = otherObject.maxSize;
  size = otherObject.size;
  dataPtr = new int[maxSize];

  for (int i = 0; i < size; i++)
  {
	dataPtr[i] = otherObject.dataPtr[i];
  }
} // copy constructor

  //------------------------------------------------------------

dynListType::~dynListType()
{
  delete[] dataPtr;
} // end destructor

  //------------------------------------------------------------

int dynListType::search(int element) const
{
  for (int i = 0; i < size; i++)
  {
	if (dataPtr[i] == element)
	{
	  return i;
	}
  }
  return -1;
} // end search

  //------------------------------------------------------------

int dynListType::at(int index) const
{
  assert(index >= 0 && index < size);
  return dataPtr[index];
} // end at

  //------------------------------------------------------------

bool dynListType::insert(int element)
{
  /*if (isFull())
  {
	maxSize *= 2;
	dynListType newArray(dataPtr);
	dynListType::~dynListType();
	newArray.dataPtr = dataPtr;
  } */

  dataPtr[size] = element;
  return true;
} // end insert

  //------------------------------------------------------------

bool dynListType::insert(int index, int element)
{
 /* if (isFull())
  {
	maxSize *= 2;
	dynListType newArray(dataPtr);
	dynListType::~dynListType();
	newArray.dataPtr = dataPtr;
  }
  */
  if (index >= 0 && index < size)
  {
	for (int i = size; i > index; i--)
	{
	  dataPtr[i] = dataPtr[i - 1];
	}

	dataPtr[index] = element;
	size++;
	return true;
  }
  return false;
} // end insert

  //------------------------------------------------------------

bool dynListType::remove(int index)
{
  if (index >= 0 && index < size)
  {
	for (int i = index; i < size; i++)
	{
	  int temp = dataPtr[i];
	  dataPtr[i] = dataPtr[i + 1];
	  dataPtr[i + 1] = temp;
	}

    size--;
    return true;
  }

  return false;
} // end remove

  //------------------------------------------------------------

void dynListType::fillArray()
{
  std::cout << "Enter " << dynListType::getMaxSize() << " to fill the Array: ";

  for (int i = 0; i < dynListType::getMaxSize(); i++)
  {
	std::cin >> dataPtr[i];
	size++;
  }
} // end fillArray

  //------------------------------------------------------------

const dynListType& operator+(const dynListType& leftArray, const dynListType& rightArray)
{
  dynListType newList(leftArray.getSize() + rightArray.getSize());

  for (int i = 0; i < leftArray.getSize(); i++)
  {
	newList.insert((leftArray.at(i)));
  }
  for (int i = 0; i < rightArray.getSize(); i++)
  {
	newList.insert((rightArray.at(i)));
  }

  return newList;
} // end operator+

  //------------------------------------------------------------

std::ostream& operator<<(std::ostream& stream, dynListType& array)
{
  stream << "[";

  for (int i = 0; i < array.getSize(); i++)
  {
	stream << array.at(i);

	if (i != array.getSize() - 1)
	{
	  stream << ", ";
	}
  }

  stream << "]" << std::endl;
  return stream;
} // end operator<<

  //------------------------------------------------------------

bool dynListType::operator==(const dynListType& array) const
{ 
  for (int i = 0; i < array.getSize() && i < size; i++)
  {
	if (this->at(i) != array.at(i))
	{
	  return false;
	}
  }
  return true;
}

  //------------------------------------------------------------

const dynListType& dynListType::operator=(const dynListType& otherList)
{
  if (this != &otherList)
  {
	delete[] dataPtr;
	maxSize = otherList.maxSize;
	size = otherList.size;
	dataPtr = new int[maxSize];

	for (int index = 0; index < size; index++)
	{
	  dataPtr[index] = otherList.dataPtr[index];
	} 
	return *this;
  } // end if not equal
} // end operator= overload
