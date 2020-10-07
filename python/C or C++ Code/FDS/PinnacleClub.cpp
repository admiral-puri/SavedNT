#include<iostream>
#include<string>

using namespace std;

/*
Department of Computer Engineering has student's
club named 'Pinnacle Club'.
Students of Second, third and final year of department
can be granted membership on request.
Similarly one may cancel the membership of club.
First node is reserved for president of club and
last node is reserved for secretary of club.

Write C++ program to maintain club member‘s
information using singly linked list.
Store student PRN and Name.
Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.

*/

class node;
class list;

class Student
{
    string name;
    string status;
public:
    void setPresident();
    void setMember();
    void setSecretary();
    void set();
    void display();

    friend class list;
    friend class node;
};

void Student :: set()
{
    cout<<"\n Enter name : ";
    cin>>name;
    status = "Member";
}

void Student :: setPresident()
{
    status = "President";
}

void Student :: setSecretary()
{
    status = "Secretary";
}

void Student :: setMember()
{
    status = "Member";
}

void Student :: display()
{
    cout<<"\n [ "<<name <<"," << status <<" ]";
}

class node
{
    Student data;
    node * next;
public:
    node();

    friend class list;
};
node :: node()
{
    data.set();
    next = NULL;
}

class list
{
    node * head;
    void displayR(node * h);

public:
    list();
    void addMembers();
    void deleteMember();
    void display();
    void displayReverse();
    int count();
    void concatenate(list & r);

};

list :: list()
{
    head = NULL;
}

void list :: addMembers()
{
    node *n, *p;
    char ch;

    if(head != NULL)
    {//list exists, make p refer to the tail
        p = head;
        while(p->next != NULL)
            p = p->next;
    }

    do
    {
        n =  new node();
        if(head == NULL)
        {
            head = n;
            p = n;
            head ->data.setPresident();
        }
        else
        {
            p->next = n;
            p = n;
        }

        //cycle
        cout<<"\n Add more members (y/n) ? ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

    p->data.setSecretary();

}//addMembers


void list :: deleteMember()
{
    node * p, *sp;

    int i, pos, tot;
    cout<<"\n Enter position of member to delete ";
    cin>>pos;

    tot = count();

    if(pos < 1 || pos > tot)
    {
       cout<<"\n Invalid Position ";
       return;
    }

    if(pos == 1)
    {
       p = head;
       head  = head ->next;
       delete p;
       if(head != NULL)
            head->data.setPresident();
    }
    else
    {
        p = head;
        for(i = 1; i < pos; i++)
        {
            sp = p;
            p = p->next;
        }

        sp->next = p->next;
        delete p;

        if(sp->next == NULL)
            sp->data.setSecretary();
    }

}

int list :: count()
{
    int x;
    node * p;

    for(x = 0, p = head; p != NULL; p = p->next)
        x++;

    return x;
}

void list ::concatenate(list & r)
{
    if(r.head == NULL)
        return ;

    node * p;

    //move to the last node of the current list
    p = head;
    while(p->next != NULL)
        p = p->next;

    //update its status from secretary to member
    p->data.setMember();

    //concatenate
    p->next = r.head;

    //update its status from president to member
    p->next->data.setMember();

    //loose the second list
    r.head = NULL;
}

void list :: display()
{
    node *p;

    if(head != NULL)
    {
        for(p = head; p != NULL ; p = p->next)
            p->data.display();
    }
    else
        cout<<"\n List is EMPTY ";
}

void list :: displayReverse()
{

    if(head != NULL)
    {
        displayR(head);
    }
    else
        cout<<"\n List is EMPTY ";
}

void list :: displayR(node * h)
{
    if(h != NULL)
    {
        displayR(h->next);
        h->data.display();
    }
}

int main()
{
    list l1, l2, l3;
    int ch, x;

    do
    {
        cout<<"\n 1. Add Members in division 1";
        cout<<"\n 2. Add Members in division 2";
        cout<<"\n 3. Delete Member from division 1";
        cout<<"\n 4. Delete Member from division 2";
        cout<<"\n 5. Compute total number of members of club ";
        cout<<"\n 6. Display members ";
        cout<<"\n 7. Display list in reverse order using recursion ";
        cout<<"\n 8. Two linked lists exists for two divisions. Concatenate two lists.";
        cout<<"\n 9. Exit ";
        cout<<"\n Enter choice ";
        cin >> ch;

        switch(ch)
        {
            case 1://add members in div 1
                l1.addMembers();
                break;
            case 2://add members in div 2
                l2.addMembers();
                break;
            case 3://delete member from div 1
                l1.deleteMember();
                break;
            case 4://delete member from div 2
                l2.deleteMember();
                break;
            case 5:
                x = l1.count();
                cout<<"\n Number of members in division 1 : "<< x;
                x = l2.count();
                cout<<"\n Number of members in division 2 : "<< x;
                break;
            case 6:
                l1.display();
                l2.display();
                break;
            case 7:
                l1.displayReverse();
                l2.displayReverse();
                break;
            case 8:
                l1.concatenate(l2);
                l1.display();
                break;

        }

    }while(ch != 9);
    return 0;
}
