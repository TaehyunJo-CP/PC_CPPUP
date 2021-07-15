#pragma once
#include <deque>

namespace lab9
{
	template<typename T>
	class ObjectPool
	{

	private:
		const size_t mMaxPoolSize;
		std::deque<T*> mPool;

	public:
		ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		{
		}

		virtual ~ObjectPool()
		{
			for (int i = 0; i < mPool.size(); i++)
			{
				T* t = mPool.front();
				mPool.pop_front();

				delete t;
			}
		}

		T* Get()
		{
			if (mPool.size() == 0)
			{
				return new T;
			}
			else
			{
				T* t = mPool.front();
				mPool.pop_front();

				return t;
			}
		}

		void Return(T* t)
		{
			assert(mPool.size() <= mMaxPoolSize);

			if (mPool.size() == mMaxPoolSize)
			{
				delete t;
			}
			else
			{
				mPool.push_back(t);
			}
		}

		size_t GetMaxFreeObjectCount()
		{
			return mMaxPoolSize;
		}

		size_t GetFreeObjectCount()
		{
			return mPool.size();
		}
	};
}