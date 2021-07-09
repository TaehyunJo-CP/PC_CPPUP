#pragma once
#include <queue>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	private:
		std::queue<T> mQueue;

		unsigned int mCount;
		double mSum;
		double mSqrSum;

	public:
		SmartQueue();
		SmartQueue(SmartQueue& other);
		virtual ~SmartQueue();
		SmartQueue<T>& operator=(SmartQueue<T>& other);

		void Enqueue(const T ele);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
	};

	template<typename T>
	inline SmartQueue<T>::SmartQueue()
		: mCount(0), mSum(0), mSqrSum(0)
	{
	}

	template<typename T>
	inline SmartQueue<T>::SmartQueue(SmartQueue& other)
	{
		mQueue = std::queue<T>(other.mQueue);

		mCount = other.mCount;
		mSum = other.mSum;
		mSqrSum = other.mSqrSum;
	}

	template<typename T>
	inline SmartQueue<T>::~SmartQueue()
	{
	}

	template<typename T>
	inline SmartQueue<T>& SmartQueue<T>::operator=(SmartQueue<T>& other)
	{
		if (&other == this)
		{
			return *this;
		}

		mQueue = std::queue<T>(other.mQueue);

		mCount = other.mCount;
		mSum = other.mSum;
		mSqrSum = other.mSqrSum;

		return *this;
	}

	template<typename T>
	inline void SmartQueue<T>::Enqueue(const T ele)
	{
		mQueue.push(ele);
		mCount++;

		double v = static_cast<double>(ele);

		mSum += v;
		mSqrSum += v * v;
	}

	template<typename T>
	inline T SmartQueue<T>::Peek() const
	{
		return mQueue.front();
	}

	template<typename T>
	inline T SmartQueue<T>::Dequeue()
	{
		T front = mQueue.front();
		mQueue.pop();

		mCount--;

		double v = static_cast<double>(front);

		mSum -= v;
		mSqrSum -= v * v;

		return front;
	}

	template<typename T>
	inline T SmartQueue<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();

		for (unsigned int i = 0; i < mCount; i ++)
		{
			T ele = Dequeue();

			if (max < ele)
			{
				max = ele;
			}

			Enqueue(ele);
		}

		return max;
		
	}

	template<typename T>
	inline T SmartQueue<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		for (unsigned int i = 0; i < mCount; i++)
		{
			T ele = Dequeue();

			if (min > ele)
			{
				min = ele;
			}

			Enqueue(ele);
		}

		return min;
	}

	template<typename T>
	inline double SmartQueue<T>::GetAverage() const
	{
		double sum = static_cast<double>(mSum);
		double count = static_cast<double>(mCount);

		return sum / count;
	}

	template<typename T>
	inline T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	inline double SmartQueue<T>::GetVariance() const
	{
		double sum = static_cast<double>(mSum);
		double sqrSum = static_cast<double>(mSqrSum);
		double count = static_cast<double>(mCount);

		return sqrSum / count - (sum / count) * (sum / count);
	}

	template<typename T>
	inline double SmartQueue<T>::GetStandardDeviation() const
	{
		return sqrt(GetVariance());
	}

	template<typename T>
	inline unsigned int SmartQueue<T>::GetCount() const
	{
		return mCount;
	}

}