// ____  _   _  ___  _   _ _____   ____   ___   ___  _  __
//|  _ \| | | |/ _ \| \ | | ____| | __ ) / _ \ / _ \| |/ /
//| |_) | |_| | | | |  \| |  _|   |  _ \| | | | | | | ' /
//|  __/|  _  | |_| | |\  | |___  | |_) | |_| | |_| | . \
//|_|   |_| |_|\___/|_| \_|_____| |____/ \___/ \___/|_|\_\//
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cstdio>
#include <windows.h>
#include <sstream>
#include "TextTable.h"
using namespace std;

struct phone{
    int id=0;
	string name;
	string family;
	string middleName;
	string email;
	string number;
	string group;
};

void noneAll(phone phoneOBJ[100])
{
	for(int i=0;i<100;i++)
	{
	    phoneOBJ[i].id = i;
		phoneOBJ[i].name = "none";
		phoneOBJ[i].family = "none";
		phoneOBJ[i].middleName = "none";
		phoneOBJ[i].email = "none";
		phoneOBJ[i].number = "none";
		phoneOBJ[i].group = "none";
	}
}

void title(string name)
{
    cout<<"========= "<<name<<" ========="<<"\n";
}

void add(phone phoneOBJ[100],int s)
{
    title("Add");
	cout<<"Enter Name :";
	getchar();
	getline(cin,phoneOBJ[s].name);
	cout<<"Enter Family :";
	getline(cin,phoneOBJ[s].family);
	cout<<"Enter middleName :";
	getline(cin,phoneOBJ[s].middleName);
	cout<<"Enter E Email :";
	getline(cin,phoneOBJ[s].email);
	cout<<"Enter Number :";
	getline(cin,phoneOBJ[s].number);
	cout<<"Enter Group :";
	getline(cin,phoneOBJ[s].group);
}

