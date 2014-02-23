// for peals practise 1.1
// 2014-01-31


#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void sort_by_set()
{
		
}

int main() 
{
	cout << "test" << endl;
	vector<float> v;
	for (int i=0; i<10; i++) {
		v.push_back(rand()%10);
	}
	sort(v.begin(), v.end());
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
