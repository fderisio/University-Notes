#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// list.h
typedef struct _bookNode
{
    //char *title;
	int numPages;
    struct _bookNode *next;
} tBookNode;


// list.c
// create node
tBookNode *createNode(int numPages) {
    tBookNode *p = malloc(sizeof(tBookNode));
	
	if (p != NULL) {
		/*p->title = malloc(strlen(title) + 1);
		strcpy(p->title, title);*/
		p->numPages = numPages;
		p->next = NULL;
	}

    return p;
}

// main.c
int main(int argc, char **argv)
{
	tBookNode* node = createNode(75);
	
	assert(node != NULL);
	
	tBookNode* head = node; 	// head points to node
	tBookNode** list = &head; 	// list points to head
	
	printf("******* node info *******\n");
	printf("node memory address: %p \n", &node);
	printf("node content: %p \n", node); // pointer to node address given by malloc()
	printf("node pages: %d \n\n", node->numPages);
	
	printf("******* head info *******\n");
	printf("head memory address: %p \n", &head);
	printf("head content: %p \n", head); // pointer to node address given by malloc()
	printf("head access num pages: %d \n\n", (*head).numPages);

	printf("******* linked list info *******\n");
	printf("list memory address: %p \n", &list);
	printf("list content: %p \n", list); // memory address of head node
	printf("list access num pages: %d \n", (**list).numPages);

	return 0;
}
