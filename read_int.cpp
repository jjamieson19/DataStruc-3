#include "read_int.h"
#include <stdexcept>
using namespace std;

int read_int(const std::string & prompt, int low, int high)
{
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try {
			cout << prompt;
			cin >> num;
			if (num < low || num > high)
				throw std::range_error("Outside range limits");
			return num;
		}
		catch (ios_base::failure& ex) {
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (range_error& ex) {
			cerr << "Outside range limits -- try again\n";
		}
	}
}
