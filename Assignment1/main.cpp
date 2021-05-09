#include "MyString.h"
#include <cassert>
#include <iostream>

using namespace assignment1;
using namespace std;

int main()
{
	// Default
	MyString s1("Hello");
	assert(s1.GetLength() == 5); // 길이는 5
	
	// Append
	MyString s2("Hello");
	s2.Append(" World"); // s는 "Hello World"가 됨
	assert(s2.GetLength() == 11);
	assert(s2 == "Hello World");
	
	// == 연산자
	MyString s3("abcde");
	MyString s4("eba");
	assert(s3 != s4);

	MyString s5("abcde");
	MyString s6("abcde");
	assert(s5 == s6);

	// + 연산자
	MyString s7("Hello");
	MyString s8(" World");
	MyString s9 = s7 + s8; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임
	
	assert(s7 == "Hello");
	assert(s8 == " World");
	assert(s9 == "Hello World");

	// IndexOf
	MyString s10("Hello");
	int i = s10.IndexOf("ell"); // i는 1
	int j = s10.IndexOf("l"); // j는 2
	int z = s10.IndexOf("This"); // z는 -1
	assert(i == 1);
	assert(j == 2);
	assert(z == -1);

	// LastIndexOf 테스트
	MyString s11("Hello");
	i = s11.LastIndexOf("ell"); // i는 1
	j = s11.LastIndexOf("l"); // j는 3
	z = s11.LastIndexOf("This"); // z는 -1
	assert(i == 1);
	assert(j == 3);
	assert(z == -1);

	// RemoveAt 테스트
	MyString s12("Hello");
	bool b1 = s12.RemoveAt(0); // s는 "ello", b1은 true
	assert(s12 == "ello");
	assert(b1);
	bool b2 = s12.RemoveAt(2); // s는 "elo", b2은 true
	assert(s12 == "elo");
	assert(b2);
	bool b3 = s12.RemoveAt(4); // s는 "elo", b3은 false
	assert(s12 == "elo");
	assert(!b3);
	
	//PadLeft
	MyString s13("Hello");

	s13.PadLeft(2); // s1: "Hello"
	assert(s13 == "Hello");
	s13.PadLeft(8); // s1: "   Hello"
	assert(s13 == "   Hello");

	MyString s14("World");
	s14.PadLeft(3, '-'); // s2: "World"
	assert(s14 == "World");
	s14.PadLeft(7, '-'); // s2: "--World"
	assert(s14 == "--World");

	//PadRight
	MyString s15("Hello");

	s15.PadRight(2); // s1: "Hello"
	assert(s15 == "Hello");
	s15.PadRight(8); // s1: "Hello   "
	assert(s15 == "Hello   ");
	
	MyString s16("World");
	s16.PadRight(3, '-'); // s2: "World"
	assert(s16 == "World");
	s16.PadRight(7, '-'); // s2: "World--"
	assert(s16 == "World--");

	// Reverse
	MyString s17("Hello");
	s17.Reverse(); // s: "olleH"
	assert(s17 == "olleH");

	MyString s18("Hello#");
	s18.Reverse(); // s: "olleH"
	assert(s18 == "#olleH");
	

	// ToUpper
	MyString s19("HEllo 123K");
	s19.ToUpper(); // s1: "HELLO 123K"
	assert(s19 == "HELLO 123K");

	// ToLower
	MyString s20("AZ");
	s20.ToLower(); // s1: "hello 123k"
	assert(s20 == "az");

	// Interleave
	MyString s21("Hello");
	s21.Interleave(" World"); // s1은 "H eWlolrold"
	assert(s21 == "H eWlolrold");

	MyString s22("abcdefg");
	s22.Interleave("1234");
	assert("a1b2c3d4efg");

	cout << "Done!" << endl;
}