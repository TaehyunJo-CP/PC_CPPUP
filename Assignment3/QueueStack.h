#pragma once
#include <queue>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	private:
		std::queue<stack<T>> mQueue;
		unsigned int mTotalCount;
		unsigned int mStackCount;
		unsigned int mStackSize;
	public:
		QueueStack(unsigned int maxStackSize);
		virtual ~QueueStack();

		void Enqueue(const T ele);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mTotalCount(0), mStackCount(0), mStackSize(maxStackSize)
	{
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(const T ele)
	{
		if (mTotalCount % mStackSize == 0)
		{
			mQueue.push(stack<T>());
			mStackCount++;
		}

		stack<T> selectedStack = mQueue.back();
		sele

			mTotalCount++;
	}





}