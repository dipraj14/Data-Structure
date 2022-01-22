
#include <bits/stdc++.h>

using namespace std;

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
            count+= mid- l + 1;   // if any position a[l] > a[r]  then all the elemtnt [l(that postion)...mid] also graterthan 
                                        // 2 5 1 // l = 0
                                    // example ... [2 5]  [1] // if 2 is greater than one then 5 is also greater than one because array are aorted
                                    // here mid = 1;  count += 1 - 0 + 1 ,so count =2,
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

    return count;
}

int margesort(vector<int> &a, int n, int low, int high){

    if(low >= high){
        return 0;
    }
    int mid = (low+high) >> 1; // means (l+h)/2

    // once this solve 

   int left= margesort(a,n,low,mid);

    // then its solve
   int right= margesort(a,n,mid+1,high);

    int count = marge(a,n,low,high,mid);

    return (count+ left+ right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    

   cout<< "Inversion = "<<  margesort(a,n,0,n-1);                                    // for 2 5 1 3 4 6
                                                    //                                   /      \
                                        //after marging              [1,2,5]           [2,5,1]     [3,4,6]
                                               //                                      /    \       /     \
 // count=2 because 2>1 and 5>1 here mid = 1;  count += 1 - 0 + 1 ,so count =2,     [2,5]    [1]   [3,4]   [6]
                                               //                                    /  \           / \
                                               //                                    2   5         3   4


                                                //                    [1,2,5]   [3,4,6 ]    // last step of marging

                                                //                    1>3 1>4 1>5  2>3 2>4 2>6  // all false
                                                //                    5>3 5>4 // true so count = 2(previous count) + 1+ 1 
                                                //                    5> 6 // flase
    return 0;
}                                               // total count = 4
