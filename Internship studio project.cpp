#include <iostream>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

static int p=0;

class a
{
    char roomn[5], host[10], start[5], send[5], from[10], to[10], chair[8][4][10];
    public:
    void install();
    void allotment();
    void empty();
    void show();
    void avail();
    void position(int i);
}

room[10];

void vline(char ch)
{
    for(int i=80;i>0;i--)
    cout<<ch;
}

void a::install()
{
    cout<<"Enter room number : ";
    cin>>room[p].roomn;
    cout<<"\n";
    cout<<"Enter the host's name : ";
    cin>>room[p].host;
    cout<<"\n";
    cout<<"Start time : ";
    cin>>room[p].start;
    cout<<"\n";
    cout<<"Session ends at : ";
    cin>>room[p].send;
    cout<<"\n";
    cout<<"From : ";
    cin>>room[p].from;
    cout<<"\n";
    cout<<"To : ";
    cin>>room[p].to;
    cout<<"\n";
    room[p].empty();
    p++;
}

void a::allotment()
{
    int chair;
    char number[5];
    top:
    cout<<"Room no : ";
    cin>>number;
    int n;
    for(n=0;n<=p;n++)
    {
        if(strcmp(room[n].roomn, number)==0)    //strcmp means it compares characters in two arrays 
        break;
    }
    while(n<=p)
    {
        cout<<"\nChair number : ";
        cin>>chair;
        if(chair>32)
        {
            cout<<"\nThere are only 32 chairs available in this room.";
        }
        else
        {
            if (strcmp(room[n].chair[chair/4][(chair%4)-1], "Empty")==0)
            {
                cout<<"Enter passengers name : ";
                cin>>room[n].chair[chair/4][(chair%4)-1];
                break;
            }
            else
            cout<<"The chair number is already reserved."<<endl;
        }
    }
    if(n>p)
    {
        cout<<"Enter correct room number"<<endl;
        goto  top;
    }
}

void a::empty()
{
    for(int i=0; i<8 ;i++)
    {
        for(int j=0; j<4 ;j++)
        {
            strcpy(room[p].chair[i][j],"Empty");      //strcpy means used to copy one string to another
        }
    }
}

void a::show()
{
    int n;
    char number[5];
    cout<<"Enter room number : ";
    cin>>number;
    cout<<"\n";
    for(n=0 ; n<=p ; n++)
    {
        if(strcmp(room[n].roomn, number)==0)
        break;
    }
    while(n<=p)
    {
        vline('*');
        cout<<"\n";
        cout<<"Room number : \t"<<room[n].roomn<<"\nHost : \t"<<room[n].host<<"\t\tStart time : \t"<<room[n].start<<"\t End time : "<<room[n].send<<"\nFrom : \t\t"<<room[n].from<<"\t\tTo : \t\t"<<room[n].to<<"\n";
        vline('*');
        room[0].position(n);
        int a=1;
        for (int i=0 ; i<8 ; i++)
        {
            for(int j=0 ; j<4 ; j++)
            {
                a++;
                if(strcmp(room[n].chair[i][j],"Empty")!=0)
                cout<<"\nThe chair number "<<(a-1)<<" is reserved for "<<room[n].chair[i][j]<<"."<<endl;
            }
        }
        break;
    }
    if(n>p)
    cout<<"Enter correct room number : ";
}

void a::position(int i)
{
    int s=0;p=0;
    for(int i=0; i<8; i++)
    {
        cout<<"\n";
        for(int j=0; j<4; j++)
        {
            s++;
            if(strcmp(room[1].chair[i][j],"Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<room[1].chair[i][j];
                p++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<s<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<room[1].chair[i][j];
            }
        }
    }
    cout<<"\n\nThere are "<<p<<" Chairs empty in room no: "<<room[1].roomn;
}

void a::avail()
{
    for(int n=0; n<p; n++)
    {
        vline('*');
        cout<<"Room no: \t"<<room[n].roomn<<"\nHost: \t"<<room[n].host<<"\t\tStart time: \t"<<room[n].start<<"\tEnd time: \t"<<room[n].send<<"\nFrom: \t\t"<<room[n].from<<"\t\tTo: \t\t\t"<<room[n].to<<"\n";
        vline('*');
        vline('_');
    }
}

int main()
{
    cout<<"***** Room Allotment and booking system using advance DSA Concepts and Multiple parameters IS C++ *****"<<endl;
    cout<<"=================***************====================*****************===================*************"<<endl;
    //system("cls");
    int w;
    while(1)
    {
        cout<<"\n";
        cout<<"1.Install\n"<<"2.Registration\n"<<"3.Show\n"<<"4.Rooms available\n" <<"5.Exit";
        cout<<"\nEnter your choise - ";
        cin>>w;
        switch(w)
        {
            case 1:
            {
            room[p].install();
            break;
            }
            case 2:
            {
            room[p].allotment();
            break;
            }
            case 3:
            {
            room[0].show();
            break;
            }
            case 4:
            {
            room[0].avail();
            break;
            }
            case 5:
            {
                exit(0);
            }
        }
    }
    return 0;
}














































































