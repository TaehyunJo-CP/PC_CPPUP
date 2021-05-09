#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char* s)
        : mLength(0)
    {
        mLength = GetCStringLength(s);

        mStr = new char[mLength + 1];

        for(int i = 0; i < mLength + 1; i++)
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
        int addLength = GetCStringLength(s);

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
        int checkLen = GetCStringLength(s);

        for(int i = 0; i < this->GetLength() - checkLen + 1; i++)
        {
            bool isMatch = true;
            for(int j = 0; j < checkLen; j++)
            {
                if (this->mStr[i + j] != s[j])
                {
                    isMatch = false;
                }
            }
            if (isMatch)
            {
                return i;
            }
        }
        return -1;
    }

    int MyString::LastIndexOf(const char* s)
    {
        int checkLen = GetCStringLength(s);

        int targetIdx = -1;

        for (int i = 0; i < this->GetLength() - checkLen + 1; i++)
        {
            bool isMatch = true;
            for (int j = 0; j < checkLen; j++)
            {
                if (this->mStr[i + j] != s[j])
                {
                    isMatch = false;
                }
            }
            if (isMatch)
            {
                targetIdx = i;
            }
        }
        return targetIdx;
    }

    void MyString::Interleave(const char* s)
    {
        int len = GetCStringLength(s);

        char* newStr = new char[mLength + len + 1];
        char* tmp = newStr;

        bool leftBig = GetLength() > len;
        int diff = leftBig ? GetLength() - len : len - GetLength();
        int firstIter = leftBig ? len : GetLength();

        int restart;
        for(int i = 0; i < firstIter; i++)
        {
            *tmp = mStr[i];
            tmp++;
            *tmp = s[i];
            tmp++;
            restart = i;
        }

        for (int j = 0; j < diff; j++)
        {
            if(leftBig)
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

            for(int i = 0; i < howManyChars; i++)
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
        for (int i = 0; i < GetLength() / 2; i++)
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

            for(int i = 0; i < this->GetLength() + 1; i++)
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
        return *this;
    }

    void MyString::ToLower()
    {
        for (int i = 0; i < GetLength(); i++) 
        {
            if ((mStr[i] > 64) && (mStr[i] < 91))
            {
                mStr[i] ^= 0x20;
            }
        }

    }

    void MyString::ToUpper()
    {
        for (int i = 0; i < GetLength(); i++) 
        {
            if ((mStr[i] > 96) && (mStr[i] < 123))
            {
                mStr[i] ^= 0x20;
            }
        }
    }

    int MyString::GetCStringLength(const char* s) const
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