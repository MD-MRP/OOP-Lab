#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

using namespace std;

class Person
{
private:
    string name;
    string DOB;
public:
    Person() {}
    Person(string name)
    {
        this->name = name;
    }

    Person(string name,string DOB)
    {
        this->name = name;
        this->DOB = DOB;
    }
    setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return name;
    }
    string getDOB()
    {
        return DOB;
    }
};
class Student : public Person
{
private:
    int id;
public:
    Student() {}
    Student(string name) : Person(name) {}
    Student(string name, int id) : Person(name)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    setId(int id)
    {
        this->id = id;
    }
    //void setMarks(int n) { marks += n;}
    /*void operator+(int n)
    {
        marks+=n;
    }*/

};
class CseSocietyMember:public Student
{
private:
    int marks = 0;
public:
    CseSocietyMember() {}
    CseSocietyMember(string name):Student(name) {}
    CseSocietyMember(string name,int id):Student(name,id) {}
    void operator+(int n)
    {
        marks+=n;
    }
    int getMarks()
    {
        return marks;
    }
    int setMark(int n)
    {
        marks+=n;
    }

};
class Teacher:public Person
{
public:
    Teacher() {}
    Teacher(string name):Person(name) {}
};
class CseDepartment
{
private:
    int studentNo = 400;
    int classRoom = 2;
    int lab = 2;
public:
    vector<string> randomSelection (CseSocietyMember* cseSocietyMember)
    {
        //srand(time(0));
        vector<string>name;
        vector<int> n = randomNumGenerator(1, 10, 1);
        //cout<<"n == "<<n<<endl;
        //for(int i=0;i<n.size();i++) cout<<"n == "<<n[i]<<endl;
        for(int i=0; i<5; i++)
        {
            cseSocietyMember+=(n[i]);
            name.push_back(cseSocietyMember->getName());
            cseSocietyMember-=(n[i]);
        }
        return name;
    }
    vector<int> randomNumGenerator(int lower, int upper,int count)
    {
        vector<int> myVector;
        srand((unsigned)time(NULL));

        while(myVector.size() < 5)
        {
            int b = rand() % 10;
            if ( !(find(myVector.begin(), myVector.end(), b) != myVector.end()))
            {
                myVector.push_back(b);
            }
        }
        return myVector;



        /*
        int i;
        for (i = 0; i < count; i++) {
            int num = (rand() % (upper - lower + 1)) + lower;
            return num;
        }
        */
    }

    void conductSurvey(CseSocietyMember* cseSocietyMember)
    {
        Student student;
        string name, isFinished;
        int n,id;
        cout<<"At first,\nStudents will give their marks.\nThen honorable Teachers will give their marks"<<endl;
        while(true)
        {
            cout<<"Please enter your name: ";
            cin>>name;
            student.setName(name);
            cout<<"Please enter your ID: ";
            cin>>id;
            student.setId(id);
            cout<<"\nHello, "<<student.getName()<<endl;
            for(int i=0; i<5; i++,cseSocietyMember++)
            {
                //int n;
                cout<<"How much point do you want to give to "<<cseSocietyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    cout<<"Invalid point.\nPlease give points between 1 to 5: ";
                    cin>>n;
                }
                cout<<n<<endl;
                //cseSocietyMember+n;
                //cseSocietyMember+n;
                cseSocietyMember->setMark(n);
                cout<<"You have given "<<cseSocietyMember->getMarks()<<" points to "<<cseSocietyMember->getName()<<endl<<endl;
                //cout<<"marks == "<<cseSocietyMember->getMarks()<<endl;
            }
            cseSocietyMember -=5;
            cout<<"\n\nWell done, "<<student.getName()<<endl;
            cout<<"You've successfully completed survey"<<endl;
            cout<<"-------------------------------------------"<<endl<<endl;

            cout<<"If all the students have finished with their markings, type 'd' and\nThen honorable Teachers will give their marks"<<endl;
            cout<<"Otherwise type 'c' to continue as a student"<<endl;
            cin>>isFinished;
            if(isFinished == "c")
                cout<<"Now next student will give mark."<<endl;
            else break;

        }

