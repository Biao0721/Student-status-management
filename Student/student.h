#ifndef SSUDENT_H_
#define STUDENT_H_
#include<string>
using namespace std;

class student {
private:
	int s_num = 0;        // 学生学号
	string s_name = "";   // 学生姓名
	string s_gender = ""; // 学生性别
	string s_class = "";  // 学生班级
public:
	student();
	int getStudentNum();       // 获得学生学号
	string getStudentName();   // 获得学生姓名
	string getStudentGender(); // 获得学生性别
	string getStudentClass();  // 获得学生班级
	void setStudentNum(int s_num);          // 修改学生学号
	void setStudentName(string s_name);     // 修改学生姓名
	void setStudentGender(string s_gender); // 修改学生性别
	void setStudentClass(string s_class);   // 修改学生班级
};

#endif // !SSUDENT_H_
#pragma once