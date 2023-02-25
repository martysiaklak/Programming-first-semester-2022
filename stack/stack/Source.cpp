#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

const int MAX_SIZE = 1000;
class Stack 
{
private:
	int stack[MAX_SIZE];
	int top;

public:
	Stack() 
	{
		top = -1; //means it's empty
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	bool IsFull()
	{
		return top == MAX_SIZE - 1;
	}

	void Push(int element) 
	{
		if (IsFull()) 
		{
			return;  
		}
		top++;
		stack[top] = element;
	}

	int Top()
	{
		if (IsEmpty())
		{
			return -1;
		}
		return stack[top];
	}

	void Pop()
	{
		if (IsEmpty())
		{
			return;
		}
		top--;
	}

	/*int Pop() 
	{
		if (IsEmpty())
		{
			return -1; 
		}
		int n = stack[top];  
		top--;
		return n;
	}*/
};

TEST_CASE("Pushing and popping 3 numbers")
{
	Stack stack;
	stack.Push(7);
	stack.Push(-9);
	stack.Push(3);

	CHECK(stack.Top() == 3);
	stack.Pop();
	CHECK(stack.Top() == -9);
	stack.Pop();
	CHECK(stack.Top() == 7);
}

TEST_CASE("When stack is empty at first and then becomes full")
{
	Stack stack;
	CHECK(stack.IsEmpty() == true);
	CHECK(stack.IsFull() == false);

	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack.Push(i);
	}

	CHECK(stack.IsEmpty() == false);
	CHECK(stack.IsFull() == true);
}

TEST_CASE("Push and pop mixed")
{
	Stack stack;
	stack.Push(5);  // push 5 elements
	stack.Push(8);
	stack.Push(-2);
	stack.Push(0);
	stack.Push(1);

    stack.Pop();   //pop 3 elements
	stack.Pop(); 
	stack.Pop(); 
 
	CHECK(stack.Top() == 8); 
	
	stack.Push(4);   // push 2 more elements
	stack.Push(-6);

    stack.Pop();     //pop all of them
	stack.Pop();
	stack.Pop();
	stack.Pop();

	CHECK(stack.IsEmpty() == true); //check if it's empty
}

TEST_CASE("Push element to full stack")   //when the stack is full it isn't pushing any more elements
{
	Stack stack;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		stack.Push(i);
	}
	stack.Push(7);
	CHECK(stack.Top() == 999);
}

//TEST_CASE("Pushing and popping 3 numbers")
//{
//	Stack stack;
//	stack.Push(7);
//	stack.Push(-9);
//	stack.Push(3);
//
//	CHECK(stack.Pop() == 3);
//	CHECK(stack.Pop() == -9);
//	CHECK(stack.Pop() == 7);
//}
//
//TEST_CASE("When stack is empty at first and then becomes full")
//{
//	Stack stack;
//	CHECK(stack.IsEmpty() == true);
//	CHECK(stack.IsFull() == false);
//
//	for (int i = 0; i < MAX_SIZE; i++) 
//	{
//		stack.Push(i);
//	}
//
//	CHECK(stack.IsEmpty() == false);       
//	CHECK(stack.IsFull() == true);
//}
//
//TEST_CASE("Push and pop mixed")
//{
//	Stack stack;
//	stack.Push(5);  // push 5 elements
//	stack.Push(8);
//	stack.Push(-2);
//	stack.Push(0);
//	stack.Push(1);
//
//	CHECK(stack.Pop() == 1); // pop 3 elements
//	CHECK(stack.Pop() == 0);
//	CHECK(stack.Pop() == -2);
//
//	stack.Push(4);   // push 2 more elements
//	stack.Push(-6);
//
//	CHECK(stack.Pop() == -6); // pop all of them
//	CHECK(stack.Pop() == 4);
//	CHECK(stack.Pop() == 8);
//	CHECK(stack.Pop() == 5);
//
//	CHECK(stack.IsEmpty() == true); //check if it's empty
//}
//
//TEST_CASE("Push element to full stack")   //when the stack is full it isn't pushing any more elements
//{
//	Stack stack;
//	for (int i = 0; i < MAX_SIZE; i++) 
//	{
//		stack.Push(i);
//	}
//	stack.Push(7);
//	CHECK(stack.Pop() == 999);
//}