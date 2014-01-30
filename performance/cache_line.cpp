#include <iostream>
#include <boost/timer/timer.hpp>
#include <array>

using namespace std;

const int arraySize = 64 * 1024 * 1024;
//const int arraySize = 64;

int main ()
{
	uint32_t *arr = new int [arraySize];
	boost::timer::auto_cpu_timer t;

	for (int i = 0; i < arraySize; i+=2)
		arr[i] += 3;

	return 0;
}
