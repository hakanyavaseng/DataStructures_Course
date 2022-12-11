#include <string>
#include <stack>
#include <iostream>


using namespace std;

// This function takes 3 arguments, 2  integer value and 1 operator char
// and does math operations.
int calculate(char opr, int value1, int value2)
{
	switch (opr)
	{
	case '+':
		return value1 + value2;
	case '-':
		return value2 - value1;
	case '*':
		return value1 * value2;
	case '/':
		return value2 / value1;
	default:
		break;
	}

}

//This function returns an integer value which is used to check the priorities of operators.
int checkPriority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
	return 0;
}
///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 
string Infix2Postfix(string& s) {

	string result = "";
	stack<char> St; // Stack initialization

	// For loop goes through the size of string
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') // Ignores spaces
			continue;
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') // If it is operator
		{


			while (!St.empty() && (checkPriority(St.top()) >= checkPriority(s[i]))) // Checks priority
			{
				char temp = St.top();
				result += ' ';
				result += temp;
				St.pop(); 

			}
			St.push(s[i]);
			result += ' ';

		}

		else if (s[i] == '(') // If it is opening bracket
		{
			St.push(s[i]); // Char is pushed to stack
		}

		else if (s[i] == ')') // If it is closing bracket
		{
			while (!St.empty() && St.top() != '(')
			{
				char temp = St.top();
				result += ' ';
				result += temp;
				St.pop();

			}
			St.pop();

		}
		else
		{
			result += s[i];
		}



	}

	while (!St.empty()) // Goes through the stack, pops stack, and adds to the result.
	{
		char temp = St.top();
		result += ' ';
		result += temp;
		St.pop();

	}




	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {

	stack<int> St; // Stack initialization
	string temp;
	int right=0, left = 0;
	int i=0;

	//This while loop works until the index is equal to size of string - 1
	while(i != s.size()-1)
	{
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/') //If it is not operator
		{
		
		    while (s[right] != ' ')
				right++;

			temp = s.substr(left, right - left); // Parsing string and store it in temporary variable
			St.push(stoi(temp));
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') // If it is operator
		{
			int value1, value2;

			//Pops two values of the stack, stores it in value 1 and value 2
			//and calls calculate function with these parameters
			value1 = St.top();
			St.pop();
			value2 = St.top();
			St.pop();

			int rst = calculate(s[i], value1, value2);
			St.push(rst); // Pushes the result to the stack again
			right++;

		}
		right++;
		left = right;
		i = left;

	}
	
	// Does same operations in loop for the last time, because when the while loop is terminated
	// There still last 2 values in stack, and they must be calculated with last operator.

	int value1, value2;

	value1 = St.top();
	St.pop();
	value2 = St.top();
	St.pop();

	int rst = calculate(s[i], value1, value2);
	St.push(rst);


	return St.top();
} // end-EvaluatePostfixExpression
