#include <bits/stdc++.h>

using namespace std;


class student{

int roll;
char * name;


public:

    student(){

    roll = NULL;
    name = NULL;

    }
    student(int rollno){

    roll = rollno;
    name = NULL;

    }
    student(int r, char * a){
    roll = r;
    name = new char[strlen(a)+1];
    strcpy(name,a);
    }
    //copy constructor
    student(student &s){
    roll = s.roll;
    name = new char[strlen(s.name)+1];
    strcpy(name,s.name);
    }

    void setroll(int r){
    roll = r;
    }

    void setname(char *name){
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    }

    char* returnname(){
    return name;
    }

    int returnroll(){
    return roll;
    }


    ~student(){
        cout<<"DELETING NAME ARRAY"<<endl;
        delete [] name;
    }

};


int main(){


    student s(34,"gautam");
    char* name = s.returnname();
    cout<<name<<endl;
    student copiedstudent(s);
    name = copiedstudent.returnname();
    cout<<name<<endl;




return 0;
}
