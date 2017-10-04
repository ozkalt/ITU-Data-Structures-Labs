#include<iostream>
#include<stdio.h>
#include"header.h"

using namespace std;

int main(){
	char *argv = new char[100];
	float value;
	cout << "Enter the postfix string: ";
	cin.getline(argv, 100);
	
	char *infix = argv;
	char *postfix = new char[100];
	int pfindex = 0;

	struct Stack operatorstack;
	operatorstack.create();

	for (int i = 0; infix[i] != '\0'; i++){
		if (infix[i] == '(')
			operatorstack.push(infix[i]);
		else if (infix[i] == '*')
			operatorstack.push(infix[i]);
		else if (infix[i] == '/'){
			if (!operatorstack.isEmpty()){
				while (operatorstack.getHeadChar() == '*'){
					postfix[pfindex] = operatorstack.pop();
					pfindex++;
					if (operatorstack.isEmpty())	break;
				}
			}
			operatorstack.push(infix[i]);
		}
		else if (infix[i] == '+'){
			if (!operatorstack.isEmpty()){
				while (operatorstack.getHeadChar() == '*' || operatorstack.getHeadChar() == '/'){
					postfix[pfindex] = operatorstack.pop();
					pfindex++;
					if (operatorstack.isEmpty())	break;
				}
			}
			operatorstack.push(infix[i]);
		}
		else if (infix[i] == '-'){
			if (!operatorstack.isEmpty()){
				if (operatorstack.getHeadChar() != '('){
					while (operatorstack.getHeadChar() == '*' || operatorstack.getHeadChar() == '/' || operatorstack.getHeadChar() == '+'){
						postfix[pfindex] = operatorstack.pop();
						pfindex++;
						if (operatorstack.isEmpty())	break;
					}
				}
			}
			operatorstack.push(infix[i]);
		}
		else if (infix[i] == ')'){
			if (operatorstack.getHeadChar() == '('){
				char buffer = operatorstack.pop();
			}
		}
		else{
			postfix[pfindex] = infix[i];
			pfindex++;
		}

		postfix[pfindex] = '\0';
		cout << "Postfix string: " << postfix << '\t';
		operatorstack.print();
	}

	while (!operatorstack.isEmpty()){
		postfix[pfindex] = operatorstack.pop();
		pfindex++;
	}

	postfix[pfindex] = '\0';
	cout << "Postfix string: " << postfix << '\t';

	operatorstack.makeEmpty();

	int temp1, temp2;

	for (int n = 0; postfix[n]; n++){
		if (isdigit(postfix[n])){
			operatorstack.push(postfix[n]);
		}
		else{
			temp1 = operatorstack.pop();
			temp2 = operatorstack.pop();

			if (postfix[n] == '+')
				operatorstack.push(temp1 + temp2 + '0');
			else if (postfix[n] == '-')
				operatorstack.push(temp2 - temp1 + '0');
			else if (postfix[n] == '*')
				operatorstack.push(temp1 * temp2 + '0');
			else if (postfix[n] == '/')
				operatorstack.push(temp2 / temp1 + '0');
		}
	}

	cout << "value: " << operatorstack.getHeadChar();

	getchar();
	return 0;
}
