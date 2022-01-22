
#include <bits/stdc++.h>

using namespace std;

int apple(int input1,vector<int> &input2){
    int sum =0;
    for(int i=0;i<input1;i++){
        sum += input2[i];
        
    }
    int avg = sum/input1;
    int diff=0;
    for(int i=0;i<input1;i++){
        if(avg> input2[i]){
            diff+=abs(avg-input2[i]);
        }
    }
    return diff;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cout<< apple(n,a);

    return 0;
}
