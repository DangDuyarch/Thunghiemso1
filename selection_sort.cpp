#include<iostream>
using namespace std;
void print(int a[],int lo,int hi)
{
    cout << endl;
    for(int i=lo;i<=hi;i++)
        cout << a[i] << " ";
    cout << endl;
}
void selection_sort(int a[],int lo,int hi)
{
    for(int i=lo;i<hi;i++)
        for(int j=i+1;j<=hi;j++)
            if(a[j]<a[i])
                {
                    int tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }
}
int main()
{
    int a[]={20,5,1,8,12,4,9,6,11};
    cout << "Before sorting:" << endl;
    print(a,0,8);
    selection_sort(a,0,8);
    cout << "After sorting:" << endl;
    print(a,0,8);
    return(0);
}