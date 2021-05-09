#include "MyString.h"
#include <cassert>
#include <iostream>

using namespace assignment1;
using namespace std;


void test() {
	/* GetLength() Ex */
	cout << "-----------------------" << endl;
	cout << "GetLength()" << endl;
	MyString s1("Hello");
	cout << s1.GetLength() << endl;   // 5

	/* GetCString() Ex */
	cout << "-----------------------" << endl;
	cout << "GetCString()" << endl;
	MyString s2("Hello");
	cout << s2.GetCString() << endl;  // Hello

	/* Append() Ex */
	cout << "-----------------------" << endl;
	cout << "Append()" << endl;
	MyString s3("Hello");
	s3.Append(" World");
	cout << s3.GetCString() << endl;  // Hello World
	s3.Append("\n\tWorld\n");
	cout << s3.GetCString() << endl;

	/* operator+ Ex */
	cout << "-----------------------" << endl;
	cout << "operator+" << endl;
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
	cout << s43.GetCString() << endl;   //Hello World

	/* IndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "IndexOf()" << endl;
	MyString s5("Hello");
	cout << s5.IndexOf("ell") << endl;   // 1
	cout << s5.IndexOf("l") << endl;     // 2
	cout << s5.IndexOf("This") << endl;  // -1
	cout << s5.IndexOf("") << endl;   // 0
	cout << s5.IndexOf("lo") << endl;   // 3

	MyString s52("");
	cout << s52.IndexOf("") << endl;   // 0
	cout << s52.IndexOf("A") << endl; // -1

	MyString s53("Hellello");
	MyString s54("Heloo");
	cout << s53.IndexOf("ell") << endl;   // 1
	cout << s54.IndexOf("ell") << endl;   // -1

	/* LastIndexOf() Ex */
	cout << "-----------------------" << endl;
	cout << "LastIndexOf()" << endl;
	MyString s6("Hello");
	cout << s6.LastIndexOf("ell") << endl;   // 1
	cout << s6.LastIndexOf("l") << endl;     // 3
	cout << s6.LastIndexOf("This") << endl;  // -1
	cout << s6.LastIndexOf("") << endl;   // 5
	cout << s6.LastIndexOf("He") << endl;   // 0

	MyString s62("");
	cout << s62.LastIndexOf("") << endl;  // 0
	cout << s62.LastIndexOf("A") << endl; // -1

	MyString s63("Hellello");
	MyString s64("Heloo");
	cout << s63.LastIndexOf("ell") << endl;   // 4
	cout << s64.LastIndexOf("ell") << endl;   // -1

	/* Interleave() Ex */
	cout << "-----------------------" << endl;
	cout << "Interleave()" << endl;
	MyString s7("Hello");
	s7.Interleave(" World");
	cout << s7.GetCString() << endl;  //H eWlolrold

	MyString s72("A");
	s72.Interleave("BCDEF");
	cout << s72.GetCString() << endl;  // ABCDEF

	MyString s73("bcdef");
	s73.Interleave("a");
	cout << s73.GetCString() << endl;  // bacdef

	/* RemoveAt() Ex */
	cout << "-----------------------" << endl;
	cout << "RemoveAt()" << endl;
	MyString s8("Hello");
	cout << boolalpha << s8.RemoveAt(0) << ", ";   // true,
	cout << s8.GetCString() << endl;               // ello
	cout << boolalpha << s8.RemoveAt(2) << ", ";   // true,
	cout << s8.GetCString() << endl;               // elo
	cout << boolalpha << s8.RemoveAt(4) << ", ";   // false,
	cout << s8.GetCString() << endl;               // elo

	MyString s82("");
	cout << boolalpha << s82.RemoveAt(0) << endl;  //false

	/* PadLeft() Ex */
	cout << "-----------------------" << endl;
	cout << "PadLeft()" << endl;
	MyString s9("Hello");
	s9.PadLeft(2);  // "Hello"
	cout << s9.GetCString() << endl;
	s9.PadLeft(8);  // "   Hello"
	cout << s9.GetCString() << endl;

	MyString s92("World");
	s92.PadLeft(3, '-');  // "World"
	cout << s92.GetCString() << endl;
	s92.PadLeft(7, '-');  // "--World"
	cout << s92.GetCString() << endl;

	/* PadRight() Ex */
	cout << "-----------------------" << endl;
	cout << "PadRight()" << endl;
	MyString s10("Hello");
	s10.PadRight(2);  // "Hello"
	cout << s10.GetCString() << endl;
	s10.PadRight(8);  // "Hello   "
	cout << s10.GetCString() << '|' << endl;// 공백 확인 위한 |

	MyString s102("World");
	s102.PadRight(3, '-');  // "World"
	cout << s102.GetCString() << endl;
	s102.PadRight(7, '-');  // "World--"
	cout << s102.GetCString() << endl;

	/* Reverse() Ex */
	cout << "-----------------------" << endl;
	cout << "Reverse()" << endl;
	MyString s11("Hello");
	s11.Reverse();  // olleH
	cout << s11.GetCString() << endl;

	MyString s112("Banana");
	s112.Reverse();   // ananaB
	cout << s112.GetCString() << endl;

	MyString s113("A");
	s113.Reverse();   // A
	cout << s113.GetCString() << endl;

	MyString s114("");
	s114.Reverse();   // 
	cout << s114.GetCString() << endl;

	/* operator== Ex */
	cout << "-----------------------" << endl;
	cout << "operator==" << endl;
	MyString s121("Hello");
	MyString s122("Hello");
	MyString s123("World");
	MyString s124("Hello ");

	cout << boolalpha << (s121 == s122) << endl;   // true
	cout << boolalpha << (s121 == s123) << endl;   // false
	cout << boolalpha << (s121 == s124) << endl;   // false

	/* ToLower() Ex */
	cout << "-----------------------" << endl;
	cout << "ToLower()" << endl;
	MyString s131("HEllo 123K");
	MyString s132("A To z");
	s131.ToLower();   // "hello 123k"
	s132.ToLower();   // "a to z"
	cout << s131.GetCString() << endl;
	cout << s132.GetCString() << endl;

	/* ToUpper() Ex */
	cout << "-----------------------" << endl;
	cout << "ToUpper()" << endl;
	MyString s141("HEllo 123K");
	MyString s142("A To z");
	s141.ToUpper();   // "HELLO 123K"
	s142.ToUpper();   // "A TO Z"
	cout << s141.GetCString() << endl;
	cout << s142.GetCString() << endl;
}

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

	test();

	cout << "Done!" << endl;
}

