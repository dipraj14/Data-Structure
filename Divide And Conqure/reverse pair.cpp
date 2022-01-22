

// leetcord hard --> https://leetcode.com/problems/reverse-pairs/

// this is written by me
#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> pr;
int marge(vector<int> &a, int n, int low, int high, int mid){

    int l = low;
    int r = mid + 1;
    int count =0;

    vector<int> temp;
    

    while(l<=mid && r<=high){
        if(a[l] <= a[r]){
            temp.push_back(a[l++]);
        }
        else{
            count+= mid- l + 1;   
            for(int i= l ;i<=mid; i++){
                pr.push_back({a[i],a[r]});

            }
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

int margesort(vector<int> &a, int n, int low, int high){

    if(low >= high){
        return 0;
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

    margesort(a,n, 0,n-1);
    int count =0;

    for(auto it: pr){
        //cout<< it.first <<" "<<it.second<<endl;
        if(it.first > 2*it.second){
            count++;
        }
    }

    cout<< count <<endl;
    

}



/*

// this is written by striver

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
int counting(vector<int> &a,int low, int mid, int high){
    int count =0;
    int l = low;
    int r = mid+1;
    for(int i=r; i<=high ;i++){
        while(l<=mid && a[l] <= 2*a[i]){
            l++;
            
        }
        count+= mid - l + 1;
        
    }
    return count;
}

int margesort(vector<int> &a, int n, int low, int high){

    if(low >= high){
        return 0;
    }
    int mid = (low+high) >> 1; // means (l+h)/2
    // once this solve 
    int left = margesort(a,n,low,mid);
    // then its solve
   int right =  margesort(a,n,mid+1,high);

   int cnt = counting(a,low, mid, high);

    marge(a,n,low,high,mid);

    return cnt+left+right;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    

    cout<< margesort(a,n,0,n-1);

   

    return 0;
}
*/