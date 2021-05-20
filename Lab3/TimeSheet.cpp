#include "TimeSheet.h"
#include <cmath>
#include <string>

namespace lab3
{

	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mName = name;
		mMaxEntries = maxEntries;
		mTimes = new int[mMaxEntries];
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
		:mMaxEntries(other.mMaxEntries)
		,mCountEntries(other.mCountEntries)
	{
		mName = other.GetName();
		mTimes = new int[mMaxEntries];
		memcpy(mTimes, other.mTimes, sizeof(int) * mMaxEntries);
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours >= 1 && timeInHours <= 10 && mMaxEntries > mCountEntries)
		{
			mTimes[mCountEntries] = timeInHours;
			mCountEntries++;
		}
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTimes;
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= 0 && index < mCountEntries)
		{
			return mTimes[index];
		}
		return -1;
	}

	int TimeSheet::GetTotalTime() const
	{
		int total = 0;
		for (unsigned int i = 0; i < mCountEntries; i++)
		{
			total += mTimes[i];
		}
		return total;
	}

	TimeSheet& TimeSheet::operator=(const TimeSheet& other)
	{
		if(&other == this)
		{
			return *this;
		}

		mName = other.GetName();
		mMaxEntries = other.mMaxEntries;
		mCountEntries = other.mCountEntries;

		delete[] mTimes;
		mTimes = new int[mMaxEntries];
		memcpy(mTimes, other.mTimes, sizeof(int) * mMaxEntries);
		return *this;
	}

	float TimeSheet::GetAverageTime() const
	{
		float sum = static_cast<float>(GetTotalTime());
		float count = static_cast<float>(mCountEntries);
		if (count == 0.0f)
		{
			return 0.0f;
		}
		return sum / count;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		if (mCountEntries == 0)
		{
			return 0.0f;
		}

		float sum = 0.0f;
		float count = static_cast<float>(mCountEntries);

		float avg = GetAverageTime();

		float e;
		float diff;
		for (unsigned int i = 0; i < mCountEntries; i++)
		{
			e = static_cast<float>(mTimes[i]);
			diff = (e - avg);
			diff = diff * diff;
			sum += diff;
		}

		return sqrt(sum / count);
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}