#include<iostream>
using namespace std;
/*
    Day la ham tim kiem tuan tu
    a la mang chua cac so nguyen
    key: gia tri can tim
    lo: chi so thap nhat cua mang
    hi: chi so cao nhat
    tra ve: chi so tim thay hoac -1 neu ko thay
*/
int search(int a[],int key,int lo,int hi)
{
    if(lo>hi) return(-1);
    for(int i=lo;i<=hi;i++)
    {
        cout << "tuan tu so sanh" << endl;
        if(key==a[i]) return(i);
    }
    return(-1);
}
int binary_search(int a[],int key,int lo,int hi)
{
    if(lo>hi) return(-1);
    while(lo<=hi)
    {
        cout << "nhi phan so sanh" << endl;
        int mid=(lo+hi)/2;
        if(key==a[mid]) return(mid);
        else 
        {
            if(key<a[mid]) hi=mid-1;
            else lo=mid+1;
        }
    }
    return(-1);
}
int main()
{
    int a[]={2,5,8,10,20,25};
    cout << "Tuan tu KQ:" << search(a,20,0,5);
    cout << "Nhi phan KQ:" << binary_search(a,20,0,5);
    return(0);
}