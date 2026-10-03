#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=nullptr;
    }

};
class List{
    Node* head;
    Node* tail;
    public:
    List(){
        head=tail=nullptr;
    }
    void push_front(int val){
        Node* newnode=new Node(val);
        if(head==nullptr)
        {
            tail=head=newnode;
            return;
        }else{
            newnode->next=head;
            head=newnode;
	  
       }
    }
    void push_back(int val){
     Node* newnode=new Node(val);
        if(head==nullptr)
        {
            tail=head=newnode;
            return;
        }else{
            tail->next=newnode;
            tail=newnode;
	  
       }
    	
    }
    void popfront(){
	    if(head==nullptr){
		    cout<<"Linked list is empty";
	    }else{
	    Node* temp=head;
	    head=head->next;
	    temp->next=nullptr;
	    delete temp;
    }}
    void popback(){
	    if(head==nullptr){
	    cout<<"Empty list";
	    return;
	    }else{
	    Node* temp=head;
	    while(temp->next!=tail){
		    temp=temp->next;
	    }
	    temp->next=nullptr;
	    delete tail;
	    tail=temp;
	    }


    }
    void insert(int val,int pos){
	    if(pos==0){
	    push_front(val);
	    return;
	    }
	    else if(pos<0){
	    cout<<"Invalid position";
	    return;
	    }
	    Node* newnode=new Node(val);
	    Node* temp =head;
	    for(int i=0;i<pos-1;i++){
		    if(temp==nullptr){
		    cout<<"invalid pos";
		    return;
		    }
		    temp=temp->next;
	    }
	    newnode->next=temp->next;
	    temp->next=newnode;

   
    }
    int search(int x){
	    Node* temp=head;
	    int h=0;
	    if(head==nullptr){
	    cout<<"There is no node to search"<<endl;
	    return -1;
	    }else{
		    while(temp!=nullptr){
	            if(temp->data==x){
		    cout<<"Node found at"<<h<<endl;
		    return h;

		    }
		    temp=temp->next;
		    h++;

		    }
		    cout<<"No such node present"<<endl;
		    return -1;
		    
	    }
    }


    
   
    void showlist(){
        Node* temp=head;
	while(temp!=nullptr){
            cout<<temp->data <<"->";
            temp=temp->next; 
        }
        cout<<"null";
        cout<<"\n";
    }
};
int main(){
    List ll;
    ll.push_front(20);
    ll.push_front(30);
    ll.push_back(40);
    ll.insert(50,2);
    ll.search(40);
    
 
   
    ll.showlist();

    return 0;
}
