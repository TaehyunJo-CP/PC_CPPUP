#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();

		TimeSheet& operator=(const TimeSheet& other);
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
		std::string mName;
		unsigned int mMaxEntries;
		int* mTimes;
		unsigned int mCountEntries = 0;
	};
}