        Teacher teacher;
        cout<<"Now honorable Teachers will give their marks"<<endl;
        while(true)
        {
            cout<<"Please enter your name: ";
            cin>>name;
            teacher.setName(name);

            cout<<"\nHello, "<<teacher.getName()<<" sir"<<endl;
            for(int i=0; i<5; i++,cseSocietyMember++)
            {
                //int n;
                cout<<"How much point do you want to give to "<<cseSocietyMember->getName()<<" (between 1 to 5): ";
                cin>>n;
                while(n<1 or n>5)
                {
                    cout<<"Invalid point.\nPlease give points between 1 to 5: ";
                    cin>>n;
                }
                cout<<n<<endl;
                //cseSocietyMember+n;
                //cseSocietyMember+n;
                cseSocietyMember->setMark(n);
                cout<<"You have given "<<cseSocietyMember->getMarks()<<" points to "<<cseSocietyMember->getName()<<endl<<endl;
                //cout<<"marks == "<<cseSocietyMember->getMarks()<<endl;
            }
            cseSocietyMember -=5;
            cout<<"\n\nWell done, "<<student.getName() <<" sir"<<endl;
            cout<<"You've successfully completed survey"<<endl;
            cout<<"-------------------------------------------"<<endl<<endl;

            cout<<"If all Teachers have finished with their markings, Then please type 'd' "<<endl;
            cout<<"Otherwise type 'c' to continue"<<endl;
            cin>>isFinished;
            if(isFinished == "d")
                break;
            else continue;
        }

    }

    void displayResult(CseSocietyMember* cseSocietyMember)
    {
        cout<<"\n\nHere is the result of the survey."<<endl;
        cout<<"Name\t\t\tPoints"<<endl;
        int max =-1,index = -1;
        for(int i=0; i<5; i++,cseSocietyMember++)
        {
            cout<<cseSocietyMember->getName()<<"\t\t\t"<<cseSocietyMember->getMarks()<<endl;
            if(max < cseSocietyMember->getMarks())
            {
                max = cseSocietyMember->getMarks();
                index = i;
            }
        }
        cseSocietyMember -=5;
        cout<<"-----------------------------------------------"<<endl;
        if(max !=-1) cseSocietyMember += index;
        cout<<"\n\nThe best CSE Society Member is "<<cseSocietyMember->getName()<<endl;
    }

    void displayMembers(CseSocietyMember* cseSocietyMember,int n)
    {

        for(int i = 0;i<n;i++)
        {
            cout<<cseSocietyMember->getName()<<endl;
            cseSocietyMember++;
        }
    }
};

int main()
{
    CseDepartment cseDepartment;

    CseSocietyMember allCseSocietyMember[10]=
    {
        CseSocietyMember("Rashid",11508061),
        CseSocietyMember("Faisal",11508062),
        CseSocietyMember("Tushar",11508063),
        CseSocietyMember("Sajed",11508064),
        CseSocietyMember("Shajjad",11508065),
        CseSocietyMember("minar",11508066),
        CseSocietyMember("saadman",11508067),
        CseSocietyMember("yasir",11508068),
        CseSocietyMember("nahid",11508069),
        CseSocietyMember("nadimul",11508070)
    };

    cout<<"Here are the list of all cse society members:"<<endl;
    cseDepartment.displayMembers(allCseSocietyMember,10);

    cout<<"\n\nHere are the 5 randomly selected student, they will be voted.\n\n";


    vector<string> namesOfRandomlySelectedMembers = cseDepartment.randomSelection(allCseSocietyMember);
    //cout<<"names"<<endl;
    //for(int i=0; i<namesOfRandomlySelectedMembers.size(); i++) cout<<namesOfRandomlySelectedMembers[i]<<endl;

    CseSocietyMember selectedCseSocietyMember[5];
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(allCseSocietyMember[j].getName() == namesOfRandomlySelectedMembers[i])
            {
                selectedCseSocietyMember[i] = allCseSocietyMember[j];
                //cout<<"allCseSocietyMember["<<j<<"] == "<<namesOfRandomlySelectedMembers[i]<<endl;
            }
        }
    }

    cseDepartment.displayMembers(selectedCseSocietyMember,5);
    cout<<endl<<endl;
    cseDepartment.conductSurvey(selectedCseSocietyMember);
    cseDepartment.displayResult(selectedCseSocietyMember);

    return 0;

}
