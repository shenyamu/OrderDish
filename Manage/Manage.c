/************************************************************************
* 版权所有  (c)2008,   卓越计算机职业培训学校。
* 文件名称： Manage.c

* 内容摘要：
*     本文件实现关于经理查询的功能。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <stdio.h>
#include <windows.h>
#include "..\\Manage\Manage.h"
#include "..\\List\List.h"
#include "..\\Staff\staff.h"
#include "..\\Waiter\Order.h"


int Ui_manage()
{	
	int n;
	while(1)
	{			
		system("cls");
		printf("\n\n\n\t\t\t经理功能选择界面\n\n");
		printf("\t\t\t1、营收汇总\n\n");
		printf("\t\t\t2、注销\n\n");
		printf("\t\t\t3、退出\n\n");
		printf("\t\t\t请输入您所要选择的功能：");
		n = glb_putString(NULL,'1','3',1,2);
	    if (n == 1)
	   {
		Profit_statist();
	   }
		else if(n == 2)
			return 0;
		else if (n == 3)
			return 1;		    				
	}	

}



void Profit_statist()
{
	pList pOrder,pStaff;
	pList p1,p2;
	struct Order_t *Odate;
	struct staff_t *Sdate;
	FILE *fp;
	long money,income;// 总金额
	long *stardate,*enddate;
    long ordernum;// 订单号
	money = income = 0;
	stardate = (long *)malloc(sizeof(long));// 开始日期
    enddate = (long *)malloc(sizeof(long));// 结束日期
	fp = File_open("./Date/Order/Order.txt");
    pOrder= File_read(fp,sizeof(struct Order_t));
	fp = File_open("./Date/Staff.txt");
    pStaff= File_read(fp,sizeof(struct staff_t));

	system("cls");
	printf("\n\t\t\t(1):当天查询\n");
	printf("\n\t\t\t(2):历史查询\n");
	printf("\n\t\t\t请输入要选择的功能：");
	if (glb_putString(NULL,'1','2',1,2) == 1)
	{
		system("cls");
		*stardate = Ordernum_get(NULL,NULL);// 获取当前系统日期
		*enddate = *stardate;
	}
	else
	{
		Orderdate_input(stardate,enddate);// 输入开始和结束日期
		printf("\n");
	}
    printf("\t\t\t%-15s%s\n","服务员","营收");
	p1 = pStaff->pNext;
	while (p1)
	{
		Sdate = (struct staff_t *)(p1->pData);
		p2 = pOrder->pNext;
		while(p2)
		{
			Odate = (struct Order_t *)(p2->pData);
			sscanf(Odate->ordernum,"%8ld",&ordernum);// 获取订单号上的日期
			if ((strcmp(Sdate->acName,Odate->acname) == 0)&&(ordernum <= *enddate) && (ordernum >= *stardate))
			{
				money = money + (Odate->money);
			}
			p2 = p2->pNext;
		}
		if ((Sdate->role == 0))// 判断是否为服务员
		{
			printf("\t\t\t%-15s%s%ld\n",Sdate->acName,"￥",money);
			income = income + money;// 累加每个服务员的营业额
			money = 0;
		}	
		p1 = p1->pNext;
	}

	    printf("\n\t\t\t总营业额：￥%ld\n",income);
		printf("\n\t\t\t请按任意键返回...");
		getch();
}