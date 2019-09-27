#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Contact
{
private:
  string name;
  string number;
  string email;
  string city;
public:
  Contact();
  Contact(string name,string number,string email,string city);
  void set_values();
  void get_values();
  void help_to_remove_contact();
  int help_to_count_contacts();
  int help_to_seach_contact(string);
  int help_to_display_contact();
  int help_to_add_contact();
  void help_to_create_file(Contact *ptr);
  void help_to_load_file(Contact *ptr);
  void display();
};
class Contacts
{
public:
  Contact object_3[50];
  Contacts();
  void add_contact(Contact);
  void remove_contact(Contact);
  void counter_contact();
  void search_contact();
  void display_contact();
  void add_contact_at_index();
  void function_create_file();
  void function_load_file();
};
//Default Constructor
Contact::Contact()
{
  name="None";
  number="None";
  email="None";
  city="None";
}
//Parameterized Constructor
Contact::Contact(string name,string number,string email,string city)
{
  this->name=name;
  this->number=number;
  this->email=email;
  this->city=city;
}
//Set values function
void Contact::set_values()
{
  name="None";
  number="None";
  email="None";
  city="None";
}
//Get values
void Contact::get_values()
{
  cout << "Enter name of your contact\n";
  cin >> name;
  cout << "Enter Contact number\n";
  cin >> number;
  cout << "Enter your Email\n";
  cin >> email;
  cout << "Enter your city name\n";
  cin >> city;
}
//help_to_remove_contact funtion to help manupulate data well
void Contact::help_to_remove_contact()
{
  if(name!="None")
  {
    name="None";
    number="None";
    email="None";
    city="None";
    cout << "Your index Contact is successfully deleted\n";
  }
  else
  {
    cout << "Index is already empty and ready for new Contact\n";
  }
}
//Help to count the Contacts
int Contact::help_to_count_contacts()
{
 if(name=="None")
 {
   return 0;
 }
 else
 {
   return 1;
 }
}
// Help to search contact in your list
int Contact::help_to_seach_contact(string input)
{
  if(input==name)
  {
    cout << "Finally search engine find your contact with complete details\n";
    cout << "Name-> " << name << endl;
    cout << "Contact number-> " << number << endl;
    cout << "Email-> " << email << endl;
    cout << "City-> " << city << endl;
  }
}
//Help to add contact in your previous list
int Contact::help_to_add_contact()
{
  if(name=="None")
  {
    cout << "Enter name of your contact\n";
    cin >> name;
    cout << "Enter Contact number\n";
    cin >> number;
    cout << "Enter your Email\n";
    cin >> email;
    cout << "Enter your city name\n";
    cin >> city;
    return 1;
  }
  else
  {
    return 0;
  }
}
//Help to display all contacts in your list
int Contact::help_to_display_contact()
{
  if(name=="None")
  {
    return 0;
  }
  else
  {
    cout << "Name-> " << name << endl;
    cout << "Contact number-> " << number << endl;
    cout << "Email-> " << email << endl;
    cout << "City-> " << city << endl;
  }
}
//Help to create file
void Contact::help_to_create_file(Contact *ptr)
{

  ofstream myfile;
    myfile.open("contact.txt");
  while(true)
  {
    if(ptr->name=="None")
    {
      break;
    }
    myfile << ptr->name << endl;
    myfile << ptr->number << endl;
    myfile << ptr->email << endl;
    myfile << ptr->city << endl;
    ptr++;
  }
    myfile << "End of file\n";
    myfile.close();

}
//Help to load contacts from text file and store in array of objects
void Contact::help_to_load_file(Contact *ptr)
{
  string line;
  ifstream read;
  read.open("contact.txt");
  while(!read.eof())
  {

    getline(read,line);
    if(line=="End of file")
    {
      break;
    }
    ptr->name=line;
    getline(read,line);
    ptr->number=line;
    getline(read,line);
    ptr->email=line;
    getline(read,line);
    ptr->city=line;
    ptr++;
  }
  read.close();

}
//Implementation of display function
void Contact::display()
{
  cout << "Name-> " << name << endl;
  cout << "Contact number-> " << number << endl;
  cout << "Email-> " << email << endl;
  cout << "City-> " << city << endl;
}
//Default Constructor Contacts class
Contacts::Contacts()
{
  int a;
  for(a=0;a<50;a++)
  {
    object_3[a].set_values();
  }
}
//Contacts Class functions Implementation
void Contacts::add_contact(Contact temp)
{
 int a=0,choice;
 cout << "Your Conatact creating list is start from here\n";
 for(a=0;a<49;a++)
 {
 temp.get_values();
 object_3[a]=temp;
 cout << "Enter 1 to keep storing contact in your list or Enter 0 to stop\n";
 cin >> choice;
 if(choice!=1)
 {
   break;
 }
 }
}
//Contacts class funtion to remove contact at specific index
void Contacts::remove_contact(Contact temp)
{
  int index;
  cout << "Enter index you want to remove your Conatact\n";
  cin >> index;
  object_3[index].help_to_remove_contact();
}
//Contacts class function to count contact in list
void Contacts::counter_contact()
{
 int counter=0,check,a;
 for(a=0;a<49;a++)
{
 check=object_3[a].help_to_count_contacts();
 if(check==1)
 {
   counter++;
 }
 else if(check==0)
 {
   cout << "Total contacts in your list -> " << counter << endl;
   break;
 }
}
}
//funtion to help search contact in list
void Contacts::search_contact()
{
  string input;
  int a,check;
  cout << "Enter your name of contact to search in your list\n";
  cin >> input;
  for(a=0;a<49;a++)
 {
  check=object_3[a].help_to_seach_contact(input);
  if(check==1)
  {
    break;
  }
 }
}
//Help to display contacts
void Contacts::display_contact()
{
  int a,check;
  for(a=0;a<49;a++)
 {
  "***************************************************************************";
  check=object_3[a].help_to_display_contact();
  if(check==0)
  {
    break;
  }

 }
}
 //Help function to add contact in your list
 void Contacts::add_contact_at_index()
 {
   int a,check;
   for(a=0;a<49;a++)
  {
   check=object_3[a].help_to_add_contact();
   if(check==1)
   {
     cout << "Finally your contact is added to your list of contacts\n";
     break;
   }
 }
}
//function help to create file contact stored in list
void Contacts::function_create_file()
{
  object_3[0].help_to_create_file(object_3);
}
//function help to load contact from text myfile
void Contacts::function_load_file()
{
  object_3[0].help_to_load_file(object_3);
}
int main()
{
 //Contact obj;
 //Contact obj1("Mahmood","3346966320","mahmoodyousaf320@gmail.cocm","Peshawar");
 //obj.set_values();
 //obj.get_values();
 //obj.display();
 Contact temp;
 Contacts object;
 int input;
 cout << "Enter 1 to add new contact in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.add_contact(temp);
 }
 cout << "Enter 1 to remove contact  in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.remove_contact(temp);
 }
 cout << "Enter 1 to count contacts in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.counter_contact();
 }
 cout << "Enter 1 to search contact in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.search_contact();
 }
 cout << "Enter 1 to display all contact in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.display_contact();
 }
 cout << "Enter 1 to add contact in your list or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.add_contact_at_index();
 }
 cout << "Enter 1 to create file for store contact or 0 to do something more\n";
 cin >> input;
 if(input==1)
 {
 object.function_create_file();
 }
 cout << "Enter 1 to load contact from your text file in your array\n";
 cin >> input;
 if(input==1)
 {
 object.function_load_file();
 object.display_contact();
 }

}
