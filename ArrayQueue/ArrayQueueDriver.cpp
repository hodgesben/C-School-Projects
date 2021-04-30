// ArrayQueueDriver.cpp
// CS225
// By Benjamin Hodges
//
// HW11. Build a queue class via inheritance
// main driver to test the queue class functions

#include <iostream>
#include "queue.h"

int main()
{
  queue intQueueList(25);

  if (intQueueList.isEmpty())
  {
	std::cout << "Queue is currently empty." << std::endl << std::endl;
  }

  for (int i = 0; i < 8; i++)
  {
	intQueueList.enque(i * 5 + 10);
	std::cout << "Queue: " << intQueueList << std::endl;
  }

  std::cout << std::endl;

  if (!intQueueList.isEmpty())
  {
	std::cout << "Front of queue: " << intQueueList.front() << std::endl;
	std::cout << "Back of queue: " << intQueueList.back() << std::endl;
	std::cout << "Queue size: " << intQueueList.size() << std::endl << std::endl;
  }

  for (int i = 0; i < 8; i++)
  {
	std::cout << "Removed " << intQueueList.deque() << " from the queue."  << std::endl;
	std::cout << "Queue: " << intQueueList << std::endl << std::endl;
  }
  
  return 0;
} // end main
