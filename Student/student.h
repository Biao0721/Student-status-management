#ifndef SSUDENT_H_
#define STUDENT_H_
#include<string>
using namespace std;

class student {
private:
	int s_num = 0;        // ѧ��ѧ��
	string s_name = "";   // ѧ������
	string s_gender = ""; // ѧ���Ա�
	string s_class = "";  // ѧ���༶
public:
	student();
	int getStudentNum();       // ���ѧ��ѧ��
	string getStudentName();   // ���ѧ������
	string getStudentGender(); // ���ѧ���Ա�
	string getStudentClass();  // ���ѧ���༶
	void setStudentNum(int s_num);          // �޸�ѧ��ѧ��
	void setStudentName(string s_name);     // �޸�ѧ������
	void setStudentGender(string s_gender); // �޸�ѧ���Ա�
	void setStudentClass(string s_class);   // �޸�ѧ���༶
};

#endif // !SSUDENT_H_
#pragma once