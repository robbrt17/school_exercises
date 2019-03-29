#include<iostream>
using namespace std;
int n=5;
int poz=1;
int M[100]={35565,533,244,104,87,18};
int heap[100];

int insert_into_heap(int value)
{
    while(value<=n)
    {
        heap[value]=M[value];
        value++;
    }
}
int main()
{
     insert_into_heap(1);
    for(int i=1;i<=n;i++)
      cout<<heap[i]<<" ";
}
