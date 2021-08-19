#include <stdio.h>
#include <conio.h>
#include <stdlib.h>         //for memory allocation
#include <string.h>

#define NAME_LEN 20

/*function prototypes*/
struct node* initnode(char*, int);
void printnode(struct node*);
void printlist(struct node*);
void addtoend(struct node*);
void addtohead(struct node*);
struct node* searchname(char*);
void deletenode(struct node*);
void deletelist();
void reverselist(struct node*);


struct node {                  //a node definition
	char name[NAME_LEN];
	int id;
	struct node* next;
};

struct node* head = NULL;
struct node* end = NULL;

struct node* initnode(char* name, int id)    //create new node
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	if (ptr == NULL)
		return NULL;
	else
	{
		strcpy(ptr->name, name);
		ptr->id = id;
		ptr->next = NULL;
		return ptr;
	}

}

void printnode(struct node* ptr)
{
	printf("Name->%s\n", ptr->name);
	printf("ID->%d\n", ptr->id);

}
void printlist(struct node* ptr)
{
	while (ptr != NULL)
	{
		printnode(ptr);
		ptr = ptr->next;
	}


}

void addtoend(struct node*new_node) //add to the end of the list
{
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		end->next = new_node;
	}
	end = new_node;
}  
void addtohead(struct node* new_node)//add to the head of the list
{
	if (head == NULL) {
		end = new_node;
	}
	else {
		new_node->next = head;
	}
	head = new_node;
}

struct node* searchname(char* name)
{
	struct node* ptr = head;
	while (ptr != NULL && strcmp(name, ptr->name)) // if the are similar strcmp return 1
		ptr = ptr->next;
	return ptr;
}

void deletenode(struct node* ptr)
{
	struct node* prev, * temp;
	temp = ptr; //node to be deleted
	prev = head;
	if (temp == prev)  //if its the first node
	{
		head = temp->next;
		if (temp == end)  //if the list  consists only one node
			end = end->next;
		free(temp);
	}
	else
	{
		while (prev->next != temp)
			prev = prev->next;
		prev->next = temp->next;
		if (temp == end)  // if the node is the last node of the list
			end = prev;
		free(temp);

	}
}
	
void deletelist()
{
	struct node* temp;
	if (head == NULL)
		return;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}


void reverselist(struct node* ptr)
{
	struct Node* prev = NULL;
	struct Node* current = head;
	struct Node* next = NULL;
	while (current != NULL) {
		// Store next
		next=current->next;

		// Reverse current node's pointer
		current->next = prev;

		// Move pointers one position ahead.
		prev = current;
		current = next;
	}
	end = head;
	head = prev;
}

int main() {
	char name[NAME_LEN];
	int id, ch = 1;
	struct node* ptr;
	while (ch != 0)
	{
		printf("\n1:add a name\n");
		printf("\n2:delete a name\n");
		printf("\n3:list all names\n");
		printf("\n4:search for name\n");
		printf("\n5:reverse the list\n");
		printf("\n0:quit\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter a name:");
			scanf("%s", name);
			printf("Enter an ID:");
			scanf(% d, id);
			ptr = initnode(name, id);
			if (ptr = NULL) {
				printf("Allocation failed");
				deletelist();
			}
			else {
				addtoend(ptr);
			}
			break;
		case 2:
			if (head == NULL)
				printf("The list is empty!")
			else {
				printf("Enter an name");
				scanf("%s", name);
				ptr = searchname(name);
				if (ptr == NULL)
					printf("Name %s not found\n", name);
				else
					deletenode(ptr);
			}
			break;
		case 3:
			printlist(head);
			break;
		case 4:
			if (head == NULL)
				printf("The list is empty!")
			else {
				printf("Enter an name");
				scanf("%s", name);
				ptr = searchname(name);
				if (ptr == NULL)
					printf("Name %s not found\n", name);
				else
					printnode(ptr);
			}
			break;
		case 5:
			printf("Now the list look like :");
			printlist(head);
			reverselist(head);
			printf("The reversing list :");
			printlist(head);
			break;
		case 0:
			deletelist();
		return 0;
		}
	  
	}
	

}