#pragma once
#include <stack>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	private:
		std::stack<T> mStack;
		std::stack<T> mMinStack;
		std::stack<T> mMaxStack;

		unsigned int mCount;

		T mMin;
		T mMax;

		T mSum;
		T mSqrSum;
	
	public:
		SmartStack();
		virtual ~SmartStack();

		void Push(const T ele);
		T Pop();
		T Peek() const;
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	};


	template<typename T>
	inline SmartStack<T>::SmartStack()
		: mCount(0), mSum(0), mSqrSum(0)
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
	}

	template<typename T>
	inline SmartStack<T>::~SmartStack()
	{
	}

	template<typename T>
	inline void SmartStack<T>::Push(const T ele)
	{
		mStack.push(ele);

		if (mMin > ele)
		{
			mMin = ele;
		}

		if (mMax < ele)
		{
			mMax = ele;
		}

		mMinStack.push(mMin);
		mMaxStack.push(mMax);

		mSum += ele;
		mSqrSum += ele * ele;

		mCount++;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T popped = mStack.top();

		mStack.pop();
		mMinStack.pop();
		mMaxStack.pop();

		mSum -= popped;
		mSqrSum -= popped * popped;

		mCount--;

		if (mCount != 0)
		{
			mMin = mMinStack.top();
			mMax = mMaxStack.top();
		}
		else
		{
			mMin = std::numeric_limits<T>::max();
			mMax = std::numeric_limits<T>::lowest();
		}

		return popped;
	}

	template<typename T>
	inline T SmartStack<T>::Peek() const
	{
		return mStack.top();
	}

	template<typename T>
	inline T SmartStack<T>::GetMax() const
	{
		if (mMaxStack.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		else
		{
			return mMaxStack.top();
		}
		
	}

	template<typename T>
	inline T SmartStack<T>::GetMin() const
	{
		if (mMinStack.empty())
		{
			return std::numeric_limits<T>::max();
		}
		else
		{
			return mMinStack.top();
		}
	}

	template<typename T>
	inline double SmartStack<T>::GetAverage() const
	{
		double sum = static_cast<double>(mSum);
		double count = static_cast<double>(mCount);
		return sum / count;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance() const
	{
		double sum = static_cast<double>(mSum);
		double sqrSum = static_cast<double>(mSqrSum);
		double count = static_cast<double>(mCount);

		return sqrSum / count - (sum / count) * (sum / count);
	}

	template<typename T>
	inline double SmartStack<T>::GetStandardDeviation() const
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartStack<T>::GetCount() const
	{
		return mCount;
	}
}