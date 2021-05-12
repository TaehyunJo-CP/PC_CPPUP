#include "Lab2.h"
#include <iomanip>

using namespace std;

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
		out << "------------ ---------- --------" << endl;

		while (true)
		{
			int num;

			in >> num;

			if (in.fail())
			{
				if (in.eof())
				{
					break;
				}

				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}

			out << setw(12) << oct << num << setw(11) << dec << num << setw(9) << hex << uppercase << num << endl;

			if (in.eof())
			{
				break;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float maxNum = FLT_MIN;

		while (true)
		{
			float num;

			in >> num;

			if (in.fail())
			{
				if (in.eof())
				{
					break;
				}

				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}

			if (maxNum < num)
			{
				maxNum = num;
			}

			cout << "     " << setw(15) << internal << fixed << setprecision(3) << num << endl;

			if (in.eof())
			{
				break;
			}
		}

		cout << "max: " << setw(15) << internal << fixed << setprecision(3) << maxNum << endl;
	}
}