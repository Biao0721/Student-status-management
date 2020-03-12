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
void getStudents(students *head);   // 从表格中获得学生信息
void getCourses(courses *head);     // 从表中获取课程信息
void getChooses(chooses *head);     // 从表中获取选课信息
void setScore(chooses *c); // 修改学生成绩
void getStudent(students *s); // 输入学号显示学生信息
void getCourse(courses *c);  // 输入编号显示课程信息
void getStudentCourse(students *student, courses *course, chooses *choose); // 根据学号查询学生的所有选课情况
void deleteStudent(students *s, chooses *c); // 根据学号删除学生
void printStudents(students *head); // 显示所有学生信息
void printCourses(courses *head);  // 显示所有课程信息
void printChooses(chooses *head);  // 显示所有选课信息
void save(students *studentsHead, courses *coursesHead, chooses *choosesHead); // 保存信息
string getStudentName(int num, students *s); // 返回学生姓名
string getCourseName(int num, courses *c);   // 返回课程名称
#endif // !FUNCTION_H_

#pragma once