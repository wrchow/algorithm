// sort by set in pearls
// 2014-02-01

#include <set>
#include <iostream>
using namespace std;

void sortbyset()
{
	set<int> S;
	set<int>::iterator j;
	int i;
	while(cin >> i) {
		S.insert(i);
		if (i :
	}
	for (j=S.begin(); j != S.end(); j++) {
		cout << *j << " ";
	}
	cout << endl;
	
}

int main()
{
	sortbyset();
	return 0;
}
