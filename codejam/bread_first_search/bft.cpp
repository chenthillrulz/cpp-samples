#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const char *endMarker="END";

// does not consider the negative cases as of now
// Note: later knew this could be done in a simpler way, but then didn know that before :)
static int
pos_to_index (const char *pos, size_t len)
{
	size_t level = len - 1;
	const char *iterator = pos;
	int calc = 0, iterPos = 0;

	// Logic is that the left most node's index would be decimal value of 111's and the index of right
	// nodes can be calculated with 111's + binary representation of R's position. Eg: LR is 2^1 + 2^0
	// LLR is 111 + 001, LLRL is 1111 + 0010
	while (level) {
		calc = calc << 1;
		calc |= 0x1;
		level--;
	}

	iterator++; // move over 'H'
	while (*iterator != '\0')
	{
		if (*iterator == 'R')
		{
			calc += pow(2, (len - (iterator - pos + 1)));
		}
		iterator++;
	}

	return calc;
}

int main ()
{
	char pos[10], data[9];
	vector<int> treeArray(1);

	while (true)
	{
		cin.getline (pos, 10);
		if (!strcmp (pos, endMarker))
			break;

		cin.getline (data, 9);
		
		int iData = atoi (data);
		size_t len = strlen (pos);
		int index = pos_to_index (pos, len);

		// This ensure at every level all leaf positions are created, so that many re-allocs can be avoided
		treeArray.resize ( pow (2, len) -1, -1);
		treeArray.at(index)=iData;
	}

	cout << "Breadth first traversal" << endl;
	for (vector<int>::iterator iter = treeArray.begin(); iter != treeArray.end(); iter++)
		if (*iter != -1)
			cout << *iter << " ";
	cout << endl << "Done " << endl;

	return 0;
}
