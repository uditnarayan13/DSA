#include<iostream>
#include<bits/stdc++.h>
 using namespace std;


 int main(){
    
    vector<int> arr = {1,1,3,2,1,0};
    int k =3;

    priority_queue<pair<int, int>>q;
    vector<int>ans;
    for(int i=0; i<k; i++){q.push({arr[i], i});}
    ans.push_back(q.top().first);
    for(int i=k; i<arr.size(); i++){
        q.push({arr[i], i});
        while(q.top().second<=i-k){
            cout<<"i "<<i<<" q.top.first "<<q.top().first<<"\n";
            q.pop();
        }
        ans.push_back(q.top().first);
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


 }