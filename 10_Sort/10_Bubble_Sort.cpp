#include<iostream>
#include<string.h>
using namespace std;
#define max 20
class bubble
{
    private:
    int arr[20],n,i,j,temp=0;
    char arr1[20][max],temp1[max];
    public:
    void accept1();
    void accept2();
    void sort_int();
    void sort_char();
    void display1();
    void display2();
};

void bubble::accept1()
{
    cout<<"\nEnter number of elements of the integer array : ";
    cin>>n;
    cout<<"\nEnter the unsorted elements (integers) : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void bubble::accept2()
{
    cout<<"\nEnter number of elements of the string array : ";
    cin>>n;
    cout<<"\nEnter the unsorted elements (strings) : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
}

void bubble::sort_int()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i)-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void bubble::sort_char()
{
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-i)-1;j++)
        {
            if(strcmp(arr1[j],arr1[j+1])>0)
            {
                strcpy(temp1,arr1[j+1]);
                strcpy(arr1[j+1],arr1[j]);
                strcpy(arr1[j],temp1);
            }
        }
    }
}

void bubble::display1()
{
    cout<<"\n\nThe Sorted elements(integers) are : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
}

void bubble::display2()
{
    cout<<"\n\nThe Sorted elements(strings) are : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr1[i]<<"   ";
    }
    cout<<"\n";
}

int main()
{
    bubble obj;
    obj.accept1();
    obj.accept2();
    obj.sort_int();
    obj.sort_char();
    obj.display1();
    obj.display2();
    return 0;
}