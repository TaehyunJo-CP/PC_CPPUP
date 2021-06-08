#include "Lab6.h"
#include <map>

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		int res = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++) 
		{
			res += *iter;
		}

		return res;
	}

	int Min(const std::vector<int>& v)
	{
		int res = INT_MAX;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++) 
		{
			if (res > *iter)
			{
				res = *iter;
			}
		}

		return res;
	}

	int Max(const std::vector<int>& v)
	{
		int res = INT_MIN;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++) 
		{
			if (res < *iter)
			{
				res = *iter;
			}
		}

		return res;
	}

	float Average(const std::vector<int>& v)
	{
		float res = static_cast<float>(Sum(v)) / static_cast<float>(v.size());
		return res;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		std::map<int, int> vote;

		int maxVotes = 0;
		int maxKey = 0;

		for (std::vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++) 
		{
			int key = *iter;
			if (vote.find(key) == vote.end())
			{
				vote[key] = 1;
			}
			else
			{
				vote[key] += 1;
			}

			if (vote[key] > maxVotes)
			{
				maxVotes = vote[key];
				maxKey = key;
			}
		}

		return maxKey;
	}

	void SortDescending(std::vector<int>& v)
	{
		quick_sort(v, 0, v.size() - 1);
	}

	void quick_sort(std::vector<int>& v, int start, int end)
	{
		if (start >= end)
		{
			return;
		}

		int pivot = start;
		int i = pivot + 1;
		int j = end;

		int tmp;

		while (i <= j)
		{
			while (i <= end && v[i] >= v[pivot])
			{
				i++;
			}

			while (j > start && v[j] <= v[pivot])
			{
				j--;
			}

			if (i > j)
			{
				tmp = v[j];
				v[j] = v[pivot];
				v[pivot] = tmp;
			}
			else
			{
				tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}

		quick_sort(v, start, j - 1);
		quick_sort(v, j + 1, end);
	}

}