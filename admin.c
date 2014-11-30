#include"admin.h"
#include"student.h"
#include"teacher.h"

/****************************************************
*	实现功能：管理员登录函数	　　				*
*	输入参数：学生链表和教师链表					*
*	返回值  ：无									*
****************************************************/
void admin(STU_PNODE stu_head, TEA_PLINK tea_head)
{
	ADMIN admin = load_admin_data();
	
	int num = login_admin();
	if(NOT_FOUND == num)
	{
		return;
	}
	while(ONE)
	{
		admin = load_admin_data();
			
		switch(get_command(SHOW_AD_LOGIN_MENU))
		{
			case 0:  change_ad_name(admin);                press_any_one(); break;
			case 1:  change_ad_passwd(admin);              press_any_one(); break;
			
			case 2:  add_stu_message(tea_head, stu_head);  press_any_one(); break;
			case 3:  find_stu_message(stu_head);           press_any_one(); break;
			case 4:  delete_student(tea_head, stu_head);   press_any_one(); break;
			case 5:  change_stu_message(stu_head);    break;
			case 6:  show_all_stu_message(stu_head);  break;
			
			case 7:  add_tea_message(tea_head);     	    press_any_one(); break;
			case 8:  find_tea_message(tea_head);     	    press_any_one(); break;
			case 9:  delete_tea_message(tea_head);    	    press_any_one(); break;
			case 10:  change_tea_message(tea_head);   break;
			case 11: show_all_tea_message(tea_head); 		press_any_one(); break;
			case 12: return;
		}
	}
}

/****************************************************
*	实现功能：更改管理员帐号名称					*
*	输入参数：管理员结构体							*
*	返回值  ：无									*
****************************************************/
void change_ad_name(ADMIN admin)
{
	system("clear");
	char new_name[NAME_MAX];
	printf("\n请输入原账号：");
	mygets(new_name, NAME_MAX);
	if(0 != strcmp(new_name, admin.name))
	{
		system("clear");
		printf("\n原账号输入错误，不能更改账号名称．\n");
		return;
	}
	
	printf("请输入新的帐号：");
	mygets(new_name, NAME_MAX);

	char yes_or_no;
	printf("是否保存新帐号？（ｙ/ｎ）");
	yes_or_no = getchar();
	while(getchar() != '\n');

	if(yes_or_no != 'y' && yes_or_no != 'n')
	{
		system("clear");
		printf("\n输入错误，帐号更改失败．\n");
		return;
	}
	if(yes_or_no == 'y')
	{
		strcpy(admin.name, new_name);
		save_admin_data(admin);
		system("clear");
		printf("\n帐号更改并保存成功．\n");
	}
	if(yes_or_no == 'n')
	{
		system("clear");
		printf("\n已放弃帐号更改．\n");
		return;
	}
}

/****************************************************
*	实现功能：更改管理员密码　　					*
*	输入参数：管理员结构体							*
*	返回值  ：无									*
****************************************************/
void change_ad_passwd(ADMIN admin)
{
	system("clear");
	
	char new_passwd[PASSWD_MAX];
	strcpy(new_passwd, getpass("\n请输入原密码："));
	
	if(0 != strcmp(new_passwd, admin.passwd))
	{
		system("clear");
		printf("\n原密码输入错误，不能更改密码．\n");
		return;
	}
	
	strcpy(new_passwd, getpass("请输入新密码(不大于16位)："));
	
	char new_passwd_1[PASSWD_MAX];
	strcpy(new_passwd_1, getpass("请再输入一次新密码："));
	
	if(strcmp(new_passwd, new_passwd_1) == 0)
	{
		printf("是否保存新密码？(ｙ/ｎ)：");
		char yes_or_no = getchar();
		while(getchar() != '\n');
		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			system("clear");
			printf("\n输入错误，密码更改失败．\n");
			return;
		}
		if(yes_or_no == 'y')
		{
			strcpy(admin.passwd, new_passwd);
			save_admin_data(admin);
			system("clear");
			printf("\n密码更改并保存成功．\n");
		}
		if(yes_or_no == 'n')
		{
			system("clear");
			printf("\n已放弃密码更改．\n");
			return;
		}
	}
	else
	{
		system("clear");
		printf("\n两次输入不一致，密码更改失败．\n");
		return;
	}
}

