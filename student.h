#ifndef STUDENT_HEAD
#define STUDENT_HEAD

typedef struct node
{
	int num;
	char name[15];
	char sex[9];
	int age;
	int english;
	int math;
	int clang;
	int macs;
	int average;
	int total;
	struct node *next;
}student_info;

extern student_info *student_list;
void init_student_info_list();

int student_list_empty();
int add_student_info();
int del_student_info(int num);
int modify_student_info(int num);

student_info *search_student_info(int num);
void display_average();
void display_total();
void display_student_info();

int save_file();
int read_file();
#endif

