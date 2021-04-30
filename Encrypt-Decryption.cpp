/**********************************************************
* HW6 Encryption and decryption
* By: Benjamin Hodges
*
* This prgram uses an encryption algorithm
* to encrypt words, also decrypts it back too
***********************************************************/

#include <iostream>
#include <string>

std::string encrypt(std::string str);
std::string decrypt(std::string str);
std::string charChanger(std::string str);
int swapLetter(int asciiNum);

int main()
{
  std::string str = "Secret 12";
  std::string secretStr = encrypt(str);

  std::cout << "original: "  << str << '\n';
  std::cout << "encrypted: " << secretStr << '\n';
  std::cout << "decrypted: " << decrypt(secretStr) << '\n';
}

//---------------------------------------------------------------------------

std::string encrypt(std::string str)
{ 
  int shiftRight = str.length() / 2;  // # of times string will sift right
  std::string moveStringLetter;       // temp char being moved

  str = charChanger(str);

  // Saves the last char in the string saves to moveStringLetter
  // Then erases it from the str
  // finally inserts the saved char into the first char of the string
  for (int i = 0; i < shiftRight; i++)
  {
    moveStringLetter = str.at(str.length() - 1);
	str.erase(str.length() - 1);
	str = str.insert(0, moveStringLetter);
  }
  return str;
} // end encrypt 

//--------------------------------------------------------------------

std::string decrypt(std::string str)
{
  int shiftLeft = str.length() / 2;  // # of times string needs to move left
  std::string moveStringLetter;      // temp char being moved in the string

  str = charChanger(str);
	
  for (int i = 0; i < shiftLeft; i++)
  {
	moveStringLetter = str.at(0);
	str = str.insert(str.length(), moveStringLetter);
	str = str.substr(1, str.length());
  }
  return str;
} // end decrypt

//-------------------------------------------------------------

std::string charChanger(std::string str)
{
  int changeCharInt;  // value of the changed char in ascii value

  // This loops through the chars of the string
  // for each pos it calls the funtion swapLetter
  // then it repaces the current char in the string with the new one retreved
  // from the swapLetter fucntion
  for (int i = 0; i < str.length(); i++)
  {
	changeCharInt = swapLetter(int(str.at(i)));
	str.replace(i, 1, std::string(1, (char)changeCharInt));
  }
  return str;
} // end charChanger

//---------------------------------------------------------------------

int swapLetter(int asciiNum)
{
  double average;    // average of the group of ascii chars being used

  if (asciiNum >= 48 && asciiNum <= 57)      // 0-9
  {
	average = 52.5;
  }
  else if (asciiNum >= 65 && asciiNum <= 90)    // A-Z
  {
	average = 77.5;
  }
  else if (asciiNum >= 97 && asciiNum <= 122)  // a-z
  {
	average = 109.5;
  }
  else           // if anything else remain same
  {
	return asciiNum;       
  }

  return (average + (average - asciiNum));
} // end swapLetter