/****************************************************
*	实现功能：添加教师信息							*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void add_tea_message(TEA_PLINK tea_head)
{
	system("clear");
	
	TEA tea_data;
	
	printf("\n请输入教师id(4位数字)：");
	scanf("%d", &tea_data.id);
	while(getchar() != '\n');
	
	if(tea_data.id < 1000 || tea_data.id > 9999)
	{
		system("clear");
		printf("\n教师id输入错误，添加教师信息失败．\n");
		return;
	}
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_data.id);
	if(find != NULL)
	{
		system("clear");
		printf("\nid已存在，添加教师信息失败．\n");
		return;
	}
	
	printf("请输入添加的教师姓名(不大于20个字符)：");
	char new_name[NAME_MAX];
	mygets(new_name, NAME_MAX);
	strcpy(tea_data.name, new_name);
	
	printf("请输入添加的教师性别('m'或'f')：");
	tea_data.sex = toupper(getchar());
	while(getchar() != '\n');
	
	if(tea_data.sex != 'M' && tea_data.sex != 'F')
	{
		system("clear");
		printf("\n性别输入错误，添加教师信息失败．\n");
		return;
	}
	
	printf("请输入添加的教师年龄(1-150)：");
	scanf("%d", &tea_data.age);
	while(getchar() != '\n');
	if(tea_data.age > 150 || tea_data.age < 1)
	{
		system("clear");
		printf("\n年龄小于1岁或超过150岁，添加教师信息失败．\n");
		return;
	}

	printf("请输入添加的教师教的科目(\"math\" or \"chinese\" or \"c_program\")：");
	mygets(tea_data.subject, SUBJECT_MAX);
	if((strcmp(tea_data.subject, "math") != 0) && (strcmp(tea_data.subject, "chinese") != 0) && (strcmp(tea_data.subject, "c_program") != 0))
	{
		system("clear");
		printf("\n科目名称输入错误，添加教师信息失败．\n");
		return;
	}
	
	printf("添加的教师是否为辅导员(input \"yes\" or \"no\")：");
	char is_head_teacher[4];  // 为什么是3时，输入yes，不行？
	mygets(is_head_teacher, 4);
	
	if((strcmp(is_head_teacher, "yes") != 0) && (strcmp(is_head_teacher, "no") != 0))
	{
		system("clear");
		printf("\n是否为辅导员输入错误，添加教师信息失败．\n");
		return;
	}
	if(strcmp(is_head_teacher, "yes") == 0)
		strcpy(tea_data.head_teacher, "yes");
	else
		strcpy(tea_data.head_teacher, "no");

	
//初始化密码
	strcpy(tea_data.passwd, "123456");

	head_insert_tea_node(tea_head, tea_data);
	
	system("clear");
	printf("\n教师信息添加完成！新添加教师密码初始为123456.\n");

}

/****************************************************
*	实现功能：查找教师信息							*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void find_tea_message(TEA_PLINK tea_head)
{
	system("clear");
	if(tea_head->next == NULL)
	{
		printf("\n教师信息为空．\n");
		return;
	}
	int find_id;
	printf("\n请输入要查找的教师id:");
	scanf("%d",&find_id);
	while(getchar() != '\n');

	TEA_PLINK find = find_tea_pre_node(tea_head, find_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	show_tea_message(find->next);	
}

/****************************************************
*	实现功能：删除教师信息							*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void delete_tea_message(TEA_PLINK tea_head)
{
	system("clear");
	if(tea_head->next == NULL)
	{
		printf("\n教师信息为空，没有信息可以删除．\n");
		return;
	}
	
	output_tea_node(tea_head);
	
	int find_id;
	printf("\n请输入要删除的教师id:");
	scanf("%d",&find_id);
	while(getchar() != '\n');

	TEA_PLINK find = find_tea_pre_node(tea_head, find_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	delete_tea_node(find); // 删除find的下一个节点
	system("clear");
	printf("\n删除教师数据成功．\n");	
}

/****************************************************
*	实现功能：显示所有教师信息						*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void show_all_tea_message(TEA_PLINK tea_head)
{
	if(tea_head->next == NULL)
	{
		system("clear");
		printf("\n教师信息为空，没有数据可以显示．\n");
		return;
	}
	
	bubble_sort_tea(tea_head);
	output_tea_node(tea_head);
}

/****************************************************
*	实现功能：显示管理员登录界面					*
*	输入参数：登录参数								*
*	返回值  ：无									*
****************************************************/
void show_ad_login_menu(int num)
{
	system("clear");
	printf(
		"\n\t     -----------------------------------------\n"
		"\n\t     个人帐号管理"
		"\n\t     ------------"
		"\n\t%s  更改个人帐号 "
		"\n\t%s  更改个人密码 "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t     学生管理    "
		"\n\t     ------------"
		"\n\t%s  增加学生信息 "
		"\n\t%s  查找学生信息 "
		"\n\t%s  删除学生信息 "
		"\n\t%s  更改学生信息 "
		"\n\t%s  查看学生信息 "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t     教师管理    "
		"\n\t     ------------"
		"\n\t%s  增加教师信息 "
		"\n\t%s  查找教师信息 "
		"\n\t%s  删除教师信息 "
		"\n\t%s  更改教师信息 "
		"\n\t%s  查看教师信息 "
		"\n\t     ------------"
		"\n\t                 "
		"\n\t%s  返回上一层   "
		"\n\t     ------------"
		"\n\t                 "
		"\n\n\t     提示：<w> -> 上   <s> -> 下   <j> -> 选择"
		"\n\t     -----------------------------------------\n"
		, num == 0 ? MARK_SELECT : MARK_NO_SELECT
		, num == 1 ? MARK_SELECT : MARK_NO_SELECT
		, num == 2 ? MARK_SELECT : MARK_NO_SELECT
		, num == 3 ? MARK_SELECT : MARK_NO_SELECT
		, num == 4 ? MARK_SELECT : MARK_NO_SELECT
		, num == 5 ? MARK_SELECT : MARK_NO_SELECT
		, num == 6 ? MARK_SELECT : MARK_NO_SELECT
		, num == 7 ? MARK_SELECT : MARK_NO_SELECT
		, num == 8 ? MARK_SELECT : MARK_NO_SELECT
		, num == 9 ? MARK_SELECT : MARK_NO_SELECT
		, num == 10 ? MARK_SELECT : MARK_NO_SELECT
		, num == 11 ? MARK_SELECT : MARK_NO_SELECT
		, num == 12 ? MARK_SELECT : MARK_NO_SELECT
		);
}

