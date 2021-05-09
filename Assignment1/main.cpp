#include "MyString.h"
#include <cassert>
#include <iostream>

using namespace assignment1;
using namespace std;

int main()
{
	// Default
	MyString s1("Hello");
	assert(s1.GetLength() == 5); // ���̴� 5
	
	// Append
	MyString s2("Hello");
	s2.Append(" World"); // s�� "Hello World"�� ��
	assert(s2.GetLength() == 11);
	assert(s2 == "Hello World");
	
	// == ������
	MyString s3("abcde");
	MyString s4("eba");
	assert(s3 != s4);

	MyString s5("abcde");
	MyString s6("abcde");
	assert(s5 == s6);

	// + ������
	MyString s7("Hello");
	MyString s8(" World");
	MyString s9 = s7 + s8; // s3�� "Hello World"�� �Ǹ�, s1�� s2�� ������ "Hello"�� " World"��
	
	assert(s7 == "Hello");
	assert(s8 == " World");
	assert(s9 == "Hello World");

	// IndexOf
	MyString s10("Hello");
	int i = s10.IndexOf("ell"); // i�� 1
	int j = s10.IndexOf("l"); // j�� 2
	int z = s10.IndexOf("This"); // z�� -1
	assert(i == 1);
	assert(j == 2);
	assert(z == -1);

	// LastIndexOf �׽�Ʈ
	MyString s11("Hello");
	i = s11.LastIndexOf("ell"); // i�� 1
	j = s11.LastIndexOf("l"); // j�� 3
	z = s11.LastIndexOf("This"); // z�� -1
	assert(i == 1);
	assert(j == 3);
	assert(z == -1);

	// RemoveAt �׽�Ʈ
	MyString s12("Hello");
	bool b1 = s12.RemoveAt(0); // s�� "ello", b1�� true
	assert(s12 == "ello");
	assert(b1);
	bool b2 = s12.RemoveAt(2); // s�� "elo", b2�� true
	assert(s12 == "elo");
	assert(b2);
	bool b3 = s12.RemoveAt(4); // s�� "elo", b3�� false
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
	s21.Interleave(" World"); // s1�� "H eWlolrold"
	assert(s21 == "H eWlolrold");

	MyString s22("abcdefg");
	s22.Interleave("1234");
	assert("a1b2c3d4efg");

	cout << "Done!" << endl;
}