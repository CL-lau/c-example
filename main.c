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
	printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
	printf("***************************\n");
	printf("---------------------------\n");
	init_student_info_list();
	if(read_file()) 
		printf("���ļ��ж�ȡѧ����Ϣ�ɹ�\n");
	else
		printf("���ļ��ж�ȡѧ����Ϣʧ��\n");
	printf("---------------------------\n");
	menu();
	while(1)
	{
		printf("ѡ�����:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
					display_student_info();
				break;
			case 2:
				if(add_student_info())
					printf("���ѧ����Ϣ�ɹ�\n");
				else
					printf("���ѧ����Ϣʧ��\n");
				break;
			case 3:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
				{
					printf("������Ҫɾ��ѧ����ѧ��:");
					scanf("%d",&num);
					if(delete_student_info(num))
						printf("�ɹ�ɾ��ѧ�Ŷ�Ӧ��ѧ����Ϣ\n");
					else
						printf("ɾ��ʧ��\n");
				}
				break;
			case 4:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
				{
					printf("������Ҫɾ��ѧ����ѧ��:");
					scanf("%d",&num);
					if(modify_student_info(num))
						printf("�ɹ��޸�ѧ�Ŷ�Ӧ��ѧ����Ϣ\n");
					else
						printf("�޸�ʧ��\n");
				}
				break;
			case 5:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
				    display_average();
				break;
			case 6:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
				    display_total();
				break;
			case 7:
				if(student_list_empty())
					printf("ѧ����ϢΪ�գ��������ѧ����Ϣ\n");
				else
				{
					if(save_file())
						printf("����ѧ����Ϣ�ɹ�\n");
					else
						printf("����ѧ����Ϣʧ��\n");
				}
				break;
			case 0:
			    printf("�ټ�\n");
				system("pause");
				exit(0);
				break;
			default:
			   printf("�������������ѡ��\n");
		}
	}
	system("pause");
	return 0;
}

void menu()
{
	printf("1.�鿴ѧ����Ϣ\n");
	printf("2.���ѧ����Ϣ\n");
	printf("3.ɾ��ѧ����Ϣ\n");
	printf("4.�޸�ѧ����Ϣ\n");
	printf("5.���ƽ���ɼ�\n");
	printf("6.����ܳɼ�\n");
	printf("7.����ѧ����Ϣ\n");
	printf("0.�˳�ϵͳ\n");
}
