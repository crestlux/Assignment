#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/* Modify from here */

/* Modify to here */

#define MAX_SIZE 100

typedef enum { false, true } bool;

typedef struct {
	char small;
	char middle;
	char large;
} Hexa_num;

typedef struct {
    Hexa_num data; // This is a priority as well as data
} PNode;

typedef struct {
	PNode items[MAX_SIZE + 1];
	int num;
} Heap;

void InitHeap(Heap *pheap);

bool IsEmpty(Heap *pheap);

bool IsFull(Heap *pheap);

void Insert(Heap *pheap, Hexa_num data);

Hexa_num Delete(Heap *pheap);

void HeapSort(Hexa_num a[], int n);

Hexa_num *CreateHexaNum(int n);

void GetInput();

/* Modify from here */
bool compareNum(Hexa_num bigger, Hexa_num smaller);
int GetParent(int idx);
int GetLChild(int idx);
int GetRChild(int idx);
int GetPrioityChild(Heap* pheap, int idx);
/* Modify to here */

int main() {
    
	GetInput();
	/*
	5
	0E0
	321
	EEE
	CCC
	3D0
	*/

	return 0;
}

void HeapSort(Hexa_num a[], int n) {
	Heap heap;
	InitHeap(&heap);
	for (int i = 0; i < n; i++)
		Insert(&heap, a[i]);
	for (int i = 0; i <= n-1; i++)
		a[i] = Delete(&heap);

	for (int i = 0; i < n; i++)
		printf("%c%c%c\n", a[i].large, a[i].middle, a[i].small);
}

Hexa_num *CreateHexaNum(int n){
    char a[4];
	Hexa_num *res = (Hexa_num*)malloc(sizeof(Hexa_num)*(n));
	for (int i = 0; i < n; i++) {
        scanf("%s", a);
        res[i].large = a[0];
		res[i].middle = a[1];
		res[i].small = a[2];
	}
	return res;
}

void GetInput() {
    int n;
    Hexa_num *data;
    scanf("%d", &n);
    data = CreateHexaNum(n);
	HeapSort(data, n);
}

/* Modify from here */
void InitHeap(Heap *pheap) {
	pheap->num = 0;
}

bool IsEmpty(Heap *pheap) {
	return pheap->num == 0;
}

bool IsFull(Heap *pheap) {
	return pheap->num == MAX_SIZE;
}

void Insert(Heap *pheap, Hexa_num data) {
	PNode newNode;
	int idx = pheap->num + 1;
	if (IsFull(pheap)) exit(1);
	while (idx > 1) {
		int parent = GetParent(idx);
		if (compareNum(pheap->items[parent].data, data)) {
			pheap->items[idx] = pheap->items[parent];
			idx = parent;
		}
		else break;
	}
	newNode.data = data;
	pheap->items[idx] = newNode;
	pheap->num++;
}

Hexa_num Delete(Heap *pheap) {
	Hexa_num max = pheap->items[1].data;
	PNode last = pheap->items[pheap->num];
	int parent = 1, child;
	while (child = GetPrioityChild(pheap, parent)) {
		if (compareNum(last.data, pheap->items[child].data)) {
			pheap->items[parent] = pheap->items[child];
			parent = child;
		}
		else break;
	}
	pheap->items[parent] = last;
	pheap->num--;
	return max;
}

int GetParent(int idx) {
	return idx / 2;
}
int GetLChild(int idx) {
	return idx * 2;
}
int GetRChild(int idx) {
	return idx * 2 + 1;
}
int GetPrioityChild(Heap* pheap, int idx) {
	if (GetLChild(idx) > pheap->num)
		return 0;
	else if (GetLChild(idx) == pheap->num)
		return GetLChild(idx);
	else {
		int left = GetLChild(idx), right = GetRChild(idx);
		if (compareNum(pheap->items[left].data, pheap->items[right].data))
			return right;
		else
			return left;
	}
}
bool compareNum(Hexa_num bigger, Hexa_num smaller) {
	if (bigger.large > smaller.large) return true;
	else if (bigger.large < smaller.large) return false;
	else {
		if (bigger.middle > smaller.middle) return true;
		else if (bigger.middle < smaller.middle) return false;
		else {
			if (bigger.small > smaller.small) return true;
			else if (bigger.small < smaller.small) return false;
			else false;
		}	
	}
}
/* Modify to here */
