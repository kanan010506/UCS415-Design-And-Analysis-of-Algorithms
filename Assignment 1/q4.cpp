#include<iostream>
using namespace std;

int main(){
  vector<int> arr = {-2, -5, 6, -2, -3, 1, 5, -6};
  int n = arr.size();
  vector<int> prefix(n+1,0);

  for(int i = 1; i <= n; i++){
    prefix[i] = prefix[i-1] + arr[i-1];
  }

  int minPrefix = 0;
  int sum = INT_MIN;

  for(int i = 1; i <= n; i++){
    sum = max(sum, prefix[i] - minPrefix);
    minPrefix = min(prefix[i], minPrefix);
  }

  cout<<sum;
  
  return 0;
}