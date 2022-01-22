/*

Question: 

Given a sorted array of n elements containing elements in range from 1 to n-1 i.e. 
one element occurs twice, the task is to find the repeating element in an array.


Input :  arr[] = { 1, 2 , 3 , 4 , 4}
Output :  4

Input :  arr[] = { 1 , 1 , 2 , 3 , 4}
Output :  1

Input:  {10 11 11 12 13 14} 
output: 11

Input:  {11 12 13 14 14 15}
output: 14

*/

#include <bits/stdc++.h>

using namespace std;

// its work onli 1 to n-1 array

int find_repeating(int a[],int l,int h){
      
      // l =0 // h =n-1
      
      if(l > h){
          return -1;
      }
      else{
          
          int mid = l+(h-l) / 2;
          
          if(a[mid] != a[0]+mid){  // if mid is not its postion  then check  left
              
              if(mid>0 && a[mid] == a[mid-1]){
                  return a[mid];
              }
              else{
                  return find_repeating(a , l ,mid-1);
              }
          }
          else{ // check right if mid is proper its postion 
              return find_repeating(a,mid+1,h);
          }
      }
 }

int main()
{   
  int n;
  cin >> n;
  
  int arr[n];
  
  for(int i=0;i<n;i++){  // only you have to input 1 to  n-1 element inn the array
      cin >> arr[i];
  }
  
  cout<< find_repeating(arr, 0 ,n-1);
  
  
}