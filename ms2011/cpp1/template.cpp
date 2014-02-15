// by wr-chow at 2011-3-6

// for solving the following errors:
//f:\roc\motionretrieval\src\preproc.cpp(10) : error C2059: syntax error : ''template<''
//f:\roc\motionretrieval\src\preproc.cpp(10) : error C2899: typename cannot be used outside a template declaration
//f:\roc\motionretrieval\src\preproc.cpp(11) : error C2065: 'T' : undeclared identifier
//f:\roc\motionretrieval\src\preproc.cpp(12) : error C2955: 'CAPG::Preproc' : use of class template requires template argument list
//        f:\roc\motionretrieval\src\preproc.h(13) : see declaration of 'CAPG::Preproc'
//f:\roc\motionretrieval\src\preproc.cpp(12) : error C2065: 'T' : undeclared identifier
//f:\roc\motionretrieval\src\preproc.cpp(12) : error C2065: 'T' : undeclared identifier
//f:\roc\motionretrieval\src\preproc.cpp(13) : error C2143: syntax error : missing ';' before '{'
//f:\roc\motionretrieval\src\preproc.cpp(13) : error C2447: '{' : missing function header (old-style formal list?)


#include <vector>

using namespace std;

template <typename T>
class AnyValue {
	T val;
public :
	AnyValue(T inv )
	{
		val = inv;
	}
};

template <typename U> class ValuesObject {
	int count;
	vector<AnyValue<U>, allocator<AnyValue<U> > > ivo;
public :
	ValuesObject() {}
	~ValuesObject() {}
	int getCount()
	{
		return count;
	}
	void addValue(AnyValue<U> av)
	{
		vector<AnyValue<U>, allocator<AnyValue<U> > >::iterator iter =
			ivo.end();
		ivo.insert(iter, av);
	}
};

