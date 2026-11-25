/*
Problem Statement 5B:
Given as input a postfix expression. Implement a program for following conversion : postfix evaluation.
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
    cout << "Enter a postfix expression: ";
    cin >> postfix;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        else
        {
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
                    cout << "Division by zero error\n";
                    return 0;
                }
                s.push(a / b);
                break;
            }
        }
    }

    cout << "Result = " << s.top() << endl;
    return 0;
}
