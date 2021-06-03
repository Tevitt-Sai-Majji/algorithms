#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minThrow(int N, int arr[]){
        vector<int>vis(31,0);
        vector<bool>visited(31,false);
        for(int i=0;i<(2*N);i+=2){
            if(arr[i]<arr[i+1])vis[arr[i]]=arr[i+1];
            else vis[arr[i]]=-1;
        }
        //for(int i=0;i<31;i++)cout<<vis[i]<<" ";
        //cout<<"\n";
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while (q.size()!=0){
            int i=q.front();
            q.pop();
            for(int k=1;k<7;k++){
                if((i+k)<31 && vis[i+k]==0 && visited[i+k]==false){
                    vis[i+k]=vis[i]+1;
                    visited[i+k]=true;
                    q.push(i+k);
                }
                else if((i+k)<31 && vis[i+k]>0 && vis[i+k]<31 && visited[i+k]==false){
                    int j=vis[i+k];
                    vis[i+k]=vis[i]+1;
                    visited[i+k]=true;
                    vis[j]=vis[i]+1;
                    visited[j]=true;
                    q.push(j);
                }
                }
            //if(king>0){
            //for(int l=0;l<31;l++)cout<<vis[l]<<" ";
            //   cout<<"\n";king--;}
        }
        //for(int i=0;i<31;i++)cout<<vis[i]<<" ";
        //cout<<"\n";
        return vis[30];
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
