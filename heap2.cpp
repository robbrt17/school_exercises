#include<iostream>
using namespace std;
int n=5;
int M[100]={35565,533,244,104,87,18};


int makeheap(int nume_nod,int heap_size)
{
    if (nume_nod<=heap_size)
    { cout<<M[nume_nod]<<" ";
       makeheap(nume_nod*2,heap_size);
       makeheap(nume_nod*2+1,heap_size);}
}

int main()
{
   makeheap(1,n);
}
