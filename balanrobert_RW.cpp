#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.txt");

int n;
int M[100][100];
int drum[100][100];

void read_data()
{
    fin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>M[i][j];
}

int conversie()
{
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if(k!=i && k!=j && i!=j) {
                        if(M[i][k]!=0 && M[k][j]!=0) {
                            if(M[i][k]<=M[k][j]) M[i][j]=M[i][k];
                            if(M[i][k]>M[k][j]) M[i][j]=M[k][j];
                        }
                    }
            }
        }
    }
}

int main()
{
    read_data();
    conversie();

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
