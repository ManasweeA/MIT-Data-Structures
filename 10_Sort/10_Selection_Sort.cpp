#include<iostream>
using namespace std;
class selection
{
    private:
        int arr[20],n,i,j;
    public:
    void accept();
    void swap(int *a,int *b);
    void sort();
    void display();
};

void selection::accept()
{
    cout<<"\nEnter number of elements : ";
    cin>>n;
    cout<<"\nEnter the unsorted elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void selection::swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection::sort()
{
    int min_index;
    for(i=0;i<n-1;i++)
    {
        min_index = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index = j;
            }
        }
        swap(&arr[min_index],&arr[i]);
    }
}

void selection::display()
{
    cout<<"\n\nThe elements after sorting are : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
}

int main()
{
    selection obj;
    obj.accept();
    obj.sort();
    obj.display();
    return 0;
}