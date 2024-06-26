#include<stdio.h>
#include<string.h>
#include<windows.h>
int password(int g)
{
    
    int k=0;
    char code[90]={"Aditya"};
    char pass[90];
    printf("\nEnter a Password : ");
    gets(pass);
    if(strcmp(code,pass)==0)
    {
        printf("Your Password is correct : ");
        k=1;
    }
    else if(g<3)
    {
        system("cls");
        g++;
        printf("\nWrong pass ! Try again........\n\n");
        password(g);
        
    }else{
        printf("\nTry  next time \n");
    }


    return k;
}