#include<iostream>
using namespace std;
void print(int a[],int lo,int hi)
{
    cout << endl;
    for(int i=lo;i<=hi;i++)
        cout << a[i] << " ";
    cout << endl;
}
void insertion_item(int a[],int lo,int hi,int item)
{
    int j=hi;
    while(j>=lo && a[j]>item)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=item;
}
void insertion_sort(int a[],int lo,int hi)
{
    for(int i=lo+1;i<=hi;i++)
        insertion_item(a,lo,i-1,a[i]);
}
int main()
{
    int a[]={20,5,1,8,12,4,9,6,11};
    cout << "Before sorting:" << endl;
    print(a,0,8);
    insertion_sort(a,0,8);
    cout << "After sorting:" << endl;
    print(a,0,8);
    return(0);
}