/****************************************************
*	实现功能：登录管理员帐号						*
*	输入参数：无									*
*	返回值  ：登录成功与否参数						*
****************************************************/
int login_admin()
{
	system("clear");
	
	ADMIN admin = load_admin_data();

	printf("\n请输入管理员帐号：");
	char input_id[NAME_MAX];
	mygets(input_id, NAME_MAX);
	if(0 != strcmp(input_id, admin.name))
	{
		system("clear");
		printf("\n管理员账户输入错误．\n");
		press_any_one();
		return NOT_FOUND;
	}
	char input_passwd[PASSWD_MAX];
	strcpy(input_passwd, getpass("请输入管理员密码："));
	
	int i = 2;
	while(0 != strcmp(input_passwd, admin.passwd) && i != 0)
	{
		system("clear");
		printf("\n密码输入不对，你还有%d次机会重新输入：", i);
		strcpy(input_passwd, getpass(""));
		i--;
	}
	if((0 == i) && (0 != strcmp(input_passwd, admin.passwd)))
	{
		system("clear");
		printf("\n三次密码输入错误．登录不成功．\n");
		press_any_one();
		return NOT_FOUND;
	}
	
	return FOUND;
}

/****************************************************
*	实现功能：加载管理员数据						*
*	输入参数：无									*
*	返回值  ：管理员结构体							*
****************************************************/
ADMIN load_admin_data()
{
	FILE * fp = fopen("DATA/admin.dat", "r");
	if( NULL == fp )
	{
		fp = fopen("DATA/admin.dat", "w+");
		if( NULL == fp )
		{
			system("mkdir DATA");
			fp = fopen("DATA/admin.dat", "w+");
		}
		fprintf(fp, "%s\n%s", "admin", "admin");
		rewind(fp);
	}
	ADMIN admin;
	fscanf(fp, "%s%s", admin.name, admin.passwd);
	fclose(fp);
	fp = NULL;
	return admin;
}

/****************************************************
*	实现功能：保存管理员数据						*
*	输入参数：管理员结构体							*
*	返回值  ：无									*
****************************************************/
void save_admin_data(ADMIN admin)
{
	FILE * fp = fopen("DATA/admin.dat", "w");
	if( NULL == fp )
	{
		printf("\n\t保存错误!\n");
		press_any_one();
		return;
	}
	fprintf(fp, "%s\n%s", admin.name, admin.passwd);
	fclose(fp);
	fp = NULL;
}

