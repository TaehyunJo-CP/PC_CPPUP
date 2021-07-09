#pragma once
#include <queue>
#include <stack>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	private:
		std::queue<std::stack<T>*> mQueue;
		unsigned int mStackSize;

	public:
		QueueStack(unsigned int maxStackSize);
		QueueStack(QueueStack& other);
		virtual ~QueueStack();

		QueueStack<T>& operator=(QueueStack<T>& other);

		void Enqueue(const T ele);
		T Peek() const;
		T Dequeue();
		T GetMax();
		T GetMin();
		double GetAverage();
		T GetSum();
		unsigned int GetCount();
		unsigned int GetStackCount();
	};

	template<typename T>
	inline QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mStackSize(maxStackSize)
	{
	}

	template<typename T>
	inline QueueStack<T>::QueueStack(QueueStack& other)
		:mStackSize(other.mStackSize)
	{
		for (unsigned int i = 0; i < other.mQueue.size(); i++)
		{
			std::stack<T>* front = other.mQueue.front();
			other.mQueue.pop();

			mQueue.push(new std::stack<T>(*front));

			other.mQueue.push(front);
		}
	}

	template<typename T>
	inline QueueStack<T>::~QueueStack()
	{
		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();
			delete front;
		}
	}

	template<typename T>
	inline QueueStack<T>& QueueStack<T>::operator=(QueueStack<T>& other)
	{
		if (&other == this)
		{
			return *this;
		}

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();
			delete front;
		}

		mStackSize = other.mStackSize;

		for (unsigned int i = 0; i < other.mQueue.size(); i++)
		{
			std::stack<T>* front = other.mQueue.front();
			other.mQueue.pop();

			mQueue.push(new std::stack<T>(*front));

			other.mQueue.push(front);
		}

		return *this;
	}

	template<typename T>
	inline void QueueStack<T>::Enqueue(const T ele)
	{
		std::stack<T>* selectedStack;
		if (mQueue.size() != 0)
		{
			selectedStack = mQueue.back();
			if (selectedStack->size() == mStackSize)
			{
				std::stack<T>* newStack = new std::stack<T>();
				mQueue.push(newStack);
			}
		}
		else
		{
			std::stack<T>* newStack = new std::stack<T>();
			mQueue.push(newStack);
		}

		selectedStack = mQueue.back();
		selectedStack->push(ele);
	}

	template<typename T>
	inline T QueueStack<T>::Peek() const
	{
		return mQueue.front()->top();
	}

	template<typename T>
	inline T QueueStack<T>::Dequeue()
	{
		std::stack<T>* selectedStack = mQueue.front();

		T ele = selectedStack->top();
		selectedStack->pop();
		if (selectedStack->size() == 0)
		{
			mQueue.pop();
		}

		return ele;
	}

	template<typename T>
	inline T QueueStack<T>::GetMax()
	{
		T max = std::numeric_limits<T>::lowest();

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();

			std::stack<T>* tmp = new std::stack<T>(*front);

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				if (max < top)
				{
					max = top;
				}
				front->pop();
			}

			delete front;
			front = tmp;

			mQueue.push(front);
		}

		return max;
	}

	template<typename T>
	inline T QueueStack<T>::GetMin()
	{
		T min = std::numeric_limits<T>::max();

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();

			std::stack<T>* tmp = new std::stack<T>(*front);

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				if (min > top)
				{
					min = top;
				}
				front->pop();
			}

			delete front;
			front = tmp;

			mQueue.push(front);
		}

		return min;
	}

	template<typename T>
	inline double QueueStack<T>::GetAverage()
	{
		double sum = static_cast<double>(GetSum());
		double count = static_cast<double>(GetCount());
		return sum / count;
	}


	template<typename T>
	inline T QueueStack<T>::GetSum()
	{
		T sum = 0;

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();

			std::stack<T>* tmp = new std::stack<T>(*front);

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				sum += top;
				front->pop();
			}

			delete front;
			front = tmp;

			mQueue.push(front);
		}

		return sum;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetCount()
	{
		unsigned int count = 0;

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();
			count += front->size();
			mQueue.push(front);
		}

		return count;
	}

	template<typename T>
	inline unsigned int QueueStack<T>::GetStackCount()
	{
		return mQueue.size();
	}





}