/*
 ============================================================================
 Name        : linkedList.c
 Author      : Akshad Agrawal
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

  typedef struct node{
	int data;
	struct node *next;
	struct node *prev;

}node;


  node * create( node *start){
	 int n; node* temp;
	 int x,i;
	 temp=NULL;start=NULL;
	 printf("\nENTER NUMBER OF NODE:- ");
	 scanf("%d",&n);

	 for(i=0 ; i<n ; i++){

		 node *ll = (node*)malloc(1*sizeof(node));

		 if(start==NULL) {
			 start=ll;
			 temp=ll;
			 temp->next=NULL;
			 temp->prev=NULL;
		 }
		 else {
			 temp->next=ll;
			 ll->prev=temp;
			 temp=ll;
			 temp->next=NULL;
		 }
		 printf("\nENTER ELEMENT:- ");

		 scanf("%d",&x);

		 (ll->data)=x;
	 }

	 printf("\n\n\t--------LINKED LIST CREATED !! --------\n");
	 return start;
 }

  node * insert(node * start){

	  int e=0,pos=0;
	  int ch;
	  node *temp1 , *temp2;
	  temp1=start;
	  temp2=start;
	  node *ll = (node*)malloc(1*sizeof(node));


	  printf("\n\t----SUB MENU----"
			  "\n\t 1.Insert by Position"
			  "\n\t 2.Insert by Element"
			  "\n\t 3.Exit\n\tEnter Choice:- ");
	  scanf("%d",&ch);

	  switch(ch){

	  case 1 :


	  	  	  printf("\nENTER ELEMENT TO INSERT:- ");
	  	  	  scanf("%d",&(ll->data));

	  	  	  printf("ENTER POSTION OF NODE:- ");
	  	  	  scanf("%d",&pos);

	  	  	  if(pos==1){
	  	  		  start=ll;
	  	  		  ll->next=temp1;
	  	  		  temp1->prev=ll;
	  	  		  ll->prev=NULL;
	  	  		  return start;
	  	  	  }

	  	  	  else{
	  	  	  	int i;
	  	  		  for(i=1 ; i<pos-1 ; i++){

	  	  		  	  if(temp1->next!=NULL)
	  	  			  	  temp1=temp1->next;

	  	  	  	  }

	  	  		  temp2=temp1->next;

	  	  		  temp1->next=ll;
	  	  		  ll->next=temp2;
	  	  		  ll->prev=temp1;
	  	  		  temp2->prev=ll;

	  	  	  }
	  	  	  break;

	  case 2 :


	 	  	  printf("\nENTER ELEMENT TO INSERT:- ");
	 	  	  scanf("%d",&(ll->data));

	 	  	  printf("ENTER ELEMENT OF NODE TO SEARCH:- ");
	 	  	  scanf("%d",&e);

	 	  	  do {

	 	  		  if(temp1->data==e){

	 	  			temp2=temp1->next;
	 	  			temp1->next=ll;
	 	  		 	ll->next=temp2;
	 	  		 	ll->prev=temp1;
	 	  		 	temp2->prev=ll;
	 	  		 	break;
	 	  		  }
	 	  		  temp1=temp1->next;

	 	  	  	  }while(temp1!=NULL);
	 	  	  if(temp1==NULL){
	 	  		  printf("\n\t----ELEMENT NOT FOUND !! ----");
	 	  	  }
	  }
	  return start;

  }

  void display (node * start){

	  node *temp = start;
	  printf("\nLinked List :: ");
	  while(temp!=NULL){

		  printf("%d -> ", (temp->data));
		  temp=temp->next;

	  }

	  printf("NULL");

  }

  void rdisplay(node * t){
	  if(t!=NULL){
		  rdisplay(t->next);
		  printf(" -> %d", (t->data));
	  }
  }

  node * delete(node * start){

	  int e=0,pos=0;
	 	  int ch;
	 	  node *temp1 , *temp2;
	 	  temp1=start;
	 	  temp2=start;


	 	  printf("\n\t----SUB MENU----"
	 			  "\n\t 1.Delete by Position"
	 			  "\n\t 2.Delete by Element"
	 			  "\n\t 3.Exit\n\tEnter Choice:- ");
	 	  scanf("%d",&ch);

	 	  switch(ch){

	 	  case 1 :


	 	  	  	  printf("ENTER POSTION OF NODE:- ");
	 	  	  	  scanf("%d",&pos);

	 	  	  	  if(pos==1){

	 	  	  		  start=temp1->next;
	 	  	  		  temp1->next=NULL;
	 	  	  		  start->prev=NULL;
	 	  	  		  free(temp1);
	 	  	  		  return start;
	 	  	  	  }

	 	  	  	  else{
	 	  	  	  		int i;
	 	  	  		  for( i=1 ; i<pos-1 ; i++){

	 	  	  		  	  if(temp1!=NULL)
	 	  	  			  	  temp1=temp1->next;
	 	  	  	  	  }
	 	  	  		  if(temp1==NULL){
	 	  	  		  printf("\n\t----POSITION NOT FOUND !! ----");
	 	  	  		  }
	 	  	  		  else{
	 	  	  			  temp2=temp1->next;
	 	  	  			  temp1->next=temp2->next;
	 	  	  			  temp2->next->prev=temp1;
	 	  	  			  temp2->prev=NULL;
	 	  	  			  temp2->next=NULL;
	 	  	  			printf("\n\t----ELEMENT DELETED !! ----\n");
	 	  	  			  free(temp2);
	 	  	  		  }
	 	  	  	  }
	 	  	  	  break;

	 	  case 2 :


	 	 	  	  printf("ENTER ELEMENT OF NODE TO SEARCH:- ");
	 	 	  	  scanf("%d",&e);

	 	 	  	  if(temp1->data==e){
	 	 	  		temp2=temp1->next;
	 	   			start=temp2;
	 	 	  		temp1->next=NULL;
	 	 	  		start->prev=NULL;
	 	  		 	free(temp1);
	 	  		 	return start;
	 	 	  		break;
	 	 	  	  }

	 	 	  	  else{
	 	 	  	  do {

	 	 	  		  if(temp1->next->data==e){

	 	 	  			temp2=temp1->next;
	 	 	  			temp1->next=temp2->next;
	 	 	  			temp2->next->prev=temp1;
	 	 	  			temp2->prev=NULL;
	 	 	  			temp2->next=NULL;

	 	 	  		 	free(temp2);
	 	 	  		printf("\n\t----ELEMENT DELETED !! ----");
	 	 	  		 	break;
	 	 	  		  }
	 	 	  		  temp1=temp1->next;

	 	 	  	  	  }while(temp1!=NULL);
	 	 	  	  if(temp1==NULL){
	 	 	  		  printf("\n\t----ELEMENT NOT FOUND !! ----");
	 	 	  	  }
	 	  }

	 }
	 	  return start;


  }

  int main(void) {



		int lp=1;
		node *start=NULL,*t;

		while(lp){

			int ch=0;
					printf("\n\n--------MENU--------");
					printf("\n 1.CREATE\n "
							"2.INSERT\n 3.DISPLAY"
							"\n 4.REVERSE DISPLAY\n 5.DELETE A NODE\n 6.EXIT\nENTER YOUR CHOICE :- ");
					scanf("%d",&ch);


					switch(ch){

					case 1 : start=create(start);
							 display(start);
							 break;

					case 2 :start=insert(start);
							display(start);
							break;


					case 3 :display(start);
							break;


					case 4 :t=start;
							printf("\nLinked List :: NULL");
							rdisplay(t);
							break;

					case 5 :start=delete(start);
							display(start);
							break;

					case 6 : lp=0;


					}

		}

}






