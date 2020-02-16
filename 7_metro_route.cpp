/*IMPLEMENT THE METRO ROUTE(SERIES OF STATION) WITH THE FOLLOWING OPERATIONS:
1.CREATE THE ROUTE WITH MIN 5 STATION
2.ADD NEW STATION TO ROUTE 
3.REMOVE THE STATION FROM THE ROUTE
4.RENAME THE STATION
5.DISPLAY THE ROUTE FROM SORCE TO DESTINATION
6.DISPLAY THE ROUTE FROM DESTINATION TO SOURCE*/

#include<iostream>
using namespace std;
#define size 10
class cqueue
{
    private:
        int front,rear,i;
        char cq[size],ch,Station,search,name;
    public:
        cqueue()
        {
            i = 0;
            front = -1;
            rear = -1;
        }
        void stations();
        void insert();
        void Delete();
        void Rename();
        void display_std();
        void display_dts();
};

void cqueue::stations()
{
    i = 0;
    while(i<5)
    {
        cout<<"\nEnter the station : ";
        cin>>cq[i];
        rear++;
        i++;
    }
    front = 0;
}

void cqueue::insert()
{
    if((front==0 && rear==size-1) || (front==rear+1))
    {
        cout<<"\nStation limit full. No more Stations can be added !!!";
    }
    else{
        cout<<"\nEnter the Station : ";
        cin>>Station;
        if((rear==size-1)&&(front!=0))
        {
            rear = -1;
        }
            cq[++rear] = Station;
            cout<<"\nStation added Successfully!!!";
        if(front==-1)
        {
            front = 0;
        }
    }
}

void cqueue::Delete()
{
    if(front == -1 && rear == -1)
    {
        cout<<"\nRoute Empty. No Stations found!!!";
    }
    else{
        cout<<"\nStation "<<cq[front++]<<" deleted Successfully!!!";
        if(front == size)
            front = 0;
        if(front-1==rear)
            front = rear = -1;
    }
}

void cqueue::Rename()
{
    if(front == -1)
    {
        cout<<"\nRoute Empty. No Stations found!!!";
    }
    else{
        cout<<"\nEnter the Station to be renamed : ";
        cin>>search;
        int i = front;
        if(front<=rear)
        {
            while(i<=rear)
            {
                if(search==cq[i])
                {
                    cout<<"\nEnter the new name for the Station : ";
                    cin>>name;
                    cq[i] = name;
                    return;
                }
                i++;
            }
            cout<<"\nStation not found!!!";
        }
        else{
            while(i<=size-1)
            {
                if(search==cq[i])
                {
                    cout<<"\nEnter the new name for the Station : ";
                    cin>>name;
                    cq[i] = name;
                    return;
                }
                i++;
            }
            i = 0;
            while(i<=rear)
            {
                if(search==cq[i])
                {
                    cout<<"\nEnter the new name for the Station : ";
                    cin>>name;
                    cq[i] = name;
                    return;
                }
                i++;
            }
            cout<<"\nStation not found!!!";
        }
    }  
}

void cqueue::display_std()
{
    if(front == -1)
    {
        cout<<"\nRoute Empty. No Stations found!!!";
    }
    else{
        int i = front;
        cout<<"\nRoute Stations front source to destination are : ";
        if(front<=rear)
        {
            while(i<=rear)
            {
                cout<<"-->"<<cq[i++];
            }
        }
        else{
            while(i<=size-1)
            {
                cout<<"-->"<<cq[i++];
            }
            i = 0;
            while(i<=rear)
            {
                cout<<"-->"<<cq[i++];
            }
        }
    }
}

void cqueue::display_dts()
{
    if(front == -1)
    {
        cout<<"\nRoute Empty. No Stations found!!!";
    }
    else{
        int i = rear;
        cout<<"\nRoute Stations from destination to source are : ";
        if(rear>=front)
        {
            while(i>=front)
            {
                cout<<"-->"<<cq[i--];
            }
        }
        else{
            i = rear;
            while(i>=0)
            {
                cout<<"-->"<<cq[i--];
            }
            i = size-1;
            while(i>=front)
            {
                cout<<"-->"<<cq[i--];
            }
        }
    }
}

int main()
{
    cqueue q;
    int ch;
    cout<<"\nEnter 5 Stations for the Metro Route!!! "<<endl;
    q.stations();
    while(1)
    {
        cout<<"\n\n1. Add a Station\n2. Delete Station\n3. Rename Station\n4. Display from start to end\n5. Display from end to start\n6. Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:q.insert();
            break;
            case 2:q.Delete();
            break;
            case 3:q.Rename();
            break;
            case 4:q.display_std();
            break;
            case 5:q.display_dts();
            break;
            case 6:exit(0);
            default:cout<<"\nInvalid Input!!!";
        }
    }
    return 0;
}