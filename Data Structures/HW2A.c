#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STACK 100

typedef enum { false, true } bool;

typedef struct {
	char small;
	char large;
	// *Variable "operator"
	// used in ConvInfixToPostfix function
	char operator;
}Hexa_num;

typedef struct {
	Hexa_num items[MAX_STACK];
	int top;
}Stack;

/* Modify from here */
// if you need any user-defined function
int htoi(Hexa_num b1, Hexa_num b2, char op) {
	int as = 0, al = 0, a, bs = 0, bl = 0, b, ans;
	if (b1.small <= '9') as = b1.small - '0';
	else {
		as = (b1.small - (char)17 - '0') + 10;
	}
	if (b2.small <= '9') bs = b2.small - '0';
	else {
		bs = (b2.small - (char)17 - '0') + 10;
	}
	if (b1.large <= '9') al = (b1.large - '0') * 16;
	else {
		al = ((b1.large - (char)17 - '0') + 10) * 16;
	}
	if (b2.large <= '9') bl = (b2.large - '0') * 16;
	else {
		bl = ((b2.large - (char)17 - '0') + 10) * 16;
	}
	a = as + al; b = bs + bl;
	if (op == '+') {
		ans = a + b;
		return ans;
	}
	if (op == '-') {
		ans = a - b;
		return ans;
	}
	if (op == '*') {
		ans = a * b;
		return ans;
	}
	if (op == '/') {
		ans = a / b;
		return ans;
	}
}
/* Modify to here */

Hexa_num add(Hexa_num b1, Hexa_num b2);
Hexa_num subtract(Hexa_num b1, Hexa_num b2);
Hexa_num multiply(Hexa_num b1, Hexa_num b2);
Hexa_num division(Hexa_num b1, Hexa_num b2);
void InitStack(Stack *pstack);
bool IsFull(Stack *pstack);
bool IsEmpty(Stack *pstack);
Hexa_num Peek(Stack *pstack);
void Push(Stack *pstack, Hexa_num item);
void Pop(Stack *pstack);
void ConvInfixToPostfix(char* exp, char* convExp, int len);
Hexa_num EvalPostfix(char* exp, int len);
void print_Hexa_num(Hexa_num result);


int main() {
	char infix_exp[100];
	char postfix_exp[100];
	Hexa_num result;

	scanf("%s", infix_exp);

	ConvInfixToPostfix(infix_exp, postfix_exp, strlen(infix_exp));
	printf("%s\n", postfix_exp);
	result = EvalPostfix(postfix_exp, strlen(postfix_exp));
	print_Hexa_num(result);
	return 0;
}
/* Modify from here */
// implementation of functions
Hexa_num add(Hexa_num b1, Hexa_num b2) {
	Hexa_num ret;
	int num, tmp1, tmp2;
	num = htoi(b1, b2, '+');
	tmp1 = num / 16;//large
	if (tmp1 <= 9) {
		ret.large = tmp1 + '0';
	}
	else {
		ret.large = (tmp1 - 10) + 'A';
	}
	tmp2 = num % 16;//small
	if (tmp2 <= 9) {
		ret.small = tmp2 + '0';
	}
	else {
		ret.small = (tmp2 - 10) + 'A';
	}
	return ret;
}
Hexa_num subtract(Hexa_num b1, Hexa_num b2) {
	Hexa_num ret;
	int num, tmp1, tmp2;
	num = htoi(b1, b2, '-');
	tmp1 = num / 16;//large
	if (tmp1 <= 9) {
		ret.large = tmp1 + '0';
	}
	else {
		ret.large = (tmp1 - 10) + 'A';
	}
	tmp2 = num % 16;//small
	if (tmp2 <= 9) {
		ret.small = tmp2 + '0';
	}
	else {
		ret.small = (tmp2 - 10) + 'A';
	}
	return ret;
}
Hexa_num multiply(Hexa_num b1, Hexa_num b2) {
	Hexa_num ret;
	int num, tmp1, tmp2;
	num = htoi(b1, b2, '*');
	tmp1 = num / 16;//large
	if (tmp1 <= 9) {
		ret.large = tmp1 + '0';
	}
	else {
		ret.large = (tmp1 - 10) + 'A';
	}
	tmp2 = num % 16;//small
	if (tmp2 <= 9) {
		ret.small = tmp2 + '0';
	}
	else {
		ret.small = (tmp2 - 10) + 'A';
	}
	return ret;
}
Hexa_num division(Hexa_num b1, Hexa_num b2) {
	Hexa_num ret;
	int num, tmp1, tmp2;
	num = htoi(b1, b2, '/');
	tmp1 = num / 16;//large
	if (tmp1 <= 9) {
		ret.large = tmp1 + '0';
	}
	else {
		ret.large = (tmp1 - 10) + 'A';
	}
	tmp2 = num % 16;//small
	if (tmp2 <= 9) {
		ret.small = tmp2 + '0';
	}
	else {
		ret.small = (tmp2 - 10) + 'A';
	}
	return ret;
}

