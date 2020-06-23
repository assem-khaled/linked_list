#include"std_types.h"
#include<stdio.h>
#include<stdlib.h>
#include"macros.h"

typedef struct node_type node;
struct node_type{
	u32 value;
	node *next;
};

node *head = NULL ;
u8 no_nodes = 0 ;

 void create_node (void)
 {
	 u32 ip;
	 printf("\nPlease Enter Node Value: ");
	 scanf("%d",&ip);
					 
	 if(head==NULL)  //create Head ------we can use(no_nodes==0)but, if we deleted all nodes we will get error
	 {
		 printf("\ncreating head... \n");
		 
		 head = (node*) malloc(sizeof(node));
		 head->value = ip;
		 head->next = NULL; 
	 }
	 else 
	 {
		 node *last;
		 printf("\ncreating node... \n");
		 
		 last = head ;
		 while (last->next != NULL)
		 {
			 last = last -> next ;
		 }
		 last-> next = (node*) malloc(sizeof(node));
		 
		 (last->next) -> value= ip ;
		 (last->next) -> next =NULL;
		 
	 }
	  no_nodes++ ;
	  printf("Node Added Thank You \n\n\n");
 }
 
 void print_list (void)
 {
	 if (head != NULL) // we can use (no_nodes>0) but, if we deleted all nodes we will get error
	 {
	 u8 i=1 ;
	 node *pnt ;
	 pnt = head;
	 
	 printf("\n\n----------------------\n");
	 printf("Node no.%d = %d\n",i,(pnt -> value) );
	 
	 while (pnt->next != NULL)
		 {
			 i++;
			 pnt = pnt -> next ;
			 printf("Node no.%d = %d\n",i,(pnt -> value) );
		 }
		 
	printf("----------------------\n");
	 }
	 else
	 {
		 printf("\nList is empty \n\n");
	 }
 }
 
 void delete(void)
 {
	 u8 i , numb ;
	 node *after_del , *befor_del;
	 
	 if (head== NULL) //check if there is no nodes 
	 {
		 printf("\nList is empty\n");
		 return;
	 }
	 
	 printf("\nPlease enter node number: ");
	 scanf("%d",&numb);
	 
	 befor_del = head ;
	 
	 if (numb ==1)  //to delete the head
	 {
		 head = befor_del -> next;
		 free(befor_del);
		 printf("\nHead deleted\n");
		 return;
	 }
	 else if (numb ==0)
	 {
		 printf("\nwrong number\n");
		 return;
	 }
	  
	 for (i=1;befor_del!=NULL && i<(numb-1);i++)
	 {
		 befor_del = befor_del -> next ;
	 }
	 if(befor_del==NULL || befor_del->next ==NULL) //if numb exceded nodes number
	 {
		 printf ("\nNumber exceded the nodes\n");
		 return;
	 }

	 after_del  = befor_del -> next-> next ;
	 free(befor_del->next);
	 befor_del-> next = after_del;
	 
	 printf("\nNode deleted\n");
	 
 }
 
 void ins_node(void)
 {
	 u32 input=1;
	 u8 i,numb;
	 node *new , *befor_new ;
	 
	 if (head== NULL) //check if there is no nodes 
	 {
		 printf("\nList is empty\n");
		 return;
	 }
	 
	 printf("\nPlease Enter Node number: ");
	 scanf("%d",&numb);
     
     if (numb ==0)
	 {
		 printf("\nwrong number\n");
		 return;
	 }
	 
	 printf("\nPlease Enter Node Value: ");
	 scanf("%d",&input);
	 
	 if (numb ==1)  //to insert the head
	 {	
		new = (node*) malloc(sizeof(node));
		new -> value = input ;
		new -> next = head;
		head = new ;

		 printf("\nHead inserted\n");
		 return;
	 }
   
	 
	 new = (node*) malloc(sizeof(node));
	 befor_new = head ;
	 
	 for (i=1;befor_new!=NULL && i<(numb-1);i++)
	 {
		 befor_new= befor_new -> next;
	 }
	 if(befor_new==NULL || befor_new->next==NULL)
	 {
		 printf ("\nNumber exceded the nodes\n");
		 return;
	 }
	 
	 new -> next =befor_new -> next ;
	 befor_new -> next = new ;
	 new -> value = input ;
	 
	 printf("\nNode inserted\n");
	 
 }
 


int main ()
{
	
	u32 input;
	u32 newValue;
	u8  ExitFlag = 0;

	
	while (ExitFlag == 0)
	{
		printf("\nTo add node enter 0\n");
		printf("To print the linked list enter 1\n");
		printf("To delete node enter 2\n");
		printf("To insert node enter 3\n");
		printf("To exit press 4\n");
		printf("Your Choice: ");
		scanf("%d",&input);
		
		switch (input)
		{
			case 0 : create_node(); break;
			case 1 : print_list(); break;
 			case 2 : delete(); break;
			case 3 : ins_node(); break;
			case 4 : printf("\nThank You\nGood Bye"); ExitFlag = 1; break;
			default: printf("\nInvalid Choice please try again\n"); break;
		}
	}
	
}
