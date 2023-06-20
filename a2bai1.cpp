#include<bits/stdc++.h>
using namespace std;
double arr[1000];
double A(double arr[], int n){
    double sum = 0.0;
    int dem = 0;
    for(int i=0; i<n;i++){
        if (arr[i]>0){
            sum=sum+arr[i];
            dem++;
        }
    }
    if(dem==0)
        return 0;
    else{
        double average = sum / (double)dem;
        return (double)average;
    }
}
double B(double arr[], int n){
    double sumb =0.0; int demb=0;
    double sums=0.0; int dems=0;
    double argb, args, arg;
    for(int i=0; i<n; i++){
        if(arr[i]>0){
            if(arr[i]<0.01){
                sums=sums+arr[i];
                dems=dems+1;
            }else {
                sumb=sumb+arr[i];
                demb=demb+1;
            }
        }
    }
    if(demb>0)
        argb=sumb/(double)demb;
    else {
        argb=0;
        arg= args;
    }
    if(dems>0)
        args=sums/(double)dems;
    else {
        args=0;
        arg= argb;
    }
    if(demb>0&&dems>0)
        arg=(double)((argb+args)/2);
        
    return arg;
    
}
double C(double arr[], int n){
    double c;
     double sumb =0.0; int demb=0;
    double sums=0.0; int dems=0;
    double argb, args, arg;
    for(int i=0; i<n; i++){
        c=arr[i];
        if(c>0){
            if(c<0.01){
                 sums = sums+c;
                dems=dems+1;
            }else{
                sumb=sumb+c;
                demb=demb+1;
            }      
        }
    }
    if(demb>0)
        argb=sumb/(double)demb;
    else {
        argb=0;
        arg= args;
    }
    if(dems>0)
        args=sums/(double)dems;
    else {
        args=0;
        arg= argb;
    }
    if(demb>0&&dems>0)
        arg=(double)((argb+args)/2);
        
    return arg;
}
int main(){
 int n;
 cout<<"nhap n";
 cin>>n;
 cout<<"nhap mang";
 for(int i=0; i<n; i++){
     cin>>arr[i];
 }
 cout<<fixed<<setprecision(5)<< A(arr,n)<<endl;
 cout<<fixed<<setprecision(5)<< B(arr,n)<<endl;
 cout<<fixed<<setprecision(5)<< C(arr,n)<<endl;
return 0;
}
