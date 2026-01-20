#include<iostream>
using namespace std;

int partition(int arr[], int l, int h){
  int pivot = arr[l];
  int i = l, j = h;
  while(i < j){
    do{
      i++;
    }while(arr[i] <= pivot);
    do{
      j--;
    }while(arr[j] > pivot);
    if(i < j){
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[l], arr[j]);
  return j;
}

void quickSort(int arr[], int l, int h){
  if(l < h){
    int j = partition(arr, l , h);
    quickSort(arr, l, j);
    quickSort(arr, j+1, h);
  }
}

int main(){
  int arr[] = { 4, 2, 6, 9, 2 };
  int n = sizeof(arr)/ sizeof(arr[0]);
  quickSort(arr, 0, n);
  for(int i = 0; i < n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}