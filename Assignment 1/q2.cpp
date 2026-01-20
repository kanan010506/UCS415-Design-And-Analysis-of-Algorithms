#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
  int n1 = m - l + 1;
  int n2 = h - m;
  int L[n1], R[n2];
  for(int i = 0; i < n1; i++){
    L[i] = arr[l+i];
  }
  for(int i = 0; i < n2; i++){
    R[i] = arr[m+1+i];
  }
  int i = 0, j = 0, k = l;
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      arr[k++] = L[i++];
    }
    else{
      arr[k++] = R[j++];
    }
  }
  while(i < n1){
    arr[k++] = L[i++];
  }
  while(j < n2){
    arr[k++] = R[j++];
  }
}

void mergeSort(int arr[], int l, int h){
  if(l < h){
    int m = l + ( h - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, h);
    merge(arr, l, m ,h);
  }
}

int main(){
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr2[] = {38, 27, 43, 3, 9, 82, 10};
  int n1 = sizeof(arr) / sizeof(arr[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  mergeSort(arr, 0, n1-1);
  mergeSort(arr2, 0, n2-1);
  for(int i = 0; i < n1; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int i = 0; i < n2; i++){
    cout<<arr2[i]<<" ";
  }

  return 0;
}