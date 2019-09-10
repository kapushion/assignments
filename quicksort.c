/*
============================================================================
 Name        : quickSort.c
 Author      : utkarsh atre
 Version     : 3
 Copyright   : Your copyright notice
  Description : Hello World in C, ANSI-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

typedef struct Data
{
	long unsigned int mob;
	char name[25];
	float salary;
}Data;


void input(Data s[],int *f)
{
	if(*f<SIZE)
	{
		printf("Enter the mob:- ");
		scanf("%lu",&s[*f].mob);
		printf("Enter the name:- ");
		while(getchar()!='\n');
		gets(s[*f].name);
		printf("Enter the salary:- ");
		scanf("%f",&s[*f].salary);
		*f=*f+1;
	}
	else
	{
		printf("\nCannot add more records!\n");
	}
}

void disp(Data s[],int f)
{
	int i;
	if(f==0)
		printf("\nPlease enter valid data\n");
	else
	{
		printf("\n-------------------------------------------------------\n");
		printf("Sr.no\tMob.No.  Name\t  salary");
		printf("\n-------------------------------------------------------\n");
		for(i=0;i<f;i++)
			printf("%3d %7lu %10s %9.2f\n",i+1,s[i].mob,s[i].name,s[i].salary);
		printf("-------------------------------------------------------\n\n");
	}

void quickSort(Data s[],int l,int h)
{
	static int f;
	Data pivot,temp;
	int low=l+1,high=h;
	int i;
	pivot=s[l];

	while(low<=high)
	{
		while(strcmp(s[low].name,pivot.name)>0)
			low++;
		while(strcmp(s[high].name,pivot.name)<0)
			high--;

		if(low<high)
		{
			temp=s[low];
			s[low]=s[high];
			s[high]=temp;
			low++;
			high--;
		}
	}
	s[l]=s[high];
	s[high]=pivot;

	high--;
	f++;
	printf("Pass :- %d\n",f);
	for(i=0;i<f;i++)
	{
		printf("%s  ",s[i].name);
	}
	printf("\n");

	if(l<high)
		quickSort(s,l,high);

	if(low<h)
		quickSort(s,low,h);
}

int main(void)
{
	Data s[SIZE];
	int flag = 1;
	int ch,f=0,i;
	int rno;

	while(flag)
	{
		printf("**********menu**********");
		printf("\n1. Accept records");
		printf("\n2. Display records");
		printf("\n3. Sort records in descending order of names(quick with recursion)");
		printf("\n4. Exit");
		printf("\n\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				input(s,&f);
				break;
			case 2:
				disp(s,f);
				break;
			case 3:
				printf("\n-------------------------------------------------------");
				printf("\nQUICK SORT FOR DESCENDING ORDER OF NAMES\n\n");
				quickSort(s,0,f);
				disp(s,f);
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Error in choice, try again\n\n");
		}
	}
	return EXIT_SUCCESS;
}
