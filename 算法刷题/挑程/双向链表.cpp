#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	node *prev,*next;
	node(int _x,node *_prev,node *_next)
	:x(_x),prev(_prev),next(_next){}
};
node *head = new node(0,NULL,NULL);
void insert(node *p,int x){
	node *q = new node(x,p,p->next);
	if(p->next){
		p->next->prev = q;
	}
	p->next = q;
}

void erase(node *p){
	if(p->next){
		p->next->prev = p->prev;
	}
	p->prev->next = p->next;
	delete p;
}

node *find(int k){
	node *p = head->next;
	for(int i=0;i<k;i++){
		p = p->next;
	}
	return p;
}

void print(){
	for(node *i=head->next;i;i=i->next){
		cout<<i->x<<" ";
	}
	cout<<endl;
}

int main(){
	
}

