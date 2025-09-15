#include <stdio.h>

typedef struct Node {
	void* data;
	struct Node* next;
	struct Node* prev;
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

void Add(LinkedList* list, void* data) {
	// �ű� ��� ����
	Node node = { data };

	// ù ����� ���
	if (list->firstNode == NULL) {
		list->firstNode = &node;
		list->lastNode = &node;

		list->firstNode->next = list->lastNode;
		list->firstNode->prev = list->lastNode;

		list->lastNode->next = list->firstNode;
		list->lastNode->prev = list->firstNode;

		list->Count++;
		return;
	}

	// �߰�
	list->lastNode->next = &node;
	node.next = list->firstNode;

	// ���ο� ����� ���� ��带 ������ ���� �߰�
	node.prev = list->lastNode;
	// ó�� ����� ���� ��带 ������ ���� ������Ʈ
	list->firstNode->prev = &node;
	// ���ο� ��带 ������ ���� ������Ʈ
	list->lastNode = &node;

	list->Count++;
}

void Delete() {

}
