/*wap to store temperature of two cities for a week and display*/
#include <iostream>

using namespace std;
class temp
{
    private:
        int arr1[7],arr2[7],i;
        char city1[10],city2[10];
    public:
    void city();
    void accept();
    void display();
};
void temp::city()
{
    cout<<"\nEnter first city name : ";
    cin>>city1;
    cout<<"\nEnter second city name :";
    cin>>city2;
}
void temp::accept()
{
    cout<<"\nEnter the temperatures for "<<city1<<" City :"<<endl;
    for(i=0;i<7;i++)
    {
        cout<<city1<<" Day "<<i+1<<":";
        cin>>arr1[i];
    }
    cout<<"\nEnter the temperatures for "<<city2<<" City :"<<endl;
    for(i=0;i<7;i++)
    {
        cout<<city2<<" Day "<<i+1<<":";
        cin>>arr2[i];
    }
}
void temp::display()
{
    cout<<"\nThe temperatures of "<<city1<<" City :"<<endl;
    for(i=0;i<7;i++)
    {
        cout<<"\n"<<city1<<" Day "<<i+1<<":";
        cout<<arr1[i];
    }
    cout<<"\n\nThe temperatures of "<<city2<<" City :"<<endl;
    for(i=0;i<7;i++)
    {
        cout<<"\n"<<city2<<" Day "<<i+1<<":";
        cout<<arr2[i];
    }    
}
int main()
{
    temp obj;
    obj.city();
    obj.accept();
    obj.display();
    return 0;
}