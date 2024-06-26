#include<stdio.h>
#include<math.h>
#include<string.h>
 struct emp
 {
    int id;
    char name[90];
    int sal;
 };
 struct emp e[3];
int main()
{
    printf("\nEnter  id name and sal : ");
    for(int i=0;i<3;i++)
    {
        scanf("%d%s%d",&e[i].id,&e[i].name,&e[i].sal);
    }
    printf("\nBefore : ");
    for(int i=0;i<3;i++)
    {
        printf("\n%d\t%s\t%d",e[i].id,e[i].name,e[i].sal);
    }
    printf("\nAfter : ");
    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        {
            if(e[i].sal<e[j].sal)
            {
                struct emp temp = e[i];
                e[i]=e[j];
                e[j]=temp;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        printf("\n%d\t%s\t%d",e[i].id,e[i].name,e[i].sal);
    }
}

