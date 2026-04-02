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
void selection_sort_index(int a[],int lo,int hi)
{
    for(int i=lo;i<hi;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<=hi;j++)
            if(a[j]<a[minIndex])
                minIndex=j;
        if(minIndex!=i)
                {
                    int tmp=a[i];
                    a[i]=a[minIndex];
                    a[minIndex]=tmp;
                }
    }
}
void selection_sort_recursive(int a[],int lo,int hi)
{
    if(lo<hi)
    {
        int minIndex=lo;
        for(int j=lo+1;j<=hi;j++)
            if(a[j]<a[minIndex])
                minIndex=j;
        if(minIndex!=lo)
                {
                    int tmp=a[lo];
                    a[lo]=a[minIndex];
                    a[minIndex]=tmp;
                }
        selection_sort_recursive(a,lo+1,hi);
    }
}
int main()
{
    int a[]={20,5,1,8,12,4,9,6,11};
    int b[]={20,5,1,8,12,4,9,6,11};
    int c[]={20,5,1,8,12,4,9,6,11};
    cout << "Before sorting:" << endl;
    print(a,0,8);
    selection_sort(a,0,8);
    selection_sort_index(b,0,8);
    selection_sort_recursive(c,0,8);
    cout << "After sorting:" << endl;
    print(a,0,8);
    print(b,0,8);
    print(c,0,8);
    return(0);
}