#include<fstream>
#include<iostream>
using namespace std;
int n, m=1;
int top;
int l[100];

typedef struct
{
    int x;
    int y;
    double cost;
}muchie;

muchie v[100];

ifstream f("input.dat");
ofstream g("output.dat");

int read_data()
{
    f>>n;
    while(true)
    {
        f>>v[m].x;
        f>>v[m].y;
        f>>v[m].cost;
        m++;
        if(f.eof()) break;
    }
    m=m-2;
    for(int i=1;i<=n;i++)
        l[i]=i;
    f.close();
    return 0;
}

int sort_data()
{
    int g=0;
    while(g==0)
    {
        g=1;
        for(int i=1;i<m;i++)
            if(v[i].cost>v[i+1].cost)
            {
                swap(v[i].cost,v[i+1].cost);
                swap(v[i].x,v[i+1].x);
                swap(v[i].y,v[i+1].y);
                g=0;
            }
    }
}

int arbori()
{
    int s,d;
    cout<<v[1].x<<" "<<v[1].y<<endl;
    s=v[1].x;
    d=v[1].y;
    for(int i=1;i<n;i++)
    {for(int j=2;j<=m;j++)
    {
        if(l[v[j].x]!=l[v[j].y] && (v[j].x==s || v[j].y==s || v[j].x==d || v[j].y==d))
        {
            if(v[j].x==s)
                s=v[j].y;
            if(v[j].y==d)
                d=v[j].x;
            cout<<v[j].x<<" "<<v[j].y<<endl;
            int z=l[v[j].y];
            for(int k=1;k<=n;k++)
                if(l[k]==z)
                    l[k]=l[v[j].x];
            i=1;
            j=2;
        }
    }}
}

int main()
{
    read_data();
    sort_data();
    arbori();
}
