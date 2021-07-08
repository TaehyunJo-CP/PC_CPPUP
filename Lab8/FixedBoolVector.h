#pragma once

namespace lab8
{

	template <size_t N>
	class FixedVector<bool, N>
	{
	private:
		uint32_t mArr[N / 32 + 1];
		size_t mSize;
		size_t mCapacity;
	public:
		FixedVector();
		bool Add(bool ele);
		bool Remove(bool ele);
		bool Get(unsigned int index) const;
		bool operator[](unsigned int index);
		int GetIndex(bool ele) const;
		size_t GetSize() const;
		size_t GetCapacity() const;
	};

	template <size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0), mCapacity(N)
	{
		for(size_t i = 0; i < N / 32 + 1; i++)
		{
			mArr[i] = 0;
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(bool ele)
	{
		if (mSize < mCapacity)
		{
			size_t arrIdx = mSize / 32;
			size_t spcIdx = mSize % 32;
			if (ele)
			{
				mArr[arrIdx] ^= (-1 ^ mArr[arrIdx]) & (1UL << spcIdx);
			}
			else
			{
				mArr[arrIdx] ^= (0 ^ mArr[arrIdx]) & (1UL << spcIdx);
			}
			
			mSize++;
			return true;
		} else
		{
			return false;
		}
	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Remove(bool ele)
	{
		int findIdx = GetIndex(ele);

		if (findIdx == -1)
		{
			return false;
		}

		size_t startIdx = static_cast<size_t>(findIdx);

		for(size_t i = startIdx; i < mSize - 1; i++)
		{
			size_t arrIdx = i / 32;
			size_t spcIdx = i % 32;

			size_t nextArrIdx = (i + 1) / 32;
			size_t nextSpcIdx = (i + 1) % 32;

			size_t nextBit = (mArr[nextArrIdx] >> nextSpcIdx) & 1U;

			if (nextBit == 1)
			{
				mArr[arrIdx] ^= (-1 ^ mArr[arrIdx]) & (1UL << spcIdx);
			}
			else if (nextBit == 0)
			{
				mArr[arrIdx] ^= (0 ^ mArr[arrIdx]) & (1UL << spcIdx);
			}
		}
	
		mSize--;
		return true;

	}

	template<size_t N>
	inline bool FixedVector<bool, N>::Get(unsigned int index) const
	{
		size_t arrIdx = index / 32;
		size_t spcIdx = index % 32;

		size_t bit = (mArr[arrIdx] >> spcIdx) & 1U;
		if (bit == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return Get(index);
	}

	template<size_t N>
	inline int FixedVector<bool, N>::GetIndex(bool ele) const
	{
		for (size_t i = 0; i < mSize; i++)
		{
			size_t arrIdx = i / 32;
			size_t spcIdx = i % 32;

			size_t bit = (mArr[arrIdx] >> spcIdx) & 1U;

			if (ele == true && bit == 1)
			{
				return i;
			}
			else if (ele == false && bit == 0)
			{
				return i;
			}

		}
		return -1;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	inline size_t FixedVector<bool, N>::GetCapacity() const
	{
		return mCapacity;
	}

}
