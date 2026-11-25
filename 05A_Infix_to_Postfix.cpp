/*
Problem Statement 5A:
Given as input an infix expression. Implement a program for following conversions :- Infix to postfix.
Fixes: Clarifies the question-bank typo in comments/prompt and validates balanced parentheses (( vs )).
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

bool infixToPostfix(string infix, string& postfix)
{
    stack<char> s;
    postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (s.empty())
            {
                // Unmatched closing parenthesis
                return false;
            }
            s.pop(); // Pop matching '('
        }
        else if (isOperator(ch))
        {
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                    (precedence(s.top()) == precedence(ch) && ch != '^')))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
        else
        {
            return false; // Invalid character
        }
    }

    while (!s.empty())
    {
        if (s.top() == '(')
        {
            // Unmatched opening parenthesis
            return false;
        }
        postfix += s.top();
        s.pop();
    }
    return true;
}

int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    if (infixToPostfix(infix, postfix))
        cout << "Postfix expression: " << postfix << endl;
    else
        cout << "Invalid infix expression! Check parentheses or operators.\n";

    return 0;
}
