/************************************************************************
* 版权所有  (c)2008,   RunShan
* 文件名称： Menu.c

* 内容摘要：
*     本文件实现关于菜谱的增删改查功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "..\\Menu\Menu.h"

void Menu_print(pList pt)
{   
	static int k = 0;
	struct Menu_t *pd;
	pd = (struct Menu_t *)(pt->pData);
	if (k == 0)
	{
		system("cls");
		printf("\t\t%-10s%-11s%-12s\n","菜编号","菜名","价格");
		k = 1;
	}
	printf("\t\t%-10s%-11s%-12d\n",pd->num,pd->name,pd->price);
	if (pt->pNext == NULL)
		k = 0;
}



void *Menu_add(void *data)
{ 	
	char str[8] = {0};
	struct Menu_t *pData,*ps;
	pData = (struct Menu_t *)malloc(sizeof(struct Menu_t));
	ps = (struct Menu_t *)data;
	if (data == NULL)
	{  
		system("cls");
		strcpy(pData->num,"10000");	
	}
	else
	{
		glb_putString(ps->num,'0','9',5,2);
		strcpy(pData->num,ps->num);
	}
	printf("\n请输入要增加的菜名：");
	glb_putString(pData->name,0,0,14,1);
	printf("请输入要增加的价格：");
    pData->price = glb_putString(str,'0','9',2,2);
	printf("\n");
    return pData;
}





int Menu_del(pList pL)
{ 
	struct Menu_t *pt;
	static int k = 0;
	static int id = 0;
	static char str[8] = {0};
	if (k == 0) 
	{
		printf("请输入要删除的菜编号(5位)：");
		glb_putString(str,'0','9',5,2);
		k = 1;
	}
	pt = (struct Menu_t *)(pL->pData);
	if (strcmp(pt->num,str) == 0)
	{
		memset(str,0,sizeof(char));
		k = 0;
		return 1;
	}
	else 
	{
		if (pL->pNext == NULL)
		{   
			memset(str,0,sizeof(char));
			k = 0;
		}
		return 0;	  
	}
}




int Menu_updata(pList pL)
{
	struct Menu_t *pt;
    static int k = 0;
	static char str[8] = {0};
	if (k == 0)
	{
		printf("请输入要修改的菜编号(5位)：");
		glb_putString(str,'0','9',5,2);
		k = 1;
	}
	pt = (struct Menu_t *)(pL->pData);
	if (strcmp(pt->num,str) == 0)
	{
		memset(str,0,sizeof(char));
		printf("\n重新输入菜名：");
		glb_putString(pt->name,0,0,14,1);
		printf("重新输入价格：");
		pt->price = glb_putString(str,'0','9',2,2);
		memset(str,0,sizeof(char));
		k = 0;
		return 1;		
	}
	
	else 
	{
        if (pL->pNext == NULL)
        {
			memset(str,0,sizeof(char));
			k = 0;
        }
			return 0;
	}
		
}




void Menu_search(pList head)
{
	char str[8] = {0};
	pList ps,pL;
	struct Menu_t *data;
	pL = List_init(NULL);
	ps = head->pNext;
	if(ps == NULL)
	{
		system("cls");
		printf("\n未存有菜谱信息，请先添加！\n");
		return;
	}
	system("cls");
	printf("\n\t\t\t(1) 全部");
	printf("\n\n\t\t\t(2) 编号");
	printf("\n\n\t\t\t请输入要查询的条件：");
	if(glb_putString(NULL,'1','2',1,2) == 1)
	{
        List_print(head,Menu_print);
		return;
	}
	printf("\n\n\t\t\t请输入要查询的菜编号(5位)：");
	glb_putString(str,'0','9',5,2);
	while(ps != NULL)
	{
		data = (struct Menu_t *)(ps->pData);
		if (strcmp(data->num,str) == 0)
		{
			List_add(pL,data);
			break;
		}		
		ps = ps->pNext;
	}
	if (ps != NULL)
	{  
          List_print(pL,Menu_print);  
	}
	else 
	{
        printf("\n\n输入有误，未查询到相关信息");	
	}	      
} 


