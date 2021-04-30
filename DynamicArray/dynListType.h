// DynaminArray.cpp 
// By Benjamin Hodges CS225
//
// dynListType.h Header for the dynListType class

class dynListType
{

  friend std::ostream& operator<<(std::ostream& stream, dynListType& array);  // prints the array in a easy to see format

public:
	dynListType(int max = 5); // constructor
						   // Post: maxSize <-- max. if max is not specified or <=0, default value 5 will be used. if max > MAX, MAX will be used
						   //       size <-- 0.

	dynListType(const dynListType& otherObject); // copy constructor

	~dynListType(); // destuctor

	int getSize() const { return size; }            // return # of elements actually stored
	int getMaxSize() const { return maxSize; }      // return capacity
	bool isEmpty() const { return size == 0; }
	bool isFull() const { return size == maxSize; }

	bool operator==(const dynListType&) const;  // checks if 2 arrays have the same elements in them
	const dynListType& operator+(const dynListType& newList);  // adds 2 elements of arrays together
	const dynListType& operator=(const dynListType& otherList); // sets arrays elements equal tp eachother

	dynListType(const dynListType leftArray, const dynListType rightArray);

	int search(int element) const;  // look for an item. return index of first occurrence
	int at(int index) const;        // return element at a specific location
	bool insert(int element);             // append/insert an element at the end
	bool insert(int index, int element);  // insert an element into location index
	bool remove(int index); // remove element at the specified location

	void fillArray();       // fills the dataArray with maxSize of ints based on user input


private:
	int* dataPtr;     // static array storing data items
	int size;         // actual # of elements stored. size <= maxSize
	int maxSize;      // 0 <= maxSize <= MAX. The capacity of a listType obj
};
