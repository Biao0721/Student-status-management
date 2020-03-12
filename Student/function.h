#ifndef FUNCTION_H_
#define FUNCTION_H_
#include"student.h"
#include"course.h"
#include"choose.h"
using namespace std;
typedef struct students {
	student *student;
	struct students *next;
	struct students *last;
}students;
typedef struct courses {
	course *course;
	struct courses *next;
	struct courses *last;
}courses;
typedef struct chooses {
	choose *choose;
	struct chooses *next;
	struct chooses *last;
}chooses;
void getStudents(students *head);   // �ӱ���л��ѧ����Ϣ
void getCourses(courses *head);     // �ӱ��л�ȡ�γ���Ϣ
void getChooses(chooses *head);     // �ӱ��л�ȡѡ����Ϣ
void setScore(chooses *c); // �޸�ѧ���ɼ�
void getStudent(students *s); // ����ѧ����ʾѧ����Ϣ
void getCourse(courses *c);  // ��������ʾ�γ���Ϣ
void getStudentCourse(students *student, courses *course, chooses *choose); // ����ѧ�Ų�ѯѧ��������ѡ�����
void deleteStudent(students *s, chooses *c); // ����ѧ��ɾ��ѧ��
void printStudents(students *head); // ��ʾ����ѧ����Ϣ
void printCourses(courses *head);  // ��ʾ���пγ���Ϣ
void printChooses(chooses *head);  // ��ʾ����ѡ����Ϣ
void save(students *studentsHead, courses *coursesHead, chooses *choosesHead); // ������Ϣ
string getStudentName(int num, students *s); // ����ѧ������
string getCourseName(int num, courses *c);   // ���ؿγ�����
#endif // !FUNCTION_H_

#pragma once