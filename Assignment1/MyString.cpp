#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mLength(0)
	{
		mLength = getCStringLength(s);

		mStr = new char[mLength + 1];

		for (int i = 0; i < mLength + 1; i++)
		{
			mStr[i] = s[i];
		}
		
	}

	MyString::MyString(const MyString& other)
	{
		mLength = other.GetLength();
		const char* s = other.GetCString();

		mStr = new char[mLength + 1];

		for (int i = 0; i < mLength + 1; i++)
		{
			mStr[i] = s[i];
		}
	}

	MyString::~MyString()
	{
		delete[] mStr;
	}

	unsigned int MyString::GetLength() const
	{
		return mLength;
	}

	const char* MyString::GetCString() const
	{
		return mStr;
	}

	void MyString::Append(const char* s)
	{
		int addLength = getCStringLength(s);

		if (addLength == 0)
		{
			return;
		}

		char* newStr = new char[mLength + addLength + 1];

		for (int i = 0; i < mLength; i++)
		{
			newStr[i] = mStr[i];
		}

		for (int i = 0; i < addLength + 1; i++)
		{
			newStr[mLength + i] = s[i];
		}

		delete[] mStr;
		mStr = newStr;

		mLength += addLength;

	}

	MyString MyString::operator+(const MyString& other) const
	{
		MyString newMyString(*this);
		newMyString.Append(other.GetCString());
		return newMyString;
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int checkLen = (unsigned int)getCStringLength(s);

		if (checkLen > GetLength())
		{
			return -1;
		}

		for (unsigned int i = 0; i < this->GetLength() - checkLen + 1; i++)
		{
			bool bIsMatch = true;
			for (unsigned int j = 0; j < checkLen; j++)
			{
				if (this->mStr[i + j] != s[j])
				{
					bIsMatch = false;
				}
			}
			if (bIsMatch)
			{
				return i;
			}
		}
		return -1;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int checkLen = getCStringLength(s);

		int targetIdx = -1;
		if (checkLen > GetLength())
		{
			return targetIdx;
		}

		for (unsigned int i = 0; i < this->GetLength() - checkLen + 1; i++)
		{
			bool bIsMatch = true;
			for (int j = 0; j < checkLen; j++)
			{
				if (this->mStr[i + j] != s[j])
				{
					bIsMatch = false;
				}
			}
			if (bIsMatch)
			{
				targetIdx = i;
			}
		}
		return targetIdx;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int len = (unsigned int)getCStringLength(s);
		if (len == 0)
		{
			return;
		}

		char* newStr = new char[mLength + len + 1];
		char* tmp = newStr;

		bool bIsleftBig = GetLength() > len;
		int diff = bIsleftBig ? GetLength() - len : len - GetLength();
		int firstIter = bIsleftBig ? len : GetLength();

		int restart = 0;
		for (int i = 0; i < firstIter; i++)
		{
			*tmp = mStr[i];
			tmp++;
			*tmp = s[i];
			tmp++;
			restart = i;
		}

		for (int j = 0; j < diff; j++)
		{
			if(bIsleftBig)
			{
				*tmp = mStr[restart + j + 1];
			}
			else
			{
				*tmp = s[restart + j + 1];
			}
			tmp++;
		}

		*tmp = '\0';

		delete[] mStr;
		mStr = newStr;
		mLength += len;
	}

	bool MyString::RemoveAt(unsigned int i)
	{
		if (i < GetLength())
		{
			char* newStr = new char[mLength];

			char* tmp = newStr;
			for (int j = 0; j < mLength + 1; j++)
			{
				if (j != i)
				{
					*tmp = mStr[j];
					tmp++;
				}
			}

			delete[] mStr;
			mStr = newStr;
			mLength -= 1;
			return true;
		}
		return false;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		PadLeft(totalLength, ' ');
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (GetLength() < totalLength)
		{
			int howManyChars = totalLength - GetLength();
			char* newStr = new char[totalLength + 1];

			char* tmp = newStr;

			for (int i = 0; i < howManyChars; i++)
			{
				*tmp = c;
				tmp++;
			}

			for (int i = 0; i < mLength + 1; i++)
			{
				*tmp = mStr[i];
				tmp++;
			}

			delete[] mStr;
			mStr = newStr;
			mLength = totalLength;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		PadRight(totalLength, ' ');
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (GetLength() < totalLength)
		{
			int howManyChars = totalLength - GetLength();
			char* newStr = new char[totalLength + 1];

			char* tmp = newStr;

			for (int i = 0; i < mLength; i++)
			{
				*tmp = mStr[i];
				tmp++;
			}
			
			for (int i = 0; i < howManyChars; i++)
			{
				*tmp = c;
				tmp++;
			}

			*tmp = '\0';

			delete[] mStr;
			mStr = newStr;
			mLength = totalLength;
		}
	}

	void MyString::Reverse()
	{
		char tmp;
		for (unsigned int i = 0; i < GetLength() / 2; i++)
		{
			tmp = mStr[i];
			mStr[i] = mStr[GetLength() - 1 - i];
			mStr[GetLength() - 1 - i] = tmp;
		}

	}

	bool MyString::operator==(const MyString& rhs) const
	{
		if (rhs.GetLength() == this->GetLength())
		{
			const char* rStr = rhs.GetCString();
			const char* lStr = this->GetCString();

			for (unsigned int i = 0; i < this->GetLength() + 1; i++)
			{
				if (rStr[i] != lStr[i])
				{
					return false;
				}
			}
			return true;   
		}
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		if (&rhs == this)
		{
			return *this;
		}

		char* newStr = new char[rhs.GetLength() + 1];
		for (unsigned int i = 0; i < rhs.GetLength() + 1; i++)
		{
			newStr[i] = rhs.GetCString()[i];
		}

		delete[] mStr;
		mStr = newStr;
		mLength = rhs.GetLength();

		return *this;
	}

	void MyString::ToLower()
	{
		for (unsigned int i = 0; i < GetLength(); i++)
		{
			if ((mStr[i] > 64) && (mStr[i] < 91))
			{
				mStr[i] ^= 0x20;
			}
		}

	}

	void MyString::ToUpper()
	{
		for (unsigned int i = 0; i < GetLength(); i++)
		{
			if ((mStr[i] > 96) && (mStr[i] < 123))
			{
				mStr[i] ^= 0x20;
			}
		}
	}

	unsigned int MyString::getCStringLength(const char* s) const
	{   
		const char* tmp = s;
		int len = 0;
		while (*tmp != '\0')
		{
			len++;
			tmp++;
		}
		return len;
	}

}