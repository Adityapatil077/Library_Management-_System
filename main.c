#include <stdio.h>
#include<string.h>
#include<conio.h>
#include "pass.h"
#include "addBook.h"
int g=1;


struct Student{
	int id;
	char s_name[40];
	char class[50];
	int roll_no;
	char b_name[50];
	char date[12];
	
}s;





void getBooks(FILE *fptr){
	system("cls");
	printf("<===== Available Books ====>\n\n");
	printf("%-10s%-10s%-14s%-13s%-14s%-14s\n","Id","B_Name","B_Author","Price","Quantity","Rack No");
	fptr=fopen("bookstore.txt","r");
	while(fscanf(fptr,"%d%s%s%d%d%d",&b.id,&b.name,&b.author,&b.price,&b.Quantity,&b.rack_no)!=-1)
	{
		printf("\n%-10d%-10s%-14s%-13d%-14d%-14d",b.id,b.name,b.author,b.price,b.Quantity,b.rack_no);
	}
	fclose(fptr);
	printf("\n\nPress any Key to continue..........");
	getch();

}

void Edit()
{

}
void Search(FILE *fptr)
{
	int f=0,skey;
	system("cls");
	printf("<=== Search Book ===>");
	printf("\n\nEnter Book Id : ");
	scanf("%d",&skey);
	fptr = fopen("bookstore.txt","rb");
	while(fread(&b,sizeof(b),1,fptr)==1)
	{
		if(b.id==skey)
		{
			f=1;
			printf("\n%-10d%-10s%-14s%-13d%-14d%-14d",b.id,b.name,b.author,b.price,b.Quantity,b.rack_no);
			break;
		}
	}
	if(f==0)
		printf("\n\tBook is not Found");

	fclose(fptr);
	printf("\n\nEnter any key to continue.......");
	getch();
}
void IssueBook(FILE *fptr)
{
	int f=0;
	system("cls");
	printf("\t<==== Issue Books ====>\n\n");
	printf("Enter Book Id to issue : ");
	scanf("%d",&s.id);

	fptr = fopen("bookstore.txt","rb");
	while(fread(&b,sizeof(b),1,fptr)==1)
	{
		if(b.id==s.id)
		{
			strcpy(b.name,s.b_name);
			f=1;
			break;
		}
	}
	if(f==0)
	{
		printf("\nNo Book found with this id");
		printf("\nPls try again........\n\n");
		return;
	}
	fclose(fptr);
	fptr = fopen("Issue.txt","ab");
	fflush(stdin);
	printf("\nEnter Student Name : ");
	gets(s.s_name);
	fflush(stdin);
	printf("\nEnter Student Class : ");
	gets(s.class);
	
	printf("\nEnter Student Roll No. : ");
	scanf("%d",&s.roll_no);
	fwrite(&b,sizeof(b),1,fptr);
	fclose(fptr);
}

void IssueList(FILE *fptr)
{
	
	system("cls");
	printf("\t<==== Book Issued List ====>\n\n");
	printf("%-14s%-13s%-14s%-14s\n","Id","S_Name","Class","Roll_NO");
	fptr=fopen("bookstore.txt","rb");
	while(fread(&b,sizeof(b),1,fptr)==1)
	{
		printf("\n%-14d %-13s %-14s %-14d %-19d",s.id,s.s_name,s.class,s.roll_no,s.b_name);
	}
	fclose(fptr);
	printf("\n\nPress any Key to continue..........");
	getch();
}

void Delete(struct Book b,FILE *fptr)
{
	int id,flag=0;
	system("cls");
	printf("<=== Delete Book ===>\n\n");
	printf("\nEnter Id to delete book : ");
	scanf("%d",&id);
	FILE *ft;

	fptr = fopen("bookstore.txt","rb");
	ft = fopen("temp.txt","wb");
	while(fread(&b,sizeof(b),1,fptr)==1)
	{
		
		if(id==b.id)
			flag = 1;
		else
			fwrite(&b,sizeof(b),1,ft);
	}
	if(flag==1)
	{
		printf("\n\nBook deleted Successfully ....");
	}else
	{
		printf("\nBook is Not Found ");
		printf("\nPlease try again......");
	}
	fclose(fptr);
	fclose(ft);
	remove("bookstore.txt");
	rename("temp.txt","bookstore.txt");
	printf("\n\nPress any key to continue......");
	getch();

}
int main(){
    FILE *fptr;
	int choice,bid;
	int k;
	k = password(g);
	if(k==1)
	{
		do{
		system("cls");
	  printf("\n1: Add New Book\n");
	  printf("2: View Books List\n");
	  printf("3: Search Book\n");
	  printf("4: Delete Books\n");
	  printf("5: Edit Book List\n");
	  printf("6: Issue Book\n");
	  printf("7: Issue Book List\n");
	  printf("0: Close the application\n\n");
	  printf("Enter your choice : ");
	  scanf("%d",&choice);
	  system("cls");
	  switch(choice)
	  {
	   case 1:
		addBook(fptr);//function call
		break;
	    case 2:
	    getBooks(fptr);
	    break;
		case 3:
			Search(fptr);
			break;
		  break;
		case 4 :
			Delete(b,fptr);
			break;
		case 5 :
			Edit();
			break;
		case 6 :
			IssueBook(fptr);
			break;
		case 7 : 
			IssueList(fptr);
			break;
		default :
			choice = 0;
		}	
	}while(choice!=0);	
	}
	system("cls");
	printf("\n\n\t<==== Thank you ====>\n\n");
	return 0;
}
