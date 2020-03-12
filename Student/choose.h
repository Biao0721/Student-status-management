#ifndef CHOOSE_H_
#define CHOOSE_H_
#include<string>
using namespace std;

class choose {
private:
	int snum = 0;      // 学生学号
	int cnum = 0;      // 课程编号
	int score = 0;  // 成绩
public:
	choose();
	int getStudentNum(); // 获取学生学号
	int getCourseNum();  // 获取课程编号
	int getScore();      // 获取课程成绩
	void setStudentNum(int snum); // 修改学生编号
	void setCourseNum(int cnum);  // 修改课程编号
	void setScore(int score);       // 修改学生成绩
};
#endif // !CHOOSE_H_

#pragma once
