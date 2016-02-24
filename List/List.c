/************************************************************************
* 版权所有  (c)2008,   RunShan
* 文件名称： List.c

* 内容摘要：
*     本文件实现关于链表基本操作的功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "..\\List\List.h"


 pList List_init(void * data)
{  
	pList head;
	head = (pList) malloc(sizeof(struct List));// 申请结点空间
	if (head == NULL)
	{
		printf("Memory error.\n");
		return NULL;
	}
	memset(head,0,sizeof(struct List));// 清零
	head->pData = data;// 数据域赋值
	return head;
}



void List_print(pList head,void (*pstr)(pList))
{
   pList pt;
   pt = head->pNext;	   
   while (pt != NULL)  
   {
       pstr(pt);// 函数指针，不同类型数据的打印
	   pt = pt->pNext;
   }
 
}



void List_add(pList head,void *data)
{
	pList pNew,pt;
	pt = head;
	pNew = List_init(data);// 初始化一个新结点
	while(pt->pNext != NULL )// 链表偏移到最后面
	{   
		pt=pt->pNext; 
	}   	
    	pt->pNext = pNew;// 往末尾添加结点
}



int  List_count(pList head)
{
	pList p1;
	int nCount = 0;
	p1=head->pNext;
	while(p1 != NULL)
	{
		nCount++;
		p1=p1->pNext;
	}
	return nCount;
}



void List_free(pList head)
{
	pList ptr = head->pNext;
	while(ptr!=NULL)
	{
		head->pNext=ptr->pNext;
		free(ptr->pData);// 先释放数据域空间
		free(ptr);// 再释放结点空间
		ptr = head->pNext;
	}
	    free(head);// 最后释放头结点
}
