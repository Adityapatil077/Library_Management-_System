#include<stdio.h>
#include "StructBook.h"
void addBook(FILE *fptr){
		fptr=fopen("bookstore.txt","a");
		printf("\nEnter id : ");
	  	scanf("%d",&b.id);
		fflush(stdin);
		printf("\nEnter name of Book : ");
		gets(b.name);
		fflush(stdin);
		printf("\nEnter a author name : ");
		gets(b.author);
		fflush(stdin);
		printf("\nEnter a Price of Book : ");
		scanf("%d",&b.price);
		printf("\nQuantity of Books : ");
		scanf("%d",&b.Quantity);
		printf("\nEnter a Rack No : ");
		scanf("%d",&b.rack_no);
		fwrite(&b,sizeof(b),1,fptr);
		fclose(fptr);

	}