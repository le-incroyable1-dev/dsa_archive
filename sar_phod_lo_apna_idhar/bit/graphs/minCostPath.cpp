#include <bits/stdc++.h>
using namespace std;


//djiktsra's algorithm
//O(V+ElogV)

#define ll long long
#define pp pair< int , pair< int , int >>
int solve(int m, int n, vector<string> &grid) {
   
     // direction which is there will be good
     
      // left , right , top , down
     
      // to go from top left  to bottom right
     
      priority_queue< pp , vector<pp> , greater<pp>> pq;
     
      pq.push({0 , {0 , 0}});
     
      int dx[4]={0 , 0 , -1 , 1}; // row
      int dy[4]={-1 , 1 , 0 , 0}; // col
     
      int left=0 , right=1 , top=2 , down=3;
      vector<vector<ll>> dist(m , vector<ll>(n , INT_MAX));
     
      dist[0][0]=0;
     
      while(!pq.empty())
      {
          auto t = pq.top();
          pq.pop();
         
          int cost=t.first;
         
          int i=t.second.first;
          int j=t.second.second;
         
          char ch=grid[i][j];
         
          int index;
         
          if(ch=='L')
          {
              index=left;
          }
          else
          if(ch=='R')
          {
              index=right;
          }
          else
          if(ch=='U')
          {
              index=top;
          }
          else{
              index=down;
          }
         
         
         
          for(int k=0;k<4;k++)
          {
              int newi=i+dx[k];
              int newj=j+dy[k];
             
              if(newi>=0 && newj>=0 && newi<m && newj<n)
              {
             
                if(k==index)
                {
                    if(dist[newi][newj]>cost)
                    {
                        dist[newi][newj]=cost;
                        pq.push({cost , {newi , newj}});
                    }
                }
                else{
                    if(dist[newi][newj]>cost+1)
                    {
                        dist[newi][newj]=cost+1;
                        pq.push({1+cost , {newi , newj}});
                    }
                }
             
              }
          }
      }
     
      if(dist[m-1][n-1]==INT_MAX)
      {
          return -1;
      }
     
      return dist[m-1][n-1];