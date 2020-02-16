#include<iostream>
using namespace std;

class bin_search
{
    public:
    int arr[20],i,n,search,first,last;
    void get_data();
    //void display();
    void without_recur();
    void recur(int arr[],int n,int f,int l);
};

void bin_search::get_data()
{
    cout<<"\nEnter Number of elements in the array : ";
    cin>>n;
    cout<<"\nEnter the elements in Sorted Order : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter a Number to Search : ";
    cin>>search;
    first = 0;
    last = n-1;
}

void bin_search::without_recur()
{
    int f,l,mid;
    f = first;
    l = last;
    mid = (f+l)/2;
    while(f<=l)
    {
        if(arr[mid]==search)
        {
            cout<<"\nNumber Found at "<<mid+1<<" position!";
            break;
        }
        else if(search<arr[mid])
        {
            l = mid - 1;
        }
        else{
            f = mid + 1;
        }
        mid = (f+l)/2;
    }
    if(l<f)
    {
        cout<<"\nNumber not found!!!";
    }
    
}

void bin_search::recur(int a[],int n,int f,int l)
{
    int mid;
    if(f<=l)
    {
        mid = (f+l)/2;
        if(a[mid]==search)
        {
            cout<<"\nNumber Found at "<<mid+1<<" position!";
        }
        else if(search<a[mid])
        {
            recur(arr,n,f,mid-1);
        }
        else{
            recur(arr,n,mid+1,l);
        }
    }
    else{
        cout<<"\nNumber not found!!!";
    }
}


int main()
{
    bin_search obj;
    obj.get_data();
    cout<<"\nBinary Search Result without Recursion : "<<endl;
    obj.without_recur();
    cout<<"\n\nBinary Search Result with Recursion : "<<endl;
    obj.recur(obj.arr,obj.n,obj.first,obj.last);
    return 0;
}