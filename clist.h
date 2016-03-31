#include <stdio.h>
#include <stdlib.h> //reqire malloc
#include <string.h> //require memset

/*
 *  a---b---c---d---e
 * */

typedef struct clist_node{
  void* data;
  struct clist_node* pre;
  struct clist_node* next;
}clist_node;

/*
 * 分配一个结点
 * */
clist_node* clist_AllocNode(void*data){
  clist_node* head=(clist_node*)malloc(sizeof(clist_node));
  memset(head,0,sizeof(clist_node));
  head->data=data;
  return head;
}
/*
 * 将此节点在列表中删除.
 * */
void clist_DeleteNode(clist_node* head){
  if(!head) return;
  if(head->pre) head->pre->next=head->next;
  free(head);
}

/*
 * 向列表尾部添加一个新节点
 * 请避免用环形列表
 * */
clist_node* clist_Push(clist_node*head,clist_node* node){
  clist_node* orihead=head;
  while(head->next && head->next!=orihead) head=head->next;
  head->next=node;
  node->pre=head;
  return node;
}
/*
 * 将列表尾部节点弹出,弹出的节点请手动释放
 * */
clist_node* clist_Pop(clist_node*head){
  clist_node* orihead=head;
  if(!head->next) return NULL;
  while(head->next&&head->next->next&&head->next!=orihead) head=head->next;
  orihead=head->next;
  orihead->pre=NULL;
  head->next=NULL;
  return orihead;
}
