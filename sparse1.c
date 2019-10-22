/*
 ============================================================================
 Name        : sparse1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct matrix
{
	int row,col,val;
};
void input(int mat[50][50],int *m,int *n)
{
	int i,j;
	printf("Enter the num of rows and column :\n");
	scanf("%d%d",m,n);
	printf("Enter the matrix: \n");
	for(i=0;i<*m;i++)
	{
		for(j=0;j<*n;j++)
			scanf("%d",&mat[i][j]);
	}
}
void convert(int mat[50][50],struct matrix s[],int m,int n)
{
	int i,j,k=1,count=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(mat[i][j]!=0)
				{
					s[k].row=i;
					s[k].col=j;
					s[k].val=mat[i][j];
					count++;
					k++;
				}
		}
	}
	s[0].row=m;
	s[0].col=n;
	s[0].val=count;
}
void displaysparse(struct matrix s[])
{
	int k;
	printf("Row Col Val\n\n");
	for( k=0;k<=s[0].val;k++)
		printf("%d   %d   %d\n",s[k].row,s[k].col,s[k].val);
}
void convert2(int mat[50][50],struct matrix s[])
{
	int i,j,k=1;
	for(i=0;i<s[0].row;i++)
	{
		for(j=0;j<s[0].col;j++)
		{

			{
				if(i==s[k].row &&j==s[k].col)
					{mat[i][j]=s[k].val;k++;}
				else { mat[i][j]=0;}
			}

		}
	}

}
void displaynormal(struct matrix s[50],int mat[50][50])
{
	int i,j;
	for( i=0;i<s[0].row;i++)
	{
		for( j=0;j<s[0].col;j++)
		{
			printf("%d ",mat[i][j]);
		}
		printf("\n");
	}
}

void trans(struct matrix s[50],struct matrix s1[50])
{
	int n,i,j,current;
	n=s[0].val;
	s1[0].row=s[0].col;
	s1[0].col=s[0].row;
	s1[0].val=n;
	if(n>0)
	{
		current=1;
		for(i=0;i<s[0].col;i++)
		{
			for(j=1;j<=n;j++)
				if(s[j].col==i)
				{
					s1[current].row=s[j].col;
					s1[current].col=s[j].row;
					s1[current].val=s[j].val;
					current++;
				}
		}
	}
}
void add(struct matrix a[50],struct matrix b[50],struct matrix c[50])
{
		int i=1,j=1,k=1;
		while(i<=a[0].val&&j<=b[0].val)
		{
			if(a[i].row==b[i].row&&a[i].col==b[j].col)
			{
				c[k].val=a[i].val+b[j].val;
				c[k].row=a[i].row;
				c[k].col=a[i].col;
				i++;j++;k++;
			}
			if(a[i].row==b[j].row&&a[i].col<b[j].col)
			{
				c[k].row=a[i].row;
				c[k].col=a[i].col;
				c[k].val=a[i].val;
				i++;k++;
			}
			if(a[i].row==b[j].row&&a[i].col>b[j].col)
			{
				c[k].row=b[j].row;
				c[k].col=b[j].col;
				c[k].val=b[j].val;
				j++;k++;
			}
			if(a[i].row<b[j].row)
			{
				c[k].row=a[i].row;
				c[k].col=a[i].col;
				c[k].val=a[i].val;
				i++;k++;
			}
			if(a[i].row>b[j].row)
			{
				c[k].row=b[j].row;
				c[k].col=b[j].col;
				c[k].val=b[j].val;
				j++;k++;
			}
		}
		while(i<=a[0].val)
		{
			c[k].row=a[i].row;
			c[k].col=a[i].col;
			c[k].val=a[i].val;
			i++;k++;
		}
		while(j<b[0].val)
		{
			c[k].row=b[j].row;
			c[k].col=b[j].col;
			c[k].val=b[j].val;
			j++;k++;
		}
		c[0].row=a[0].row;
		c[0].col=a[0].col;
		c[0].val=k;
}
void fast(struct matrix s[50],struct matrix s1[50])
{
           int row_terms[100],  start_pos[100];
           int i,  j,  p;

           int numTerms = s[0].val;
           int numCols = s[0].col;

           s1[0].row = numCols;
           s1[0].col = s[0].row;
           s1[0].val = numTerms;
           if(numTerms>0)
           {
                       for(i =0; i<numCols;  i++)
                                               row_terms[i] = 0;

                       for(i=1; i<=numTerms; i++)
                                               row_terms[s[i].col]++;

                       start_pos[0]=1;

                       for(i=1; i<numCols; i++)
                                               start_pos[i] = start_pos[i-1] + row_terms[i-1];

                       for(i=1; i<=numTerms; i++)
                       {
                                               j = start_pos[s[i].col]++;
                                   s1[j].row = s[i].col;
                                               s1[j].col = s[i].row;
                                               s1[j].val = s[i].val;
                       }
            }
           printf("\nThe Fast Transpose sparse matrix is:\n");
           printf("\nRow\tColumn\tValue\n");
           for(p=0; p<=s[0].val; p++)
           {
                       printf("%d\t", s1[p].row);
                       printf("%d\t", s1[p].col);
                       printf("%d\n", s1[p].val);
           }
}
int main(void)
{
	int m,n,mat[50][50],mat1[50][50],ch,r1,r2,c1,c2;
	struct matrix s[50];
	struct matrix s1[50];
	int a[50][50],b[50][50],c[50][50];
	struct matrix a1[50],b1[50],sum[50];
	while(1)
	{
		printf("\n---SPARSE MATRIX OPERAIONS---\n\n");
		printf("1.INPUT MATRIX\n2.DISPLAY SPARSE MATRIX\n3.SIMPLE TRANSPOSE\n4.FAST TRANSPOSE\n5.ADDITION\n6.EXIT\n\n");
		printf("ENTER CHOICE :");
		scanf("%d",&ch);
		switch(ch)
		{
		 case 1:input(mat,&m,&n);
		 	 	break;
		 case 2:convert(mat,s,m,n);
			    printf("\nThe sparse matrix is: \n");
		 	    displaysparse(s);
		 	    break;
		 case 3:convert(mat,s,m,n);
			    trans(s,s1);
		 	 	convert2(mat1,s1);
		 	 	printf("\nThe  Transpose matrix is: \n");
		 	 	displaysparse(s1);
		 	 	displaynormal(s1,mat1);
		 	 	break;
		 case 4:convert(mat,s,m,n);
		 	    fast(s,s1);
		 	 	convert2(mat1,s1);
		 	 	printf("\nThe Fast Transpose matrix is: \n");
		 	 	displaynormal(s1,mat1);
		 	 	break;
		 case 5:printf("FOR MATRIX A: \n");
		 	    input(a,&r1,&c1);
		 	    printf("FOR MATRIX B: \n");
		 	    input(b,&r2,&c2);
		 	    if((r1!=r2)||(c1!=c2))
		 	    	printf("\nPLEASE ENTER SAME ORDER\n");
		 	    else
		 	    {
					convert(a,a1,r1,c1);
					convert(b,b1,r2,c2);
					add(a1,b1,sum);
					convert2(a,a1);
					convert2(b,b1);
					convert2(c,sum);
					printf("MATRIX A: \n");
					displaynormal(a1,a);
					printf("\nMATRIX B: \n");
					displaynormal(b1,a);
					printf("ADDITION MATRIX: \n");
					displaynormal(sum,c);
					displaysparse(sum);
		 	    }
		 	    break;

		}
	}

}
