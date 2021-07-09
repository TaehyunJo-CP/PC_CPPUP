#pragma once
#include <queue>
#include <stack>
#include <limits>
#include <cmath>
#include <vector>

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
		virtual ~QueueStack();

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
		T max = std::numeric_limits<T>::min();

		for (unsigned int i = 0; i < mQueue.size(); i++)
		{
			std::stack<T>* front = mQueue.front();
			mQueue.pop();

			std::vector<T> tmp;

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				if (top > max)
				{
					max = top;
				}
				tmp.push_back(top);

				front->pop();
			}

			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				front->push(tmp[j]);
			}

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

			std::vector<T> tmp;

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				if (top < min)
				{
					min = top;
				}
				tmp.push_back(top);

				front->pop();
			}

			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				front->push(tmp[j]);
			}

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

			std::vector<T> tmp;

			int s = front->size();
			for (int j = 0; j < s; j++)
			{
				T top = front->top();
				
				sum += top;

				tmp.push_back(top);

				front->pop();
			}

			for (int j = tmp.size() - 1; j >= 0; j--)
			{
				front->push(tmp[j]);
			}

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