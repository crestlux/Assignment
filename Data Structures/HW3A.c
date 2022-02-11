#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Modify from here */


/* Modify to here */


typedef enum { false, true } bool;


typedef struct _Node
{
	int octal;
	struct _Node* next;
} Node;

typedef struct
{
	Node* head;
	int len;
} LinkedList;

void InitList(LinkedList* plist);
int IsEmpty(LinkedList* plist);
void Insert(LinkedList* plist, int data);
void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c);
void PrintList(LinkedList* plist);
void PrintListHex(LinkedList* plist);

/* Modify from here */
void bubbleSortNode(Node *list, int size);
void swapNodeData(Node *node1, Node *node2);
/* Modify to here */


int main() {
	int i, j;
	int cnt;
	int input;
	LinkedList list_a, list_b, list_c;

	InitList(&list_a);
	InitList(&list_b);
	InitList(&list_c);

	for (i = 0; i < 2; i++)
	{
		scanf("%d", &cnt);
		for (j = 0; j < cnt; j++)
		{
			scanf("%d", &input);
			if (i == 0)
				Insert(&list_a, input);
			else
				Insert(&list_b, input);
		}
	}

	MergeTwoList(&list_a, &list_b, &list_c);

	PrintList(&list_a);
	PrintList(&list_b);
	PrintList(&list_c);
	PrintListHex(&list_c);

	return 0;
}

/* Modify from here */
void InitList(LinkedList* plist) {
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->len = 0;
}
int IsEmpty(LinkedList* plist) {
	return plist->len == 0;
}
void Insert(LinkedList* plist, int data) {
	Node* cur, *newNode;
	newNode = (Node *)malloc(sizeof(Node));
	newNode->octal = data;
	newNode->next = NULL;
	cur = plist->head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	newNode->next = cur->next;
	cur->next = newNode;
	plist->len++;

}
void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c) {
	for (Node* cur = plist_a->head->next; cur != NULL; cur = cur->next)
		Insert(plist_c, cur->octal);
	for (Node* cur = plist_b->head->next; cur != NULL; cur = cur->next)
		Insert(plist_c, cur->octal);
}
void PrintList(LinkedList* plist) {
	bubbleSortNode(plist->head, plist->len);
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next)
		printf("%d ", cur->octal);
	printf("\n");
}
void PrintListHex(LinkedList* plist) {
	bubbleSortNode(plist->head, plist->len);
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next) {
		int temp = cur->octal; long res;
		char oct[4]; char* end;
		sprintf(oct, "%d", temp);
		res = strtol(oct, &end, 8);
		printf("%X ", (unsigned int)res);
	}
	printf("\n");
}
void bubbleSortNode(Node *list, int size) {
	Node *cur;
	cur = list; cur->octal = 0;
	cur = cur->next;
	for (int i = 0; i < size; i++) {
		if (cur->next == NULL) break;
		for (int j = 0; j < size - 1 - i; j++) {
			if (cur->octal > cur->next->octal) {
				swapNodeData(cur, cur->next);
			}
			cur = cur->next;
		}
		cur = list->next;
	}
}
void swapNodeData(Node *node1, Node *node2) {
	int temp;
	temp = node1->octal;
	node1->octal = node2->octal;
	node2->octal = temp;
}
/* Modify to here */
