/*
 ============================================================================
 Name        : file1.c
 Author      : utkarsh atre
 Version     : 1
 Copyright   : Your copyright notice
 Description : Hello World in C, ANSI-style
 ============================================================================
 */
//command line argument!!!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if(argc<3)
		printf("Incorrect No. of arguments entered\n");
	else
	{
		if(	!(strcmp(argv[1], "type")) && argc == 3)
		{
			FILE *fp;
			char c;
			fp=fopen(argv[2], "r");
			if(fp == NULL)
				printf("File does not exist!\n");
			else
			{
				printf("\n\nContents of file are : \n\n");
				while(!feof(fp)){
					c = getc(fp);
					if(c!=-1)
						printf("%c", c);
				}
				printf("\n\n");
			}
			fclose(fp);
		}
		else if(!(strcmp(argv[1], "copy")) && argc == 4)
		{
			FILE *src,*tar;
			src=fopen(argv[2], "r");
			tar=fopen(argv[3], "w");
			if(src == NULL)
				printf("File does not exist!\n");
			else
			{
				char c=getc(src);
				while(!feof(src)){
					putc(c, tar);
					c=getc(src);
				}
				printf("File copied successfully to %s!\n", argv[3]);
			}
			fclose(src);
			fclose(tar);
		}
		else
			printf("Incorrect arguments entered!\n");
	}
	return 0;
}
