#include<iostream>
using namespace std;
int size=5;
class ArrayOperation
{
    protected :
        int arr[5];
         
    public:
        void setArray(int a[])
        {
            for(int i=0;i<5;i++)
            {
                arr[i]=a[i];
            }
        }
};

class Sort : public ArrayOperation
{
    public :
       void SortArray()
       {
         for(int i=0;i<5;i++)
        {
            for(int j=i+1;j<5;j++)
            {
                if(arr[i]>arr[j])
                {
                    int temp = arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        cout<<"\nAfter sorting :";
        for(int i=0;i<5;i++)
        {
            cout<<"\t"<<arr[i];
        }
       }
};
class Insertion : public ArrayOperation
{
    public:
    void InsertElement()
    {
        int ele,pos;
        cout<<"\nEnter element : ";
        cin>>ele;
        cout<<"\nEnter a position : ";
        cin>>pos;
        arr[pos] = ele;
        cout<<"\nAfter Insertion :";
        for(int i=0;i<5;i++)
        {
            cout<<"\t"<<arr[i];
        }
    }
};
class Deletion : public ArrayOperation
{
    public :
    void deleteData()
    {
       
        int value;
        cout<<"Enter value do you want to delete : ";
        scanf("%d",&value);
        for(int i=0;i<size;i++)
        {
            if(arr[i]==value)
            {
                for(int j=i;j<size;j++)
                {
                    int temp = arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
                 size--;
                 break;
            }
        }
       
        for(int i=0;i<size;i++)
        {
            cout<<"\t"<<arr[i];
        }
    }
};
class Reverse : public ArrayOperation
{

};

int main()
{
    int a[5],choice;
    cout<<"\nEnter array element : ";
    for(int i=0;i<5;i++)
    {
        cin>>a[i];
    }
    do{
        cout<<"\n1. sort\n2. Insertion\n3. Deletion\n4. Reverse\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                Sort s;
                s.setArray(a);
                s.SortArray();
                break;
            case 2:
                Insertion i;
                i.setArray(a);
                i.InsertElement();
                break;
            case 3:
                Deletion d;
                d.setArray(a);
                d.deleteData();
                break;
            case 4:
                break;
            default :
                choice=0;
        }

    }while(choice!=0);

    return 0;
}