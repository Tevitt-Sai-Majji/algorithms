/*Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] 
(up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient 
i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2

*/


#include<bits/stdc++.h> 
using namespace std; 


class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {
        int r=hospital.size();
        int c=hospital[0].size();
        vector<vector<bool>>vis;
        int tim=0;
        queue<vector<int>>q;
        for(int i=0;i<r;i++){
            vector<bool> visi;
            for(int j=0;j<c;j++){
                if (hospital[i][j]==2){
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(j);
                    q.push(v);
                    visi.push_back(true);
                }
                else{
                    visi.push_back(false);
                }
            }vis.push_back(visi);
        }
        while(q.size()!=0){
            int size=q.size();
            while(size--){
            vector<int>v;
            v=q.front();
            q.pop();
            if (v[0]!=0 && hospital[v[0]-1][v[1]]==1 && vis[v[0]-1][v[1]]==false){
                vector<int> ne;
                ne.push_back(v[0]-1);
                ne.push_back(v[1]);
                q.push(ne);
                vis[v[0]-1][v[1]]=true;
            }
            if (v[1]!=0 && hospital[v[0]][v[1]-1]==1 && vis[v[0]][v[1]-1]==false){
                vector<int> ne;
                ne.push_back(v[0]);
                ne.push_back(v[1]-1);
                q.push(ne);
                vis[v[0]][v[1]-1]=true;
            }
            if (v[0]!=r-1 && hospital[v[0]+1][v[1]]==1 && vis[v[0]+1][v[1]]==false){
                vector<int> ne;
                ne.push_back(v[0]+1);
                ne.push_back(v[1]);
                q.push(ne);
                vis[v[0]+1][v[1]]=true;
            }
            if (v[1]!=c-1 && hospital[v[0]][v[1]+1]==1 && vis[v[0]][v[1]+1]==false){
                vector<int> ne;
                ne.push_back(v[0]);
                ne.push_back(v[1]+1);
                q.push(ne);
                vis[v[0]][v[1]+1]=true;
            }
            }
            tim++;
        }
        tim--;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (hospital[i][j]==1 && vis[i][j]==false){
                    tim=-1;
                    break;
                }
            }
        }
        return tim;
      }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
          for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
