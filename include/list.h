#pragma once
#include <iostream>
template <class T>
class Node {
public:
	Node* next;
	T data;
	Node(T value, Node* pnext=nullptr) 
	{ 
		next=pnext; data=value;
	}
};
template <class T>
class List {
private:
	Node<T>* first;
	int size;
public:
	   class iterator {
       private:
	      Node<T>* curr;
       public:
	      iterator(Node<T>* pcurr) 
		  { 
			  curr=pcurr;
		  }
	      iterator(const iterator& iter) 
		  { 
			  curr=iter.curr;
		  }
	      Node<T>*& operator*()
		  {
			  return curr;
		  }
		  Node<T>* operator->()
		  {
			  return curr;
		  }
		  iterator operator++()
		  {
			  curr=curr->next;
			  return (*this);
		  }
		  bool operator==(iterator iter)
		  {
			  if (curr==iter.curr) return true;
			  else return false;
		  }
		  bool operator !=(iterator iter)
		  {
			  return !(*this==iter);
		  }
     };
	iterator begin() const
	{
		iterator iter(first);
		return iter;
	}

	iterator end() const
	{
		iterator iter(nullptr);
		return iter;
	}
	 List()
	 {
		 first=nullptr;
		 size=0;
	 }

	 List(const List& list)
	 {
		 first=nullptr;
		 Node<T>* curr=first;
		 for (iterator iter=list.begin(); iter!=list.end(); ++iter)
		 { 
			 insert(iter->data, curr);
		 }
		 size=list.size;
	 }

	 ~List()
	 {
		 clear();
	 }

	 Node<T>* get_first()
	 {
		 return first;
	 }

	 bool empty() 
	 {
	    return (first==nullptr);
	 }

	 T front()
	 {
		 return first->data;
	 }

	 void clear()
	 {
		while (first!=nullptr)
		pop_front();
		size=0;
	 }

	 void push_front(T elem)
	 {
		Node<T>*p=new Node<T> (elem, first);
		first=p;
		size++;
	 }

	void pop_front()
	 {
		 Node<T>* p=first;
		 first=p->next;
		 delete p;
		 size--;
	 }

	void insert(T value, Node<T>* pn)
	{
		if (pn==nullptr)
			 push_front(value);
		else {
			Node<T>* p=new Node<T>(value, pn->next);
			pn->next=p;
			size++;
		}
	}
	
	void erase(Node<T>* pn)
	{
		if (pn==nullptr)
			pop_front();
		else {
			Node<T>* p=pn->next;
			pn->next=p->next;
			delete p;
			size--;
		}
	}
	int get_size() { return size; }
	void push_back(T elem)
	{
		insert(elem, get_last());
	}
	Node <T>* get_last()
	{
		if (first==nullptr)
		    return first;
		else {
			Node <T>* last; Node <T>* curr=first;
		    while (curr->next!=nullptr)
			      curr=curr->next;
		    last=curr;
		    return last;
		}
	}
};
