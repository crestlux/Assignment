#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10001

typedef enum { false, true } bool;

bool cycle = false;
int parx, pary;

typedef struct _GNode {
	int id;
	char data;
	struct _GNode* next;
} GNode;

typedef struct {
	int num;
	GNode** heads;
} Graph;

void CreateGraph(Graph* pgraph, int num, char* data);
void DestroyGraph(Graph* pgraph);
void AddEdge(Graph* pgraph, int src, int dest);
void GetInput();

int parent[MAX_SIZE];

int find(int x) {
	if (parent[x] < 0) {
		return x;
	}
	else {
		int y = find(parent[x]);
		parent[x] = y;
		return y;
	}
}

void Union(int x, int y) {
	int nx = find(x); int ny = find(y);
	if (nx == ny) {
		cycle = true;
		parx = x; pary = y;
		return;
	}
	if (parent[nx] < parent[ny]) {
		parent[nx] += parent[ny];
		parent[ny] = nx;
	}
	else {
		parent[ny] += parent[nx];
		parent[nx] = ny;
	}
}

int main() {
	for (int i = 0; i < MAX_SIZE; i++)
		parent[i] = -1;
	GetInput();
	return 0;
}

void CreateGraph(Graph* pgraph, int num, char* data) {
	pgraph->num = num;
	pgraph->heads = (GNode **)malloc(sizeof(GNode*) * num);
	for (int i = 0; i < num; i++) {
		pgraph->heads[i] = (GNode *)malloc(sizeof(GNode));
		pgraph->heads[i]->data = data[i];
		pgraph->heads[i]->next = NULL;
	}
}

void DestroyGraph(Graph* pgraph) {
	for (int i = 0; i < pgraph->num; i++) {
		GNode* cur = pgraph->heads[i];
		while (cur != NULL) {
			GNode* temp = cur;
			cur = cur->next;
			free(temp);
		}
	}
	free(pgraph->heads);
}

void GetInput() {
	int node, edge, src, des;
	char* a;
	scanf("%d %d", &node, &edge);
	getchar();
	a = malloc(sizeof(char) * (node + 1));
	scanf("%s", a);
	getchar();
	Graph g;
	CreateGraph(&g, node, a);
	for (int i = 0; i < edge; i++) {
		scanf("%d %d", &src, &des);
		AddEdge(&g, src, des);
		Union(src, des);
		getchar();
	}
	if (cycle == true) {
		printf("%d %d\n", parx, pary);
	}
	DestroyGraph(&g);
}

void AddEdge(Graph* pgraph, int src, int dest) {
	GNode *newNode1, *newNode2, *cur;
	newNode1 = (GNode *)malloc(sizeof(GNode));
	newNode1->id = dest;
	newNode1->next = NULL;
	cur = pgraph->heads[src];
	while (cur->next != NULL) {
		if (cur->id < newNode1->id && newNode1->id < cur->next->id) {
			newNode1->next = cur->next;
			cur->next = newNode1;
			break;
		}
		else cur = cur->next;
	}
	if (cur->next == NULL) cur->next = newNode1;
	newNode2 = (GNode *)malloc(sizeof(GNode));
	newNode2->id = src;
	newNode2->next = NULL;
	cur = pgraph->heads[dest];
	while (cur->next != NULL) {
		if (cur->id < newNode2->id && newNode2->id < cur->next->id) {
			newNode2->next = cur->next;
			cur->next = newNode2;
			break;
		}
		else cur = cur->next;
	}
	if (cur->next == NULL) cur->next = newNode2;
}
