/************************************************************************
* 版权所有  (c)2008,   RunShan
* 文件名称： File.c

* 内容摘要：
*     本文件实现关于文件操作的所有功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <string.h>
#include <conio.h>
#include <malloc.h>
#include <windows.h>
#include "..\\File\\File.h"
#include "..\\Glb_putstring\\Glb_putstring.h"


FILE *File_open(char *dirname)
{
	FILE *fp;
	fp = fopen(dirname,"rb+");// 文件存在，用r+打开
	if (fp == NULL)
	{
		fp = fopen(dirname,"wb+");// 文件不存在，用w+打开
		if (fp == NULL)
		{
			printf("file open failed.\n");// 打开不成功，作提示
		}
	} 
	
	return fp;
}



int File_write(FILE *fp,pList head,int size,int n)
{	
	pList pt;
	int count = 0;
	fseek(fp,0,n);// 文件指针偏移到n指定的位置
	pt = head->pNext;
	while(pt != NULL)
	{ 
		count++;
        fwrite(pt->pData,size,1,fp);// 从n指定的位置写入链表
		fflush(fp);// 更新文件
		pt = pt->pNext;
	}
	return count;
}




pList File_read(FILE *fp,int size)
{
	pList head;
	int flag;
    void *p1;
	fseek(fp,0,SEEK_SET);//定位到文件头
	head = List_init(NULL);
	p1 = malloc(size);
	flag = fread(p1,size,1,fp);// flag表征读出成功与否
	while(flag)
	{		 	
		List_add(head,p1);
		p1 = malloc(size);// 每次开辟一个新空间，存放每次读出来的数据
		flag = fread(p1,size,1,fp); 
	}
    return head;//返回读出链表的头指针
}



void File_remove(FILE *fp,pList head,int size,int (*prem)(pList))
{	
	
	pList pt;
	int count;
	count = 0;
    pt = head->pNext;
	while(pt != NULL)
	{
		count++;// 记录结点的位置
		if(prem(pt))// 查询要操作的结点数据
		break;
		pt = pt->pNext;	
	}
      
	  	if (pt == NULL)
	    printf("\n未查到此条信息");

		else
	{

		printf("\n是否确认删除(y)是、(n)不:");
		if (glb_putString(NULL,0,0,1,1) == 'y')// 提示是否确定删除
		{
			fseek(fp,(count-1)*size,SEEK_SET);// 定位到要假删除的结点位置
		    fwrite(pt->pData,size,1,fp);// 覆盖旧数据
		    fflush(fp);
			printf("\n删除成功");
		}
		else
			printf("\n删除失败");	
} 
  
	   printf("，按任意键继续...");
	   getch();	
}



void File_add(FILE *fp,pList head,int size,void *(*padd)(void *data))//添加一个成员
{	
	pList pNew,pt;
	pt = head;
	while(pt->pNext != NULL )
	{   
		pt=pt->pNext; 
	}
   	pNew = List_init(padd(pt->pData));		
	printf("是否确认增加(y)是、(n)不:");
	if (glb_putString(NULL,0,0,1,1) == 'y')// 提示是否确定增加
	{
	        pt->pNext = pNew; 
			fseek(fp,0,SEEK_END);//定位到文件末尾添加数据  
			fwrite(pNew->pData,size,1,fp);// 加入新增的数据
			fflush(fp);	  	     
	        printf("\n增加成功");			
	}
	else
	    	printf("\n增加失败");
          
    printf("，按任意键继续...");
	getch();	          
}



void File_del(FILE *fp,char dir[],pList head,int size,int (*pdel)(pList))
{
   
  	pList pt,ps;
	ps = head;
	pt = head->pNext;
	while (pt != NULL )
{    
	if (pdel(pt))
{
			
	  printf("\n是否确认删除(y)是、(n)不:");
     if (glb_putString(NULL,0,0,1,1) == 'y')
    { 
	   ps->pNext = pt->pNext; 
	   free(pt);// 释放要删除的结点
       fclose(fp);
	   fp = fopen(dir,"w+");// 已W+方式重新打开文件
 	   File_write(fp,head,size,0);// 重新把链表写入文件
	   printf("\n删除成功");
	}
	else
	   printf("\n删除失败");
	   break;
}
        ps = pt;
		pt = pt->pNext;
}
     if (pt == NULL)
	 	printf("\n未找到此条信息");	
     printf("，按任意键继续...");
	 getch();	
}



void File_updata(FILE *fp,pList head,int size,int (*p)(pList))//在链表中修改信息，同时更新到文件中
{
	pList pt;
	int count;
	count = 0;
    pt = head->pNext;
	while(pt != NULL)
	{
		count++;// 记录要更新的数据在链表中的位置
		if(p(pt))// 查找要更新的数据
		{ 
		  break;			
		}
		pt = pt->pNext;		
	}

	if(pt == NULL)
	printf("\n未查到此条信息");

    else
	{
		printf("\n是否确认修改(y)是、(n)不:");
		if (glb_putString(NULL,0,0,1,1) == 'y')
		{
			fseek(fp,(count-1)*size,SEEK_SET);// 定位到要更新的结点位置
		    fwrite(pt->pData,size,1,fp);// 覆盖旧数据
		    fflush(fp);
			printf("\n修改成功");
		}
		else
			printf("\n修改失败");    
	} 
	 printf("，按任意键继续...");
	 getch();	
}

