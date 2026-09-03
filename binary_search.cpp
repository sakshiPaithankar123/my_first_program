#include<iostream>
using namespace std;

int binary_search(int a[],int n,int x){
    int first=0;
    int last=n-1;
    int mid;

    while(first<=last){
        mid=(first+last)/2;

        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            first=mid+1;
        }
        else{
            last=mid-1;
        }
        
    }
return (-1);
}

int main(){
    int n,x;
    int a[20];

    cout<<"enter the size of the array:";
    cin>>n;

    cout<<"enter the sorted array:"<<endl;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
cout<<"enter the no to find:";
cin>>x;


   int position= binary_search(a,n,x);

   cout<<"no is found at position:"<<position<<endl;

   return 0;
}

