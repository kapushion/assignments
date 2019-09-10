/*
 ============================================================================
 Name        : sparse.c
 Author      : utkarsh atre
 Version     : 2
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct sparse
{
	int row;
	int col;
	int value;
}sparse;

int main(void) {
	sparse s[25];
	int mat[10][10];
	int n,m;
	int f=1;
	int ch;
	while(f)
	{
		printf("\n**********SPARSE MATRIX OPERATIONS***********\n");
		printf("1.accept matrix and conversion into sparse matrix\n2. Addition of sparse matrix\n3.Simple transpose\n4.Fast transpose\n5.exit");
		printf("\nEnter you're choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\nEnter the row size of the matrix: ");
			scanf("%d",&n);
			printf("\nEnter the column size of the matrix: ");
			scanf("%d",&m);
			input(mat,n,m);
			conversion(mat,s,n,m);
			break;
		case 2:
			break;
		case 3:
			f=0;
			break;


		}

	}
	return EXIT_SUCCESS;
}
void input(int mat[][10],int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}
void conversion(int mat[][10] ,sparse s[],int n,int m)
{
	int i,j,count = 0,k = 0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat[i][j]!=0)
			{
				count++;
			}
		}
	}
	s[0].row = n;
	s[0].col = m;
	s[0].value = count;
	printf("\nROW\tCOLUMN\tVALUE\n");
	printf("\n%d\t  %d\t  %d",n,m,count);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat[i][j]!=0)
			{
				s[0].row = i;
				s[1].col = j;
				s[2].value = mat[i][j];
				printf("\n%d\t  %d\t  %d",s[0].row,s[1].col,s[2].value);
			}
		}
	}
}
