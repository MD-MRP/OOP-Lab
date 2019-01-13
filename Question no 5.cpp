#include<bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    string DOB;
public:
    Person(){}
    Person(string name)
    {
        this->name = name;
    }
    Person(string name,string DOB)
    {
        this->name = name;
        this->DOB = DOB;
    }
    string getName()
    {
        return name;
    }
    string getDOB()
    {
        return DOB;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setDOB(string DOB)
    {
        this->DOB = DOB;
    }
};

class Date
{
private:
    int date,month,year;
public:
    Date(){}
    Date(int date,int month,int year)
    {
        this->date = date;
        this->month = month;
        this-> year = year;
    }

    int getDate(){ return date; }
    int getMonth(){ return month; }
    int getYear(){ return year; }


    void setDate(int date){ this->date=date; }
    void setMonth(int month){ this->month=month; }
    void setYear(int year){ this->year=year; }


    void setCurrentDate()
    {
            string str;
        int cnt=0;
        time_t my_time = time(NULL);
        str=ctime(&my_time);
        istringstream ss(str);
        do
        {
            string word;
            ss >> word;
            //cout << word << endl;
            cnt++;
            if(cnt==2) /// Month
            {
                if((word.compare("Jan")) == 0){ setMonth(1); }
                else if((word.compare("Feb")) == 0){ setMonth(2); }
                else if((word.compare("Mar")) == 0){ setMonth(3); }
                else if((word.compare("Apr")) == 0) { setMonth(4); }
                else if((word.compare("May")) == 0) { setMonth(5); }
                else if((word.compare("Jun")) == 0){ setMonth(6); }
                else if((word.compare("Jul")) == 0){ setMonth(7); }
                else if((word.compare("Aug")) == 0){setMonth(8);}
                else if((word.compare("Sep")) == 0){ setMonth(9);}
                else if((word.compare("Oct")) == 0){ setMonth(10);}
                else if((word.compare("Nov")) == 0){setMonth(11); }
                else if((word.compare("Dec")) == 0) { setMonth(12); }
            }
            if(cnt==3)  /// Date
            {
                stringstream geek(word);
                int x = 0;
                geek >> x;
                setDate(x);
            }
            if(cnt==5)  ///year
            {
                stringstream geek(word);
                int y = 0;
                geek >> y;
                setYear(y);
            }
        }
        while (ss);
    }
    int operator-(Date birth_Date)  ///operator overloading
    {
        setCurrentDate();
        int month[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };
        if (birth_Date.getDate() > getDate())
        {
            setDate(getDate() + month[birth_Date.getMonth()]);
            setMonth(getMonth()-1);
            //c.current_date = c.current_date + month[birth_month - 1];
            //c.current_month = c.current_month - 1;
        }

        if (birth_Date.getMonth() > getMonth())
        {
            setYear(getYear() - 1);
            setMonth(getMonth() + 12);
            //c.current_year = c.current_year - 1;
            //c.current_month = c.current_month + 12;
        }
        int calculated_date = getDate() - birth_Date.getDate();
        int calculated_month = getMonth() - birth_Date.getMonth();
        int calculated_year = getYear() - birth_Date.getYear();
        return calculated_year;
    }

};

class Player:public Person
{
private:
    Date age;
public:
    Player(){}
    Player(string name):Person(name){}
    Player(string name, string DOB):Person(name,DOB){}
    void setbirth_date(int birth_date)
    {
        age.setDate(birth_date);
    }
    void setbirth_month(int birth_month)
    {
        age.setMonth(birth_month);
    }
    void setbirth_year(int birth_year)
    {
        age.setYear(birth_year);
    }
    void setAge()
    {
        Date current_Date;
        Date birth_Date(age.getDate(), age.getMonth(),age.getYear());
        age.setYear(current_Date - birth_Date);     ///we are interested only year of players age.
    }

    int getAge()
    {
        return age.getYear();               ///we are interested only year of players age.
    }
};

class SpinBowler:public Player
{
public:
    SpinBowler(){}
    SpinBowler(string name):Player(name){}
    SpinBowler(string name, string DOB):Player(name,DOB){}
};

class FastBowler:public Player
{
public:
    FastBowler(){}
    FastBowler(string name):Player(name){}
    FastBowler(string name, string DOB):Player(name,DOB){}
};

class BatsMan:public Player
{
public:
    BatsMan(){}
    BatsMan(string name):Player(name){}
    BatsMan(string name, string DOB):Player(name,DOB){}
};

class WicketKeep:public Player
{
public:
    WicketKeep(){}
    WicketKeep(string name):Player(name){}
    WicketKeep(string name, string DOB):Player(name,DOB){}
};

