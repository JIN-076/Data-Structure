#include <iostream>
using namespace std;

template<class T>
struct ArrayListNodeType
{
	T data;
};
typedef ArrayListNodeType<int> *pELement;
