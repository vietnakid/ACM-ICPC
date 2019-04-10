#include <bits/stdc++.h>
using namespace std;
 
const int n=5;
string Names[]={"Thao","Bac","Khuyen","Hoa","Hoang"};   //1
string Ages[]={"19","22","16","25","28"};               //2
string Jobs[]={"Ca si","Hoa si","Dau bep","Y ta","Tho anh"};//1
string Clues[]={"Nau an","Party","Di cho","Chup anh","####"};//0
string Vehicles[]={"Xe buyt 1","Xe buyt 2","Xe may","Xe dap","O to"};//1
 
void Check()
{
    map<string,int> M;
    for(int i=0;i<5;i++)
    {
        M[Names[i]]=i+1;
        M[Ages[i]]=i+1;
        M[Jobs[i]]=i+1;
        M[Clues[i]]=i+1;
        M[Vehicles[i]]=i+1;
    }
    if(M["O to"]!=3)
        return;
    if(abs(M["Ca si"]-M["Party"])!=1)
        return;
    if(M["Tho anh"]!=M["Chup anh"])
        return;
    if(abs(M["Y ta"]-M["Di cho"])!=1)
        return;
    if(M["Hoa si"]!=M["Xe dap"])
        return;
    if(M["Hoang"]!=M["Nau an"])
        return;
    if(M["Bac"]!=M["25"])
        return;
    if(M["Xe may"]!=M["16"])
        return;
    if(M["Khuyen"]!=M["Dau bep"])
        return;
    if(abs(M["16"]-M["28"])!=1)
        return;
    if(M["Hoa"]!=M["Xe buyt 2"])
        return;
    for(int i=0;i<5;i++)
        cout<<Names[i]<<' '<<Ages[i]<<' '<<Jobs[i]<<' '<<Vehicles[i]<<' '<<Clues[i]<<"\n";
}
 
void Try()
{
    int Count=0;
    do
    {
        do
        {
            do
            {
                do
                {
                    do
                    {
                        Count++;
                        if(Count%int(1e5)==0)
                            cerr<<Count<<"\n";
                        Check();
                    }while(next_permutation(Vehicles+1,Vehicles+5));
                }while(next_permutation(Clues,Clues+5));
            }while(next_permutation(Jobs+1,Jobs+5));
        }while(next_permutation(Ages+2,Ages+5));
    }while(next_permutation(Names+1,Names+5));
}
 
void Init()
{
 
}
 
int main()
{
    sort(Names+1,Names+5);
    sort(Ages+2,Ages+5);
    sort(Jobs+1,Jobs+5);
    sort(Clues,Clues+5);
    sort(Vehicles+1,Vehicles+5);
    Try();
}
 