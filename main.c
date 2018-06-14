#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void menu();
student_info *student_list;
int main()
{
	int choice;
	int num;
	printf("***************************\n");
	printf("欢迎使用学生信息管理系统\n");
	printf("***************************\n");
	printf("---------------------------\n");
	init_student_info_list();
	if(read_file()) 
		printf("从文件中读取学生信息成功\n");
	else
		printf("从文件中读取学生信息失败\n");
	printf("---------------------------\n");
	menu();
	while(1)
	{
		printf("选择操作:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
					display_student_info();
				break;
			case 2:
				if(add_student_info())
					printf("添加学生信息成功\n");
				else
					printf("添加学生信息失败\n");
				break;
			case 3:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
				{
					printf("请输入要删除学生的学号:");
					scanf("%d",&num);
					if(delete_student_info(num))
						printf("成功删除学号对应的学生信息\n");
					else
						printf("删除失败\n");
				}
				break;
			case 4:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
				{
					printf("请输入要删除学生的学号:");
					scanf("%d",&num);
					if(modify_student_info(num))
						printf("成功修改学号对应的学生信息\n");
					else
						printf("修改失败\n");
				}
				break;
			case 5:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
				    display_average();
				break;
			case 6:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
				    display_total();
				break;
			case 7:
				if(student_list_empty())
					printf("学生信息为空，请先添加学生信息\n");
				else
				{
					if(save_file())
						printf("保存学生信息成功\n");
					else
						printf("保存学生信息失败\n");
				}
				break;
			case 0:
			    printf("再见\n");
				system("pause");
				exit(0);
				break;
			default:
			   printf("输入错误，请重新选择\n");
		}
	}
	system("pause");
	return 0;
}

void menu()
{
	printf("1.查看学生信息\n");
	printf("2.添加学生信息\n");
	printf("3.删除学生信息\n");
	printf("4.修改学生信息\n");
	printf("5.输出平均成绩\n");
	printf("6.输出总成绩\n");
	printf("7.保存学生信息\n");
	printf("0.退出系统\n");
}
