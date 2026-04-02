#include<iostream>
#include<chrono>
#include<vector>
using namespace std;

void print(int a[],int lo,int hi)
{
    cout << endl;
    for(int i=lo;i<=hi;i++)
        cout << a[i] << " ";
    cout << endl;
}
void fillArr(vector<int> &a,vector<int> &b,vector<int> &c,vector<int> &d, int low,int hi)
{

    for(int i=low;i<=hi;i++)
        a[i]=b[i]=c[i]=d[i]=rand();
}
void merge(int a[],int lo,int mid,int hi)
{
    int i=lo,j=mid+1,k=0;
    int *tmp=new int[hi-lo+1];
    while(i<=mid && j<=hi)
        if(a[i]<a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=hi)
        tmp[k++]=a[j++];
    for(i=lo,k=0;i<=hi;i++,k++)
        a[i]=tmp[k];
    delete[] tmp;
}
void merge1(int a[],int lo,int mid,int hi,int tmp[])
{
    int i=lo,j=mid+1,k=lo;
    //int *tmp=new int[hi-lo+1];
    while(i<=mid && j<=hi)
        if(a[i]<a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=hi)
        tmp[k++]=a[j++];
    for(i=lo,k=lo;i<=hi;i++,k++)
        a[i]=tmp[k];
    //delete[] tmp;
}
void merge_sort(int a[],int lo,int hi)
{
    if(lo<hi)
    {
        int mid=(lo+hi)/2;
        merge_sort(a,lo,mid);
        merge_sort(a,mid+1,hi);
        merge(a,lo,mid,hi);
    }
}
void merge_sort1(int a[],int lo,int hi,int tmp[])
{
    if(lo<hi)
    {
        int mid=(lo+hi)/2;
        merge_sort1(a,lo,mid,tmp);
        merge_sort1(a,mid+1,hi,tmp);
        merge1(a,lo,mid,hi,tmp);
    }
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
int main()
{
    std::vector<int> A(200001),B(200001),C(200001),D(200001),tmp(200001);
    fillArr(A,B,C,D,0,200000);
    auto start=chrono::high_resolution_clock::now();
    merge_sort(A.data(),0,200000); 
    auto end=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    std::cout << "Merge Sort Time: " << duration.count() << " ms" << std::endl;
    start=chrono::high_resolution_clock::now();
    selection_sort(B.data(),0,200000); 
    end=chrono::high_resolution_clock::now();   
    duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    std::cout << "Selection Sort Time: " << duration.count() << " ms" << std::endl;
    start=chrono::high_resolution_clock::now(); 
    selection_sort_index(C.data(),0,200000); 
    end=chrono::high_resolution_clock::now();
    duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    std::cout << "Selection Sort Index Time: " << duration.count() << " ms" << std::endl;
    start=chrono::high_resolution_clock::now();
    merge_sort1(D.data(),0,200000,tmp.data()); 
    end=chrono::high_resolution_clock::now();
    duration=chrono::duration_cast<chrono::milliseconds>(end-start);
    std::cout << "Merge Sort 1 Time: " << duration.count() << " ms" << std::endl;   
    return(0);
}