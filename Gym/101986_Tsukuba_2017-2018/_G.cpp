#include <bits/stdc++.h>
using namespace std;

const long double PI=acos(-1);
int d1,d2,l1,l2,ID[5][5];
string s1,s2;

long double DtoR(long double d)
{
    return d*PI/180.0;
}

void Init()
{
    ID[0][0]=1,ID[0][1]=2,ID[0][2]=4,ID[0][3]=3;
    ID[1][0]=4,ID[1][1]=2,ID[1][2]=1,ID[1][3]=3;
    ID[2][0]=4,ID[2][1]=3,ID[2][2]=1,ID[2][3]=2;
    ID[3][0]=1,ID[3][1]=3,ID[3][2]=4,ID[3][3]=2;
}

int Cal(long double d,long double l)
{
    int x=(long double)(l*cos(DtoR(abs(d-30))))/(long double)(sqrt(3.0)/2.0);
    int y=(-int((long double)(l*sin(DtoR(60.0-d)))/(long double)(sin(DtoR(120.0))))+int((long double)(l*sin(DtoR(d)))/sin(DtoR(120.0))))%4+4;
    return ID[x%4][y%4];
}

int Convert(int id)
{
    return (id<=3?id%3+1:4);
}

int main()
{
    Init();
    cin>>s1>>d1>>l1>>s2>>d2>>l2;
    int tmp1=Cal(d1,l1),tmp2=Cal(d2,l2);
    if(s1!=s2)
    {
        if(s1[1]==s2[0])
            tmp2=Convert(tmp2);
        else
            tmp1=Convert(tmp1);
    }
    cout<<(tmp1==tmp2?"YES":"NO");
}