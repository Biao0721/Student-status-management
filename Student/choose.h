#ifndef CHOOSE_H_
#define CHOOSE_H_
#include<string>
using namespace std;

class choose {
private:
	int snum = 0;      // ѧ��ѧ��
	int cnum = 0;      // �γ̱��
	int score = 0;  // �ɼ�
public:
	choose();
	int getStudentNum(); // ��ȡѧ��ѧ��
	int getCourseNum();  // ��ȡ�γ̱��
	int getScore();      // ��ȡ�γ̳ɼ�
	void setStudentNum(int snum); // �޸�ѧ�����
	void setCourseNum(int cnum);  // �޸Ŀγ̱��
	void setScore(int score);       // �޸�ѧ���ɼ�
};
#endif // !CHOOSE_H_

#pragma once
