#include<stdlib.h>
#include<stdio.h>

// Creating a structure for linked list node
struct node
{
	int data; // variable to store data in node
	struct node *next; //pointer to store the address of the connected node
};

// This function will add a node at the end of the linked list
// This functions takes pointer to pointer of head and value to be appended into 
// the linked list
void append(struct node **head_ref, int value)
{
	// Creating a memory block using malloc to store the data and assigning 
	// it to a struct node pointer named temp
	struct node *temp = (struct node *)malloc(sizeof(struct node)) ;

	// assigning the data to the node
	temp->data = value;

	// assigning the next pointer to NULL, as 
	// it will be the last node of linked list
	temp->next = NULL;

	// if head is NULL, then we will just point the head node to
	// the temp node created above and return
	if(*head_ref == NULL) 
	{
		*head_ref = temp;
		return;
	}

	// creating a struct node pointer called trav to traverse the list
	// to the end
	struct node *trav = *head_ref;

	// traversing the list to the end
	while(trav->next != NULL)
		trav = trav->next;

	// pointing the next pointer of last node to the temp node 
	trav->next = temp;
}

//This funtion deletes the node with given key from the linked list
// function takes double pointer of head node, and the key of node to be 
// deleted as parameters
void deletenode(struct node **head, int value)
{
	// declaring two pointers temp and prev to traverse the linked list to 
	// the node with given key and keeping track of previous node too
	struct node *temp = *head, *prev;

	// if head is not NULL and contains the value to be deleted
	// changing the head to the next of head and free the head node using
	// address stored in temp 
	if((*head) != NULL && (*head)->data == value)
	{
		*head = (*head)->next;
		free(temp);
		return;
	}

	// traversing the linked list to the node with given data
	while(temp != NULL && temp->data != value)
	{
		prev = temp;
		temp = temp->next;
	}

	// if there is no node with given data, return 
	if(temp == NULL) return;

	// changing the next of prev node to the next of temp node 
	// and then free the temp node
	prev->next = temp->next;
	free(temp);
}


// This function prints the linked list and takes the head pointer as 
// its parameter
void print_list(struct node *head)
{	
	// traversing the linked list till the end and printing 
	// the data in the nodes
	while(head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}

	// printing new line after printing the whole linked list
	printf("\n");
}

// Main driver function
int main()
{
	// this is to read input and write output in 
	// input.txt and output.txt files in the same folder
	#ifndef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// creating head node of the linked list and assigning it to NULL
	struct node *head = NULL;

	// call the append function to add elements to the list
	append(&head, 7);
	append(&head, 8);
	append(&head, 9);

	// printing the list with all elements
	print_list(head);

	// deleting node with given key from the list
	deletenode(&head, 7);
	
	// printing the list
	print_list(head);

	// deleting node with given key from the list
	deletenode(&head, 8);
	
	// printing the list
	print_list(head);
	
	return 0;
}
