
#include <bits/stdc++.h>

using namespace std;

void marge(vector<int> &a, int n, int low, int high, int mid){

    int l = low;
    int r = mid + 1;

    vector<int> temp;

    while(l<=mid && r<=high){
        if(a[l] <= a[r]){
            temp.push_back(a[l++]);
        }
        else{
            temp.push_back(a[r++]);
        }
    }
    // if left run out and we still somwthing have left
    while(l<=mid){
        temp.push_back(a[l++]);
    }
    // same as if right run out and we still somwthing have right
    while(r<=high){
        temp.push_back(a[r++]);
    }
    // int j=0;
    for(int i=low; i<=high; i++){
        a[i] = temp[i - low];   // tepm[low-low], temp[low + 1 -low], temp[low + 2 -low], temp[low + 3 -low]......

        // its also correct
        //a[i]= temp[j++];
    }
}

void margesort(vector<int> &a, int n, int low, int high){

    if(low >= high){
        return;
    }
    int mid = (low+high) >> 1; // means (l+h)/2
    // once this solve 
    margesort(a,n,low,mid);
    // then its solve
    margesort(a,n,mid+1,high);

    marge(a,n,low,high,mid);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    

    margesort(a,n,0,n-1);

    for(int i=0;i<n;i++){
        cout << a[i] <<" ";
    }

    return 0;
}
