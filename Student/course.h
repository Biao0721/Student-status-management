#ifndef COURSE_H_
#define COURSE_H_
#include<string>
using namespace std;

class course {
private:
	int c_num = 0;      // �γ̱��
	string c_name = ""; // �γ�����
	int c_code = 0;     // �γ�ѧ��
public:
	course();
	int getCourseNum();     // ��ȡ�γ̱��
	string getCourseName(); // ��ÿγ�����
	int getCourseCode();    // ��ȡ�γ�ѧ��
	void setCourseNum(int c_num);      // �޸Ŀγ̱��
	void setCourseName(string c_name); // �޸Ŀγ�����
	void setCourseCode(int c_code);    // �޸Ŀγ�ѧ��
};
#endif // !COURSE_H_

#pragma once
