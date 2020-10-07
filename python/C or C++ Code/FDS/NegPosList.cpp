#include<iostream>
using namespace std;

/*
Write C++ program to store set of negative and positive numbers using linked list. Write functions to
a) Insert numbers
b) Delete nodes with negative numbers
c) Create two more linked lists using this list, one containing all positive numbers and other containing negative numbers
d) For two lists that are sorted
e) Merge these two lists into third resultant list that is sorted

*/

class sll; //forward declaration

class node
{
    int data;
    node * next;
public:
    node(int);
    friend class sll; //allow all functions of sll to access all members of this class
};
node :: node(int q)
{
    data = q;
    next = NULL;
}

class sll
{
    node * head;
public:
    sll();
    void create();
    void insert(int);
    void delNode(int);
    void display();
    void create2Lists(sll &, sll &);
    int count();
    void deleteList();
    void sort();
    node * nodeAtPosition(int);
    void merge(sll & , sll &);
};

sll :: sll()
{
    head = NULL;
}

void sll:: create()
{
    node *n, *p;
    char ch;
    int val;

    deleteList();//drop existing nodes (if any)

    cout<<"\n Creating a linked list \n";
    do
    {
        cout<<"\n Enter data for the new node ";
        cin>>val;
        //allocate and initialize
        n = new node(val);

        //connect
        if(head == NULL)
        {//first node
            head = n;
            p = n;
        }
        else
        {//successive nodes
            p->next = n;
            p = n;
        }

        //cycle
        cout<<"\n Continue (y/n) ? ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');

}//create


void sll::display()
{
    node *p;
    if(head != NULL)
    {
        cout<<"\n";
        p = head;//at the head
        while(p != NULL)
        {
            cout<<p->data<<" "; //process
            p=p->next; //traverse
        }//while
    }
    else
        cout<<"\n List is EMPTY";
}//display

int sll::count()
{
    node *p;
    int x =0;
    p = head;//at the head

    while(p != NULL)
    {
        x++;//process
        p=p->next; //traverse
    }//while
    return x;
}//count

//insert a new node into the list, by position
void sll ::insert(int pos)
{
    node *n, *p, *sp;
    int size, i, val;

    size = count();
    //authenticate the position
    if(pos < 1 || pos > size +1)
    {
        cout<<"\n Invalid position ";
        cout<<"\n Valid range is 1 to "<<size +1;
        return ; //return to terminate the operation
    }

    //now we have a valid position
    //create and intitialize the node
    cout<<"\n enter data for new node ";
    cin>>val;
    n = new node(val);

    //connect by position
    if(pos == 1)
    {
        n->next = head;
        head = n; //reset the head
    }
    else
    {//intermediate and tail
        p = head;
        for(i = 1; i< pos; i++ )
        {
            sp = p;
            p=p->next;
        }
        //connect
        sp->next = n;
        n->next = p;
    }
}

void sll:: delNode( int pos)
{
    node  *p, *sp;
    int size, i;
    size = count();
    //authenticate the position
    if(pos < 1 || pos > size)
    {
        cout<<"\n Invalid position ";
        cout<<"\n Valid range is 1 to "<< size;
        //terminate the operation
        return ;
    }

    //now we have a valid position
    if(pos == 1)
    {//delete the head node
        p = head; //at the head
        head = head->next;//reset the head
        delete p;//deallocate the original head
    }
    else
    {//intermediate or tail node to be deleted
        p = head;//at the head
        for(i =1; i< pos; i++)
        {
            sp = p;//maintain a shadow pointer
            p = p->next;//move
        }

        //p is at node : pos
        //now sp is at node : pos-1

        sp->next = p->next;//reset the connection
        delete p;//deallocate the node
    }//else

}

void sll::deleteList()
{
    node *p;
    while(head != NULL)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void sll :: create2Lists(sll &s1, sll &s2)
{
    node *p, *p1, *p2;
    node *n;

    s1.deleteList();//ensure old data is dropped
    s2.deleteList();//ensure old data is dropped

    //traverse the original list
    for(p = head; p != NULL ; p=p->next)
    {
        n = new node(p->data);

        if(n->data >= 0)
        {//connect to positive list
            if(s1.head == NULL)
            {
                s1.head = n;
                p1 = n;
            }
            else
            {
                p1->next = n;
                p1 = n;
            }
        }
        else
        {//connect to negative list
            if(s2.head == NULL)
            {
                s2.head = n;
                p2 = n;
            }
            else
            {
                p2->next = n;
                p2 = n;
            }
        }
    }
}

node * sll:: nodeAtPosition(int x)
{
    node * p;
    int i;

    if(x == 0)
        return head;

    p = head;
    for(i =0; i < x && p != NULL; i++)
        p = p->next;

    return p;
}
void sll:: sort() //by pointer manipulation
{
    int s;
    int i, j; //loop control
    node *p, *q;
    node *sp;

    s = count();
    for(i = s-1; i >0; i--)
    {
        for(j =0; j < i; j++)
        {
            p = nodeAtPosition(j);
            if(p == NULL)
                break; //to avoid processing NULL

            //q = nodeAtPosition(j+1);
            //instead
            q = p->next;//j+1

            if(p->data > q->data)
            {//swap
                if(p == head)
                {
                    p->next = q->next;
                    q->next = p;
                    head = q;
                }
                else
                {
                    sp = nodeAtPosition(j-1);
                    sp->next = q;
                    p->next = q->next;
                    q->next = p;
                }
            }//if
        }//for(j...
    }//for(i...
}

void sll:: merge(sll & s1, sll &s2)
{
    node *p;

    deleteList(); //drop existing nodes

    if(s1.head == NULL && s2.head == NULL)
    {
        head = NULL;
    }
    else if(s1.head != NULL && s2.head == NULL)
    {
        s1.sort();
        head = s1.head;
        s1.head = NULL;
    }
    else if(s1.head == NULL && s2.head != NULL)
    {
        s2.sort();
        head = s2.head;
        s2.head = NULL;
    }
    else
    {
        s1.sort();
        s2.sort();
        //as the lists are sorted
        //so simply connect the head
        //of positive list with the
        //tail of the negative list

        //set the head of mergedList to the head of negative list
        head = s2.head;

        p = head;

        while(p->next != NULL)
            p = p->next;

        //connect
        p->next = s1.head;

        s1.head = NULL; //the two lists dont
        s2.head = NULL;//exist any longer
    }
}

int main()
{
    sll s;
    sll s1, s2;
    sll s3;

    int cnt;
    int ch, pos;

    do
    {
        cout<< "\n 1. Create ";
        cout<< "\n 2. Display the list ";
        cout<< "\n 3. Insert a node by position ";
        cout<< "\n 4. Delete a node by position ";
        cout<< "\n 5. Create 2 Lists (+ve and -ve) ";
        cout<<  s.create()"\n 6. Sort 2 Lists ";
        cout<< "\n 7. Merge 2 Lists ";
        cout<< "\n 8. exit ";
        cout<< "\n enter choice ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                s.create();
                break;
            case 2:
                s.display();
                break;
            case 3:
                cout<<"\n Enter position for new node ";
                cin>>pos;
                s.insert(pos);
                break;
            case 4:
                cout<<"\n Enter the position of the node to be deleted ";
                cin>>pos;
                s.delNode(pos);
                break;
            case 5:
                s.create2Lists(s1,s2);
                s1.display();
                s2.display();
                break;
            case 6:
                s1.sort();
                s2.sort();
                s1.display();
                s2.display();
                break;
            case 7:
                s3.merge(s1, s2);
                s3.display();
                break;
            case 8://exit
                break;
            default :
                cout<<"\n Wrong Choice";
        }//switch
    }while(ch != 8);

    return 0;
}

