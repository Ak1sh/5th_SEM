
#include <iostream>

using namespace std;

int main()
{
    int arr[20];
    int bucket_capacity=4, bucket_remaining=0,bucket_rate=3,sent,recieved,n;
    cout<<"Enter the number of packets:";
    cin>>n;
    cout<<"Enter the packets:";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    cout<<"Cycle\tPacket size\tRecieved\tSent\tRemaining"<<endl;
    for(int i=0;i<n;i++){
    if(arr[i]!=0){
        if(arr[i]+bucket_remaining<=bucket_capacity){
            recieved=arr[i];
            bucket_remaining+=arr[i];
        }
        else recieved=-1;
    }
    else recieved=0;
    
    if(bucket_remaining!=0){
        if(bucket_remaining<bucket_rate){
            sent=bucket_remaining;
            bucket_remaining=0;
        }
        else{
            sent=bucket_rate;
            bucket_remaining-=sent;
        }
    }
    else sent =0;
    
    if(recieved==-1)
    cout<<i+1<<"\t"<<arr[i]<<"\t\t"<<"Dropped\t\t"<<sent<<"\t"<<bucket_remaining<<endl;
    else
     cout<<i+1<<"\t"<<arr[i]<<"\t\t"<<recieved<<"\t\t"<<sent<<"\t"<<bucket_remaining<<endl;
    }
    return 0;
}
