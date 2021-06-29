#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;

		int minLength = std::min(keys.size(), values.size());
		for (int i = 0; i < minLength; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}
		
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			v.push_back(it->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		int backIndex;
		int vSize = v.size();
		for (int i = 0; i < vSize; i++)
		{
			backIndex = vSize - i - 1;
			rv.push_back(v[backIndex]);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		for (int i = 0; i < v1.size(); i++)
		{
			T v = v1[i];
			if (std::find(combined.begin(), combined.end(), v) == combined.end())
			{
				combined.push_back(v);
			}
		}

		for (int i = 0; i < v2.size(); i++)
		{
			T v = v2[i];
			if (std::find(combined.begin(), combined.end(), v) == combined.end())
			{
				combined.push_back(v);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (auto it = m1.begin(); it != m1.end(); it++)
		{
			K k = it->first;
			V v = it->second;

			combined.insert(std::pair<K, V>(k, v));
		}

		for (auto it = m2.begin(); it != m2.end(); it++)
		{
			K k = it->first;
			V v = it->second;

			combined.insert(std::pair<K, V>(k, v));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			T t = v[i];
			os << t;
			if (i != v.size() - 1)
			{
				os << ", ";
			}
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (auto it = m.begin(); it != m.end(); it++)
		{
			K k = it->first;
			V v = it->second;

			os << "{ ";
			os << k;
			os << ", ";
			os << v;
			os << " }" << std::endl;
		}

		return os;
	}
}