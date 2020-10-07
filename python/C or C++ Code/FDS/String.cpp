/*
Write C++ program with class for String.
Write following functions :
1) frequency : that determines the frequency of occurrence of particular character in the string.
2) delete : that accepts two integers, start and length. The function computes a new string that is equivalent to the original string, except that length characters being at start have been removed.
3) chardelete : that accepts a character c. The function returns the string with all occurrences of c removed.
4) replace : to make an in-place replacement of a substring w of a string by the string x. note that w may not be of same size of x
5) palindrome : to check whether given string is palindrome or not

 */

#include <iostream>
#define SIZE 100
using namespace std;

class String
{
    //data member of the class
    char data[SIZE];
public:
    //functions of the class
    void set();
    void display();
    int length();
    int frequency(char);
    String deletePortion(int ,int);
    String charDelete(char);
    int searchSubstring(String);
    void inplaceReplacement(String, String);
    int palindrome();
};

//void set that belongs to class String
void String :: set()
{
    cout << "\n Enter a String "; //print
    cin >> data;//scan
}

//void display that belongs to class String
void String :: display()
{
    cout<<"\n"<<data;
}

int String :: length()
{
    int x;
    x = 0;
    while(data[x] != '\0')
        x++;

    return x;
}

//int frequency that belongs to class String
int String :: frequency(char x)
{
    int cnt, i;
    cnt = 0;
    for(i =0; data[i] != '\0'; i++)
    {
        if(data[i] == x) //ascii match (case sensitive)
            cnt++;
    }
    return cnt;
}

String String :: deletePortion(int startPos, int len)
{
    String target;
    int i;//index of source data
    int j;//index of target data
    int l = length();

    if(startPos <0 || startPos > l)
    {
        cout<<"\n Invalid Start Position";
        target.data[0] = '\0'; //empty string
        return target;
    }
    else
    {
        i =0;
        j =0 ;

        while(data[i] != '\0')
        {
            if(i < startPos || i >= startPos + len)
            {
                target.data[j] = data[i];
                j++;
            }
            i++;
        }//while
        target.data[j] = '\0'; //mark end of target string

        return target;
    }
}

String String :: charDelete(char c)
{
    int  i, j;
    String target;

    j =0 ;
    for(i =0; data[i] != '\0'; i++)
    {
        if(data[i] != c) //ascii comparison (case sensitive)
        {
            target.data[j] = data[i];
            j++;
        }
    }//for
    target.data[j] = '\0';
    return target;
}

int String :: searchSubstring(String w)
{
    int i;//index for w
    int j;//index for source

    i =0 ;
    for(j =0 ; data[j] != '\0'; j++)
    {
            if(w.data[i] == data[j])
            {
                i++;
                if(w.data[i] == '\0')
                {
                    return (j-i+1); //position where found
                }
            }
            else if(i >0)
            {
                i =0 ; //restart
                j--;//so that next j++ is cancelled and element j is compared with element i
            }
    }//for
    return -1; //not found
}

void String :: inplaceReplacement(String w, String x)
{
        int a, b;
        int pos, i;
        int point1, point2, jump;

        pos = searchSubstring(w);

        if(pos != -1)
        {
            a = x.length();
            b = w.length();

            if(a > b)
            {
                //shift the remaining data rightwards
                point2 = pos + b;
                point1 = length();
                jump = a - b;

                for(i =point1; i>= point2; i--)
                {
                    data[jump + i] = data[i];
                }
            }
            else if(a < b)
            {
                //shift the remaining data leftwards
                point1 = pos + b;
                point2 = length();
                jump = b - a;

                for(i =point1; i <= point2; i++)
                {
                    data[i-jump] = data[i];
                }
            }
            //replace
            for(i =0; i< a; i++)
                data[pos + i] = x.data[i];
        }
        else
            cout<<"\n Substring not found in source";
}

//to check whether given string is palindrome or not
int String :: palindrome()
{
    int x, y;
    x = 0; //left boundary
    y = length() - 1; //right boundary

    while (x < y)
    {
        if(data[x] != data[y])
        {
            return 0; //not palindrome
        }
        x++;
        y--;
    }//while

    return 1; //palindrome
}

int main()
{
    String s, result, w, x;
    char temp;
    int val, ch, startPos, len;

    do
    {
        cout<<"\n 1. Frequency ";
        cout<<"\n 2. Delete ";
        cout<<"\n 3. Char Delete ";
        cout<<"\n 4. Inplace Replacement ";
        cout<<"\n 5.  Palindrome Check ";
        cout<<"\n 6.  Exit";
        cout<<"\n Enter Choice ";
        cin>> ch;

        switch(ch)
        {
        case 1: //frequency
            s.set();
            cout<<"\n Enter a char to determine frequency ";
            cin>>temp;
            val = s.frequency(temp);
            cout<<"\n"<<temp<<" found "<<val <<" times in ";
            s.display();
            break;
        case 2: //delete
            s.set();
            cout<<"\n Enter start position for delete operation ";
            cin>>startPos;
            cout<<"\n Enter length of portion to delete ";
            cin>>len;
            result = s.deletePortion(startPos , len);
            cout<<"\n Original String : ";
            s.display();
            cout<<"\n Resultant String : ";
            result.display();
            break;
        case 3: //char delete
            s.set();
            cout<<"\n Enter a char to remove from the string ";
            cin>>temp;
            result = s.charDelete(temp);
            cout<<"\n Original String : ";
            s.display();
            cout<<"\n Resultant String : ";
            result.display();
            break;
        case 4://inplace replacement
            s.set();
            cout<<"\n Enter substring to search ";
            w.set();
            cout<<"\n Enter replace string ";
            x.set();
            s.inplaceReplacement(w, x);
            cout<<"\n Result : ";
            s.display();
            break;
        case 5://palindrome
            s.set();
            val = s.palindrome();
            if(val == 1)
                cout<<"\n String is  a palindrome ";
            else
                cout<<"\n String is not a palindrome ";
            break;
        case 6: //exit
            break;
        default:
            cout<<"\n Wrong Choice";
            break;

        }//switch
    }while(ch != 6);
    return 0;
}

