#include<iostream>
#include<stdio.h>
#include<math.h>
#include"header.h"

using namespace std;

int calculatePredence(char a){
	switch (a){
	case '(': case ')':
		return 5;
		break;
	case '*':
		return 4;
		break;
	case '/':
		return 3;
		break; 
	case '+':
		return 2;
		break;
	case '-':
		return 1;
		break;
	}
	return 0;
}

int main(){
	char *argv = new char[100];
	float value;
	cout << "Enter the infix string: ";
	cin.getline(argv, 100);

	char *infix = argv;
	char *postfix = new char[100];

	struct Stack operatorstack;
	operatorstack.create();

	int j = 0;
	for (int i = 0; infix[i] != '\0'; i++){
		if (infix[i] != '+' && infix[i] != '*' && infix[i] != '/' && infix[i] != '-' && infix[i] != ')' && infix[i] != '('){
			postfix[j] = infix[i];
			j++;
		}
		else{
			if (infix[i] == '(' && operatorstack.isEmpty()){
				operatorstack.push(infix[i]);
			}
			else if (infix[i] == ')'){
				while (operatorstack.getHeadChar() != '('){
					postfix[j] = operatorstack.pop();
					j++;
				}
				if (operatorstack.getHeadChar() == '('){
					operatorstack.pop();
				}
			}
			else if (calculatePredence(infix[i]) < calculatePredence(operatorstack.getHeadChar())){
				if (operatorstack.getHeadChar() != '('){
					postfix[j] = operatorstack.pop();
					j++;
				}
				operatorstack.push(infix[i]);
			}
			else if (calculatePredence(infix[i]) >= calculatePredence(operatorstack.getHeadChar())){
				operatorstack.push(infix[i]);
			}
			

		}

	}

	while (!operatorstack.isEmpty()){
		postfix[j] = operatorstack.pop();
		j++;
	}
	postfix[j] = '\0';


	cout << "Postfix string: " << postfix << endl;

	operatorstack.makeEmpty();

	int sayi1, sayi2, result;
	char pop, push[10];
	for (int i = 0; postfix[i] != '\0'; i++){
		if (postfix[i] != '+' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '-' && postfix[i] != ')' && postfix[i] != '('){
			operatorstack.push(postfix[i]);
		}
		else{
			pop = operatorstack.pop();
			sayi1 = atoi(&pop);
			pop = operatorstack.pop();
			sayi2 = atoi(&pop);

			if (postfix[i] == '*'){
				result = sayi1 * sayi2;
			}
			else if (postfix[i] == '/'){
				result = sayi2 / sayi1;
			}
			else if (postfix[i] == '-'){
				result = sayi2 - sayi1;
			}
			else if (postfix[i] == '+'){
				result = sayi1 + sayi2;
			}
			
			sprintf(push, "%d", result);
			operatorstack.push(*push);
		}
	}

	pop = operatorstack.pop();
	result = atoi(&pop);

	cout << "Value = " << result;

	getchar();
	return 0;
}
