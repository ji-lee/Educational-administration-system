#include"login.h"


/****************************************************
*	函数介绍：login									*
*	实现功能：登录选择　　　　　					*
*	输入参数：无　　								*
*	返回值  ：无　									*
****************************************************/
void login()
{
	STU_PNODE stu_head = load_stu_data();
	TEA_PLINK tea_head = load_tea_data();
	
	while(ONE)
	{
		switch(get_command(SHOW_LOGIN_MENU))
		{
			case 0: 
					student(stu_head);           
					break;
			case 1: 
					teacher(stu_head, tea_head); 
					break;
			case 2: 
					admin(stu_head, tea_head);   
					break;
			case 3: 
					save_stu_data(stu_head);
					save_tea_data(tea_head);
					return;
		}
	}
}

/****************************************************
*	实现功能：显示登录界面菜单　					*
*	输入参数：菜单选择变量							*
*	返回值  ：无　　　　　　						*
****************************************************/
void show_login_menu(int num)
{
	system("clear");
	printf(
		"\n\t     ---------------------------------------\n"
		"\n\t%s  学生登录   "
		"\n\t               "
		"\n\t%s  老师登录   "
		"\n\t               "
		"\n\t%s  管理员登录 "
		"\n\t     ----------"
		"\n\t               "
		"\n\t%s  退出系统   "
		"\n\t     --------  "
		"\n\t            "
		"\n\n\t     提示：<w> -> 上  <s> -> 下  <j> -> 选择"
		"\n\t     ---------------------------------------\n"
		, num == 0 ? MARK_SELECT : MARK_NO_SELECT
		, num == 1 ? MARK_SELECT : MARK_NO_SELECT
		, num == 2 ? MARK_SELECT : MARK_NO_SELECT
		, num == 3 ? MARK_SELECT : MARK_NO_SELECT
		);
	
}

/****************************************************
*	实现功能：从文件中加载学生数据			　		*
*	输入参数：无　　								*
*	返回值  ：学生链表								*
****************************************************/
STU_PNODE load_stu_data()
{
	FILE *fp;
	if(NULL == (fp = fopen("DATA/stu_data.dat", "rb")))
	{
		if(NULL == (fp = fopen("DATA/stu_data.dat", "wb+")))
		{
			system("mkdir DATA");
			if(NULL == (fp = fopen("DATA/stu_data.dat", "wb+")))
			{
			printf("学生数据加载失败．请重新加载．\n");
			exit(0);
			}
		}	
	}
	
	STU_PNODE stu_head = (STU_PNODE)malloc(sizeof(STU_NODE));
	stu_head->next = NULL;

	STU stu_data; 

	while(fread(&stu_data, sizeof(STU), 1, fp) != 0)
	{
		head_insert_stu_node(stu_head, stu_data);
	}

	printf("\n学生数据加载成功．\n");
	
	fclose(fp);
	fp = NULL;
	return stu_head;

}

/****************************************************
*	实现功能：从文件中加载老师数据					*
*	输入参数：无　　								*
*	返回值  ：老师链表								*
****************************************************/
TEA_PLINK load_tea_data()
{
	FILE *fp;
	if(NULL == (fp = fopen("DATA/tea_data.dat", "rb")))
	{
		if(NULL == (fp = fopen("DATA/tea_data.dat", "wb+")))
		{
			printf("老师数据加载失败．请重新加载．\n");
			exit(0);
		}	
	}
	
	TEA_PLINK tea_head = (TEA_PLINK)malloc(sizeof(TEA_LINK));
	tea_head->next = NULL;

	TEA tea_data; 
	while(fread(&tea_data, sizeof(TEA), 1, fp) != 0)
	{
		head_insert_tea_node(tea_head, tea_data);
	}
	
	printf("老师数据加载成功．\n");
	
	fclose(fp);
	fp = NULL;
	
	return tea_head;

}

/****************************************************
*	实现功能：保存学生数据				　　		*
*	输入参数：学生链表								*
*	返回值  ：无									*
****************************************************/
void save_stu_data(STU_PNODE stu_head)
{
	FILE *fp;
	if(NULL == (fp = fopen("DATA/stu_data.dat", "wb+")))
	{
		printf("学生数据保存失败，请重新保存．\n");
		exit(0);
	}
	if(NULL == stu_head->next)
	{
		printf("退出时学生数据为空，不需要保存数据．\n");
		return;
	}
	
	
	STU_PNODE p = stu_head->next;
	while(p != NULL)
	{
		fwrite(&p->stu_data, sizeof(STU), 1, fp);
		p = p->next;
	}
		
	fclose(fp);
	fp = NULL;

}

/****************************************************
*	实现功能：保存教师数据				　　		*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void save_tea_data(TEA_PLINK tea_head)
{
	FILE *fp;
	if(NULL == (fp = fopen("DATA/tea_data.dat", "wb+")))
	{
		printf("教师数据保存失败，请重新保存．\n");
		exit(0);
	}
	if(NULL == tea_head->next)
	{
		printf("退出时教师数据为空，不需要保存数据．\n");
		return;
	}
	
	
	TEA_PLINK p = tea_head->next;
	while(p != NULL)
	{
		fwrite(&p->tea_data, sizeof(TEA), 1, fp);
		p = p->next;
	}
	
	fclose(fp);
	fp = NULL;
	
	system("clear");
}

