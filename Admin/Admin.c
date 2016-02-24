/************************************************************************
* 版权所有  (c)2008,   卓越计算机职业培训学校。
* 文件名称： Admin.c

* 内容摘要：
*     本文件实现关于管理员管理数据的功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "..\\File\File.h"
#include "..\\Admin\Admin.h"
#include "..\\List\List.h"
#include "..\\Staff\staff.h"
#include "..\\Table\Table.h"
#include "..\\Menu\Menu.h"
#include "..\\Glb_putstring\\Glb_putstring.h"



int Ui_admin()
{  
	int n;
	void (*pst[3])() = {Table_manage,Menu_manage,Staff_manage};
	while(1)
	{	
		system("cls");
		printf("\n\n\n\t\t\t管理员功能选择界面\n\n");
		printf("\t\t\t1、台桌管理\n\n");
		printf("\t\t\t2、菜谱管理\n\n");
		printf("\t\t\t3、人员管理\n\n");
		printf("\t\t\t4、注销\n\n");
		printf("\t\t\t5、退出\n\n");
		printf("\t\t\t请输入您所要选择的功能：");
	    n = glb_putString(NULL,'1','5',1,2);
		if (n > 0 && n <4)
		{
			pst[n-1]();
		}
	    else if(n == 4)
			return 0;
		else if (n == 5)
		     return 1;		    				
	}	

}




void Staff_manage()
{
	char dirname[] = "./Date/Staff.txt";
	FILE *fp;
	pList head;
	int n,count;
	fp = File_open(dirname);
	head = File_read(fp,sizeof(struct staff_t));
	count = List_count(head);
	while(1)
	{	 
		system("cls");
		printf("\n\n\n\t\t\t员工管理界面\n\n");
		printf("\t\t\t1、增加员工\n\n"); 
		printf("\t\t\t2、删除员工\n\n");
		printf("\t\t\t3、修改员工\n\n"); 
		printf("\t\t\t4、查询员工\n\n"); 
		printf("\t\t\t5、返回\n\n"); 
		printf("\t\t\t请输入要操作的功能：");
		n = glb_putString(NULL,'1','5',1,2);
		switch(n)
		{
		case 1:	
			List_print(head,staff_print);
			File_add(fp,head,sizeof(struct staff_t),staff_add);
			List_print(head,staff_print);		
			break;
		case 2:
			List_print(head,staff_print);
			File_remove(fp,head,sizeof(struct staff_t),staff_remove);
			head = File_read(fp,sizeof(struct staff_t));
			List_print(head,staff_print);			
			break;
		case 3:
			List_print(head,staff_print);
			File_updata(fp,head,sizeof(struct staff_t),staff_updata);
			head = File_read(fp,sizeof(struct staff_t));
			List_print(head,staff_print);		
			break;
		case 4:  
			staff_search(head);			
			break;
		case 5:
			break;
		}
		if (n == 5)
		{
			break;
		}
		else
		{
            printf("\n按<Esc>键返回...");
			while(getch() != 27)
			{}
		}
		
		
	}
	List_free(head);
}




void Table_manage()
{
	char dirname[] = "./Date/Table.txt";
	FILE *fp;
	pList head;
	int n;
	fp = File_open(dirname);
	head = File_read(fp,sizeof(struct Table_t));
	while(1)
	{	 
		system("cls");
		printf("\n\n\n\t\t\t台桌管理界面\n\n");
		printf("\t\t\t1、增加台桌\n\n"); 
		printf("\t\t\t2、删除台桌\n\n");
		printf("\t\t\t3、修改台桌\n\n"); 
		printf("\t\t\t4、查询台桌\n\n"); 
		printf("\t\t\t5、返回\n\n"); 
		printf("\t\t\t请输入您要操作的功能：");
	    n = glb_putString(NULL,'1','5',1,2);
		switch(n)
		{
		case 1:	
			List_print(head,Table_print);
			File_add(fp,head,sizeof(struct Table_t),Table_add);
			head = File_read(fp,sizeof(struct Table_t));
			List_print(head,Table_print);			
			break;
		case 2:
			List_print(head,Table_print);
			File_remove(fp,head,sizeof(struct Table_t),Table_remove);
			head = File_read(fp,sizeof(struct Table_t));
			List_print(head,Table_print);
			break;
		case 3:
			List_print(head,Table_print);
			File_updata(fp,head,sizeof(struct Table_t),Table_updata);
		    head = File_read(fp,sizeof(struct Table_t));
			List_print(head,Table_print);
			break;
		case 4: 
		    Table_search(head,3,4);
			break;
		case 5:
			break;
		}
		if (n == 5)
		{
			break;
		}
		else
		{
            printf("\n按<Esc>键返回...");
			while(getch() != 27)
			{}
		}
		
	}
	  List_free(head);
}





void Menu_manage()
{
	char dirname[] = "./Date/Menu.txt";
	FILE *fp;
	pList head;
	int n;
	fp = File_open(dirname);
	head = File_read(fp,sizeof(struct Menu_t));
	while(1)
	{	 
		system("cls");
		printf("\n\n\n\t\t\t菜谱管理界面\n\n");
		printf("\t\t\t1、增加菜谱\n\n"); 
		printf("\t\t\t2、删除菜谱\n\n");
		printf("\t\t\t3、修改菜谱\n\n"); 
		printf("\t\t\t4、查询菜谱\n\n"); 
		printf("\t\t\t5、返回\n\n"); 
		printf("\t\t\t请输入您要操作的功能：");
	    n = glb_putString(NULL,'1','5',1,2);
		switch(n)
		{
		case 1:	
			List_print(head,Menu_print);
			File_add(fp,head,sizeof(struct Menu_t),Menu_add);
			head = File_read(fp,sizeof(struct Menu_t));
			List_print(head,Menu_print);
			break;
		case 2:
			List_print(head,Menu_print);
			File_del(fp,dirname,head,sizeof(struct Menu_t),Menu_del);
			List_print(head,Menu_print);
			break;
		case 3:
			List_print(head,Menu_print);
			File_updata(fp,head,sizeof(struct Menu_t),Menu_updata);
		    head = File_read(fp,sizeof(struct Menu_t));
			List_print(head,Menu_print);
			break;
		case 4: 
	
		    Menu_search(head);
			break;
		case 5:
			break;
		}
		if (n == 5)
		{
			break;
		}
		else
		{
            printf("\n按<Esc>键返回...");
			while(getch() != 27)
			{}
		}
		
	}
	  List_free(head);
}