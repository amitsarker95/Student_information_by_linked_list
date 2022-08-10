#include<bits/stdc++.h>
using namespace std;
class Student
{
public:
    int roll;
    string name;
    string phone;
    string section;
    float attend;
    Student *next;
    Student(int roll,string name,string phone,string section,float attend)
    {
        this->roll = roll;
        this->name = name;
        this->phone = phone;
        this->section = section;
        this->attend = attend;
        this->next = NULL;


    }
};

void insert_data(Student * &head,int roll,string name,string phone,string section,float attend)
{
    Student *newNode = new Student(roll,name,phone,section,attend);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    Student *tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;

}
void display(Student *head)
{

    Student *tmp = head;
    if(head == NULL)
    {
        cout<<"No information found yet."<<endl;
    }

    while(tmp!=NULL)
    {
        cout<<"Name : "<<tmp->name<<endl;
        cout<<"Roll : "<<tmp->roll<<endl;
        cout<<"Section : "<<tmp->section<<endl;
        cout<<"phone : "<<tmp->phone<<endl;
        cout<<"Attend : "<<tmp->attend<<endl;
        tmp = tmp->next;
        cout<<endl;
    }


}
void search_information(Student *head,int roll)
{

    if(head==NULL)
    {
        cout<<"No information found yet."<<endl;
    }
    Student *tmp = head;
    while(tmp != NULL)
    {
        if(tmp->roll == roll)
        {
            cout<<"Name : "<<tmp->name<<endl;
            cout<<"Roll : "<<tmp->roll<<endl;
            cout<<"Section : "<<tmp->section<<endl;
            cout<<"phone : "<<tmp->phone<<endl;
            cout<<"Attend : "<<tmp->attend<<endl;
            return;
        }
        tmp = tmp->next;
    }

}


void update_data(Student * &head,int roll,float attend,string section,string phone)
{
    Student *tmp = head;
    while(tmp != NULL)
    {

        if(tmp->roll == roll)
        {
           tmp->attend = attend;
           tmp->section = section;
           tmp->phone = phone;
        }
        tmp = tmp->next;
    }
}
void delete_student(Student *&head,int roll){
    if(head->roll == roll){
        head = NULL;
        return;
    }
    if(head == NULL){
        cout<<"NO information found yet.";
        return;
    }
    Student *tmp = head;
    while(tmp->next !=NULL ){
            if(tmp->next->roll == roll){
                Student *save = tmp->next->next;
                tmp->next = save;
                break;
            }
        tmp = tmp->next;
    }

}

int sizeCount(Student * &head){
    int counter = 0;
    Student *tmp = head;
    while(tmp!=NULL){
        counter++;
        tmp=tmp->next;
    }
return counter;

}

void inser_at_specific_position(Student *&head,int roll,string name,string phone,string section,float attend,int pos){
    Student *student = new Student(roll,name,phone,section,attend);
    if(pos == 1){
      student -> next = head;
      head = student;
      return;
    }
    int counter = 0;
    int length = sizeCount(head);
    Student *tmp = head;
    while(tmp->next != NULL){
            if(pos == length-2){
                tmp->next->next = student;
                break;
            }
            if(pos-2 == counter){
                Student *save = tmp->next;
                tmp->next = student;
                student->next = save;
                break;
            }
            counter++;
        tmp=tmp->next;
    }

}


int main()
{
    Student *head = NULL;
    int option;
    cout<<"Option 1: Add student information."<<endl
        <<"Option 2: View students information."<<endl
        <<"Option 3: Search student information by roll."<<endl
        <<"Option 4: Update student information by roll."<<endl
        <<"Option 5: Delete student information by roll."<<endl
        <<"Option 6: Count students information"<<endl
        <<"Option 7: Add students information at specific position"<<endl
        <<"Option 0: Exit"<<endl
        <<"Choose an option : ";
    cin>>option;
    string name,phone,section;
    int roll;
    float attend;
    int length,pos;
    while(option != 0&&option<=7)
    {
        switch(option)
        {
        case 1:
            cout<<"Enter student name : ";
            cin>>name;
            cout<<"Enter Roll number : ";
            cin>>roll;
            cout<<"Enter Section : ";
            cin>>section;
            cout<<"Enter Phone number : ";
            cin>>phone;
            cout<<"Enter attendance : ";
            cin>>attend;
            insert_data(head,roll,name,phone,section,attend);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 2:
            display(head);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 3:
            cout<<"Enter roll : ";
            cin>>roll;
            search_information(head,roll);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 4:
            cout<<"Enter Roll number : ";
            cin>>roll;
            cout<<"Enter Section : ";
            cin>>section;
            cout<<"Enter Phone number : ";
            cin>>phone;
            cout<<"Enter attendance : ";
            cin>>attend;
            update_data(head,roll,attend,section,phone);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 5:
            cout<<"Enter roll : ";
            cin>>roll;
            delete_student(head,roll);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 6:
            length = sizeCount(head);
            cout<<"There are "<<length<<" students information."<<endl;
            cout<<"Choose an option : ";
            cin>>option;
            break;
        case 7:
            cout<<"Enter student name : ";
            cin>>name;
            cout<<"Enter Roll number : ";
            cin>>roll;
            cout<<"Enter Section : ";
            cin>>section;
            cout<<"Enter Phone number : ";
            cin>>phone;
            cout<<"Enter attendance : ";
            cin>>attend;
            cout<<"Enter a position to add student : ";
            cin>>pos;
            inser_at_specific_position(head,roll,name,phone,section,attend,pos);
            cout<<"Choose an option : ";
            cin>>option;
            break;
        default:
            break;

        }


    }


    return 0;
}
