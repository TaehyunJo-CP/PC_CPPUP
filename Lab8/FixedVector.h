#pragma once

namespace lab8
{

	template <typename T, size_t N>
	class FixedVector
	{
	private:
		T mArr[N];
		size_t mSize;
		size_t mCapacity;
	public:
		FixedVector();
		bool Add(T& ele);
		bool Remove(T& ele);
		const T& Get(unsigned int index) const;
		T& operator[](unsigned int index);
		int GetIndex(T& ele) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0), mCapacity(N)
	{
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(T& ele)
	{
		if (mSize < mCapacity)
		{
			mArr[mSize] = ele;
			mSize++;
			return true;
		} 
		else
		{
			return false;
		}
	}

	template<typename T, size_t N>
	inline bool FixedVector<T, N>::Remove(T& ele)
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArr[i] == ele)
			{
				for (size_t j = i; j < mSize - 1; j++)
				{
					mArr[j] = mArr[j + 1];
				}
				mSize--;
				return true;
			}
		}

		return false;
	}

	template<typename T, size_t N>
	inline const T& FixedVector<T, N>::Get(unsigned int index) const
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		return mArr[index];
	}

	template<typename T, size_t N>
	inline int FixedVector<T, N>::GetIndex(T& ele) const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			if (mArr[i] == ele)
			{
				return i;
			}
		}
		return -1;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	inline size_t FixedVector<T, N>::GetCapacity() const
	{
		return mCapacity;
	}

}
