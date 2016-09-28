/*
  Infix to postfix conversion
  Operands and operator, both must be single character.
  Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected. 
*/
#include <bits/stdc++.h>

using namespace std;

string InfixToPostfix(string expression);
int HasHigherPrecedence(char operator1, char operator2);
bool IsOperator(char C);
bool IsOperand(char C);

int main(){
	string expression; 
	cout << "Enter Infix Expression \n";
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout << "Output = "<< postfix << "\n";
	return 0;
}

string InfixToPostfix(string expression){
	stack<char> S;
	string postfix = "";
	for(int i = 0;i< expression.length();i++){

		if(expression[i] == ' ' || expression[i] == ',')
			continue; 
		
		else if(IsOperator(expression[i])) {
			while(!S.empty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i])){
				postfix+= S.top();	
				S.pop();
			}
			S.push(expression[i]);	
		}
		else if(IsOperand(expression[i])){
			postfix +=expression[i];
		}

		else if (expression[i] == '(') {
			S.push(expression[i]);
		}

		else if(expression[i] == ')') {
			while(!S.empty() && S.top() !=  '(') {	// pop untill closing bracket is obtained
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

bool IsOperand(char C) {
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C){
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

int IsRightAssociative(char op){
	if(op == '$')	// exponent
		return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence. 
int GetOperatorWeight(char op){
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
	}
	return weight;
}

// Function to perform an operation and return output. 
int HasHigherPrecedence(char op1, char op2){
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1Weight == op2Weight){
		if(IsRightAssociative(op1)) 
			return false;
		else
			return true;
	}
	return op1Weight > op2Weight ?  true: false;
}