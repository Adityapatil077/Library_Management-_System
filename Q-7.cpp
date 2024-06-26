#include <iostream>
using namespace std;
#include <string.h>
class Person
{
protected:
    char name[60];
    int mob;
    char adharno[90];

public:
    Person(char name[], int mob, char adharno[])
    {
        strcpy(this->name, name);
        this->mob = mob;
        strcpy(this->adharno, adharno);
    }
    virtual void display() = 0;
};
class Employee:public Person
{
private:
    int empid;
    char dept[90];
    int sal;

public:
    Employee(int empid, char dept[], int sal, char name[], int mob, char adharno[]) : Person(name, mob, adharno)
    {
        this->empid = empid;
        strcpy(this->dept, dept);
        this->sal = sal;
    }
    void display()
    {
        cout << "\nEmployee Information";
        cout << "\nEmployee Id : " << empid;
        cout << "\nEmployee name : " << name;
        cout << "\nEmployee Department : " << dept;
        cout << "\nEmployee mobile : " << mob;
        cout << "\nEmployee Salary : " << sal;
        cout << "\nEmployee Aadhar No : " << adharno;
    }
};
int main()
{
    int empid;
    char name[10], dept[10];
    int mob, sal;
    char adharno[90];
    cout << "\nEnter the EmployeeId,name,Defname,mobileno,adharno,sal : ";
    cin >> empid;
    fflush(stdin);
    gets(name);
    fflush(stdin);
    gets(dept);
    cin >> mob;
    cin >> adharno;
    cin >> sal;
    Employee emp(empid, dept, sal, name, mob, adharno);
    emp.display();

    return 0;
}