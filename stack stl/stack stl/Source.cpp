#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stack>
using namespace std; 
TEST_CASE("pushing elements and checking the top's value")
{
	stack<int> stack;

	stack.push(0);
	stack.push(-9);
	stack.push(3);

	CHECK(stack.top()==3);
}

TEST_CASE("pushing elements, popping and checking")
{
	stack<int> stack;

	stack.push(7);
	stack.push(-9);
	stack.push(6);

	CHECK(stack.top() == 6);
	stack.pop();
	CHECK(stack.top() == -9);
	stack.pop();
	CHECK(stack.top() == 7);
}

TEST_CASE("checking size of stack")
{
	stack<int> stack;

	stack.push(0);       
	stack.push(-8);
	stack.push(-6);

	CHECK(stack.size() == 3);
	stack.pop();
	CHECK(stack.size() == 2);
	stack.pop();
	CHECK(stack.size() == 1);
	stack.pop();
	CHECK(stack.size() == 0);
	CHECK(stack.empty() == true);
}

TEST_CASE("swapping 2 stacks")
{
	stack<int> stack1;
	stack<int> stack2;

	stack1.push(0);       //adding elements to the first stack
	stack1.push(-8);
	stack1.push(-6);

	stack2.push(0);       //adding elements to the second stack
	stack2.push(9);

	stack1.swap(stack2);   //swapping

	CHECK(stack1.size() == 2);
	CHECK(stack2.top() == -6);
}
