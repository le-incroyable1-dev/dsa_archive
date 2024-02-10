#include <bits/stdc++.h>
using namespace std;


//Disjoint Set (Union Find)



//Find the parent, set the new parents accordingly
int find(vector<int> &parent,int x){
    while(parent[x]!=x){
        //set new parent
        parent[x]=parent[parent[x]];

        //find next parent
        x=parent[x];
    }
    return x;
}

int solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    
    vector<int> parent(A.size()+1);
    
    for(int i=0;i<parent.size();i++)
    parent[i]=i;
    

    //Create the Union after finding the corresponding roots/parents according to the swaps available
    for(int i=0;i<C.size();i++){
        int par_src=find(parent,A[C[i][0]-1]);
        int par_des=find(parent,A[C[i][1]-1]);
        
        if(par_src!=par_des)
        parent[par_src]=par_des;
    }


    //Check if all corresponding elements have the same root/parent
    for(int i=0;i<A.size();i++){
        if(A[i]!=B[i]){
            if(find(parent,A[i])!=find(parent,B[i]))
            return 0;
        }
    }

    return 1;
}


int main(void){
    vector<int> p = {1,3,2,4};
    vector<int> res = {1,4,2,3};
    vector<vector<int>> swaps = {{2,4}};

    cout << solve(p,res,swaps);
}