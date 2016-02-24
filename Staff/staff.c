/************************************************************************
* 版权所有  (c)2008,   卓越计算机职业培训学校。
* 文件名称： staff.c

* 内容摘要：
*     本文件实现关于员工的增删改查功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <stdio.h>
#include <malloc.h>
#include <windows.h>
#include <conio.h>
#include "..\\Staff\staff.h"
#include "..\\Glb_putstring\\Glb_putstring.h"


void staff_print(pList pt)
{   
	static int k = 0;
    char role[3][10] ={"服务员","经理","管理员"};
	struct staff_t *pd;
	pd = (struct staff_t *)(pt->pData);
	if (k == 0)
	{
	 system("cls");
	 printf("\t\t%-10s%-12s%-12s%-10s\n","编号","用户名","角色","状态");
	 k = 1;
	}
     printf("\t\t%-10d%-12s%-12s%-10s\n",pd->acNO,pd->acName,role[pd->role],
		pd->flag>0?"在职":"离职");
	 if (pt->pNext == NULL)
	 k = 0;
}



void *staff_add(void *data)
{ 	
	struct staff_t *pData,*ps;
	char str[8] = {0};
	pData = (struct staff_t*)malloc(sizeof(struct staff_t));// 申请一块数据空间
	ps = (struct staff_t *)data;
	pData->acNO = (ps->acNO)+1;// 员工号为整型，直接加1
	printf("\n请输入要增加的用户名(10位内)：");
	glb_putString(pData->acName,0,0,10,1);
   while(1)
   {
    memset(pData->psd,0,sizeof(char));
	printf("\n请输入要增加的密码(6位)：");
    glb_putString(pData->psd,'0','9',6,2);
	printf("\n再次确认输入密码(6位)：");
	glb_putString(str,'0','9',6,2);
    if(strcmp(pData->psd,str) == 0)// 验证两次密码输入的一致性
	{
	 break;
	}
	else
	{
		printf("\n密码不一致，请重新输入，按任意键继续...");
		memset(str,0,sizeof(char));
		getch();
        printf("\n");
	}

   }
	printf("\n请输入要增加的角色(0-服务员、1-经理、2-管理员)：");
    pData->role = glb_putString(NULL,'0','2',1,2);
	printf("\n请输入要增加的状态(0-离职、1-在职):");
    pData->flag = glb_putString(NULL,'0','1',1,2);
    printf("\n");
    return pData;
}



int staff_remove(pList pL)
{ 
      struct staff_t *pt;
      static int k = 0;
      static int id = 0;
	  static char str[8] = {0};
  if (k == 0) // 输入信息标志
  {
	  printf("请输入要删除的员工编号：");
	  id = glb_putString(str,'0','9',4,2);
	  k = 1;
	  memset(str,0,sizeof(char));
  }
  pt = (struct staff_t *)(pL->pData);
  if (pt->acNO == id)
  {
	  pt->flag = 0;// 员工状态改为离职，即为删除
      k = 0;
	  
      return 1; // 删除成功
  }
  else 
  {
	  if (pL->pNext == NULL)
		  k = 0;
	  return 0;	// 删除失败
}
}




int staff_updata(pList pL)
{
	struct staff_t *pt;
	static int k = 0;
	static int id = 0;
	static char str[8] = {0};
	if (k == 0)
	{
		printf("请输入要修改的员工编号(4位)：");
		id = glb_putString(str,'0','9',4,2);
		k = 1;
		memset(str,0,sizeof(char));
	}
	    pt = (struct staff_t *)(pL->pData);
	  if (pt->acNO == id)
	{
		printf("\n重新输入员工用户名：");
		glb_putString(pt->acName,0,0,10,1);
		while(1)
		{
		    memset(pt->psd,0,sizeof(char));
			printf("\n重新输入用户密码：");
			glb_putString(pt->psd,'0','9',6,2);
			printf("\n再次确认输入密码：");
			glb_putString(str,'0','9',6,2);
			if(strcmp(pt->psd,str) == 0)
			{
			    memset(str,0,sizeof(char));
				break;
			}
			else
			{
				printf("\n密码不一致，请重新输入，按任意键继续...");
				memset(str,0,sizeof(char));
				getch();
				printf("\n");
			}
		}
		printf("\n重新输入员工角色(0-服务员、1-经理、2-管理员)：");
		pt->role = glb_putString(NULL,'0','2',1,2);
		printf("\n重新输入员工状态(0-离职、1-在职)：");
		pt->flag = glb_putString(NULL,'0','1',1,2);
		k = 0;
		return 1;// 修改成功标志		
	}
        else 
	{
        if (pL->pNext == NULL)
        {
			k = 0;
        }
			return 0;// 修改失败
	}
		
}




  void staff_search(pList head)
 {
	  int n;
	  pList pL,ps;
	  void (*pf[3])(int n,pList ps,pList pL) = {staff_search_flag,staff_search_flag,staff_search_acNO};
	  system("cls");
	  pL = List_init(NULL);
      printf("\n\n\t\t\t(1) 全部\n\n\t\t\t(2) 离职\n\n\t\t\t(3) 在职\n\n\t\t\t(4) 编号");
	  printf("\n\n\t\t\t请输入要查询的条件:");
	  n = glb_putString(NULL,'1','4',1,2);
	  if (n == 1)
	  List_print(head,staff_print);
	  else
  {
	   ps = head->pNext;
	   while(ps != NULL)
      {
	    pf[n-2](n-2,ps,pL);
		ps = ps->pNext;
      }
  }	      
   		 
}




void staff_search_flag(int n,pList ps,pList pL)
 {
	 struct staff_t *pt;
	 pt = (struct staff_t *)(ps->pData);
	 if (pt->flag == n)
	 {
		 List_add(pL,pt);// 符合条件的结点添加进链表
	 }
	 if (ps->pNext == NULL)
	 {   
		 if (pL->pNext != NULL)
		 {
			 List_print(pL,staff_print);
			 if (n == 1)// 判断状态
			 {
               printf("在职人数：%d人",List_count(pL));
			 }
			  else
			   printf("离职人数：%d人",List_count(pL));
		 }
		 else
			 printf("\n\n未查询到相关信息");	    
	 }	         	 

} 




void staff_search_acNO(int n,pList ps,pList pL)
{
    static int id,k = 0;
	struct staff_t *pt;
	static char str[8] = {0};
	pt = (struct staff_t *)(ps->pData);
	if (k == 0)
	{
		printf("\n\n\t\t\t请输入要查询的编号(4位)：");
	    id = glb_putString(str,'0','9',4,2);
		k = 1;
		memset(str,0,sizeof(char));
	}
	if (pt->acNO == id)
	{
		List_add(pL,pt);
	}
    if (ps->pNext == NULL)
   {   
		if (pL->pNext != NULL)
		{		
		    List_print(pL,staff_print);
		}
		else	
		    printf("\n\n输入有误，未查询到相关信息");		
		k = 0;	
   }
	
} 