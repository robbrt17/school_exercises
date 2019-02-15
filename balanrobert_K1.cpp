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

ifstream fin("input.dat");
ofstream fout("output.dat");

int read_data()
{
    fin>>n;
    while(true)
    {
        fin>>v[m].x;
        fin>>v[m].y;
        fin>>v[m].cost;
        m++;
        if(fin.eof()) break;
    }
    m=m-2;
    for(int i=1;i<=n;i++)
        l[i]=i;
    fin.close();
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
    int i=0;
    for(int j=1;j<=m;j++)
    {
        if(l[v[j].x]!=l[v[j].y])
        {
            cout<<v[j].x<<" "<<v[j].y<<endl;
            int z=l[v[j].y];
            i++;
            for(int k=1;k<=n;k++)
                if(l[k]==z)
                    l[k]=l[v[j].x];
        }
        if(i==n-1)
            break;
    }
}

int main()
{
    read_data();
    sort_data();
    arbori();
}
