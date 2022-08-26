// NAME- SAARTHAK ARORA
// ROLL NO - 2010991696
// SET - 05
// Q1  find maxlength subarray having given sum

#include <bits/stdc++.h>
using namespace std;
int findMaxLength(int arr[],int n,int k){
    int sum = 0 ; 
    int maxL = 0 ;  
    unordered_map<int,int> mp;  // for storing the vlaue of sum upto that particular index of arr
    pair<int,int> p = make_pair(0,0);  // for storing the starting and ending index of sub arr
    for(int i =0;i<n;i++){
        sum += arr[i];
        if(sum == k){
            maxL = i+1;
            p.first = 0;
            p.second = i;
        }
        if(mp.find(sum) == mp.end()){  // if not in mp then add its entry
            mp[sum] = i;
        }
        if(mp.find(sum-k) != mp.end()){
            if(maxL < i-mp[sum - k]){
                maxL = i-mp[sum - k];
                p.first = mp[sum - k];
                p.second = i;
            }
        }
    }
 
 // printing the subarray elements
 cout<<"reqiured output = "<<endl;
    for(int i =p.first+1 ;i<=p.second;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // printing the length of subarray
    cout<<"maxlength = "<<maxL<<endl;
        
}
int main(){

    // taking input
    int n,k;
    try{
    cout<<"enter size of array ";
    cin>>n;
    cout<<"enter target value ";
    cin>>k;
    if(n == 0){
        throw n;
    }
       int arr[n];
       cout<<"enter element of array "<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        // calling function for finding maxlength 
         findMaxLength(arr,n,k);
        

    }
    catch(int x){ // if n ==0 this will show error message
        cout<<"invalid input- give array size > 0"<<endl;
    }


    return 0;
}

