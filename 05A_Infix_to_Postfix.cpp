/*
Problem Statement 5A:
Given as input an infix expression. Implement a program for following conversions :- Infix to postfix.
*/

#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// ==========================================
// HELPER: CHECK IF CHARACTER IS AN OPERATOR
// ==========================================
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// ==========================================
// OPERATOR PRECEDENCE
// ==========================================
// Returns higher integer for operators with higher mathematical precedence
int precedence(char op)
{
    if (op == '^')
        return 3; // Exponentiation has highest precedence
    else if (op == '*' || op == '/')
        return 2; // Multiplication and Division
    else if (op == '+' || op == '-')
        return 1; // Addition and Subtraction
    else
        return 0; // Parentheses or non-operators
}

// ==========================================
// INFIX TO POSTFIX CONVERSION (Using Stack)
// ==========================================
bool infixToPostfix(string infix, string& postfix)
{
    stack<char> s; // Stack to hold operators and opening parentheses
    postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // 1. If scanned character is an operand (alphanumeric), append directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // 2. If '(', push it onto the stack
        else if (ch == '(')
        {
            s.push(ch);
        }
        // 3. If ')', pop from stack to output until '(' is encountered
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if (s.empty())
            {
                // Unmatched closing parenthesis error
                return false;
            }
            s.pop(); // Discard the matching '('
        }
        // 4. If an operator is encountered
        else if (isOperator(ch))
        {
            // Pop operators with higher or equal precedence (except right-associative '^')
            while (!s.empty() && s.top() != '(' &&
                   (precedence(s.top()) > precedence(ch) ||
                    (precedence(s.top()) == precedence(ch) && ch != '^')))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch); // Push current operator onto stack
        }
        else
        {
            return false; // Invalid token in expression
        }
    }

    // 5. Pop all remaining operators from the stack
    while (!s.empty())
    {
        if (s.top() == '(')
        {
            // Unmatched opening parenthesis error
            return false;
        }
        postfix += s.top();
        s.pop();
    }
    return true;
}

// ==========================================
// MAIN FUNCTION
// ==========================================
int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    // Convert and display result
    if (infixToPostfix(infix, postfix))
        cout << "Postfix expression: " << postfix << endl;
    else
        cout << "Invalid infix expression! Check parentheses or operators.\n";

    return 0;
}
