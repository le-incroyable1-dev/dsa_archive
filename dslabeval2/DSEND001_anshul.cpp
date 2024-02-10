#include<bits/stdc++.h>

using namespace std;

void Print(queue<int> q, stack<int> s1, stack<int> s2){
   
    while(!q.empty()){
       cout<<q.front()<<" ";
       q.pop();
       if(q.empty()) cout<<endl;
   }
   
   while(!s1.empty()){
       cout<<s1.top()<<" ";
       s1.pop();
       if(s1.empty()) cout<<endl;
   }
   
    while(!s2.empty()){
       cout<<s2.top()<<" ";
       s2.pop();
       if(s2.empty()) cout<<endl;
   }
}

void Enqueue(queue<int> &q, stack<int> &s1, stack<int> &s2){
    while(!s1.empty() or !s2.empty()){
         
         if(s1.empty()){
             while(!s2.empty()){
                q.push(s2.top());
                s2.pop();
                
                
             }
             
         }
         else if (s2.empty()){
             while(!s1.empty()){
                 q.push(s1.top());
                 s1.pop();
                 
                 
             }
         }
         
        else{
            if(s1.top()<s2.top()){
                q.push(s1.top());
                s1.pop();
            }
            else{
                q.push(s2.top());
                s2.pop();
            }
            
            
        }
        Print(q, s1, s2);
    }
}

void Reverse(stack<int> &s){
    stack<int> ste;
    
    while(!s.empty()){
        ste.push(s.top());
        s.pop();
    }
    
    s = ste;
    
    
}



int main(){
    
    int n;
    
    cin>>n;
    
    int arr[n];
    
    
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    

    stack<int> s1, s2;
    queue<int> q;
    
    for(int i=0; i<n; i++){
        
        
        int x = arr[i];
        
        if(s1.empty() or x<s1.top()){
            
            s1.push(x);
            Print(q, s1, s2);
           
            
        }
        else if(s2.empty() or x> s2.top()){
            s2.push(x);
            Print(q, s1, s2);
            
        }
        else{
            
            if(abs(s1.top()-x) > abs(s2.top()- x)){
                while(!s2.empty() and s2.top()>= x){
                    q.push(s2.top());
                    s2.pop();
                    
                    
                }
                s2.push(x);
                Print(q, s1, s2);
                
                while(!q.empty()){
                    int len = q.size();
                    
                    for(int i=0; i< len-1; i++){
                        q.push(q.front());
                        q.pop();
                    }
                    
                    s2.push(q.front());
                    q.pop();
                }
                
                
            }
            else{
                while(!s1.empty() and s1.top()<= x){
                    q.push(s1.top());
                    s1.pop();
                    
                }
                s1.push(x);
                Print(q, s1, s2);
                
                while(!q.empty()){
                    int len = q.size();
                    
                    for(int i=0; i< len-1; i++){
                        q.push(q.front());
                        q.pop();
                    }
                    
                    s1.push(q.front());
                    q.pop();
                }
                
                
            }
        }
    }
    
    Reverse(s2);
    
    
    
    Enqueue(q, s1, s2);
    
    
    
    
    
    
    return 0;
}