string intToStr(int number)
{
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

void newTitle(TextTable& t)
{
    t.add("Id");
    t.add("Name");
    t.add("Family");
    t.add("MiddleName");
    t.add("Email");
    t.add("Number");
    t.add("Group");
    t.endOfRow();
}

void PrintById(TextTable& t,phone phoneOBJ[100],int i=0)
{
    phoneOBJ[i].id = i;
    t.add(intToStr(phoneOBJ[i].id));
    t.add(phoneOBJ[i].name);
    t.add(phoneOBJ[i].family);
    t.add(phoneOBJ[i].middleName);
    t.add(phoneOBJ[i].email);
    t.add(phoneOBJ[i].number);
    t.add(phoneOBJ[i].group);
    t.endOfRow();
}

void printByIdJustOne(phone phoneOBJ[100],int i=0)
{
    TextTable t('-', '|', '+');
    newTitle(t);
    phoneOBJ[i].id = i;
    t.add(intToStr(phoneOBJ[i].id));
    t.add(phoneOBJ[i].name);
    t.add(phoneOBJ[i].family);
    t.add(phoneOBJ[i].middleName);
    t.add(phoneOBJ[i].email);
    t.add(phoneOBJ[i].number);
    t.add(phoneOBJ[i].group);
    t.endOfRow();
    t.setAlignment(2,TextTable::Alignment::RIGHT );
    std::cout<<t;
}

void printByIdJustOneWithOutTitle(TextTable& t,phone phoneOBJ[100],int i=0)
{
    phoneOBJ[i].id = i;
    t.add(intToStr(phoneOBJ[i].id));
    t.add(phoneOBJ[i].name);
    t.add(phoneOBJ[i].family);
    t.add(phoneOBJ[i].middleName);
    t.add(phoneOBJ[i].email);
    t.add(phoneOBJ[i].number);
    t.add(phoneOBJ[i].group);
    t.endOfRow();
    /*t.setAlignment(2,TextTable::Alignment::RIGHT );
    std::cout<<t;*/
}

void list(TextTable& t,phone phoneOBJ[100])
{
    title("List");
    newTitle(t);
	for(int i=0;i<100;i++)
	{
		if(phoneOBJ[i].name!="none"
            || phoneOBJ[i].family != "none"
            || phoneOBJ[i].number != "none"
            || phoneOBJ[i].email != "none"
            || phoneOBJ[i].middleName != "none"
            || phoneOBJ[i].group != "none")
		{
			PrintById(t,phoneOBJ,i);
		}
	}
    t.setAlignment(2, TextTable::Alignment::RIGHT );
    std::cout<<t;
}

void delet(phone phoneOBJ[100])
{
    //Delete Just BY Name
	/*char name[31];
	cout<<"======== Delete ========"<<"\n";
	cout<<"Enter Name For Remove:";
	cin>>name;
	for(int i=0;i<100;i++)
	{
		if(phoneOBJ[i].name==name)
		{
			phoneOBJ[i].id = i;
            phoneOBJ[i].name = "none";
            phoneOBJ[i].family = "none";
            phoneOBJ[i].middleName = "none";
            phoneOBJ[i].email = "none";
            phoneOBJ[i].number = "none";
            phoneOBJ[i].group = "none";
		}
	}*/
	int menu = 0;
    title("Delete");
    cout<<"Delete By :"<<"\n";
    cout<<"1-Id"<<"\n";
    cout<<"2-Name"<<"\n";
    cout<<"3-Family"<<"\n";
    cout<<"4-MiddleName"<<"\n";
    cout<<"5-Number"<<"\n";
    cout<<"6-Email"<<"\n";
    cout<<"7-Group"<<"\n";
    cout<<"8-BACK"<<"\n";
    cout<<"Enter :";
    cin>>menu;
    switch(menu)
    {
        case 1:
            {
                int id;
                cout<<"Enter Id :";
                cin>>id;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].id==id)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 2:
            {
                string name;
                cout<<"Enter Name :";
                cin>>name;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].name==name)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 3:
            {
                string family;
                cout<<"Enter Family :";
                cin>>family;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].family==family)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 4:
            {
                string middleName;
                cout<<"Enter middleName :";
                cin>>middleName;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].middleName==middleName)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 5:
            {
                string number;
                cout<<"Enter Number :";
                cin>>number;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].number==number)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 6:
            {
                string email;
                cout<<"Enter Email :";
                cin>>email;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].email==email)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 7:
            {
               string group;
                cout<<"Enter Group :";
                cin>>group;
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].group==group)
                    {
                        phoneOBJ[i].id = i;
                        phoneOBJ[i].name = "none";
                        phoneOBJ[i].family = "none";
                        phoneOBJ[i].middleName = "none";
                        phoneOBJ[i].email = "none";
                        phoneOBJ[i].number = "none";
                        phoneOBJ[i].group = "none";
                    }
                }
            }
            break;
        case 8:
            break;
    }
}

