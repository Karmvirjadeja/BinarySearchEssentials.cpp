/**
 * @file GameOfGreed.cpp
 * @author Karmvir
 * @brief 
 * @version 0.1
 * @date 2024-07-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/*
   number of friends 
   a vector storing the coins with the price
*/

bool divideAmong(int *arr,int n,int k,int mid, int sum){
    int currentGiven=0;
    int f=0;
    for(int i=0;i<n;i++){
        currentGiven+=arr[i];
        if(currentGiven>=mid){
            f++;
           currentGiven=sum-currentGiven;
        }
        if(f==k) return true;
    }

    return false;
}

int K_partion(int *arr,int n,int k){
    int start=0;
    int end=0;
   for(int i=0;i<n;i++){
    end+=arr[i];
   }
   int ans=-1;
   while(start<=end){
    int mid=(start+end)/2;
   
    bool isPossible=divideAmong(arr,n,k,mid,end);
    if(isPossible){
        ans=mid;
        start=mid+1;
    }
    else{
        end=mid-1;
    }
   }
   return ans;
}
#include<bits/stdc++.h>
using namespace std;


int main(){
    int a[]={10,22,40,50};
   
    int n=sizeof(a)/sizeof(int);
    int k=3;

    cout<<K_partion(a,n,k)<<endl;

}