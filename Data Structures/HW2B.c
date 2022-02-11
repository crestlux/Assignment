#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK 101
typedef enum{ false, true } bool; 
typedef int Data; 
typedef struct{ 
	Data items[MAX_STACK];
	int top; 
} Stack;

void InitStack(Stack*pstack);
bool IsFull(Stack*pstack);
bool IsEmpty(Stack*pstack);
Data Peek(Stack*pstack);
void Push(Stack*pstack, Data item);
void Pop(Stack*pstack);

void printRev(char* input, int len);
int ReverseChk(char* input, int len);

int main() {
	char input[101] = {'\0',};
	scanf("%s", input);
	printRev(input, strlen(input));
	printf("%d", ReverseChk(input, strlen(input)));
	return 0;
}

void InitStack(Stack*pstack) {
	pstack->top = -1;
}
bool IsFull(Stack*pstack) {
	return pstack->top == MAX_STACK - 1;
}
bool IsEmpty(Stack*pstack) {
	return pstack->top == -1;
}
Data Peek(Stack*pstack) {
	if (IsEmpty(pstack))exit(1);
	return pstack->items[pstack->top];
}
void Push(Stack*pstack, Data item) {
	if (IsFull(pstack))exit(1);
	pstack->items[++(pstack->top)] = item;
}
void Pop(Stack*pstack) {
	if (IsEmpty(pstack))exit(1);
	--(pstack->top);
}

void printRev(char* input, int len) {
	Stack stack; int count_length = 0, j = 0;
	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		Push(&stack, input[i]);
		++count_length;
	}
	while (!IsEmpty(&stack) && j < count_length) {
		printf("%c", Peek(&stack));
		++j;
		Pop(&stack);
	}
	printf("\n");
}

int ReverseChk(char* input, int len) {
	Stack stack;
	char output[101] = { '\0', }; int count_length = 0, count = 0;
	InitStack(&stack);
	for (int i = 0; i < len; i++) {
		Push(&stack, input[i]);
		++count_length;
	}
	int j = 0;
	while (!IsEmpty(&stack) && j < count_length) {
		output[j] = Peek(&stack);
		++j;
		Pop(&stack);
	}
	for (int i = 0; i < len; i++) {
		if (input[i] == '*' || output[i] == '*') {
			continue;
		}
		else if (input[i] != output[i]) {
			count++;
		}
		else continue;
	}
	return count;
}
