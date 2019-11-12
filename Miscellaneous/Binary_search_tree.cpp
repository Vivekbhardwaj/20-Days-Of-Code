#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node 
{
	int data;
	struct node*left;
	struct node*right;
};

struct node* createnode(int data)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void insert(int Data,struct node * temp){

	if(temp->data > Data){
		if(temp->left==NULL){
			temp->left=createnode(Data);
			return;
		}
		insert(Data,temp->left);
	} else{
		if(temp->right==NULL){
			temp->right=createnode(Data);
			return;
		}
		insert(Data,temp->right);
	}
}

void inorder(struct node*temp)
{
	if(temp==NULL)
		return;
	inorder(temp->left);
	printf("%d ",temp->data);
	inorder(temp->right);
}

bool find(struct node * ROOT,int to_find){
	if(ROOT==NULL) return false;
	if(ROOT->data==to_find) return true;
	if(ROOT->data>to_find){
		return find(ROOT->left,to_find);
	}else{
		return find(ROOT->right,to_find);
	}
}

int main(){
	struct node *ROOT=createnode(4);
	insert(2,ROOT);
	insert(3,ROOT);
	insert(8,ROOT);
	insert(7,ROOT);
	insert(6,ROOT);
	inorder(ROOT);
}
