// NAME- SAARTHAK ARORA
// ROLL NO - 2010991696
// SET - 05
// Q2

#include <bits/stdc++.h>
using namespace std;


vector< pair<int, int> > findSub(int arr[], int n)
{
	
	unordered_map<int, vector<int> > map;

	
	vector <pair<int, int>> out;  // for containing the sub array strting index and ending index whose sum == 0

	
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		
		sum += arr[i];

		
		if (sum == 0)
			out.push_back(make_pair(0, i));

		
		if (map.find(sum) != map.end())
		{
			
			vector<int> vc = map[sum];
			for (auto it = vc.begin(); it != vc.end(); it++)
				out.push_back(make_pair(*it + 1, i));
		}
		map[sum].push_back(i);
	}

	
	return out;
}


// for printing the output sub arrays
void print(vector<pair<int, int>> out,int arr[])
{
    cout<<"required output is "<<endl;
	for (auto it = out.begin(); it != out.end(); it++){
        for(int i =it->first;i<=it->second;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
		
       
}


int main()
{
	
    int n;
    try{
    cout<<"enter size of array ";
    cin>>n;

    
    if(n == 0){
        throw n;
    }
       int arr[n];
       cout<<"enter element of array "<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        
       
	vector<pair<int, int> > ot = findSub(arr, n);

        if(ot.size() == 0){
            cout<<"na "<<endl;
        }
        else{
            print(ot,arr);
        }

    }
    catch(int x){ // if n ==0 this will show error message
        cout<<"invalid input- give array size > 0"<<endl;
    }

	
	

	return 0;
}
