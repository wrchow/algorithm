#include "Singleton.h"

Singleton* Singleton::_instance;
Singleton* Singleton::Instance(){
	if(_instance == 0) {
		_instance = new Singleton();
	}
	return _instance;
}

int main()
{	
	Singleton* pSingleton = Singleton::Instance();
	Singleton s1 = *pSingleton;
	Singleton s2 = *pSingleton; 
}

