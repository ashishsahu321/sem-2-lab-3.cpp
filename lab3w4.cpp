
//create a doubly circular link list
//use function to insert delete and print element

#include<iostream>
using namespace std;
//declare class of node type
class node{
    public:
//it has three part:
//data for store value
int data;
//pointer prev and next of node type
node*prev;
node*next;
//constructor initially assign value NULL
node(){
    prev=NULL;
    next=NULL;
}
};
//class link list shows the way node are connected to each other
class linklist{
public:
//define two pointer
node*head,*tail;
//constructor initially assign NULL to pointer
linklist(){
head=NULL;
tail=NULL;
}
//insert element
void insert(int value){
//create new node
node*temp=new node;
//store value in that node;
temp->data=value;
//entry of first element
if(head==NULL){
//head store value of temp
 head=temp;
//next of temp is also temp
 temp->next=temp;
 //and temp previous is also is temp;
 temp->prev=temp;
 tail=temp;
}
//entry of element other than
else{
// entering element at next to tail
 tail->next=temp;
 temp->prev=tail;
 temp->next=head;
 head->prev=temp;
}
tail=temp;
tail->next=head;
head->prev=tail;
}
void insertat(int pos,int value){
cout<<"after inserting "<<value<<" at position  "<<pos<<"th   ";
//initially current point tot head
node*current=head;
//integer point to position
int i=1;
while(i<pos-1){
  i++;
  current=current->next;
}
node*temp=new node;
temp->data=value;
temp->next=current->next;
temp->prev=current->next->prev;
current->next=temp;
current->next->next->prev=temp;
tail->next=head;
head->prev=tail;
}
void Delete(){
cout<<"deleting last element  ";
node*current=head;
while(current->next->next!=head){
 current=current->next;
}
node*temp=current->next;
temp=current->next->next->prev;
current->next=temp->next;
current->next->next->prev=temp->prev;
delete temp;
}
void Deleteat(int pos){
cout<<"After deleting element of "<<pos<<"th ";
node*current=head;
int i=1;
while(i<pos-1){
 i++;
 current=current->next;
}
node*temp=current->next;
temp->prev=current->next->prev;
current->next=temp->next;
current->next->prev=temp->prev;
delete temp;
}
void display(){
cout<<"display the no:  ";
node*current=head;
while(current->next!=head){
    cout<<current->data<<"  ";
    current=current->next;
}
cout<<current->data;
cout<<endl;
}
void count(){
int i=1;
node*current=head;
while(current->next!=head){
    current=current->next;
    i++;
}
cout<<"The no of element present in the circular link list is  "<<i<<endl;
}
void displayfrom(int pos){
int i;
node*current=head;
while(i<pos-1){
  current=current->next;
  i++;
}
node*temp=current->next;
current->next=temp;
while(current->next->next!=temp){
    cout<<current->data<<"  ";
    current=current->next;
}
cout<<current->data<<endl;
}
//print in reverse order
void revdisplay(){
cout<<"After print in reverse order  ";
node*current=tail;
while(current->prev!=tail){
    cout<<current->data<<"  ";
current=current->prev;
}
cout<<current->data;;
cout<<endl;
}
};

int main(){
linklist L;
L.insert(1);
L.insert(2);
L.insert(3);
L.insert(4);
L.insert(5);
L.display();
L.revdisplay();
L.display();
L.insertat(3,2);
L.display();
L.Delete();
L.display();
L.Deleteat(2);
L.display();
L.displayfrom(3);
L.count();
return 0;
}

