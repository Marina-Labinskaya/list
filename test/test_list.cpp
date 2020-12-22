#include "list.h"
#include <gtest.h>

TEST(TIterator, can_create_iterator)
{
	List<int> list;
	ASSERT_NO_THROW(List<int>::iterator iter(list.get_first()));
}

TEST(TIterator, can_create_copied_iterator)
{
	List<int> list;
	List<int>::iterator iter1(list.get_first());
	ASSERT_NO_THROW(List<int>::iterator iter2(iter1));
}

TEST(TIterator, can_dereference)
{
	Node<int>* node=new Node<int>(7);
	List<int>::iterator iter(node);
	ASSERT_NO_THROW(*iter);
}

TEST(TIterator, arrow_operator_is_correct)
{
	Node<int>* node=new Node<int>(7);
	List<int>::iterator iter(node);
	EXPECT_EQ(iter->data, 7);
}

TEST(TIterator, operator_plus_plus_is_correct)
{
	List<int> list;
	list.push_front(2);
	list.push_front(4);
	List<int>::iterator iter(list.get_first());
	++iter;
	EXPECT_EQ(iter->data, 2);
}

TEST(TIterator, operator_equal_is_correct)
{
	Node<int>* node=new Node<int>(7);
	List<int>::iterator iter1(node);
	List<int>::iterator iter2(node);
	ASSERT_TRUE(iter1==iter2);
}

TEST(TIterator, operator_not_equal_is_correct)
{
	Node<int>* node1=new Node<int>(7);
	List<int>::iterator iter1(node1);
	Node<int>* node2=new Node<int>(5);
	List<int>::iterator iter2(node2);
	ASSERT_TRUE(iter1!=iter2);
}

TEST(TList, can_create_empty_list)
{
	ASSERT_NO_THROW(List<int> list);
}

TEST(TList, can_create_copied_list)
{
	List<int> list1;
	ASSERT_NO_THROW(List<int> list2(list1));
}

TEST(TList, return_true_if_list_is_empty)
{
	List<int> list;
	ASSERT_TRUE(list.empty());
}

TEST(TList, return_front_node)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	EXPECT_EQ(list.front(), 3);
}

TEST(TList, can_clear_list)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	ASSERT_NO_THROW(list.clear());
}

TEST(TList, clear_list_is_empty)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	list.clear();
	ASSERT_TRUE(list.empty());
}

TEST(TList, can_push_front)
{
	List<int> list;
	ASSERT_NO_THROW(list.push_front(5));
}

TEST(TList, can_pop_front)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	list.pop_front();
	EXPECT_EQ(list.front(), 5);
}

TEST(TList, can_insert)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	list.insert(4, list.get_first());
	list.pop_front();
	EXPECT_EQ(list.front(),4);
}

TEST(TList, can_erase)
{
	List<int> list;
	list.push_front(5);
	list.push_front(3);
	list.erase(list.get_first());
	list.pop_front();
	ASSERT_TRUE(list.empty());
}

