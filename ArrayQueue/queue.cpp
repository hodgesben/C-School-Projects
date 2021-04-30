// queue.cpp
// CS225
// By Benjamin Hodges
//
// HW11. Build a queue class via inheritance
// grand-sub class

#include "queue.h"

bool queue::isEmpty() const
{
  return arrayListType::isEmpty();
}

int queue::size() const
{
  return arrayListType::listSize();
}

int queue::front() const
{
  int retItem;

  arrayListType::retrieveAt(0, retItem);
  return retItem;
}

int queue::back() const
{
  int retItem;

  arrayListType::retrieveAt(size()-1, retItem);
  return retItem;
}

void queue::enque(int newItem)
{
  unorderedArrayListType::insertEnd(newItem);
}

int queue::deque()
{
  int retItem = front();

  arrayListType::removeAt(0);
  return retItem;
}

queue::queue(int size)
  : unorderedArrayListType(size)
{
  //std::cout << "constructor of unorderedalt: " << this << "\n"; // testing
}

std::ostream & operator<<(std::ostream& out, const queue& obj)
{
  for (int i = 0; i < obj.length; i++)
	out << obj.list[i] << " ";
  return out;
}
