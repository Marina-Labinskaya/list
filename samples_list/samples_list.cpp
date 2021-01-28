#include "list.h"
#include "conio.h"
typedef int TELEM;
const TELEM UNIT=1;
template <class T>
	void print_list(List<T> list)
	{
		for (List<T>::iterator it=list.begin(); it!=list.end(); ++it)
			std::cout<<(it->data);
		std::cout<<std::endl;
	}

void add_unit (TELEM a)
{
	List<TELEM> list; TELEM d;
	while (a) //convert a number to a list
	{
	  d=a%10;
	  list.push_back(d);
	  a/=10;
	}
	//print_list(list);
	int k=0;
	for (List<TELEM>::iterator it=list.begin(); it!=list.end(); ++it)
	{
		if ((it->data)==9)
		{
			it->data=0;
			k++;
		}
		else 
		{
			(it->data)++;
			break;
		}
	}
	if (k==list.get_size())
			list.push_back(UNIT);
	//print_list(list);
}

void main()
{
	TELEM a;
	std::cin>>a;
	add_unit(a);
	_getch();
}
