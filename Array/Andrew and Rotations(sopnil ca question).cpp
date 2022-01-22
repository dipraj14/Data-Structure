
/*

Andrew and Rotations:


Andrew was going through the topic of array rotations when he came across a peculiar problem. 
The problem was given a list of distinct random numbers, if the maximum number lies before the minimum number in the list, 
then the list should be left rotated by the difference between the maximum and minimum. On the other hand,
 if the maximum number lies after the minimum number in the list, then the list should be right rotated by the difference between 
 the maximum and minimum. Since Andrew is new to programming, help him by writing a program.

Input Format

The first line of input consists of an integer n which is the total number of elements in the list.
 The next line contains n space separated integers.

Constraints

1 <= N <= 100000
1 <= array elements <= 100000

Output Format

In case the maximum number lies before the minimum number in the list,
 then left rotate the list by the difference between the maximum and 
 the minimum number and print the output otherwise right rotate the list and print the output.

Sample Input 0

5
1 2 3 4 5
Sample Output 0

2 3 4 5 1
Explanation 0

In this sample test case, the minimum element is 1 and the maximum element is 5. 
The difference between these two is 4. Since, the maximum element comes after the minimum, 
hence the list will be right rotated 4 times.





*/


#include <bits/stdc++.h>
using namespace std;

void rev(int arr[], int n,int left, int right){
    
    while(left< right){
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    
}

void right_Rotate(int a[],int n,int k){
    
    k = k%n;
    
    rev(a,n,0,n-1);
    rev(a,n,0,k-1);
    rev(a,n,k,n-1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
}

void left_Rotate(int a[],int n,int k){
    
    k = k%n;
    
    rev(a,n,0,n-1);
    rev(a,n,0,n-k-1);
    rev(a,n,n-k,n-1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    
}


int main() {
   
    
    int n;
    cin>>n;
  
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int maxi =INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i <n;i++){
        mini = min(arr[i],mini);
        maxi= max(arr[i],maxi);
    }
    
    int maxi_idx, mini_idx;

    for(int i=0;i <n;i++){
        if(maxi == arr[i]){
            maxi_idx = i;
        }
        if(mini == arr[i]){
            mini_idx = i;
        }
    }

    if(maxi_idx > mini_idx){
        int k = maxi-mini;
        right_Rotate(arr,n,k);

    }
    else{
        int k = maxi-mini;
        left_Rotate(arr,n,k);

    }

    
}


