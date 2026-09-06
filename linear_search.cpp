#include<iostream>
using namespace std;

int linear_search(int a[],int n,int x){
    for(int i=0;i<n;i++){
        if(a[i]==x){
            return i;
        }
    }
}

int main(){
    int a[20];
    int n,x;

    cout<<"enter the size of the array:"<<endl;
    cin>>n;

    cout<<"enter the element of arrray:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"enter the targrt element:";
    cin>>x;

    int p=linear_search(a,n,x);
    cout<<"the element "<<x<<" found at the position "<<p<<endl;

    return 0;
    

}
