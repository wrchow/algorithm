// max & min in the same time <beauty coding> page163

#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

pair<int,int> maxmin(vector<int> v);
vector<int> genv(int n);

int main(int argc, char *argv[])
{
    assert(argc == 2);
    int N = atoi(argv[1]);
    pair<int,int> mm(0,0);
    vector<int> v = genv(N);
    mm = maxmin(v);
    cout << mm.first << ", " << mm.second << endl;
    return 0;
}

vector<int> genv(int n)
{
	vector<int> v;
    cout << "genv : " ;
	srand(time(0));
	for (int i=0; i<n; i++) {
		v.push_back(rand()%n);
        cout << v[i] << ' ';
	}
    cout << endl;
	return v;
}

pair<int,int> maxmin(vector<int> v)
{
    assert(v.size() > 1);
    if (v.size() == 1) return pair<int,int>(v[0],v[0]);
    if (v.size() == 2) return pair<int,int>(v[0],v[1]);
    int Max(v[0]),Min(v[1]);
    for (int i=2; i<v.size(); i+=2) {
        if (v[i] > v[i+1]) {
            if ( Max < v[i] ) Max = v[i];
            else if ( Min > v[i+1] ) Min = v[i+1];
        } else {
            if ( Max < v[i+1]) Max = v[i+1];
            else if (Min > v[i])  Min = v[i];
        }
    }
    return pair<int,int>(Max,Min);
}

















