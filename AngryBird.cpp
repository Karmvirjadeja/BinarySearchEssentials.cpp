/**
 * @file AngryBird.cpp
 * @author Karmivr Jadeja 
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
  Total nests available are = 5;
  Total Birds are = 3;
  Nests={1,2,4,8,9}

  O/p -----M Maximum distance between them and accomodations
*/
#include<bits/stdc++.h>
using namespace std;

bool canPlaceMid(int B, int N,vector<int>&nest,int mid,int distance){

int Birds=1;
int CurrentLocation=nest[0];

for(int i=1;i<N;i++)
{
    
    if((nest[i]-CurrentLocation)>=distance){
        Birds++;
        CurrentLocation=nest[i];
    }
    if(Birds==B) return true;
}
   return false;
}

int main(){
    int B=3;
    vector<int>nest{1,2,4,8,9};
    sort(nest.begin(),nest.end());
    int N=nest.size();
    int start=nest[0];
    int end=nest[N-1]-nest[0];
    int ans=-1;
    if(start<=end){
       int mid=(end-start)/2;
       int distance=mid;
        if(canPlaceMid(B,N,nest,mid,distance)){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }

    cout<<"Here Max Distance after all is "<<ans<<endl;
}
