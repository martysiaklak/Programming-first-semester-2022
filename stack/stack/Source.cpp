#include <iostream>
#include <stack>
#include <string>
using namespace std;
//and(or(false, not(false)), true, not(true))
string infixToPostfix(string s)    //������������ � �������� � ����������
{
    stack<char> st;
    string expression;

    for (int i = 0; i < s.length(); i++)
    {
        size_t found = expression.find("and");
        char c = s[i];

        if (c >= '0' && c <= '9')    //����� ������ � string
        {
            expression += c;
        }

        else if (c == '(')        // ( ������ � stack
        {
            st.push('(');
        }

        else if (c == ')')        // ) �������� �� �������� � ����� ���� �� ������ �� (
        {
            while (st.top() != '(')
            {
                expression += st.top();
                st.pop();
            }
            st.pop();
        }

        else          //���� ��������
        {
            while (!st.empty() && getPrecedence(s[i]) <= getPrecedence(st.top()))
            {
                expression += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) //�������� ��� � �����
    {
        expression += st.top();
        st.pop();
    }
    return expression;  //expression means result
}
