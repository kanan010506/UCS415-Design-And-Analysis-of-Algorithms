#include<iostream>
using namespace std;

int binarySearch(int arr[], int target, int left, int right){
  int mid = left + (right - left) / 2;
  if(right < left){
    return -1;
  }
  else if(arr[mid] == target){
    return mid;
  }
  else if (arr[mid] < target){
    return binarySearch(arr,target,mid+1,right);
  }
  else{
    return binarySearch(arr,target,left,mid-1);
  }
}

int main(){
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int n = sizeof(arr)/sizeof(arr[0]);
  int target = 23;
  cout<<"Target is forund at index : "<<binarySearch(arr,target,0,n-1)<<endl;
  return 0;
}