void searchh(TextTable& t,phone phoneOBJ[100])
{
    int menu = 0;
    title("Search");
    cout<<"Search According To :"<<"\n";
    cout<<"1-Name"<<"\n";
    cout<<"2-Family"<<"\n";
    cout<<"3-MiddleName"<<"\n";
    cout<<"4-Number"<<"\n";
    cout<<"5-Email"<<"\n";
    cout<<"6-Group"<<"\n";
    cout<<"7-Id"<<"\n";
    cout<<"8-BACK"<<"\n";
    cout<<"Enter :";
    cin>>menu;
    switch(menu)
    {
        case 1:
            {
                string name;
                cout<<"Enter Name :";
                cin>>name;
                TextTable tName('-', '|', '+');
                newTitle(tName);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].name==name)
                    {
                        printByIdJustOneWithOutTitle(tName,phoneOBJ,i);
                    }
                }
                tName.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tName;
            }
            break;
        case 2:
            {
                string family;
                cout<<"Enter Family :";
                cin>>family;
                TextTable tFamily('-', '|', '+');
                newTitle(tFamily);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].family==family)
                    {
                        printByIdJustOneWithOutTitle(tFamily,phoneOBJ,i);
                    }
                }
                tFamily.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tFamily;
            }
            break;
        case 3:
            {
                string middleName;
                cout<<"Enter middleName :";
                cin>>middleName;
                TextTable tMiddleName('-', '|', '+');
                newTitle(tMiddleName);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].middleName==middleName)
                    {
                        printByIdJustOneWithOutTitle(tMiddleName,phoneOBJ,i);
                    }
                }
                tMiddleName.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tMiddleName;
            }
            break;
        case 4:
            {
                string number;
                cout<<"Enter Number :";
                cin>>number;
                TextTable tNumber('-', '|', '+');
                newTitle(tNumber);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].number==number)
                    {
                        printByIdJustOneWithOutTitle(tNumber,phoneOBJ,i);
                    }
                }
                tNumber.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tNumber;
            }
            break;
        case 5:
            {
                string email;
                cout<<"Enter Email :";
                cin>>email;
                TextTable tEmail('-', '|', '+');
                newTitle(tEmail);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].email==email)
                    {
                        printByIdJustOneWithOutTitle(tEmail,phoneOBJ,i);
                    }
                }
                tEmail.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tEmail;
            }
            break;
        case 6:
            {
               string group;
                cout<<"Enter Group :";
                cin>>group;
                TextTable tGroup('-', '|', '+');
                newTitle(tGroup);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].group==group)
                    {
                        printByIdJustOneWithOutTitle(tGroup,phoneOBJ,i);
                    }
                }
                tGroup.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tGroup;
            }
            break;
        case 7:
            {
                int id;
                cout<<"Enter Id :";
                cin>>id;
                TextTable tId('-', '|', '+');
                newTitle(tId);
                for(int i=0;i<100;i++)
                {
                    if(phoneOBJ[i].id==id)
                    {
                        printByIdJustOneWithOutTitle(tId,phoneOBJ,i);
                    }
                }
                tId.setAlignment(2,TextTable::Alignment::RIGHT );
                std::cout<<tId;
            }
            break;
        case 8:
            break;
    }
}

void edit(phone phoneOBJ[100])
{
    int menu;
	int id=0;
	title("Edit");
	cout<<"1-Enter Id"<<"\n";
	cout<<"2-Back"<<"\n";
	cout<<"Enter :";
	cin>>menu;
	if(menu!=1)
    {
        goto backk;
    }
    cout<<"Enter ID :";
	cin>>id;
	for(int i=0;i<100;i++)
    {
        if(i==id)
        {
            cout<<"i = "<<i<<"id = "<<id<<"\n";
            cout<<"Enter New Name "<<"("<<phoneOBJ[i].name<<")"<<" :";
            getchar();
            getline(cin,phoneOBJ[i].name);
            cout<<"Enter New Family "<<"("<<phoneOBJ[i].family<<")"<<" :";
            getline(cin,phoneOBJ[i].family);
            cout<<"Enter New MiddleName "<<"("<<phoneOBJ[i].middleName<<")"<<" :";
            getline(cin,phoneOBJ[i].middleName);
            cout<<"Enter New Email "<<"("<<phoneOBJ[i].email<<")"<<" :";
            getline(cin,phoneOBJ[i].email);
            cout<<"Enter New Number "<<"("<<phoneOBJ[i].number<<")"<<" :";
            getline(cin,phoneOBJ[i].number);
            cout<<"Enter New Group "<<"("<<phoneOBJ[i].group<<")"<<" :";
            getline(cin,phoneOBJ[i].group);
            cout<<"Done ... "<<"\n";
            break;
        }
    }
    backk:;
}

int getAllRecord(phone phoneOBJ[100])
{
    int sum = 0;
    for(int i=0;i<100;i++)
    {
        if(phoneOBJ[i].name!="none"
            || phoneOBJ[i].family != "none"
            || phoneOBJ[i].number != "none"
            || phoneOBJ[i].email != "none"
            || phoneOBJ[i].middleName != "none"
            || phoneOBJ[i].group != "none")
		{
			sum++;
		}
    }
    return sum;
}

