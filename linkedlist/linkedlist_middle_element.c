// THis program calculates the number of occurrences of an element in the linked list
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

// This function returns the middle element of the linked list
// this function uses two pointer, one traverse two times faster than other
// hence when the faster pointer reaches the end, slower one is in the middle
int middle_element(struct node *head)
{
	// declaring and initialising two pointers to traverse the linked list
	struct node *fast_ptr = head ;
	struct node *ptr = head;

	// traversing the linked list 
	while(fast_ptr != NULL && fast_ptr->next != NULL)
	{
		fast_ptr = (fast_ptr->next)->next;
		ptr = ptr->next;
	}

	// returning middle element
	return ptr->data;
}

// This function returns middle element using only one pointer
// In this function, the pointer traverse with half the speed,
// so when the list is traverse using head pointer, the middle pointer
// reaches the mid point of the list.
int middle_elem(struct node *head)
{
	// declaring and initializing the middle pointer 
	struct node *middle = head;

	// declaring and initializing a count variable to zero
	int count = 0;

	// traversing the linked list and updating the middle pointer 
	// only when the count is odd
	while(head != NULL)
	{
		// if count is odd update middle pointer
		if(count %2)
			middle = middle->next;
		
		// increament count
		++count;

		// updating head pointer to traverse the linked list
		head = head->next;
	}

	// returning the middle element
	return middle->data;
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
	append(&head, 15);
	append(&head, 12);
	append(&head, 9);

	printf("Printing all the elements : ");

	// printing the list with all elements
	print_list(head);

	// printing middle element using two pointer method
	printf("Middle element is : %d \n", middle_element(head));

	// printing middle element using single pointer method
	printf("Middle element is : %d \n", middle_elem(head));


	return 0;
}

