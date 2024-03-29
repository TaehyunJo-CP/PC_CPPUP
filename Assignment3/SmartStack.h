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

		T mSumT;
		double mSqrSum;
	
	public:
		SmartStack();
		SmartStack(SmartStack<T>& other);
		SmartStack<T>& operator=(SmartStack<T>& other);
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
		: mCount(0), mSqrSum(0), mSumT(0)
	{
		mMin = std::numeric_limits<T>::max();
		mMax = std::numeric_limits<T>::lowest();
	}

	template<typename T>
	inline SmartStack<T>::SmartStack(SmartStack<T>& other)
	{
		mStack = std::stack<T>(other.mStack);
		mMinStack = std::stack<T>(other.mMinStack);
		mMaxStack = std::stack<T>(other.mMaxStack);

		mCount = other.mCount;

		mMin = other.mMin;
		mMax = other.mMax;

		mSumT = other.mSumT;
		mSqrSum = other.mSqrSum;
	}

	template<typename T>
	inline SmartStack<T>& SmartStack<T>::operator=(SmartStack<T>& other)
	{
		if (this == &other)
		{
			return *this;
		}

		mStack = std::stack<T>(other.mStack);
		mMinStack = std::stack<T>(other.mMinStack);
		mMaxStack = std::stack<T>(other.mMaxStack);

		mCount = other.mCount;

		mMin = other.mMin;
		mMax = other.mMax;

		mSumT = other.mSumT;
		mSqrSum = other.mSqrSum;

		return *this;
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

		mSumT += ele;
		double v = static_cast<double>(ele);
		mSqrSum += v * v;

		mCount++;
	}

	template<typename T>
	inline T SmartStack<T>::Pop()
	{
		T popped = mStack.top();

		mStack.pop();
		mMinStack.pop();
		mMaxStack.pop();

		mSumT -= popped;
		double v = static_cast<double>(popped);
		mSqrSum -= v * v;

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
		double sum = static_cast<double>(mSumT);
		double count = static_cast<double>(mCount);
		return sum / count;
	}

	template<typename T>
	inline T SmartStack<T>::GetSum() const
	{
		return mSumT;
	}

	template<typename T>
	inline double SmartStack<T>::GetVariance() const
	{
		double sum = static_cast<double>(mSumT);
		double count = static_cast<double>(mCount);

		return mSqrSum / count - (sum / count) * (sum / count);
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