/*
#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin >> n;
    int nse[n];
    int a[n];

    for(int i=0;i<=n;i++){
        cin >>a[i];
    }

    stack<int> st;

    for(int i=n-1; i>=0; i--){

        while(!st.empty() && st.top() >= a[i]){
            st.pop();
        }
        if(!st.empty()){
            nse[i] = st.top();
        }
        else{
            nse[i] = -1;
        }

        st.push(a[i]);
    }

    for(int i=0;i<n ;i++){
        cout<< a[i] <<" -> "<< nse[i] << endl;
    }


}

*/

// triverse the array from front 0 - n-1


#include<bits/stdc++.h>
using namespace std;

int main(){ 


    int n;
    cin >> n;
    vector<int> nge(n,-1);
    int a[n];

    for(int i=0;i<n;i++){
        cin >>a[i];
    }

    stack<int> st;

   for(int i=0 ;i <n;i++){
       while(!st.empty() && a[st.top()] >  a[i]){
           nge[st.top()] = a[i];
           st.pop();
       }

       st.push(i);

   }

    for(int i=0;i<n ;i++){
        cout<< a[i] <<" -> "<< nge[i] << endl;
    }


}

