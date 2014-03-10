#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int 
main ()
{
	string input;
	int total = 1;

	// Does not check for negative case. the input should a sorted one
	input.reserve (100);
	cin >> input;

	int last = input.length () - 1;

	cout << input << endl;
	while (true)
	{
		int iterator = last, swapPosA = -1;
	
		// Move from right to left	
		// Find the position to insert a character from right to produce next number
		while (true)
		{
			int cmp = iterator -1;
			if (cmp < 0)
				break;

			if (input.at (iterator) > input.at(iterator -1))
			{
				swapPosA = iterator - 1;
				break;
			}
			--iterator;
		}

		// no insert position found and so we are done
		if (swapPosA == -1)
			break;

		// Find a number greater than the num at swapPosA and least among the greater numbers on the right side
		int swapPosB = -1;
		for (int pos = swapPosA + 1; pos < last + 1; ++pos)
		{
			if (input.at(pos) > input.at(swapPosA) && (swapPosB == -1 || input.at(pos) <= input.at (swapPosB)))
				swapPosB = pos;
		}

		// swap the characters
		char t = input.at (swapPosB);
		input.replace (swapPosB, 1, 1, input.at(swapPosA));
		input.replace (swapPosA, 1, 1, t);
		
		//reverse the characters from swapPosA+1 to end
		int begin = swapPosA + 1;
		int end = last;
		while (begin < end)
		{
			char temp = input.at(begin);
			input.replace (begin, 1, 1, input.at(end));
			input.replace (end, 1, 1, temp);
			++begin;
			--end;
		}

		cout << input << endl;
		++total;
	}

	cout << "Total permutations " << total <<endl;
	return 0;
}
