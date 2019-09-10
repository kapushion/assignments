/*
 ============================================================================
 Name        : sortingandsearching.c
 Author      : utkarsh atre
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
	char name[25];
	int rollno;
	float per;
	char class[10];
};
int main(void) {
	int f=1;
	int n;
	int nwrollno;
	printf("\nEnter the number of entries you want to enter: ");
	scanf("%d",&n);
	struct student data[n];
	while(f)
	{
		printf("\n*************MENU************\n");
		printf("1.input of the entries\n2.display\n3.ascending order\n4.descending order\n5.search by roll.no\n6.binary search with recursion\n7.exit ");
		printf("\nEnter you're choice: ");
		int ch;
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				input(data,n);
				break;
			case 2:
				display(data,n);
				break;
			case 3:
				ascending(data,n);
				display(data,n);
				break;//int p=sizeof str1[]/sizeof str[0];
			case 4:
				descending(data,n);
				display(data,n);
				break;
			case 5:
				binarysearch(data,n);
				break;
			case 6:
				printf("\nEnter the roll number you want to search: ");
				scanf("%d",&nwrollno);
				binarysearchwithr(data,0,n-1,nwrollno);
				break;
			case 7://int p=sizeof str1[]/sizeof str[0];
				f=0;
				break;
		}
	}

	return EXIT_SUCCESS;
}
void input(struct student data[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nstudent %d: ",(i+1));
		printf("\nNAME: ");
		scanf("%s",data[i].name);
		printf("ROLL NUMBER: ");
		scanf("%d",&data[i].rollno);
		printf("PERCENTAGE: ");
		scanf("%f",&data[i].per);
		printf("CLASS: ");
		scanf("%s",data[i].class);
	}
}
void display(struct student data[],int n)
{
	int i;
	printf(" Sr.no\troll no\t\tName\t\tclass\t\tpercentage");
	printf("\n----------------------------------------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("\n %d       %d\t\t%s\t\t  %s\t   %2f",(i+1),data[i].rollno,data[i].name,data[i].class,data[i].per);
	}
}
void ascending(struct student data[],int n)
{
	 int compare = 0;
	 int i,j,flag;
	 struct student temp;
	 for (j=1; j<n; j++)
	     {
		 	 flag=0;
	         for (i=0; i<n-j; i++)
	         {
	        	 compare++;
	             if (data[i].rollno > data[i+1].rollno)
	             {
	            	flag=1;
	            	temp = data[i+1];
	                data[i+1] = data[i];
	                data[i] = temp;
	             }
	             if(!flag)
	            	 break;
	         }
	     }
	 printf("\nThis operation is performed by bubble sort\n");
	 printf("\nComparisions:- %d\n",compare);
	 printf("\nPasses:- %d\n",(j+1));
	 if(flag == 0)
	 {
		 printf("\nBest case having the time complexity O(n)\n");
	 }
	 else
	 {
		 printf("\nWorst case having time complexity O(n^2)\n");
	 }
}
void descending(struct student data[],int n)
{
	struct student temp;
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min = i;

		for(j=i+1;j<n;j++)
		{
			if(strcmp(data[min].name, data[j].name) <0)
			{
				min = j;

				temp = data[i];
				data[i] = data[min];
				data[min] = temp;

			}
		}
	}
}
void binarysearch(struct student data[],int n)
{
	int l,mid,h;
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(data[j].rollno > data[j+1].rollno)
			{
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
		}
	}
	int nrollno,z=1;
	printf("\nEnter the roll number you want to search");
	scanf("%d",&nrollno);
	l=0;
	h = n-1;
	while(h>=l)
	{
		mid = (l+h)/2;
		if(data[mid].rollno == nrollno)
		{
			printf(" Sr.no\tname\t\troll number\tclass\tpercentage\n");
			printf("\n %d       %d\t\t%s\t\t     %s\t%2f",z,data[mid].rollno,data[mid].name,data[mid].class,data[mid].per);
			break;
		}
		else if(data[mid].rollno > nrollno)
		{
			l=0;
			h = mid-1;
		}
		else
		{
			l = mid+1;
			h = n-1;
		}
	}

}
void binarysearchwithr(struct student data[],int l,int h,int nwrollno)
{
	int mid,z=1;
	int i,j;
	struct student temp;

	for(i=0;i<h;i++)
		{
			for(j=0;j<h;j++)
			{
				if(data[j].rollno > data[j+1].rollno)
				{
					temp = data[j+1];
					data[j+1] = data[j];
					data[j] = temp;
				}
			}
		}
	if(h>=l)
	{
		mid = (l+(h-l))/2;
	}
	if(data[mid].rollno == nwrollno)
	{
		printf(" Sr.no\tname\t\troll number\tclass\tpercentage\n");
		printf("\n %d       %d\t\t%s\t\t     %s\t%2f",z,data[mid].rollno,data[mid].name,data[mid].class,data[mid].per);
	}
	else if(data[mid].rollno > nwrollno)
	{
		binarysearchwithr(data,l,mid-1,nwrollno);
	}
	else
	{
		binarysearchwithr(data,mid+1,h,nwrollno);
	}
}





