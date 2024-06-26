#include<iostream>
using namespace std;
class Interest
{
    protected :
        int pamt,irate,dur,si;
    public:
    void setPRD(int pamt,int irate,int dur)
    {
        this->pamt=pamt;
        this->irate=irate;
        this->dur=dur;
    }
};
class CalculateInterest :public Interest
{
    public :
    void callInterest()
    {
        si = (pamt*irate*dur)/100;
        cout<<"\nSimple Interest : "<<si;
    }
};
class InterestApp
{
    
};
int main()
{
    int pamt,irate,dur;
    cout<<"\nEnter Principle amount : ";
    cin>>pamt;
    cout<<"\nEnter Interest rate : ";
    cin>>irate;
    cout<<"\nEnter duration : ";
    cin>>dur;
    CalculateInterest c1;
    c1.setPRD(pamt,irate,dur);
    c1.callInterest();


}