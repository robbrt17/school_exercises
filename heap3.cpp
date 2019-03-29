#include<iostream>
using namespace std;
int n=5;
int poz=1;
int M[100]={35565,533,244,104,87,18};


int find_heap(int nume_nod,int heap_size,int value)
{
    if(M[nume_nod]==value)
        {cout<<poz; return 1;}
    else
    {

        if(nume_nod<=heap_size)
        {
            poz=poz*10+1;
        find_heap(nume_nod*2, heap_size, value);
        poz=(poz/10)*10;
        find_heap(nume_nod*2+1, heap_size, value);}
    }
    return 0;
}

int main()
{
   cout<<"Some huffman code : "<<endl;
   find_heap(1,n,87);
}