int StrToIntFourDigit(string str)
{
    char temp[5];
    int phone = 0;
    for(int i=0;i<4;i++)
    {
        temp[i] = str[i];
    }
    stringstream s(temp);
    s>>phone;
    return phone;
}

void sortt(phone phoneOBJ[100])
{
    int menu = 0;
    title("Sort");
    cout<<"Sort By :"<<"\n";
    cout<<"1-name"<<"\n";
    cout<<"2-family"<<"\n";
    cout<<"3-middle name"<<"\n";
    cout<<"4-number"<<"\n";
    cout<<"5-email"<<"\n";
    cout<<"6-group"<<"\n";
    cout<<"7-BACK"<<"\n";
    cout<<"Enter :";
    cin>>menu;
    switch(menu)
    {
        case 1:
            {
                int n = getAllRecord(phoneOBJ);
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(phoneOBJ[i].name.at(0) < phoneOBJ[j].name.at(0))
                        {
                            phone tmp = phoneOBJ[i];
                            phoneOBJ[i] = phoneOBJ[j];
                            phoneOBJ[j] = tmp;
                        }
                    }
                }
            }
            break;
        case 2:
            {
                int n = getAllRecord(phoneOBJ);
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(phoneOBJ[i].family.at(0) < phoneOBJ[j].family.at(0))
                        {
                            phone tmp = phoneOBJ[i];
                            phoneOBJ[i] = phoneOBJ[j];
                            phoneOBJ[j] = tmp;
                        }
                    }
                }
            }
            break;
        case 3:
            {
                int n = getAllRecord(phoneOBJ);
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(phoneOBJ[i].middleName.at(0) < phoneOBJ[j].middleName.at(0))
                        {
                            phone tmp = phoneOBJ[i];
                            phoneOBJ[i] = phoneOBJ[j];
                            phoneOBJ[j] = tmp;
                        }
                    }
                }
            }
            break;
        case 4:
            {
                int SortNumberMenu = 0;
                cout<<"1-Nozoli(Down To Up)"<<"\n";
                cout<<"2-Soodi (Up To Down) "<<"\n";
                cout<<"Enter (1 or 2 ):";
                cin>>SortNumberMenu;
                if(SortNumberMenu==1)
                {
                    int n = getAllRecord(phoneOBJ);
                    for (int i = 0; i < n; i++)
                    {
                        for(int j = 0; j < n; j++)
                        {
                            if(StrToIntFourDigit(phoneOBJ[i].number) < StrToIntFourDigit(phoneOBJ[j].number))
                            {
                                phone tmp = phoneOBJ[i];
                                phoneOBJ[i] = phoneOBJ[j];
                                phoneOBJ[j] = tmp;
                            }
                        }
                    }
                }
                else if(SortNumberMenu==2)
                {
                    int n = getAllRecord(phoneOBJ);
                    for (int i = 0; i < n; i++)
                    {
                        for(int j = 0; j < n-1; j++)
                        {
                            if(StrToIntFourDigit(phoneOBJ[j].number) < StrToIntFourDigit(phoneOBJ[j+1].number))
                            {
                                phone tmp = phoneOBJ[j];
                                phoneOBJ[j] = phoneOBJ[j+1];
                                phoneOBJ[j+1] = tmp;
                            }
                        }
                    }
                }
                else
                {
                    break;
                }

            }
            break;
        case 5:
            {
                int n = getAllRecord(phoneOBJ);
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(phoneOBJ[i].email.at(0) < phoneOBJ[j].email.at(0))
                        {
                            phone tmp = phoneOBJ[i];
                            phoneOBJ[i] = phoneOBJ[j];
                            phoneOBJ[j] = tmp;
                        }
                    }
                }
            }
            break;
        case 6:
            {
                int n = getAllRecord(phoneOBJ);
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(phoneOBJ[i].group.at(0) < phoneOBJ[j].group.at(0))
                        {
                            phone tmp = phoneOBJ[i];
                            phoneOBJ[i] = phoneOBJ[j];
                            phoneOBJ[j] = tmp;
                        }
                    }
                }
            }
            break;
        case 7:
            break;
    }
}

