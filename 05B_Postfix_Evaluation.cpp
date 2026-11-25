/*
Problem Statement 5B:
Given as input a postfix expression. Implement a program for following conversion : postfix evaluation.
Fixes: Guards against stack underflow (s.size() < 2), invalid characters, and malformed postfix expressions (s.size() != 1).
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (s.size() < 2)
            {
                cout << "Invalid postfix expression! Insufficient operands.\n";
                return 0;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                if (b == 0)
                {
                    cout << "Division by zero error!\n";
                    return 0;
                }
                s.push(a / b);
                break;
            }
        }
        else
        {
            cout << "Invalid character '" << ch << "' in expression!\n";
            return 0;
        }
    }

    if (s.size() != 1)
    {
        cout << "Invalid postfix expression! Extra operands remaining.\n";
        return 0;
    }

    cout << "Result = " << s.top() << endl;
    return 0;
}
