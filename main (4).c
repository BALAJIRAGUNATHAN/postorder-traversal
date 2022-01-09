#include <stdio.h>
#include <stdlib.h>
#define MARKER -1
typedef struct Node{
int key;
struct Node *left, *right;
}Node;
struct Node *temp;
Node* newNode(int key){
temp =(Node *) malloc(sizeof(struct Node));
temp->key = key;
temp->left = temp->right = NULL;
return (temp);}
void serialize(Node *root, FILE *fp){
if (root == NULL){
fprintf(fp, "%d ", MARKER);
return;}

serialize(root->left, fp);
serialize(root->right, fp);
    fprintf(fp,"%d",root->key);
}
void postorder(Node *root){
if (root){
postorder(root->left);
postorder(root->right);
    printf("%d",root->key);
}}
int main(){
struct Node *root = newNode(20);
root->left = newNode(8);
root->right = newNode(22);
root->left->left = newNode(4);
root->left->right = newNode(12);
root->left->right->left = newNode(10);
root->left->right->right = newNode(14);
void deSerialize(Node *root, FILE *fp){
int val;
if ( !fscanf(fp, "%d ", &val) || val == MARKER)
return;
root = newNode(val);
deSerialize(root->left, fp);
deSerialize(root->right, fp);}
FILE *fp = fopen("tree.txt", "w");
if (fp == NULL){
puts("Could not open file");
return 0;}
serialize(root, fp);
fclose(fp);
Node *root1 = NULL;
fp = fopen("tree.txt", "r");
deSerialize(root1, fp);
printf("postorder Traversal of the tree constructed from file:\n");
postorder(root1);
return 0;
}