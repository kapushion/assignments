/*
 ============================================================================
 Name        :  fileb.c
 Author      : AkshadA
 Version     :
 Copyright   : Your copyright notice
 Description : Database, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>



struct student
{
	int roll;
	char name[25];
	int class;
	float marks;

};

void getInput(struct student s[],int n)
{
	FILE *fp;
	fp=fopen("abc","a");


		printf("Enter roll no: ");
		scanf("%d",&s[n].roll);
		printf("Enter name: ");
		scanf("%s",&s[n].name);
		printf("Enter class: ");
		scanf("%d",&s[n].class);
		printf("Enter marks: ");
		scanf("%f",&s[n].marks);
		printf("\n");

		fprintf(fp,"%1d\t    %10s\t\t%2d\t\t%.2f\n",s[n].roll,s[n].name,s[n].class,s[n].marks);

		fclose(fp);

}

void display()
{

	FILE *fp;
	fp=fopen("abc","r");

	char ch;
	printf("Database is:\n ");
	ch=getc(fp);
	while(!feof(fp))
	{
		printf("%c",ch);
		ch=getc(fp);
	}
	fclose(fp);
}

int search(struct student s[],int m)
{
	int i;
	int count=0;
	FILE *fp;
	fp=fopen("abc","r");
	for( i=0;i<5;i++)
	{
		fscanf(fp,"%d",&s[i].roll);
		if(s[i].roll==m){
		count++;
		printf("%1d\t    %10s\t\t%2d\t\t%.2f\n\n",s[i].roll,s[i].name,s[i].class,s[i].marks);}
	}
	return count;
	fclose(fp);
}

void modify(struct student s[],int m,int record)
{
	int i;
	FILE *fp;

	fp=fopen("abc","w");
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%d",&s[i].roll);
		if(s[i].roll==m)
			break;
	}

	printf("Enter name: ");
	scanf("%s",&s[i].name);
	printf("Enter class: ");
	scanf("%d",&s[i].class);
	printf("Enter marks: ");
	scanf("%f",&s[i].marks);
	printf("Record Modified Successfully!!");
	int j;
	fprintf(fp,"Roll no\t Name\t\tClass\t\tPercentage\n\n");
	for(j=0;j<record;j++)
	{
		fprintf(fp,"%1d\t    %10s\t\t%2d\t\t%.2f\n",s[j].roll,s[j].name,s[j].class,s[j].marks);
	}
	fclose(fp);
}

void delete(struct student s[],int m,int record)
{
	int j;
	FILE *fp;
	fp=fopen("abc","w");

	for( j=0;j<(record+1);j++)
		{
			if(s[j].roll==m)
			{
			s[j].roll = s[j+1].roll;
			strcpy(s[j].name,s[j+1].name);
			s[j].class = s[j+1].class;
			s[j].marks = s[j+1].marks;
			}
		}


	fprintf(fp,"Roll no\t Name\t\tClass\t\tPercentage\n\n");
	for(j=0;j<record;j++)
	{
		fprintf(fp,"%1d\t    %10s\t\t%2d\t\t%.2f\n",s[j].roll,s[j].name,s[j].class,s[j].marks);
	}

	printf("Record Deleted Successfully!!");
	fclose(fp);



}

int main(void)
{
	struct student s[5];
	int n=0;
	int x;
	int m,l;
	int record=0;
	FILE *fp;
	fp=fopen("abc","w");
	fprintf(fp,"Roll no\t Name\t\tClass\t\tPercentage\n\n");
	fclose(fp);
	while(1)
	{
		printf("\n*******MENU*****\n");
		printf("1.Display\n2.Add Record\n3.Search\n4.Modify\n5.Delete\n\nEnter your choice: ");
		scanf("%d",&x);

		switch(x)
		{
		case 1: display();
			    break;

		case 2: printf("Enter details\n\n");
				getInput(s,n);
				n++;
				record++;
				break;

		case 3: printf("Enter roll no to be searched: ");
				scanf("%d",&m);
				l=search(s,m);
				if(l==0)
					printf("Record not found!!");
				else
					printf("Record Found!!\n");

				break;

		case 4: printf("Enter roll no to be modified: ");
				scanf("%d",&m);
				modify(s,m,record);
				break;

		case 5: printf("Enter roll no to be deleted: ");
				scanf("%d",&m);
				record--;
				delete(s,m,record);


		}

	}

	return EXIT_SUCCESS;
}
