#include<iostream>
#include"course.h"
#include"choose.h"
#include"student.h"
#include"function.h"
using namespace std;

int main() {
	students *head1 = (students*)malloc(sizeof(students));
	courses *head2 = (courses*)malloc(sizeof(courses));
	chooses *head3 = (chooses*)malloc(sizeof(chooses));

	while (true)
	{
		getStudents(head1);
		getCourses(head2);
		getChooses(head3);

		int flag;
		cout << "--------------------" << endl;
		cout << "\n1.显示所有学生信息" << endl;
		cout << "\n2.显示所有课程信息" << endl;
		cout << "\n3.显示所有选课信息" << endl;
		cout << "\n4.修改学生成绩信息" << endl;
		cout << "\n5.查询指定学生信息" << endl;
		cout << "\n6.查询指定课程信息" << endl;
		cout << "\n7.显示学生课程信息" << endl;
		cout << "\n8.删除所有学生信息" << endl;
		cout << "\n9.退出" << endl;
		cout << "\n--------------------" << endl;
		cout << "\n你的选择是：";
		cin >> flag;
		system("cls");
		switch (flag)
		{
		case 1:
			printStudents(head1->next);
			break;
		case 2:
			printCourses(head2->next);
			break;
		case 3:
			printChooses(head3->next);
			break;
		case 4:
			setScore(head3->next);
			break;
		case 5:
			getStudent(head1->next);
			break;
		case 6:
			getCourse(head2->next);
			break;
		case 7:
			getStudentCourse(head1->next, head2->next, head3->next);
			break;
		case 8:
			deleteStudent(head1->next, head3->next);
			break;
		case 9:
			exit(1);
			break;
		default:
			break;
		}
		save(head1, head2, head3);
		system("pause");
		system("cls");
	}

	return 0;
}