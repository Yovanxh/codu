/*
Problem Statement 5B:
Given as input a postfix expression. Implement a program for following conversion : postfix evaluation.
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// ==========================================
// MAIN FUNCTION: POSTFIX EVALUATION USING STACK
// ==========================================
int main()
{
    string postfix;
    stack<int> s; // Stack to hold intermediate integer operands

    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    // Scan the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // 1. If operand, convert char digit to int and push onto stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }
        // 2. If operator, pop two operands, perform operation, and push result
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            // Verify sufficient operands on stack
            if (s.size() < 2)
            {
                cout << "Invalid postfix expression! Insufficient operands.\n";
                return 0;
            }

            int b = s.top(); // Second operand was on top
            s.pop();
            int a = s.top(); // First operand was below it
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
                // Handle division by zero error
                if (b == 0)
                {
                    cout << "Division by zero error!\n";
                    return 0;
                }
                s.push(a / b);
                break;
            }
        }
        // 3. Reject unrecognized characters
        else
        {
            cout << "Invalid character '" << ch << "' in expression!\n";
            return 0;
        }
    }

    // After processing, stack must have exactly one element (the final result)
    if (s.size() != 1)
    {
        cout << "Invalid postfix expression! Extra operands remaining.\n";
        return 0;
    }

    // Display evaluated final result
    cout << "Result = " << s.top() << endl;
    return 0;
}
