#include"change_tea_message.h"

/****************************************************
*	实现功能：更改教师信息登录选项					*
*	输入参数：教师链表								*
*	返回值  ：	无									*
****************************************************/
void change_tea_message(TEA_PLINK tea_head)
{
	system("clear");
	if(NULL == tea_head->next)
	{
		printf("\n教师数据为空，没有数据可以更改．\n");
		press_any_one();
		return;
	}
	
	while(ONE)
	{
		
		switch(get_command(SHOW_CHANGE_TEA_MENU))
		{
			case 0:change_tea_id(tea_head);press_any_one();      break;
			case 1:change_tea_name(tea_head);press_any_one();    break;
			case 2:change_tea_sex(tea_head);press_any_one();     break;
			case 3:change_tea_age(tea_head);press_any_one();     break;
			case 4:change_tea_subject(tea_head);press_any_one(); break;
			case 5:init_tea_passwd(tea_head); press_any_one();   break;
			case 6:return;
		}
	}
}

/****************************************************
*	实现功能：更改教师id							*
*	输入参数：教师链表								*
*	返回值  ：	无									*
****************************************************/
void change_tea_id(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要更改的教师id：");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');

	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	
	int new_id = 0;
	printf("请输入新的教师id(4位数字):");
	scanf("%d", &new_id);
	while(getchar() != '\n');
	
	if(new_id < 1000 || new_id > 9999)
	{
		system("clear");
		printf("\n输入错误，更改教师id失败．\n");
		return;
	}
	
	if(find->next->tea_data.id == new_id)
	{
		system("clear");
		printf("\n您输入的新id与之前的id一样，无需更改．\n");
		return;
	}
	
	find = find_tea_pre_node(tea_head, new_id);
	if(find != NULL)
	{
		system("clear");
		printf("\nid已存在．更改教师id失败．\n");
		return;
	}
	
	find->next->tea_data.id = new_id;
	
	system("clear");
	printf("\n教师id更改完成．\n");
}

/****************************************************
*	实现功能：更改教师姓名							*
*	输入参数：教师链表								*
*	返回值  ：	无									*
****************************************************/
void change_tea_name(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要更改的教师id:");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	
	char str[NAME_MAX];
	printf("请输入新的教师name(不大于20个字符):");
	mygets(str, NAME_MAX);
	strcpy(find->next->tea_data.name, str);
	
	system("clear");
	printf("\n教师name更改完成．\n");
}

/****************************************************
*	实现功能：更改教师性别							*
*	输入参数：教师链表								*
*	返回值  ：	无								*
****************************************************/
void change_tea_sex(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要更改的教师id:");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}

	char yes_or_no;
	if(find->next->tea_data.sex == 'M')
	{
		printf("该教师是男性，您确定要改变他的性别，让他成为女性吗？(y/n)");
		yes_or_no = tolower(getchar());
		while(getchar() != '\n');
		
		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			printf("输入错误．教师性别更改失败．\n");
			return;
		}
		if(yes_or_no == 'y')
		{
			system("clear");
			find->next->tea_data.sex = 'F';
			printf("操作成功，%s老师现在是女性了．^_^\n", find->next->tea_data.name);
		}
		else
		{
			system("clear");
			printf("您放弃了对%s老师的性别更改．\n", find->next->tea_data.name);
		}
	}
	else
	{
		printf("该教师是女性，您确定要改变她的性别，让她成为男性吗？(y/n)");
		yes_or_no = tolower(getchar());
		while(getchar() != '\n');
		
		if(yes_or_no != 'y' && yes_or_no != 'n')
		{
			printf("输入错误．教师性别更改失败．\n");
			return;
		}
		if(yes_or_no == 'y')
		{
			system("clear");
			find->next->tea_data.sex = 'F';
			printf("操作成功，%s老师现在是男性了．^_^\n", find->next->tea_data.name);
		}
		else
		{
			system("clear");
			printf("您放弃了对%s老师的性别更改．\n", find->next->tea_data.name);
		}
	}
}

/****************************************************
*	实现功能：更改教师年龄							*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void change_tea_age(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要更改的教师id:");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	
	int new_age;
	printf("请输入新的教师年龄:");
	scanf("%d", &new_age);
	while(getchar() != '\n');
	
	if(new_age < 1 || new_age > 150)
	{
		system("clear");
		printf("\n年龄输入小于1岁或超过150岁．更改失败．\n");
		return;
	}
	
	find->next->tea_data.age = new_age;
	
	system("clear");
	printf("教师年龄更改完成．\n");
}

/****************************************************
*	实现功能：更改教师所教科目						*
*	输入参数：教师链表								*
*	返回值  ：无									*
****************************************************/
void change_tea_subject(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要更改的教师id:");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	
	printf("请输入新的学科名字(\"math\" or \"chinese\" or \"c_program\")：");
	char new_subject[SUBJECT_MAX];
	mygets(new_subject, SUBJECT_MAX);

	if((strcmp(new_subject, "math") != 0) && (strcmp(new_subject, "chinese") != 0) && (strcmp(new_subject, "c_program") != 0))
	{
		system("clear");
		printf("学科名称输入错误，更改失败．\n");
		return;
	}
	strcpy(find->next->tea_data.subject, new_subject);
	
	system("clear");
	printf("\n学科更改完成．\n");
}

/****************************************************
*	实现功能：初始化教师密码						*
*	输入参数：教师链表								*
*	返回值  ：	无									*
****************************************************/
void init_tea_passwd(TEA_PLINK tea_head)
{
	system("clear");
	output_tea_node(tea_head);
	
	printf("\n请输入要初始化密码的教师id:");
	int tea_id;
	scanf("%d",&tea_id);
	while(getchar() != '\n');
	
	TEA_PLINK find = find_tea_pre_node(tea_head, tea_id);
	if(NULL == find)
	{
		system("clear");
		printf("\n该教师id不存在．\n");
		return;
	}
	
	strcpy(find->next->tea_data.passwd, "123456");
	
	system("clear");
	printf("\n教师%s的密码初始化成功，密码为：123456\n", find->next->tea_data.name);

}

/****************************************************
*	实现功能：更改教师信息界面显示					*
*	输入参数：箭头指示位置							*
*	返回值  ：	无									*
****************************************************/
void show_change_tea_menu(int num)
{
	system("clear");
	printf(
		"\n\t     ----------------------------------------\n"
		"\n\t%s  更改教师id  "
		"\n\t%s  更改教师姓名"
		"\n\t%s  更改教师性别"
		"\n\t%s  更改教师年龄"
		"\n\t%s  更改教学科目"
		"\n\t%s  初始化教师密码"
		"\n\t     -----------"
		"\n\t                 "
		"\n\t%s  返回上一层"
		"\n\t     -----------"
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
		);
}
