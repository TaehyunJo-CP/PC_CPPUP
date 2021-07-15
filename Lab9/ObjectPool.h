#pragma once
#include <deque>
#include <cassert>

namespace lab9
{
	template<typename T>
	class ObjectPool
	{
	public:
		ObjectPool(size_t maxPoolSize)
			: mMaxPoolSize(maxPoolSize)
		{
		}

		ObjectPool(ObjectPool& other) = delete;
		ObjectPool& operator=(ObjectPool& other) = delete;

		virtual ~ObjectPool()
		{
			unsigned int s = mPool.size();
			for (unsigned int i = 0; i < s; i++)
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

	private:
		const size_t mMaxPoolSize;
		std::deque<T*> mPool;

	};
}