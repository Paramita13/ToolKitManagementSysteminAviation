#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* Basic node structure. */
struct node
{
    int data;
    struct node *next;
};

struct node *head,*newnode,*temp;


int G_counter=0;


/*******   Function declarations */

void create(int);
void deleteKey(int);
void display();
void search(int);
void sort();
void count();
void savef();
void openf();


void main()
{
    int n, key, choice,loop_var=1;
    clrscr();
    while(loop_var == 1)
    {
	printf("\n|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|");
	printf("\n|			Toolkit management system in aviation                 |");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("!				1. Enter tool                                 !\n");
	printf("!				2. Delete any tool                            !\n");
	printf("!				3. Display tool details                       !\n");
	printf("!				4. Search any tool                            !\n");
	printf("!				5. Display file contents                      !\n");
	printf("!				0. Exit                                       !\n");
	printf("!-----------------------------------------------------------------------------!\n");
	printf("Enter your choice : ");

	scanf("%d", &choice);

	switch(choice)
	{
	    case 1:
		printf("Enter number of toolkits to register:  ");
		scanf("%d", &n);
		create(n);
		printf("Updating database...\n");
		sort();
		printf("Database Updated\n");
		break;

	    case 2:
		printf("Enter toolkit ID number to delete from list: ");
		scanf("%d", &key);
		deleteKey(key);
		break;

	    case 3:
		display();
		break;

	    case 4:
		printf("Enter toolkit number to check availability: ");
		scanf("%d",&key);
		search(key);
		break;
		
	    case 5:
		openf();
		break;

	    case 0:
		loop_var=0;
		break;

	    default:
		savef();
		printf("Error! Invalid choice.\n");
		break;
	}

	       printf("\n\n");
    }
	count();
	savef();
	printf("\nEnter any character to exit");
	scanf("%d",&key);
	getch();
}

//to enter data of tools

void create(int n)
{
while(n!=0)
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("\nEnter data:");
scanf("%d",&newnode->data);
newnode->next=NULL;

if(head==NULL)
{
head=newnode;
newnode->next=head;
}
else
{
temp=head;
while(temp->next != head)
{
temp=temp->next;
}

temp->next=newnode;
newnode->next=head;
}
n=n-1;
printf("\nentered\n");
}
}



//Deletion of tool details

void deleteKey(int key)
{
    int i, count;
    struct node *prev, *cur;

    if (head == NULL)
    {
	printf("Toolkit list is empty.\n");
	return;
    }

    count = 0;
    cur   = head;
    prev  = cur;

    while (prev->next != head)
    {
	prev = prev->next;
	count++;
    }

    i = 0;
    while (i <= count)
    {
	if (cur->data == key)
	{
	    if (cur->next != cur)
		prev->next = cur->next;
	    else
		prev->next = NULL;

	    if (cur == head)
		head = prev->next;

	    // Delete current node
	    free(cur);

	    if (prev != NULL)
		cur = prev->next;
	    else
		cur = NULL;
	}
	else
	{
	    prev = cur;
	    cur  = cur->next;
	}
		i++;
    }
}


//Display tool details

void display()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
	printf("Tool list is empty.\n");
	return;
    }

    current = head;
    printf("DATA IN THE TOOLKIT LIST:\n");

    do {
	printf("Tool %d = %d\n", n, current->data);

	current = current->next;
	n++;
    }while(current != head);
}


//To search any tool from the list

void search(int key)
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
	printf("Toolkit list is empty...\n");
	return;
    }

    current = head;

    do {
	if(current->data==key)
	{
		printf("Toolkit %d present at position %d of the database\n", current->data, n);
		return;
	}
	current = current->next;
	n++;
    }while(current != head);

    printf("Tool data not found...");
}


// To sort the tool details in the list

void sort()
{
    struct node *current, *nxt;
    int temp;
    current = head;
    while (current->next != head)
	{
	    nxt = current->next;
	    while (nxt !=  head)
	    {
		if (nxt !=  head)
		{
		    if (current->data > nxt->data)
		    {
			temp = current->data;
			current->data = nxt->data;
			nxt->data = temp;
		    }
		}
		else
		{
		    break;
		}
		nxt = nxt->next;
	    }
	    current = current->next;
	}

}


//To count no. of tools in the list

void count()
{
     struct node *current = head;

     if(head != NULL)
	{
	     do
	     {
		current = current -> next;
		G_counter++;
	     }
	     while(current != head);
	}
}

/******** Function for file operations    *******/

//To write into a file

void savef()
{
int i;
FILE *fp;
fp=fopen("toolkit.txt","a");
if(fp==NULL)
{
	printf("\nFile cannot be opened");
}
else
{
	printf("\nFile opened for writing operations");
}

fprintf(fp,"\nToolkit data saved\n");
temp=head;

for(i=0;i<G_counter;i++)
{
	fprintf(fp,"%d\t",temp->data);
	fprintf(fp,"\n");
	temp=temp->next;
}

fclose(fp);
}


//To read from a file

void openf()
{
char ch;
FILE *fp;
fp=fopen("toolkit.txt","r");
while((ch=fgetc(fp))!=EOF) 
    {
      printf("%c",ch);
    }
    fclose(fp);
    getch();
}    
	

