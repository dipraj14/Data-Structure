
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int a[n];
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int min_n = INT_MAX;
    
    int max_n = INT_MIN;
    
     for(int i=0;i<n;i++){
        min_n = min(a[i], min_n);
    
        max_n = max(a[i], max_n);
    }
    
    cout<< "min ele: "<< min_n<<endl;
    cout<< "max ele: "<< max_n;
    
    

    return 0;
}


