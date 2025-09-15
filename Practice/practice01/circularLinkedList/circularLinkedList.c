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
	// 신규 노드 생성
	Node node = { data };

	// 첫 노드인 경우
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

	// 추가
	list->lastNode->next = &node;
	node.next = list->firstNode;

	// 새로운 노드의 이전 노드를 마지막 노드로 추가
	node.prev = list->lastNode;
	// 처음 노드의 이전 노드를 마지막 노드로 업데이트
	list->firstNode->prev = &node;
	// 새로운 노드를 마지막 노드로 업데이트
	list->lastNode = &node;

	list->Count++;
}

void Delete() {

}
