#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);

		Storage(Storage&& other);
		Storage(const Storage& other);

		Storage<T>& operator=(Storage&& other);
		Storage<T>& operator=(const Storage& other);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
	private:
		std::unique_ptr<T[]> mData;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
	{
		mData = std::make_unique<T[]>(mLength);
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
	{
		mData = std::make_unique<T[]>(mLength);

		for (unsigned int i = 0; i < mLength; i++)
		{
			*(mData.get() + i) = initialValue;
		}

	}

	template<typename T>
	Storage<T>::Storage(Storage&& other)
		: mLength(other.mLength)
	{
		mData = std::move(other.mData);

		other.mData = nullptr;
		other.mLength = 0;
	}

	template<typename T>
	Storage<T>::Storage(const Storage& other)
		: mLength(other.mLength)
	{
		mData = std::make_unique<T[]>(mLength);

		for (unsigned int i = 0; i < mLength; i++)
		{
			*(mData.get() + i) = *(other.mData.get() + i);
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage&& other)
	{
		if (this != &other)
		{
			mData.reset();

			mData = std::move(other.mData);
			mLength = other.mLength;

			other.mData = nullptr;
			other.mLength = 0;
		}

		return *this;
	}

	template<typename T>
	inline Storage<T>& Storage<T>::operator=(const Storage& other)
	{
		if (this != &other)
		{
			mData.reset();

			mData = std::make_unique<T[]>(mLength);
			mLength = other.mLength;

			for (unsigned int i = 0; i < mLength; i++)
			{
				*(mData.get() + i) = *(other.mData.get() + i);
			}
		}

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mLength)
		{
			*(mData.get() + index) = data;
			return true;
		}

		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return mData;
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}