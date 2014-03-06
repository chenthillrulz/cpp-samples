#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

const char *endMarker="END";

// does not consider the negative cases as of now
static int
pos_to_index (const char *pos, size_t len)
{
	size_t level = len - 1;
	const char *iterator = pos;
	int calc = 0, iterPos = 0;

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
