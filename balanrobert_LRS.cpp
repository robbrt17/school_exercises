#include <iostream>
#include <fstream>
using namespace std;

ifstream f("input.dat");

int n;
int INFO[100], STANGI[100], DREPTI[100];

int read_data()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>INFO[i];
    }
    for(int i=1;i<=n;i++)
    {
        f>>STANGI[i];
    }
    for(int i=1;i<=n;i++)
    {
        f>>DREPTI[i];
    }
}

int RSD(int node)
{
    cout<<INFO[node]<<" ";
    if(STANGI[node]!=0)
    {
        RSD(STANGI[node]);
    }
    if(DREPTI[node]!=0)
    {
        RSD(DREPTI[node]);
    }
}

int SRD(int node)
{
    if(STANGI[node]!=0)
    {
        SRD(STANGI[node]);
    }
    cout<<INFO[node]<<" ";
    if(DREPTI[node]!=0)
    {
        SRD(DREPTI[node]);
    }
}

int SDR(int node)
{
    if(STANGI[node]!=0)
    {
        SDR(STANGI[node]);
    }
    if(DREPTI[node]!=0)
    {
        SDR(DREPTI[node]);
    }
    cout<<INFO[node]<<" ";
}

int main()
{
    read_data();
    RSD(1);
    cout<<endl;
    SRD(1);
    cout<<endl;
    SDR(1);
}
