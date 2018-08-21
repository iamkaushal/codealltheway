#include<stdio.h>
#include<stdlib.h>

// Creating a structure for linked list node
struct node
{
	int data; // variable to store data in node
	struct node *next; //pointer to store the address of the connected node
};


// This function will add a node at the beginning of the linked list
// This functions takes pointer to pointer of head and value to be pushed in 
// the linked list
void push(struct node **head, int value)
{
	// Creating a memory block using malloc to store the data and assigning 
	// it to a struct node pointer named temp
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	//assigning data to the node 
	temp->data = value;

	// changing the next pointer in node to point to head node
	temp->next  = (*head);

	// Changing the head node to point to the temp node created above
	*head = temp;
}

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

// This function will insert a node into the linked list at the given position 
// This functions takes pointer to pointer of head, value to be inserted 
// and the position at which it has to be inserted into the linked list
void insert_at_position(struct node **head, int value, int position)
{
	// Creating a memory block using malloc to store the data and assigning 
	// it to a struct node pointer named temp
	struct node *temp = (struct node*)malloc(sizeof(struct node));

	// assigning the data to the node
	temp->data = value;

	// if position at which node is to be inserted is 0 and
	// head is not NULL, then we will point the next of temp node
	// to the head and pointer of head node to the temp node and return
	if(position == 0 && *head != NULL)
	{
		temp->next = (*head)->next;
		*head = temp;
		return;
	}

	// creating a struct node pointer called trav to traverse the list
	// to the the given position and using pointer named prev to keep 
	// track of the previous node
	struct node *trav = *head, *prev;

	// traversing the linked list to the given position and keeping
	// track of the prev node too
	while(trav != NULL && position--)
	{
		prev = trav;
		trav = trav->next;
	}

	// changing the next pointer of prev node to the temp node created
	// above and them changing  the pointer of the temp node to the 
	// node at current positon i.e, trav
	prev->next = temp;
	temp->next = trav;
}

// This function inserts a node after a node of given key.
// This function takes pointer to pointer of head node, key of node after which
// node is to be inserted and the data of the node to be inserted into the linked list
void insert_after(struct node **head, int key, int data)
{
	// Creating a memory block using malloc to store the data and assigning 
	// it to a struct node pointer named temp
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	// assigning the data to the node
	temp->data = data;

	// If head node is NULL, return 
	if(*head == NULL)
	{
		printf("Head cannot be a null pointer\n");
		return;
	}

	// creating a struct node pointer called trav to traverse the list
	// to the the node with given key
	struct node *trav = *head;

	while(trav != NULL && trav->data != key)
		trav = trav->next;

	// if the trav pointer is NULL, then the key is not found, hence return
	if(trav == NULL)
	{
		printf("Element not found\n");
		return;
	}

	// changing the next pointer of the temp node created above to the next of current node
	// and changing the next pointer of current node, i.e, trav to the temp node.
	temp->next = trav->next;
	trav->next = temp;
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

	// Calling the function to add elements at the end of linked list
	append(&head, 7);
	append(&head, 8);
	append(&head, 9);
	print_list(head);

	// calling the function to add element at the beginning of linked list
	push(&head, 5);
	print_list(head);

	// calling the function to add element at a given positon of the linked list
	insert_at_position(&head, 4, 1);
	print_list(head);

	// calling the function to add node after the node with given key
	insert_after(&head, 7 ,47);
	print_list(head);

	return 0;
}
