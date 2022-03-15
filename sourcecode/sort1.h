#include<bits/stdc++.h>
using namespace std; 
void Merge(ll arr[],int left,int mid, int right){
    ll *tmp=new ll[right-left+1];
    int j=mid+1,cur=0;
    for(int i=left;i<=mid;i++)
    {
        while(j<=right&&arr[i]>arr[j])
        {
            tmp[cur++]=arr[j];
            j++;
        }
        tmp[cur++]=arr[i];
    }
    for(int i=left;i<=right;i++)
    {
        arr[i]=tmp[i-left];
    }
    delete[]tmp;
 }
void MergeSort(ll arr[], int left, int right){
    if(left >= right)   return;
    int mid=(right-left)/2+left;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid+1,right);
    Merge(arr,left,mid,right);
}
void heapify(ll arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void HeapSort(ll arr[],int q,int n)
{
    n++;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int part(ll arr[],int left, int right){
    ll val=arr[(left+right)>>1];
    int current=left;
    for(int i=left;i<=right;i++)
        if(arr[i]<=val)  swap(arr[i],arr[current++]);
    return current;
}
void QuickSort(ll arr[], int left, int right){
    if(left>=right) return;
    int p=part(arr,left,right);
    QuickSort(arr,left, p-2);
    QuickSort(arr, p, right);
}
void SortCpp(ll  arr[], int left, int right){
    right++; 
    sort(arr+left,arr+right);
}