/************************************************************************
* 版权所有  (c)2008,   RunShan
* 文件名称： Log_in.c

* 内容摘要：
*     本文件实现关于登录界面和初始化的功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "..\\Log_in\Log_in.h"
char acName[10] = {0};// 存放登陆用户名


void JR_EmptyRaw(int r1,int r2)
{
  int i,j;
  for (i = r1;i <= r2;i++)
  {
    JR_SetCursor(i,0);
    for (j=0;j<=80;j++)
    printf("%c",' ');// 用空格来清空每行
  }

}




void JR_SetCursor(int x, int y)
{
	
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {y, x};
    SetConsoleCursorPosition(hOut, pos);
}



int Log_in(pList head)
{  	 
     int a,b,c;
	 char time[10] = {0};
	 pList pt;
	 struct staff_t *data;
	 char name[10] = {0};// 存放输入的用户名
	 char psd[8] = {0}; // 存放输入的密码
     char role[3][10] ={"服务员","经理","管理员"};
     Ordernum_get(time,NULL);
	 sscanf(time,"%4d%2d%2d",&a,&b,&c);
	 while(1)
 { 
      system("cls");
	  printf("\n\n\n\t\t\t卓越点菜机登录界面\n\n");
	  printf("\t\t\t%-19s","用户名：");
	  printf("(10位)");
	  printf("\n\n\t\t\t%-19s","密码：");
	  printf("(6位)");
      printf("\n\n\n\n\t\t\t\t\t   学    员：沈永木\n");
	  printf("\t\t\t\t\t   当前日期：%4d-%02d-%02d",a,b,c);

	  JR_SetCursor(5,32);// 光标定位到用户名输入的位置
	  glb_putString(name,0,0,10,1);// 控制输入函数，只能输入字母
	  JR_SetCursor(7,30);// 定位到密码输入的位置
      glb_putString(psd,'0','9',6,2);//只能输入数字 
      pt = head->pNext;
		while(pt)
	{
		data = (struct staff_t*)(pt->pData);
		if ((strcmp(data->acName,name) == 0)&&(strcmp(data->psd,psd) == 0))
		{		
		   strcpy(acName,data->acName); // 存储登陆用户名
		   printf("\n\n\t\t\t登录成功，身份为：%s，按任意键继续...",role[data->role]);
		   getch();	  
		   return data->role;// 返回员工角色标志
		}
           pt = pt->pNext;
	}
           printf("\n\n\t\t\t密码输入错误，请重新输入，按任意键继续...");
		   memset(psd,0,sizeof(char));
           getch();
   }
         
}
				



void Login_init(FILE *fp,pList head)
{	
	struct staff_t *data;
	data = (struct staff_t *)malloc(sizeof(struct staff_t));
	data->acNO = 1000;// 初始化超级管理员的参数
	strcpy(data->acName,"admin");
	strcpy(data->psd,"123456");
	data->role = 2;// 管理员身份
	data->flag = 1;
	List_add(head,data);// 添加到链表
	File_write(fp,head,sizeof(struct staff_t),0);// 写入文件   

}
