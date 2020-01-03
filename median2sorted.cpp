// Author: SHUBHAM KUMAR
// Idea was taken from  https://www.geeksforgeeks.org/median-two-sorted-arrays-different-sizes-ologminn-m/

// condition: The two array must be sorted and of different length (this is not for same length)
// Time  Complexity: o(log(min(n,m))) where m and n are size of array
// Space Complexity: o(n+m) for storing the array
// This was done by using the iterative Binary Search


#include<bits/stdc++.h>
using namespace std;

double medianOfTwoSortedArray(vector<int>& v1,vector<int>& v2)
{
    if(v1.size()>v2.size())
    {
        return medianOfTwoArray(v2,v1);
    }
    int n=v1.size();
    int m=v2.size();
    int low=0,high=n;
    while(low<=high)
    {
        int partix=(low+high)/2;
        int partiy=(n+m+1)/2 -partix;
        
        int leftx,rightx,lefty,righty;
        
        ///////////// x   ////////
        
        if(partix==0)
        {
            leftx=INT_MIN;
        }
        else
        {
            leftx=v1[partix-1];
        }

        if(partix==n)
        {
            rightx=INT_MAX;
        }
        else
        {
            rightx=v1[partix];
        }
        
        ////////////  y ///////////
        
        if(partiy==0)
        {
            lefty=INT_MIN;
        }
        else
        {
            lefty=v2[partiy-1];
        }

        if(partiy==m)
        {
            righty=INT_MAX;
        }
        else
        {
            righty=v2[partiy];
        }

        if(leftx<=righty && lefty<=rightx)
        {
            if((n+m)%2==0)
            {
                return (double)( max(leftx,lefty)  + min(rightx,righty))/2;
            }
            else
            {
                return (double)max(leftx,lefty);
            }
            
        }
        else if(leftx>righty)
        {
            high=partix-1;
        }
        else
        {
            low=partix+1;
        }
    }
} 


int main()
{
    vector<int>v1;
    vector<int>v2;
    int n,m,x;
    cin>>n>>m;
    cout<< "INPUT THE ARRAY ELEMENT IN SORTED WAY"<<"n";
    
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<m;i++)
    {
        cin>>x;
        v2.push_back(x);
    }
    double ans;
    ans=medianOfTwoSortedArray(v1,v2);
    cout<<ans;
}
