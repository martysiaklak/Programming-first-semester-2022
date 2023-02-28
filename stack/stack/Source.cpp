#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;

class Stack 
{
private:
	int* stack;
	int capacity;
	int top;
public:
	Stack(int initialCapacity = 10) : capacity(initialCapacity), top(-1) {stack = new int[capacity];}
	~Stack()
	{
		delete[] stack;
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	int Size() 
	{
		return top + 1;
	}

	void Push(int element) 
	{
		if (Size() == capacity) 
		{
			// double the capacity if the array is full
			int* new_stack = new int[capacity * 2];
			for (int i = 0; i <= top; i++) 
			{
				new_stack[i] = stack[i];
			}
			delete[] stack;
			stack = new_stack;
			capacity *= 2;
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

TEST_CASE("When stack is empty at first and then we add elements")
{
	Stack stack;
	CHECK(stack.IsEmpty() == true);

	stack.Push(17);

	CHECK(stack.IsEmpty() == false);
}

TEST_CASE("Checking size")
{
	Stack stack;

	CHECK(stack.Size() == 0);

	stack.Push(7);
	stack.Push(2);
	
	CHECK(stack.Size() == 2);

	stack.Pop();

	CHECK(stack.Size() == 1);
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

TEST_CASE("Pushing 12 elements")
{
	Stack stack;
	stack.Push(7);
	stack.Push(-9);
	stack.Push(3);
	stack.Push(7);
	stack.Push(-9);
	stack.Push(3);
	stack.Push(7);
	stack.Push(-9);
	stack.Push(3);
	stack.Push(7);
	stack.Push(-9);
	stack.Push(3);

	CHECK(stack.Top() == 3);
}