#include<iostream>
using namespace std;
int binary_search(int a[],int key,int lo,int hi)
{
    if(lo>hi) return -1; // ko thay
    int mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(key==a[mid])
            return(mid);
        else 
        {
            if(key<a[mid])
                hi=mid-1;
            else
                lo=mid+1;
        }
    }
    return(-1);
}
int recursion_binary_search(int a[],int key,int lo,int hi)
{
    cout << "called function" << endl;
    if(lo > hi)
        return(-1);
    else
    {
        int mid=(lo+hi)/2;
        if(key==a[mid]) return(mid);
        else if(key<a[mid]) return(recursion_binary_search(a,key,lo,mid-1));
             else return(recursion_binary_search(a,key,mid+1,hi));
    }
}
int main(int argc,char* argv[])
{

    int a[]={2,5,6,8,10,15,20,25,27,29};
    int key=8;
    if(argc>1)
        key=atoi(argv[1]);
    cout << "result:" << binary_search(a,key,0,9) << endl;
    cout << "recursive result:" << recursion_binary_search(a,key,0,9) << endl;
    return(0);
}