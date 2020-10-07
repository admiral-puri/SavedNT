//Polynomial Operations Using CLL

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int coeff, expo;
    struct node * next;
};

typedef struct node node;

node * insertTerm(node * h, int c, int e)
{
    node *n, *p, *q;
    int flag;
    
    if(c == 0) //do not create term with zero coeff
        return h;
    
    //term == node
    n = (node *) malloc(sizeof(node));
    
    //initialize
    n->coeff = c;
    n->expo = e;
    n->next = NULL; //will be reset

    //connect
    if(h == NULL)
    {//head node doesn't exist
        h = n;//set as head
        h->next = h; //make circular
    }
    else
    {//head node exists
        flag = 0;
        p= h;
        do
        {
            if(n->expo > p->expo)
            {//n will be inserted before (to the left of) p
                if(p == h)
                {
                    n->next = p;
                    //reach the tail node
                    while(p->next != h)
                    {
                        p = p->next;
                    }
                    //reset its next 
                    p->next = n;
                    //set n as new head
                    h = n;
                    //stop loop
                    flag= 1;
                    break;
                }
                else
                {
                    //connection
                    q->next = n;
                    n->next = p;
                    //stop loop
                    flag= 1;
                    break;
                }
            }
            else if(n->expo == p->expo)
            {//merge the coeff
                p->coeff = p->coeff + n->coeff;
                free(n);//remove term n
                
                if(p->coeff == 0)
                {//remove term p as well
                    if(p == h)
                    {
                        if(h->next == h)
                        {//only one node in the list
                            free(p);
                            h = NULL;
                        }
                        else
                        {//multiple nodes in the list
                           //reach the tail node 
                           while(p->next != h)
                               p =p->next;
                           
                           //catch the head node
                           q = h;
                           //reset the head
                           h = h->next;
                           //reset next of tail
                           p->next = h;
                           //delete old head
                           free(q);
                        }
                    }
                    else
                    {
                        q->next = p->next;
                        free(p);
                    }
                }//if(p->coeff ==0)
                flag = 1;
                break;
            }
            else
            {//traverse
                q = p;
                p = p->next;
            }
        }while(p != h);
        
        if(flag == 0)
        {//connect as tail
            q->next = n;
            n->next = h; //make it circular
        }
    }//else
    
    return h;
    
}//insertTerm

node * create()
{
    char ch;//loop 
    int c, e; //input
    node * head;//head node
    
    head = NULL; //important initialization
    
    do
    {
        printf("\n creating a term ");
        printf("\n enter coefficient ");
        scanf("%d", &c); 
        printf("\n enter exponent "); 
        scanf("%d", &e);
        
        head = insertTerm(head, c, e);
        
        printf("\n add more terms to polynomial ");
        fflush(stdin);
        scanf("%c", &ch);
    }while(ch == 'y');
    
    return head;
}

void display(node *h)
{
    node *p;    
    printf("\n");
    if(h != NULL)
    {
        p = h;
        do
        {
            if(p != h && p->coeff > 0)
            {
                printf(" + ");
            }
            printf(" %dx^%d ", p->coeff, p->expo);
            p = p->next;
        }while(p != h);
    }
    else
    {
        printf("\n Polynomial Not Created");
    }
}//display


int count(node *h)
{
    int tot = 0;
    node *p;    
    if(h != NULL)
    {
        p = h;
        do
        {
            tot++;
            p = p->next;
        }while(p != h);
    }
    return tot;
}//count


node* multiply(node *h1, node *h2)
{
    node * h3 ;//result
    node *p, *q; //loop
    int c, e;
    
    if(h1 == NULL || h2 == NULL)
    {
        printf("\n Multiplication Not Possible");
        return NULL;
    }

    h3 = NULL;//imp initialization    
    p = h1;
    do
    {
        q = h2;
        do
        {
            c = p->coeff * q->coeff;
            e = p->expo + q->expo;
            h3 = insertTerm(h3, c, e);
            q = q->next;
    
        }while(q != h2);
        p = p->next;
    }while(p != h1);
    
    return h3;
}

node * add(node *h1, node *h2)
{
    node *p, *q;
    node *h3; //result
    int c, e, pi, qi;
    int tot1, tot2;
    
    if(h1 == NULL || h2 == NULL)
    {
        printf("\n Addition Not Possible");
        return NULL;
    }
    
    tot1 = count(h1);
    tot2 = count(h2);
    
    h3 = NULL;//imp initialization
    p = h1;
    q = h2;
    pi = 0;
    qi = 0;
    
    while(pi < tot1 && qi < tot2)//until p and q have terms
    {
        if(p->expo > q->expo)
        {
            c = p->coeff;
            e = p->expo;
            p = p->next;
            pi++;
        }
        else if(q->expo > p->expo)
        {
            c = q->coeff;
            e = q->expo;
            q = q->next;
            qi++;
        }
        else if(p->expo == q->expo)
        {
            c = p->coeff + q->coeff;   
            e = p->expo; //or e = q->expo;
            p = p->next;
            q = q->next;
            pi++;
            qi++;
        }
        
        h3 = insertTerm(h3, c, e);
    }
    
    while(pi < tot1) //remaining terms of p
    {
        c = p->coeff;
        e = p->expo;
        h3 = insertTerm(h3, c, e);
        p = p->next;
        pi++;
    }
    
    while(qi < tot2)//remaining terms of q
    {
        c = q->coeff;
        e = q->expo;
        h3 = insertTerm(h3, c, e);
        q = q->next;
        qi++;
    }
    
    return h3;
}


float eval(node * h)
{
    float x, sum;
    node *p;

    if(h == NULL)
    {
        printf("\n polynomial not created ");
        return 0;
    }

    //2x^5 == p->coeff * pow(x, p->expo)

    printf("\n enter value for x ");
    scanf("%f", &x);
    sum = 0;

    p = h;
    do
    {
        sum = sum + p->coeff* pow(x, p->expo);
        p = p->next;
    }while(p != h);
    
    return sum;
}

int main()
{
   node  *p1, *p2, *res;
   float ans;
   
   p1 = p2 = NULL; //imp initialization
   
   printf("\n Create polynomial 1 ");
   p1 = create();
   printf("\n Create polynomial 2 ");
   p2 = create();
   
   printf("\n Multiplication");
   res = multiply(p1,p2);
   display(p1);        
   display(p2);
   display(res);
   printf("\n Evaluating the result ");
   ans = eval(res);
   printf("\n Ans : %f ", ans);
   
   printf("\n Addition");
   res = add(p1,p2);
   display(p1);        
   display(p2);
   display(res);
   printf("\n Evaluating the result ");
   ans = eval(res);
   printf("\n Ans : %f ", ans);
   
   return 0;  
}