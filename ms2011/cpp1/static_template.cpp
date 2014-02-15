// static_template.cpp
// by wr-chow at 2011-3-6
// refer to http://zh-cn.w3support.net/index.php?db=so&id=488959

#include <iostream>
#include <vector>

//foo.h 
Class Foo 
{ 
public:
	template<typename T> 
	static void RemoveVectorDuplicates(std::vector<T>& vectorToUpdate); 
}; 
//foo.cpp
template<typename T> 
void Foo::RemoveVectorDuplicates(std::vector<T>& vectorToUpdate) 
{ 
	for(typename T::iterator sourceIter = vectorToUpdate.begin(); 
		(sourceIter != vectorToUpdate.end() - 1); sourceIter++) 
	{     
		for(typename T::iterator compareIter = (vectorToUpdate.begin() + 1);
			compareIter != vectorToUpdate.end(); compareIter++) { 
				if(sourceIter == compareIter) { 
					vectorToUpdate.erase(compareIter);   
				}    
			}    
	} 
}

int main()
{
	Foo foo;
	return 0;
}