#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left,*right;
}node;

node* newnode(int data){
    node* t=(node*)malloc(sizeof(node));
    t->data=data;
    t->left=NULL;
    t->right=NULL;
    return t;
}
node* create(node* root,int data){
    if(root==NULL){
       root=newnode(data);
        return root;
    }
    else if(data<root->data){root->left=create(root->left,data);}
    else{
        root->right=create(root->right,data);
    }return root;
}
void traversal(node* root){node* temp;
temp=root;
if(temp!=NULL){
   traversal(temp->left);
   printf(" %d ",temp->data);
   traversal(temp->right);
}}
node* minval(node* root){
    node* temp;
    temp=root;
    while(temp!=NULL){
        temp=temp->left;
    }return temp;
}
node* del(node* root,int data){node* temp=NULL;
    if(root==NULL){
    return root;
    }
    if(data<root->data){
        root->left=del(root->left,data);
    }else if(data>root->data){
        root->right=del(root->right,data);
    }else{
      if(root->left==NULL){
        temp=root->right;
        free(root);
        return temp;
      }else if(root->right==NULL){
        temp=root->left;
        free(root);
        return temp;
      }else{
        temp=minval(root->right);
        root->data=temp->data;
      }
    }    return root;
}
int main(){
node* root=NULL; 
root=create(root,8);
root=create(root,10);
root=create(root,20);
root=create(root,40);
root=create(root,100);
traversal(root);
del(root,40);
printf("\n");
traversal(root);
return 0;
}






