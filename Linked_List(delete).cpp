#include<stdio.h>
#include<malloc.h>

struct Node
{
	int data;
	struct Node* add;
};

void insertatStart(int data, struct Node** head)    //INSERTION AT START
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->add=*head;
	*head=node;
	return;
}

 void insertatend(int data, struct Node** head)    //INSERTION AT END
 { 
    struct Node* s;
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
 	node->data=data;
 	node->add=NULL;
 	if(head==NULL)
 	{
 		*head=node;
	}
	s=*head;
	while(s->add!=NULL)
	{
	 	s=s->add;
	}
	s->add=node;
	return;
 }
 
 void insertatSpecific(int data ,struct Node** head ,int data_after)  //INSERTION AT SPECIFIC POSITION 
 {
 	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
 	node->data=data;
 	node->add=NULL;
 	struct Node* s=*head;
 	while(s->data!=data_after)
 	{
 		s=s->add;
	}
	node->add=s->add;
	s->add=node;
	return;
}
 
 void displayLL(struct Node* head)      //DISPLAY LINKED LIST
 {
 	struct Node* p=head;
 	while(p!=NULL)
 	{
 		printf("%d->",p->data);
 		p=p->add;
	 }
	 return;
 }

void deleteatend(struct Node* head)   //Deletion at End
{
	struct Node* s=head;
	while(s->add->add!=NULL)
	{
		s=s->add;
	}
	free(s->add);
	s->add=NULL;
	return;
}

void deleteatstart(struct Node* head)   //Deletion at Start
{
	struct Node* s=head;
	head=head->add;
	
	return;
}

void deleteatspecific(struct Node* head, int pos)   //Deletion at Specific
{ 
    pos--;
    struct Node* s=head;
    while(pos>1)
    {
    	s=s->add;
    	pos--;
	}
	struct Node* temp=s->add;
	s->add=s->add->add;
	free(temp);
	return;
	
}

 int main()
 {int pos;
 	struct Node* head=NULL;
	int data, choice,data_after;
	while(1)
	{
		int data;
 	    printf("linked list menu\n");
 	    printf("1. Insert at Start\n");
 	    printf("2. Insert at End\n");
 	    printf("3. Insert at Specific Position\n");
 	    printf("4. Display Linked List\n");
 	    printf("5. Delete at Start\n");
 	    printf("6. Delete at End\n");
 	    printf("7. Delete at Specific\n");
 	    printf("Enter your choice \n");
 	    scanf("%d",&choice);
 	    switch(choice)
 	{
 	   case 1:  printf("enter data");
 	            scanf("%d",&data);
		     	insertatStart(data,&head);
 	            break;
 	            
 	   case 2:printf("enter data");
 	          scanf("%d",&data); 
		      insertatend(data,&head);
			  break;
	   case 3:printf("enter data");
              scanf("%d",&data);
			  printf("enter the after data");
			  scanf("%d",&data_after);
			  insertatSpecific(data,&head,data_after);
			  break;
        case 4: displayLL(head);
               break;
        case 5:deleteatend(head);
 	    	      break;
 	    case 6:deleteatstart(head);
			      break; 
		case 7:printf("Enter the deleting position");
		        scanf("%d",&pos);
	        	deleteatspecific(head,pos);	      
	    default: printf("invalid case");
		       
 	             
	}
 }

}
