#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	void* Data;
	struct Node* Next;
	struct Node* Prev;
} Node;

typedef struct LinkedList {

	Node* firstNode;
	Node* lastNode;
	int Count;
} LinkedList;

LinkedList CreateLinkedList() {
	LinkedList list;
	list.Count = 0;
	list.firstNode = NULL;
	list.lastNode = NULL;
	return list;
}

Node* GetNode(LinkedList* list, int index) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.
	if (index < 0 || index >= list->Count) {
		return NULL; // ���� ó�� ��� ã�ƺ���
	}

	// ����Ʈ ��ü ������ ����
	int temp = index / 2;
	// 0 : �տ������� Ž��, 1 : �ڿ������� Ž��
	int isFirst = 0;

	// �ε����� ����Ʈ�� ���� ���̺��� ������ �տ��� Ž��, ũ�� �ڿ��� Ž��
	if (index <= temp) {
		isFirst = 0;
	}
	else {
		isFirst = 1;
	}

	// �տ������� Ž��
	if (isFirst == 0) {

		Node* currentNode = list->firstNode;

		for (int i = 0; i < list->Count; i++) {
			if (i == index) {
				break;
			}
			currentNode = currentNode->Next;
		}

		return currentNode;
	}
	// �ھּ����� Ž��
	else if (isFirst == 1) {

		Node* currentNode = list->lastNode;

		for (int i = list->Count - 1; i >= 0; i--)
		{
			if (i == index)
			{
				break;
			}
			currentNode = currentNode->Prev;
		}

		return currentNode;
	}
}


void Add(LinkedList* list, void* data) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.

	// �ű� ��� ����
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		// �޸� �Ҵ� ���� ó��
		return;
	}
	node->Data = data;

	// ù ����� ���
	if (list->firstNode == NULL) {
		list->firstNode = node;
		list->lastNode = node;

		list->firstNode->Next = list->lastNode;
		list->firstNode->Prev = list->lastNode;

		list->lastNode->Next = list->firstNode;
		list->lastNode->Prev = list->firstNode;

		list->Count++;
		return;
	}

	// �߰�
	list->lastNode->Next = node;
	node->Next = list->firstNode;

	// ���ο� ����� ���� ��带 ������ ���� �߰�
	node->Prev = list->lastNode;
	// ó�� ����� ���� ��带 ������ ���� ������Ʈ
	list->firstNode->Prev = node;
	// ���ο� ��带 ������ ���� ������Ʈ
	list->lastNode = node;

	list->Count++;
}

void AddIndex(LinkedList* list, int index, void* data) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.
	if (index < 0 || index > list->Count) {
		return; // ���� ó�� ��� ã�ƺ���
	}

	// �ű� ��� ����
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		// �޸� �Ҵ� ���� ó��
		return;
	}
	node->Data = data;

	// ù ����� ���
	if (list->Count == 0) {
		list->firstNode = node;
		list->lastNode = node;
	}

	// Ž��
	Node* currentNode = GetNode(list, index);
	Node* beforeNode = currentNode->Prev;

	// �߰�
	beforeNode->Next = node;
	currentNode->Prev = node;

	node->Next = currentNode;
	node->Prev = beforeNode;

	list->Count++;

	if (index == 0) {
		// ��带 �߰��� �ε����� 0�� ��� FirstNode, LastNode�� ������Ʈ
		list->firstNode = node;
		list->lastNode = node;
	}
	if (index == list->Count) {
		// ��带 �߰��� �ε����� ����Ʈ�� ũ��� ���� ��� LastNode�� ������Ʈ
		list->lastNode = node;
	}
}

void Delete(LinkedList* list, int index) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.
	if (index < 0 || index > list->Count) {
		return; // ���� ó�� ��� ã�ƺ���
	}

	// Ž��
	Node* currentNode = GetNode(list, index);
	Node* beforeNode = currentNode->Prev;

	// ����
	beforeNode->Next = currentNode->Next;
	currentNode->Next->Prev = beforeNode;

	list->Count--;

	if (index == 0)
	{
		// ��带 ������ �ε����� 0�� ��� FirstNode�� ������Ʈ
		list->firstNode = list->firstNode->Next;
	}
	if (index == list->Count)
	{
		// ������ ��尡 ������ ����� ��� lastNode ������Ʈ
		list->lastNode = beforeNode;
	}
	free(currentNode);
}

void* Get(LinkedList* list, int index) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.
	if (index < 0 || index >= list->Count) {
		return; // ���� ó�� ��� ã�ƺ���
	}

	Node* node = GetNode(list, index);
	return node->Data;
}


void Edit(LinkedList* list, int index, void* data) {

	// ���� ó��, list�� ����ִ� ��� �߰��� ��.
	if (index < 0 || index >= list->Count) {
		return; // ���� ó�� ��� ã�ƺ���
	}

	Node* currentNode = GetNode(list, index);
	currentNode->Data = data;
}

int main() {
	LinkedList list = CreateLinkedList();

	int a = 10, b = 20, c = 30;

	// �� �߰�
	Add(&list, &a);
	Add(&list, &b);
	Add(&list, &c);

	// �߰��� �� ���
	printf("LinkedList ���:\n");
	for (int i = 0; i < list.Count; i++) {
		int* val = (int*)Get(&list, i);
		printf("Index %d: %d\n", i, *val);
	}

	// �� ����
	int d = 100;
	Edit(&list, 1, &d);

	printf("\n���� �� LinkedList ���:\n");
	for (int i = 0; i < list.Count; i++) {
		int* val = (int*)Get(&list, i);
		printf("Index %d: %d\n", i, *val);
	}

	// ��� ����
	Delete(&list, 0);

	printf("\n���� �� LinkedList ���:\n");
	for (int i = 0; i < list.Count; i++) {
		int* val = (int*)Get(&list, i);
		printf("Index %d: %d\n", i, *val);
	}

	return 0;
}
