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

// This funtion for a node with given key in a linked list iteratively
// and takes pointer to head node and key to be searched as arguments
int linked_list_search(struct node *head, int key)
{

	// traversing the linked list to the end  
	while(head != NULL)
	{
		// if key is found, return 1
		if(head->data == key) return 1;
		head = head->next;
	}

	// if key is not found return 0
	return 0;
}

// This funtion for a node with given key in a linked list recursively
// and takes pointer to head node and key to be searched as arguments
int linked_list_search_recursive(struct node *head, int key)
{
	// base case when head is NULL return 0
	if(head == NULL) return 0;
	
	// if key is found return 1;
	if(head->data == key) return 1;


	// recursive case
	else return (linked_list_search_recursive(head->next, key));
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

	printf("Printing all the elements : ");

	// printing the list with all elements
	print_list(head);
	
	// searching an element in linked list iterattivley
	linked_list_search(head, 21)? printf("Yes\n") : printf("No\n");


	// searching an element in linked list iterattivley
	linked_list_search(head, 7)? printf("Yes\n") : printf("No\n");


	// searching an element in linked list iterattivley
	linked_list_search(head, 9)? printf("Yes\n") : printf("No\n");


	// searching an element in linked list iterattivley
	linked_list_search(head, 1)? printf("Yes\n") : printf("No\n");

	return 0;
}