void login(string RealUsername,string RealPassword)
{
    while(1)
    {
        string username,password="";
        cout<<"Enter UserName :";
        getline(cin,username);
        cout<<"Enter Password :";
        getline(cin,password);
        if(username == RealUsername && password == RealPassword)
        {
            system("CLS");
            cout<<"Welcome"<<"\n";
            break;
        }
        else
        {
            system("CLS");
            cout<<"username or password invalid."<<"\n";
        }
    }
}

void testProgram(phone phoneOBJ[100])
{
    phoneOBJ[0].name = "mehdi";
    phoneOBJ[0].family = "khosravi";
    phoneOBJ[0].middleName = "";
    phoneOBJ[0].email = "mahdi_khosravi@gmail.com";
    phoneOBJ[0].number = "091156464";
    phoneOBJ[0].group = "family";

    phoneOBJ[1].name = "ali";
    phoneOBJ[1].family = "alavi";
    phoneOBJ[1].middleName = "mohammadreza";
    phoneOBJ[1].email = "alavi@gmail.com";
    phoneOBJ[1].number = "091322222";
    phoneOBJ[1].group = "family";

    phoneOBJ[2].name = "mohsen";
    phoneOBJ[2].family = "ramzani";
    phoneOBJ[2].middleName = "amir";
    phoneOBJ[2].email = "mohsen@yahoo.com";
    phoneOBJ[2].number = "0912333333";
    phoneOBJ[2].group = "family";

    phoneOBJ[3].name = "reza";
    phoneOBJ[3].family = "rezae";
    phoneOBJ[3].middleName = "mohammadreza";
    phoneOBJ[3].email = "reza_rezae@gmail.com";
    phoneOBJ[3].number = "0911222222";
    phoneOBJ[3].group = "doost";

    phoneOBJ[4].name = "mohammd";
    phoneOBJ[4].family = "mohammadi";
    phoneOBJ[4].middleName = "mohammadreza";
    phoneOBJ[4].email = "mohammad@gmail.com";
    phoneOBJ[4].number = "09363333333";
    phoneOBJ[4].group = "doost";

    phoneOBJ[5].name = "hasan";
    phoneOBJ[5].family = "hossini";
    phoneOBJ[5].middleName = "amir";
    phoneOBJ[5].email = "hossini@gmail.com";
    phoneOBJ[5].number = "091255555555";
    phoneOBJ[5].group = "family";
}

int main()
{
    //login("admin","admin"); //This should not be Comment
	phone phoneOBJ[100];
	noneAll(phoneOBJ);
    testProgram(phoneOBJ);
	int menu=0;
	do
	{
	    TextTable t('-', '|', '+');
        cout<<"+-------- Menu --------+"<<"\n";
		cout<<"|1-insert              |"<<"\n";
		cout<<"|2-list                |"<<"\n";
		cout<<"|3-delete              |"<<"\n";
		cout<<"|4-search              |"<<"\n";
		cout<<"|5-edit                |"<<"\n";
		cout<<"|6-sort                |"<<"\n";
		cout<<"|7-clear Screen        |"<<"\n";
		cout<<"|8-exit                |"<<"\n";
		cout<<"|111-Delete All(danger)|"<<"\n";
		cout<<"|All("<<getAllRecord(phoneOBJ)<<")\t\t       |"<<"\n";
		cout<<"+----------------------+"<<"\n";
		cout<<"Enter :";
		cin>>menu;
		switch(menu)
		{
			case 1:
				add(phoneOBJ,getAllRecord(phoneOBJ));
				break;
			case 2:
				list(t,phoneOBJ);
				break;
			case 3:
				delet(phoneOBJ);
				break;
            case 4:
                searchh(t,phoneOBJ);
                break;
            case 5:
                edit(phoneOBJ);
                break;
			case 6:
                sortt(phoneOBJ);
				break;
			case 7:
                system("CLS");
				break;
            case 8:
				break;
            case 111:
                noneAll(phoneOBJ);
                break;
		}
	}while(menu!=8);
	return 0;
}


