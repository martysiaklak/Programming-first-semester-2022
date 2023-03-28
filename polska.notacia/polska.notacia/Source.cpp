#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <stack>
#include <string>
using namespace std;

int getPrecedence(char op)   //пріоритети операцій
{
    if (op == '+' || op == '-') 
    {
        return 1;
    }
    if (op == '*' || op == '/') 
    {
        return 2;
    }
    return 0;
}

string infixToPostfix(string s)    //перетворюємо з інфіксної в постфіксну
{
    stack<char> st;
    string expression;

    for (int i = 0; i < s.length(); i++) 
    {
        char c = s[i];

        if (c == ' ')
        {
            continue;
        }

        if (c >= '0' && c <= '9')    //число додаємо в string
        {
            expression += c;
        }

        else if (c == '(')        // ( додаємо в stack
        {
            st.push('(');
        }

        else if (c == ')')        // ) витягуємо усі елементи зі стеку поки не дійдемо до (
        {
            while (st.top() != '(') 
            {
                expression += st.top();
                st.pop();
            }
            st.pop();
        }

        else          //якщо оператор
        {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top()))
            {
                expression += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) //витягуємо усе зі стеку
    {
        expression += st.top();
        st.pop();
    }
    return expression;  //expression means result
}

int ComputeExpression(string expression)     //обчислюємо результат з постфіксної форми
{
    stack<int> st;
    int arg1;
    int arg2;
    int result;
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression[i];
        switch (expression[i])
        {
        case '+':
            arg2 = st.top();
            st.pop();
            arg1 = st.top();
            st.pop();
            result = arg1 + arg2;
            break;
        case '-':
            arg2 = st.top();
            st.pop();
            arg1 = st.top();
            st.pop();
            result = arg1 - arg2;
            break;
        case '*':
            arg2 = st.top();
            st.pop();
            arg1 = st.top();
            st.pop();
            result = arg1 * arg2;
            break;
        case '/':
            arg2 = st.top();
            st.pop();
            arg1 = st.top();
            st.pop();
            result = arg1 / arg2;
            break;
        default:
            result = c - '0';  //з char в int
            break;
        }
        st.push(result);
    }
    result = st.top();
    st.pop();
    return result;
}

TEST_CASE("from infix to postfix")
{
    CHECK(infixToPostfix("2 + 3") == "23+");
    CHECK(infixToPostfix("(2 + 3) * 4") == "23+4*");
    CHECK(infixToPostfix("2 * (3 + 4)") == "234+*");
    CHECK(infixToPostfix("1 + 2 * 3 - 4") == "123*+4-");
}
TEST_CASE("Calculating the result of postfix form") 
{
    CHECK(ComputeExpression("23+") == 5);
    CHECK(ComputeExpression("23+4*") == 20);
    CHECK(ComputeExpression("234+*") == 14);
    CHECK(ComputeExpression("123*+4-") == 3);
}
