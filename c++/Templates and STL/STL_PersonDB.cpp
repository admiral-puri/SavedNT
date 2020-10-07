//Program to study STL
//Implementing Person Database System

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

//forward declaration of the class
class PersonDB;

class Person
{
  int age;
  char name[20];

public:
  void getData();
  void displayData();

  //to used internally by sort
  bool operator <(Person &);

  //When a class is declared as a friend
  //then all of its functions get access
  //(through object) to all the members
  //(private/protected/ public) of the
  //current class.

  friend class PersonDB;
};

bool Person :: operator < (Person &r)
{
  if(strcmpi(name, r.name) < 0)
    return true;
  return false;
}


void Person :: getData()
{
  cout<<"\n Enter name : ";
  cin>> name;
  cout<<"\n Enter age : ";
  cin>>age;
}

void Person :: displayData()
{
  cout<<"\n"<<name<<" "<<age;
}


class PersonDB
{
  vector<Person> group;
public:
  void addToGroup();
  void deleteFromGroup();
  void arrangeByName();
  void displayGroup();
};

void PersonDB :: addToGroup()
{//add (append) a Person to the group (vector)
  Person p;
  p.getData();

  //append an element to the vector
  group.push_back(p);

  cout<<"\n"<<p.name <<" added to the group";
}

void PersonDB :: deleteFromGroup()
{
  int flag;
  char temp[20];
  cout<<"\n Enter name of person to delete ";
  cin>>temp;


  //iterator for the vector
  vector<Person>::iterator itr;


  //initialize the iterator
  itr = group.begin();
  flag = 0;

  while(itr != group.end())
  {
    if(strcmpi(itr->name, temp)==0)
    {
      //delete the element referred by itr
      group.erase(itr);

      flag = 1;
      break;

    }

    //make the iterator refer to the next element
    itr++;
  }//while


  if(flag == 1)
    cout<<"\n"<<temp <<" removed from group";
  else
    cout<<"\n"<<temp <<" not found in group";

}

void PersonDB :: arrangeByName()
{
  sort(group.begin(), group.end());

}

void PersonDB :: displayGroup()
{
  //iterator for the vector
  vector<Person>::iterator itr;

  //initialize the iterator
  itr = group.begin();

  while(itr != group.end())
  {
    itr->displayData();

    //make the iterator refer to the next element
    itr++;
  }

}

int main()
{
  PersonDB pdb;
  int ch;
  do
  {
    cout<<"\n 1. Add Person ";
    cout<<"\n 2. Delete Person ";
    cout<<"\n 3. Display ALL ";
    cout<<"\n 4. Arrange By Name ";
    cout<<"\n 5. Exit";
    cout<<"\n enter choice ";
    cin>>ch;

    switch(ch)
    {
      case 1:
        pdb.addToGroup();
        break;
      case 2:
        pdb.deleteFromGroup();
        break;
      case 3:
        pdb.displayGroup();
        break;
      case 4:
        pdb.arrangeByName();
        break;
      case 5:
        break;
      default:
        cout<<"\n Wrong Choice ";
        break;
    }//switch
  }while(ch != 5);
  return 0;
}

