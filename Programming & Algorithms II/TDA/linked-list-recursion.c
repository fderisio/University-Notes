#include <stdio.h>

// Linked list of theatre plays and spectators
typedef struct _tNode {         // structure name
	int idPlay;
	int spectators;
	struct _tNode* next;        // pointer to next node 
} tNode;                        // data type to declare structure

tNode createNode(int idPlay, int spectators, tNode *next) {
	
	tNode node;
	
	node.idPlay = idPlay;
	node.spectators = spectators;
	node.next = next;
	
	return node;
}

int calculateAudience(tNode* list) {
	int result = 0;
	
    // base case
	if (list->next == NULL) {
		result = list->spectators;
	} else {
        // recursion case
		result = list->spectators + calculateAudience(list->next);
	}

	return result;
}

int main(int argc, char **argv)
{
	tNode node1;
	tNode node2;
	tNode node3;
		
	node1 = createNode(1, 50, &node2);
	node2 = createNode(2, 50, &node3);
	node3 = createNode(3, 50, NULL);
	
	printf("Total audience: %d", calculateAudience(&node1));
	
	return 0;
}
