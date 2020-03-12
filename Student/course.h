#ifndef COURSE_H_
#define COURSE_H_
#include<string>
using namespace std;

class course {
private:
	int c_num = 0;      // 课程编号
	string c_name = ""; // 课程名称
	int c_code = 0;     // 课程学分
public:
	course();
	int getCourseNum();     // 获取课程编号
	string getCourseName(); // 获得课程名称
	int getCourseCode();    // 获取课程学分
	void setCourseNum(int c_num);      // 修改课程编号
	void setCourseName(string c_name); // 修改课程名称
	void setCourseCode(int c_code);    // 修改课程学分
};
#endif // !COURSE_H_

#pragma once
