/*
 ============================================================================
 Name        : string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int length(char str[100]){
	int i=0;
	while(str[i]!='\0'){
		i++;
	}
	return i;
}



void copy(char str[100]){
	int k,i;
	char tar[100];
	printf("\nEnter the string to be copied: ");
	scanf("%s",tar);
	k=length(tar);
	for(i=0;i<k;i++)
		str[i]=tar[i];
		printf("%s",str);
}



void compare(char str[100]){
	int l=length(str);
	int i=0;
	char tar[100];
	printf("Enter the string to be compared: ");
	scanf("%s",tar);
	int k=length(tar);
	if(l==k){
		for(i=0;i<l;i++){
			if(str[i]!=tar[i])
				printf("Two strings are not equal!!\n");
		}
	if(i==l)
	printf("Two strings are equal\n");
	}
	else
		printf("Two strings are not equal!!\n");
}



void reverse(char str[100]){
	int l=length(str);
	int k=l,i;
	char tar[100];
	for(i=0;i<l;i++)
		tar[k-i-1]=str[i];
	tar[l]='\0';
	printf("%s",tar);
}


void palindrome(char str[100]){
	int l=length(str);
	int k=l,i;
	char tar[100];
	for(i=0;i<l;i++)
		tar[k-i-1]=str[i];
	tar[l]='\0';
	for(i=0;i<l;i++){
		if(str[i]!=tar[i])
			break;
	}
	if(i==l)
		printf("The given string is Palindrome\n");
	else
		printf("The given string is not Palindrome\n");
}


void substring(char str[100]){
	int l=length(str);
	int i,j;
	char sub[100];
	printf("Enter the Substring: ");
	scanf("%s",sub);
	int k=length(sub);
	for(i=0;i<l;i++){
		if(sub[0]==str[i])
			break;
	}
	for(j=0;j<k;j++){
		if(sub[j]!=str[j+i])
			break;
	}
	if(j==k)
		printf("The given string is substring. \n");
	else
		printf("The given string not is substring. \n");
}


int main() {
	char str[100];
	int f=1,t;
	printf("Enter the String :");
	scanf("%s",str);
	while(f){
			printf("\n\n 1.String Length \n 2.Palindrome \n 3.String Comparison \n 4.Copy \n 5. Reverse \n 6.Substring \n 7. Exit");
			printf("\n Enter the choice: ");
			scanf("%d",&t);
			switch(t)
			{
				case 1: printf("\n  String Length is :");
				int k=length(str);
				printf("%d\n",k);
				break;

				case 2: palindrome(str);
				break;

				case 3: compare(str);
				break;

				case 4: copy(str);
				break;

				case 5: reverse(str);
				break;

				case 6: substring(str);
				break;

				case 7: f=0;
				break;
			}
	}





	return 0;
}
