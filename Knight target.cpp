#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool check(vector<int>&KnightPos,vector<vector<int>>&vis,int i,int j,int n){
        if((i==KnightPos[0] && j==KnightPos[1])||i<1||j<1||i>n||j>n||vis[i][j]!=0) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    if (KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1]) return 0;
	    queue<pair<int,int>> q;
	    vector<vector<int>> vis(N+1,vector<int>(N+1,0));
	    q.push({KnightPos[0],KnightPos[1]});
      while(q.size()!=0){
	        auto pr=q.front();
	        int i=pr.first;
	        int j=pr.second;
	        q.pop();
	        if (check(KnightPos,vis,i+2,j+1,N)){
	            vis[i+2][j+1]=vis[i][j]+1;
	            q.push({i+2,j+1});
	            if (i+2==TargetPos[0] && j+1==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i+2,j-1,N)){
	            vis[i+2][j-1]=vis[i][j]+1;
	            q.push({i+2,j-1});
	            if (i+2==TargetPos[0] && j-1==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i-2,j+1,N)){
	            vis[i-2][j+1]=vis[i][j]+1;
	            q.push({i-2,j+1});
              if (i-2==TargetPos[0] && j+1==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i-2,j-1,N)){
	            vis[i-2][j-1]=vis[i][j]+1;
	            q.push({i-2,j-1});
	            if (i-2==TargetPos[0] && j-1==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i+1,j+2,N)){
	            vis[i+1][j+2]=vis[i][j]+1;
	            q.push({i+1,j+2});
	            if (i+1==TargetPos[0] && j+2==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i+1,j-2,N)){
	            vis[i+1][j-2]=vis[i][j]+1;
	            q.push({i+1,j-2});
	            if (i+1==TargetPos[0] && j-2==TargetPos[1])break;
	        }
          if (check(KnightPos,vis,i-1,j+2,N)){
	            vis[i-1][j+2]=vis[i][j]+1;
	            q.push({i-1,j+2});
	            if (i-1==TargetPos[0] && j+2==TargetPos[1])break;
	        }
	        if (check(KnightPos,vis,i-1,j-2,N)){
	            vis[i-1][j-2]=vis[i][j]+1;
	            q.push({i-1,j-2});
	            if (i-1==TargetPos[0] && j-2==TargetPos[1])break;
	        }
	    }
	    return vis[TargetPos[0]][TargetPos[1]];
	    // Code here
	}
};
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
} 