void InitStack(Stack *pstack) {
	pstack->top = -1;
}
bool IsFull(Stack *pstack) {
	return pstack->top == MAX_STACK - 1;
}
bool IsEmpty(Stack *pstack) {
	return pstack->top == -1;
}
Hexa_num Peek(Stack *pstack) {
	if (IsEmpty(pstack))exit(1);
	return pstack->items[pstack->top];
}
void Push(Stack *pstack, Hexa_num item) {
	if (IsFull(pstack))exit(1);
	pstack->items[++(pstack->top)] = item;
}
void Pop(Stack *pstack) {
	if (IsEmpty(pstack))exit(1);
	--(pstack->top);
}

void ConvInfixToPostfix(char* exp, char* convExp, int len) {
	Stack s1; Hexa_num h1; int nlenstk = 0;
	InitStack(&s1);
	for (int i = 0, j = 0; i < len; i++)
	{
		if ((exp[i] >= '0' && exp[i] <= '9') || (exp[i] >= 'A' && exp[i] <= 'F')) {
			h1.large = exp[i];
			h1.small = exp[i + 1];
			convExp[i-j] = exp[i];
			convExp[i + 1 - j] = exp[i + 1];
			i++;
			nlenstk += 2;
			continue;
		}
		else {
			if (exp[i] == '+' || exp[i] == '-') {
				h1.operator = exp[i];
				while (!IsEmpty(&s1)) {
					convExp[i-j] = Peek(&s1).operator;
					Pop(&s1);
					--j;
				}
				Push(&s1, h1);
				++nlenstk;
				++j;
				continue;
			}
			else if (exp[i] == '*' || exp[i] == '/')
			{
				h1.operator = exp[i];
				while (!IsEmpty(&s1) && (Peek(&s1).operator == '*' || Peek(&s1).operator == '/')) {
					convExp[i-j] = Peek(&s1).operator;
					Pop(&s1);
					--j;
				}
				Push(&s1, h1);
				++nlenstk;
				++j;
				continue;
			}
		}
	}
	int tmp = 0 , stackcnt = 0;
	Stack s2;
	InitStack(&s2);
	s2 = s1;
	while (!IsEmpty(&s2)) {
		Pop(&s2);
		++stackcnt;
	}
	while (!IsEmpty(&s1)) {
		convExp[nlenstk+tmp-stackcnt] =  Peek(&s1).operator;
		++tmp;
		Pop(&s1);
	}
	convExp[len] = '\0';
}
Hexa_num EvalPostfix(char* exp, int len) {
	Hexa_num ret, operand, tp1, tp2; Stack s1;
	InitStack(&s1);
	for (int i = 0; i < len; i++) {
		if (exp[i] == '+') {
			tp1 = Peek(&s1);
			Pop(&s1); 
			tp2 = Peek(&s1);
			Pop(&s1);
			Push(&s1, add(tp2, tp1));
		}
		else if (exp[i] == '-') {
			tp1 = Peek(&s1);
			Pop(&s1);
			tp2 = Peek(&s1);
			Pop(&s1);
			Push(&s1, subtract(tp2,tp1));
		}
		else if (exp[i] == '*') {
			tp1 = Peek(&s1);
			Pop(&s1);
			tp2 = Peek(&s1);
			Pop(&s1);
			Push(&s1, multiply(tp2, tp1));
		}
		else if (exp[i] == '/') {
			tp1 = Peek(&s1);
			Pop(&s1);
			tp2 = Peek(&s1);
			Pop(&s1);
			Push(&s1, division(tp2, tp1));
		}
		else {
			operand.large = exp[i];
			operand.small = exp[i+1];
			Push(&s1, operand);
			i++;
		}
	}
	ret = Peek(&s1);
	Pop(&s1);
	return ret;
}
void print_Hexa_num(Hexa_num result) {
	printf("%c%c", result.large, result.small);
}

/* Modify to here */
