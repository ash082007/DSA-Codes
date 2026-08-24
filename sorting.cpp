#include<iostream>
#include<vector>
using namespace std;
void bubblesort(vector<int>& arr){
	int s=arr.size();
	for(int i=0;i<s-1;s++ ){
		bool check=false;
		for(int j=0;j<s-i-1;j++){
			if(arr[j]>arr[j+1]){
				check=true;
				swap(arr[j+1],arr[j]);
			}
		}
			if(!check){
			break;
			}
	}
}
void selectionsort(vector<int>& arr){
	int s=arr.size(),min;
	for(int i=0;i<s-1;i++){
		int min=i;
		for(int j=i+1;j<s;j++){
			if(arr[min]<arr[j]){
			min=j;
			}

		}
		swap(arr[min],arr[i]);

	}
}
void insertionsort(vector<int>&arr){
	int s=arr.size();
	for(int i=1;i<s-1;i++){
		int curr=arr[i];
		int prev=i-1;
		while(prev>=0&&arr[prev]>curr){
			arr[prev+1]=arr[prev];
			prev--;
		}
		arr[prev+1]=curr;
	}


}
void merge(vector<int>& arr,int st,int mid,int end){
	vector<int>temp;
	int i=st;
	int j=mid+1;
	while(i<=mid && j<=end){
		if(arr[i]<=arr[j]){
			temp.push_back(arr[i]);
			i++;
		}else{
			temp.push_back(arr[j]);
			j++;
		}
		
	}
	while(i<=mid){
		temp.push_back(arr[i]);
		i++;
	}
	while(j<=end){
		temp.push_back(arr[j]);
		j++;
	}
	for(int x=0;x<temp.size();x++){
		arr[st+x]=temp[x];
	}
}
void mergesort(vector<int>& arr,int st,int end){

		int mid=st+(end-st)/2;
		if(st<end){
			mergesort(arr,st,mid);
			mergesort(arr,mid+1,end);
			merge(arr,st,mid,end);	
		}
}
int main(){
	vector<int> hello={5,4,6,2,7};
	mergesort(hello,0,hello.size()-1);
	for(int f:hello){
		cout<<f<<" ";
	}
	cout<<endl;

}
