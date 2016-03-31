#include "../clist.h"

//定义一个私有数据属性
typedef struct mydata{
  int mdata;
}mydata;

//为了方便起见定义个宏
#define GETMYDATA(n) ((struct mydata*)(n))
//再定义两个函数方便分配数据
struct mydata* alloc_mydata(int mdata)
{
  mydata* temp=(mydata*)malloc(sizeof(mydata));
  temp->mdata=mdata;
  return temp;
}
void free_mydata(mydata* n)
{
  if(n){
    printf("释放节点 %d\n",n->mdata);
    free(n);
  }
}

int main(){
  //分配头结点,头结点不包含任何数据
  clist_node* head=clist_AllocNode(0);
  for(int i=0;i<10;++i){
    //构造私有数据
    mydata* temp=alloc_mydata(i);
    //构造clist_node
    clist_node* node=clist_AllocNode(temp);
    //追加到head尾部
    clist_Push(head,node);
  }
  clist_node* iter;
  while((iter=clist_Pop(head))!=NULL){
    printf("output : %d\n",GETMYDATA(iter->data)->mdata);
    //释放已经用完的元素
    free_mydata(GETMYDATA(iter->data));
    clist_DeleteNode(iter);
  }
  //删除头结点
  clist_DeleteNode(head);
  return 0;
}
