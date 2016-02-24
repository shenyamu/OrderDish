/************************************************************************
* 版权所有  (c)2008,   RunShan
* 文件名称： main.c

* 内容摘要：
*     本文件为主函数入口，实现系统的运行。
* 历史记录：
*     创建日期：2013-08-05   修改人：沈永木
*************************************************************************/
#include <windows.h>
#include ".\\Staff\staff.h"
#include ".\\File\File.h"
#include ".\\Log_in\Log_in.h"
#include ".\\Admin\Admin.h"
#include ".\\Waiter\Waiter.h"
#include ".\\Manage\Manage.h"

 int main()
{
  int n,k;
  pList head;
  char dir_staff[] = "./Date/Staff.txt";
  FILE * fp;
  int (*pF[3])() = {Ui_waiter,Ui_manage,Ui_admin};
  fp = File_open(dir_staff); 
  head = File_read(fp,sizeof(struct staff_t));
  if (head->pNext == NULL)
  {
	  Login_init(fp,head);
  }   
	  while (1)
	  {
	      fclose(fp);
		  n = Log_in(head);
	      k = pF[n]();
	      if (k == 1)
			   break;
		  else
		  {
		    fp = File_open(dir_staff); 
            head = File_read(fp,sizeof(struct staff_t));
		  }

	  }
         system("cls");
         printf("\n\n\n\n\t\t\t已退出系统.....");
         return 0; 
}