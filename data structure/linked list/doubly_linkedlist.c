#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
}
*first=NULL;

void create(int a[],int n)
{
	struct node *t,*last;
	first=(struct node *)malloc(sizeof(struct node));
	first->data=a[0];
	first->prev=first->next=NULL;
 	last=first;
 	
	for(int i=1;i<n;i++)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=a[i];
		t->next=last->next;
		t->prev=last;
		last->next=t;
		last=t;
	}
	
}

void insert(struct node *p,int index,int x)
{
	struct node *t;
	if(index<0)
	{
		return;
	}
	if(index==0)
	{
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->prev=NULL;
		t->next=first;
		first->prev=t;
		first=t;
	}
	else
	{
		for(int i=0;i<index-1;i++)
		{
			p=p->next;
		}
		t=(struct node *)malloc(sizeof(struct node));
		t->data=x;
		t->prev=p;
		t->next=p->next;
		if(p->next)
		{
			p->next->prev=t;
		}
		p->next=t;
	}
	
}

void display(struct node *p)
{
	while(p)
	{
		printf("%d ", p->data);
		p=p->next;
	}
	printf("\n");
}


int main() 
{
    int a[]={10,20,30,40,50};
    create(a,5);
    insert(first , 4, 5);
    display(first);
	
}
