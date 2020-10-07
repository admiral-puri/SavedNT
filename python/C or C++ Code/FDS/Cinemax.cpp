#include<iostream>
#define R 10
#define C 7

using namespace std;

/*
The ticket booking system of Cinemax theater
has to be implemented using C++ program.
There are 10 rows and 7 seats in each row.

Doubly circular linked list has to be maintained to
keep track of free seats at rows.
Assume some random booking to start with.
Use array to store pointers (Head pointer) to each row.
On demand  :
a) The list of available seats is to be displayed
b) The seats are to be booked
c)  The booking can be cancelled.
*/

class CLL;
class Cinemax;

class node
{
    node * next;
    int data;
    node * prev;
public:
    node();
    friend class CLL;
    friend class Cinemax;
};

node :: node()
{
    next = NULL;
    data = 0;
    prev = NULL;
}

class CLL
{
    node * head;
public:
    CLL();
    void create();
    void display();

    friend class Cinemax;
};

CLL :: CLL()
{
    head = NULL;
}

void CLL :: create()
{
    node *n, *p;
    int i;
    for(i =0 ; i< C; i++)
    {
        n = new node();

        //connect
        if(head == NULL)
            head = n;
        else
        {
            p->next = n;
            n->prev = p;
        }

        //track of last node
        p = n;
        //circular doubly list
        n->next = head;
        head->prev = n;
    }
}

void CLL :: display()
{
    node * p;

    if(head != NULL )
    {
        p = head;
        cout<<"\n";
        do
        {
            if(p->data ==0)
                cout<<"  A ";
            else
                cout<<" NA ";

            p= p->next;
        }while(p != head);
    }
    else
        cout<<"\n List is EMPTY ";
}

class Cinemax
{
    CLL rows[R];
public:
    Cinemax();
    void availableSeats();
    void bookSeats();
    void cancelSeats();
};

Cinemax :: Cinemax()
{
    int i;
    for(i =0 ; i< R; i++)
        rows[i].create();

}

void  Cinemax :: availableSeats()
{
    int i;
    for(i =0 ; i< R; i++)
        rows[i].display();
}

void  Cinemax :: bookSeats()
{
    char ch;
    int i, r, c;
    node * p;

    do
    {
        cout<<"\n Enter Row Number (1-"<<R<<") : ";
        cin>>r;
        cout<<"\n Enter Column Number (1-"<<C<<") : ";
        cin>>c;

        if(r >=1 && r <= R && c >=1 && c <=C )
        {
            p = rows[r-1].head;
            for(i =1 ; i< c; i++)
                p = p->next;

            if(p->data == 0)
            {
                p->data = 1;
                cout<<"\n Seat["<<r<<"]["<<c<<"] booked ";
            }
            else
                cout<<"\n Seat["<<r<<"]["<<c<<"] is not available ";
        }
        else
            cout<<"\n Invalid Choice ";

        cout<<"\n Book More Seats ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

}

void Cinemax :: cancelSeats()
{
    char ch;
    int  i, r, c;
    node * p;

    do
    {
        cout<<"\n Enter Row Number (1-"<<R<<") : ";
        cin>>r;
        cout<<"\n Enter Column Number (1-"<<C<<") : ";
        cin>>c;

        if(r >=1 && r <= R && c >=1 && c <=C )
        {
            p = rows[r-1].head;
            for(i =1 ; i< c; i++)
                p = p->next;

            if(p->data == 1)
            {
                p->data = 0;
                cout<<"\n Seat["<<r<<"]["<<c<<"] cancelled ";
            }
            else
                cout<<"\n Seat["<<r<<"]["<<c<<"] is not booked ";
        }
        else
            cout<<"\n Invalid Choice ";

        cout<<"\n Cancel More Seats ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

}
int main()
{
    Cinemax c;
    int  ch;

    do
    {
        cout<< "\n 1. Show Available Seats ";
        cout<< "\n 2. Book  Seats ";
        cout<< "\n 3. Cancel Seats";
        cout<< "\n 4. Exit ";
        cout<< "\n Enter Choice ";
        cin>>ch;

        switch(ch)
        {
            case 1://available seats
                c.availableSeats();
                break;
            case 2://book seats
                c.bookSeats();
                break;
            case 3://cancel seats
                c.cancelSeats();
                break;
            case 4://exit
                break;

            default:
                cout<<"\n Wrong Choice ";
                break;
       };

    }while(ch != 4);
    return 0;
}
