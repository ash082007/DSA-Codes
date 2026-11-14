#include<iostream>
#include<vector>
using namespace std;
class CirclQueue{
int* arr;
int currsize,cap;
int f,r;
public:
	CirclQueue(int size){
		cap=size;
		arr=new int[cap];
		currsize=0;
       		 f=0;
		r=-1;
	}			
	void push(int data){
		if(currsize==cap){
			cout<<"CQ is full"<<endl;
		return;
		}
		r=(r+1)%cap;
		arr[r]=data;
		currsize++;		

	}
	void pop(){
		if(isempty()){
		cout<<"CQ is empty"<<endl;
		return;
		}
		f=(f+1)%cap;
		currsize--;
	}
	int front(){
		if(isempty()){
		cout<<"CQ is empty"<<endl;
		return -1;
		}
		return arr[f];
	}
	bool isempty(){
	return currsize==0;	
	}
	void printArr(){
		for(int i=0;i<cap;i++){
		cout<<arr[i]<<" ";
		}
	cout<<endl;
	}
};
int main(){
CirclQueue cq(3);
cq.push(4);
cq.push(3);
cq.push(2);
cq.pop();
cq.push(5);
//cq.printArr();
while(!cq.isempty()){
	cout<<cq.front()<<" ";
	cq.pop();
}
cout<<endl;
return 0;
}