class Coach:public Person
{
private:
    vector<string>nameOfSelectedSpinBowlers;
    vector<string>nameOfSelectedFastBowlers;
    vector<string>nameOfSelectedBatsMan;
    vector<string>nameOfSelectedWicketKeep;
public:
    Coach(){}
    Coach(string name):Person(name){}
    Coach(string name,string DOB):Person(name,DOB){}
    vector<string> getNameOfSelectedSpinBowlers()
    {
        return nameOfSelectedSpinBowlers;
    }
    vector<string> getNameOfSelectedFastBowlers()
    {
        return nameOfSelectedFastBowlers;
    }
    vector<string> getNameOfSelectedWicketKeep()
    {
        return nameOfSelectedWicketKeep;
    }
    vector<string> getNameOfSelectedBatsMan()
    {
        return nameOfSelectedBatsMan;
    }
    void selectSpinBowlers(SpinBowler* spinBowler,int noOfSpinBowlers)
    {
        vector<string>namesOfSpinBowlers;
        //vector<string>nameOfSelectedSpinBowlers;
        cout<<"\n\nHere is the list of Spin Bowlers whose age are above 25"<<endl;
        for(int i=0;i<noOfSpinBowlers;i++,spinBowler++)
        {
            if(spinBowler->getAge()>25)
            {
                cout<<spinBowler->getName()<<endl;
                namesOfSpinBowlers.push_back(spinBowler->getName());
            }
        }
        spinBowler-=noOfSpinBowlers;
        cout<<"Please type more then one spin Bowlers name(type 'd' when done):\n(You must select one spin bowler)\n";
        string spinBowlerName;

        cin>>spinBowlerName;
        while(checkSpinBowlerName(namesOfSpinBowlers,spinBowlerName) == false)
        {
            cout<<"Invalid name\nPlease enter a valid Name"<<endl;
            cin>>spinBowlerName;
        }
        nameOfSelectedSpinBowlers.push_back(spinBowlerName);
        while(true)
        {
            cin>>spinBowlerName;
            if(spinBowlerName == "d") break;
            while(checkSpinBowlerName(namesOfSpinBowlers,spinBowlerName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>spinBowlerName;
            }
            nameOfSelectedSpinBowlers.push_back(spinBowlerName);
        }


    }
    bool checkSpinBowlerName(vector<string>nameOfSpinBowler, string spinBowlerName)
    {
        for(int i=0;i<nameOfSpinBowler.size();i++)
        {
            if(nameOfSpinBowler[i] == spinBowlerName) return true;
        }
        return false;

    }

    void selectFastBowlers(FastBowler* fastBowler,int noOfFastBowlers)
    {
        vector<string>namesOfFastBowlers;
        //vector<string>nameOfSelectedSpinBowlers;
        cout<<"\n\nHere is the list of Fast Bowlers whose age are above 25"<<endl;
        for(int i=0;i<noOfFastBowlers;i++,fastBowler++)
        {
            if(fastBowler->getAge()>25)
            {
                cout<<fastBowler->getName()<<endl;
                namesOfFastBowlers.push_back(fastBowler->getName());
            }
        }
        fastBowler-=noOfFastBowlers;
        cout<<"Please type two or more then two fast Bowlers name(type 'd' when done):\n(You must select 2 fast bowlers)\n";
        string fastBowlerName;
        for(int i=0;i<2;i++)
        {
            cin>>fastBowlerName;
            while(checkFastBowlerName(namesOfFastBowlers,fastBowlerName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>fastBowlerName;
            }
            nameOfSelectedFastBowlers.push_back(fastBowlerName);
        }
        while(true)
        {
            cin>>fastBowlerName;
            if(fastBowlerName == "d") break;
            while(checkFastBowlerName(namesOfFastBowlers,fastBowlerName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>fastBowlerName;
            }
            nameOfSelectedFastBowlers.push_back(fastBowlerName);
        }


    }
    bool checkFastBowlerName(vector<string>nameOfFastBowler, string fastBowlerName)
    {
        for(int i=0;i<nameOfFastBowler.size();i++)
        {
            if(nameOfFastBowler[i] == fastBowlerName) return true;
        }
        return false;

    }

    void selectBatsMan(BatsMan* batsMan,int noOfBatsMan)
    {
        vector<string>namesOfBatsMan;
        //vector<string>nameOfSelectedSpinBowlers;
        cout<<"\n\nHere is the list of Bats Man whose age are above 25"<<endl;
        for(int i=0;i<noOfBatsMan;i++,batsMan++)
        {
            if(batsMan->getAge()>25)
            {
                cout<<batsMan->getName()<<endl;
                namesOfBatsMan.push_back(batsMan->getName());
            }
        }
        batsMan-=noOfBatsMan;
        cout<<"Please type 4 or more then 4 Bats Man name(type 'd' when done):\n(You must select 4 Bats Man)\n";
        string batsManName;

        for(int i=0;i<4;i++)
        {
            cin>>batsManName;
            while(checkBatsManName(namesOfBatsMan,batsManName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>batsManName;
            }
            nameOfSelectedBatsMan.push_back(batsManName);
        }
        while(true)
        {
            cin>>batsManName;
            if(batsManName == "d") break;
            while(checkBatsManName(namesOfBatsMan,batsManName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>batsManName;
            }
            nameOfSelectedBatsMan.push_back(batsManName);
        }
    }
    bool checkBatsManName(vector<string>nameOfBatsMan, string batsManName)
    {
        for(int i=0;i<nameOfBatsMan.size();i++)
        {
            if(nameOfBatsMan[i] == batsManName) return true;
        }
        return false;

    }

    void selectWicketKeep(WicketKeep* wicketKeep, int noOfWicketKeep)
    {
        vector<string>namesOfWicketKeepers;
        //vector<string>nameOfSelectedSpinBowlers;
        cout<<"\n\nHere is the list of Wicket Keepers whose age are above 25"<<endl;
        for(int i=0;i<noOfWicketKeep;i++,wicketKeep++)
        {
            if(wicketKeep->getAge()>25)
            {
                cout<<wicketKeep->getName()<<endl;
                namesOfWicketKeepers.push_back(wicketKeep->getName());
            }
        }
        wicketKeep-=noOfWicketKeep;
        cout<<"Please type more then one wicket keeper name(type 'd' when done):\n(You must select one wicket keeper)\n";
        string wicketKeeperName;

        cin>>wicketKeeperName;
        while(checkWicketKeeperName(namesOfWicketKeepers,wicketKeeperName) == false)
        {
            cout<<"Invalid name\nPlease enter a valid Name"<<endl;
            cin>>wicketKeeperName;
        }
        nameOfSelectedWicketKeep.push_back(wicketKeeperName);
        while(true)
        {
            cin>>wicketKeeperName;
            if(wicketKeeperName == "d") break;
            while(checkWicketKeeperName(namesOfWicketKeepers,wicketKeeperName) == false)
            {
                cout<<"Invalid name\nPlease enter a valid Name"<<endl;
                cin>>wicketKeeperName;
            }
            nameOfSelectedWicketKeep.push_back(wicketKeeperName);
        }


    }
    bool checkWicketKeeperName(vector<string>namesOfWicketKeepers, string wicketKeeperName)
    {
        for(int i=0;i<namesOfWicketKeepers.size();i++)
        {
            if(namesOfWicketKeepers[i] == wicketKeeperName) return true;
        }
        return false;

    }


};


int main()
{
    Coach BDCricketCouncilCoach("SR");
    int birth_date,birth_month,birth_year;
    string name;

    ///Spin Bowlers  (minimum 1 player)
    int noOfSpinBowlers;
    cout<<"How many spin bowlers is there : ";
    cin>>noOfSpinBowlers;
    SpinBowler spinBowler[noOfSpinBowlers];
    for(int i=0;i<noOfSpinBowlers;i++)
    {
        cout<<"\nPlease, Enter the name of the spin bowler no "<<i+1<<" : ";
        cin>>name;
        cout<<"\nPlease, Enter the date of birth date(DD/MM/YYYY) of the spin bowler no "<<i+1<<" : ";
        scanf("%d%d%d",&birth_date,&birth_month,&birth_year);
        //cout<<"b == "<<birth_date<<" "<<" "<<birth_month<<" "<<birth_year<<endl;
        spinBowler[i].setName(name);
        spinBowler[i].setbirth_date(birth_date);
        spinBowler[i].setbirth_month(birth_month);
        spinBowler[i].setbirth_year(birth_year);
        spinBowler[i].setAge();
        cout<<"Age of "<<spinBowler[i].getName()<<" is "<<spinBowler[i].getAge()<<endl;
    }

    ///FastBowlers (minimum 2 player)
    int noOfFastBowlers;
    cout<<"\n\nHow many Fast bowlers are there : ";
    cin>>noOfFastBowlers;
    FastBowler fastBowler[noOfFastBowlers];
    for(int i=0;i<noOfFastBowlers;i++)
    {
        cout<<"\nPlease, Enter the name of the Fast bowler no "<<i+1<<" : ";
        cin>>name;
        cout<<"\nPlease, Enter the date of birth date(DD/MM/YYYY) of the spin bowler no "<<i+1<<" : ";
        scanf("%d%d%d",&birth_date,&birth_month,&birth_year);
        //cout<<"b == "<<birth_date<<" "<<" "<<birth_month<<" "<<birth_year<<endl;
        fastBowler[i].setName(name);
        fastBowler[i].setbirth_date(birth_date);
        fastBowler[i].setbirth_month(birth_month);
        fastBowler[i].setbirth_year(birth_year);
        fastBowler[i].setAge();
        //cout<<fastBowler[i].getAge()<<endl;
        cout<<"Age of "<<fastBowler[i].getName()<<" is "<<fastBowler[i].getAge()<<endl;
    }

    ///BatsMan  (minimum 4 player)
    int noOfBatsMan;
    cout<<"\n\nHow many Bats Man are there : ";
    cin>>noOfBatsMan;
    BatsMan batsMan[noOfBatsMan];
    for(int i=0;i<noOfBatsMan;i++)
    {
        cout<<"\nPlease, Enter the name of the spin bowler no "<<i+1<<" : ";
        cin>>name;
        cout<<"\nPlease, Enter the date of birth date(DD/MM/YYYY) of the spin bowler no "<<i+1<<" : ";
        scanf("%d%d%d",&birth_date,&birth_month,&birth_year);
        //cout<<"b == "<<birth_date<<" "<<" "<<birth_month<<" "<<birth_year<<endl;
        batsMan[i].setName(name);
        batsMan[i].setbirth_date(birth_date);
        batsMan[i].setbirth_month(birth_month);
        batsMan[i].setbirth_year(birth_year);
        batsMan[i].setAge();
        //cout<<batsMan[i].getAge()<<endl;
        cout<<"Age of "<<batsMan[i].getName()<<" is "<<batsMan[i].getAge()<<endl;
    }

    ///WicketKeep  (minimum 1 player)
    int noOfWicketKeep;
    cout<<"\n\nHow many Wicket Keep are there : ";
    cin>>noOfWicketKeep;
    WicketKeep wicketKeep[noOfWicketKeep];
    for(int i=0;i<noOfWicketKeep;i++)
    {
        cout<<"\nPlease, Enter the name of the Wicket Keep no "<<i+1<<" : ";
        cin>>name;
        cout<<"\nPlease, Enter the date of birth date(DD/MM/YYYY) of the spin bowler no "<<i+1<<" : ";
        scanf("%d%d%d",&birth_date,&birth_month,&birth_year);
        //cout<<"b == "<<birth_date<<" "<<" "<<birth_month<<" "<<birth_year<<endl;
        wicketKeep[i].setName(name);
        wicketKeep[i].setbirth_date(birth_date);
        wicketKeep[i].setbirth_month(birth_month);
        wicketKeep[i].setbirth_year(birth_year);
        wicketKeep[i].setAge();
        //cout<<wicketKeep[i].getAge()<<endl;
        cout<<"Age of "<<wicketKeep[i].getName()<<" is "<<wicketKeep[i].getAge()<<endl;
    }


    cout<<"\n\nNow Coach will select players"<<endl<<endl;
    BDCricketCouncilCoach.selectSpinBowlers(spinBowler,noOfSpinBowlers);
    BDCricketCouncilCoach.selectFastBowlers(fastBowler,noOfFastBowlers);
    BDCricketCouncilCoach.selectBatsMan(batsMan,noOfBatsMan);
    BDCricketCouncilCoach.selectWicketKeep(wicketKeep, noOfWicketKeep);


    cout<< "--------------------------------------------"<<endl;

    ///display spin bowlers
    vector<string>selectedSpinBowlers;
    selectedSpinBowlers = BDCricketCouncilCoach.getNameOfSelectedSpinBowlers();
    cout<<"\n\nHere is the selected spin bowlers:"<<endl;
    for(int i=0;i<selectedSpinBowlers.size();i++) cout<<selectedSpinBowlers[i]<<endl;



    ///display fast bowlers
    vector<string>selectedFastBowlers;
    selectedFastBowlers = BDCricketCouncilCoach.getNameOfSelectedFastBowlers();
    cout<<"\n\nHere is the selected fast bowlers:"<<endl;
    for(int i=0;i<selectedFastBowlers.size();i++) cout<<selectedFastBowlers[i]<<endl;


    ///display bats man
    vector<string>selectedBatsMan;
    selectedBatsMan = BDCricketCouncilCoach.getNameOfSelectedBatsMan();
    cout<<"\n\nHere is the selected Bats Man:"<<endl;
    for(int i=0;i<selectedBatsMan.size();i++) cout<<selectedBatsMan[i]<<endl;


    ///display wicket keep
    vector<string>selectedWicketKeepers;
    selectedWicketKeepers = BDCricketCouncilCoach.getNameOfSelectedWicketKeep();
    cout<<"\n\nHere is the selected wicket keepers:"<<endl;
    for(int i=0;i<selectedWicketKeepers.size();i++) cout<<selectedWicketKeepers[i]<<endl;

    cout<< "--------------------------------------------"<<endl;
    return 0;
}
