// by wr-chow for motionretrieval
// at 2011-3-6

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Seqs;

void fvector(Seqs &seqs, int i)
{
	seqs.push_back(i);
	cout << " i = " << i << endl;
}

void fconst()
{
	// const int i; error!@
	// const object must initialized if not extern
	const int i = 1;
	// i = 2; error!@
	// you can't assign to a variable that is const
}
 
class FStatic{
	// default is private.
public:
	FStatic(){};
	static int num(int i){
		return i;
	}
};

template<typename T>
T TMax(T a, T b)
{
  return a < b ? b : a;
}

// Filename: Point.h
template<typename T>
class Point
{
public:
	Point():myX(1),myY(2){};
public:
	T getX();
	T getY(){
		return myY;
	}
	static std::vector<T> mergeVector(std::vector<T> v1, std::vector<T> v2)
	{
		for (size_t i = 0; i < v2.size(); i++) {
			v1.push_back(v2[i]);
		}
		return v1;
	}
	static std::vector<T> mergeVector2(std::vector<T> v1, std::vector<T> v2);
private:
    T myX;
    T myY;
}; // class Point

template<typename T>
T Point<T>::getX()
{
	return myX;
}

template <typename T>
std::vector<T> Point<T>::
mergeVector2(std::vector<T> v1, std::vector<T> v2)
{
	for (size_t i = 0; i < v2.size(); i++) {
		v1.push_back(v2[i]);
	}
	return v1;
} // mergeVector(v1, v2)

int main()
{
	Seqs seqs;	
	fvector(seqs,1);
	fvector(seqs,2);
	cout << "length of seqs = " << 
			seqs.size() << endl;

	fconst();
	cout.precision(3);
	cout << "cout.precision(3) : " << 
		 111.333 << " " << 0.003333 << endl;

	FStatic fs;
	cout << "static member function num : "
		 << FStatic::num(3) << endl << endl;
	
	int myints[] = {16,2,77,29};
	vector<int> v1(myints,myints + sizeof(myints)/4);
	vector<int> v2(myints,myints + sizeof(myints)/4);
	vector<int> m = Point<int>::mergeVector2(v1, v2);
	cout << "sizeof (v1) = " << v1.size() << endl
		 << "sizeof (v2) = " << v2.size() << endl
		 << "sizeof m(mergeVector) = " << m.size() << endl;
	for (size_t i = 0; i < m.size(); i++) {
		cout << m[i] << "	";
	}
	cout << endl << endl;

	int x = 5, y = 10;
	cout << "Template function TMax(5,10) : " << 
		  TMax<int>(x, y) << endl;

	Point<int> p;
	cout << "Template class Point<int> p.getX() : " <<
				p.getX() << endl;
	return 0;
}