#include <iostream>
#include <stack>
#include <string>
using namespace std;
//and(or(false, not(false)), true, not(true))
string infixToPostfix(string s)    //перетворюЇмо з ≥нф≥ксноњ в постф≥ксну
{
    stack<char> st;
    string expression;

    for (int i = 0; i < s.length(); i++)
    {
        size_t found = expression.find("and");
        char c = s[i];

        if (c >= '0' && c <= '9')    //число додаЇмо в string
        {
            expression += c;
        }

        else if (c == '(')        // ( додаЇмо в stack
        {
            st.push('(');
        }

        else if (c == ')')        // ) вит€гуЇмо ус≥ елементи з≥ стеку поки не д≥йдемо до (
        {
            while (st.top() != '(')
            {
                expression += st.top();
                st.pop();
            }
            st.pop();
        }

        else          //€кщо оператор
        {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top()))
            {
                expression += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) //вит€гуЇмо усе з≥ стеку
    {
        expression += st.top();
        st.pop();
    }
    return expression;  //expression means result
}
