#include<iostream>
#include<stdio.h>
#include<fstream> 
#include<vector>
#include<sstream> 
#include<string>
#include"student.h"
#include"course.h"
#include"choose.h"
#include"function.h"

void getStudents(students *head) {
	head->last = NULL;
	head->next = NULL;
	vector<vector<string>> strArray;

	// ��ȡѧ����Ϣ
	ifstream inFile("F:\\student.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //��ȡcsv��һ�����ݲ�ȫ������ss��
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //һ��������vector����
		strArray.push_back(lineArray);  //ÿһ��vector����strArray��
	}
	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 0; i < strArray.size(); i++) {
			students *flag = (students*)malloc(sizeof(students));
			student *s = new student();
			s->setStudentNum(stoi(strArray[i][0]));
			s->setStudentName(strArray[i][1]);
			s->setStudentGender(strArray[i][2]);
			s->setStudentClass(strArray[i][3]);
			flag->student = s;
			flag->last = head;
			flag->next = NULL;
			head->next = flag;
			head = flag;
		}
	}
	inFile.close();
}// �ӱ���л��ѧ����Ϣ

void getCourses(courses *head) {
	head->last = NULL;
	head->next = NULL;
	vector<vector<string>> strArray;

	// ��ȡ�γ���Ϣ
	ifstream inFile("F:\\course.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //��ȡcsv��һ�����ݲ�ȫ������ss��
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //һ��������vector����
		strArray.push_back(lineArray);  //ÿһ��vector����strArray��
	}
	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 0; i < strArray.size(); i++) {
			courses *flag = (courses*)malloc(sizeof(courses));
			course *c = new course();
			c->setCourseNum(stoi(strArray[i][0]));
			c->setCourseName(strArray[i][1]);
			c->setCourseCode(stoi(strArray[i][2]));
			flag->course = c;
			flag->last = head;
			flag->next = NULL;
			head->next = flag;
			head = flag;
		}
	}
	inFile.close();
}// �ӱ��л�ȡ�γ���Ϣ

void getChooses(chooses *head) {
	head->last = NULL;
	head->next = NULL;
	vector<vector<string>> strArray;

	// ��ȡѡ����Ϣ
	ifstream inFile("F:\\choose.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //��ȡcsv��һ�����ݲ�ȫ������ss��
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //һ��������vector����
		strArray.push_back(lineArray);  //ÿһ��vector����strArray��
	}
	if (strArray.size() <= 1) {
	}
	else {
		for (int i = 0; i < strArray.size(); i++) {
			chooses *flag = (chooses*)malloc(sizeof(chooses));
			choose *c = new choose();
			c->setStudentNum(stoi(strArray[i][0]));
			c->setCourseNum(stoi(strArray[i][1]));
			c->setScore(stoi(strArray[i][2]));
			flag->choose = c;
			flag->last = head;
			flag->next = NULL;
			head->next = flag;
			head = flag;
		}
	}
	inFile.close();
}// �ӱ��л�ȡѡ����Ϣ

void setScore(chooses *c) {
	int snum, cnum;
	cout << "\n���������޸�ѧ����ѧ�ţ�";
	cin >> snum;
	cout << "\n��������ɾ���Ŀγ̱�ţ�";
	cin >> cnum;
	for (; c; c = c->next) {
		if (c->choose->getStudentNum() == snum) {
			if (c->choose->getCourseNum() == cnum) {
				int num;
				cout << "\nԭʼ�ɼ�Ϊ��" << c->choose->getScore() << endl;
				cout << "\n�����³ɼ���";
				cin >> num;
				c->choose->setScore(num);
				cout << "\n�޸����!\n" << endl;
				return;
			}
		}
	}
	cout << "\nδ�ҵ���Ӧ�ɼ�\n" << endl;
}// �޸�ѧ���ɼ�

void getStudent(students *s) {
	students *flag = (students*)malloc(sizeof(students));
	int s_num;
	cout << "\n�����ѯѧ����ѧ�ţ�";
	cin >> s_num;
	for (flag = s; flag; flag = flag->next) {
		if (flag->student->getStudentNum() == s_num) {
			cout << "\n--------------------------" << endl;
			cout << flag->student->getStudentNum() << "\t" << flag->student->getStudentName() << " \t" << flag->student->getStudentGender() << "\t" << flag->student->getStudentClass() << endl;
			cout << "--------------------------\n" << endl;
			return;
		}
	}
	cout << "\nδ�ҵ���Ӧѧ��\n" << endl;
}// ����ѧ����ʾѧ����Ϣ

void getCourse(courses *c) {
	courses *flag = (courses*)malloc(sizeof(courses));
	int c_num;
	cout << "\n�����ѯ�Ŀγ̱�ţ�";
	cin >> c_num;
	for (flag = c; flag; flag = flag->next) {
		if (flag->course->getCourseNum() == c_num) {
			cout << "\n-------------------" << endl;
			cout << flag->course->getCourseNum() << "\t" << flag->course->getCourseName() << "\t" << flag->course->getCourseCode() << endl;
			cout << "-------------------\n" << endl;
			return;
		}
	}
	cout << "\nδ�ҵ���Ӧ�γ�\n" << endl;
}// ��������ʾ�γ���Ϣ

void getStudentCourse(students *student, courses *course, chooses *choose) {
	chooses *flag = (chooses*)malloc(sizeof(chooses));
	int sum, num, s_num;
	sum = num = 0;
	cout << "\n�����ѯ��ѧ��ѧ�ţ�";
	cin >> s_num;
	cout << "\nѧ��������" << getStudentName(s_num, student) << endl;
	cout << "\n";
	for (flag = choose; flag; flag = flag->next) {
		if (flag->choose->getStudentNum() == s_num) {
			sum += flag->choose->getScore();
			num++;
			cout << "---------------------------" << endl;
			cout << flag->choose->getCourseNum() << "\t" << getCourseName(flag->choose->getCourseNum(), course) << "\t" << flag->choose->getScore() << endl;
		}
	}
	cout << "---------------------------\n" << endl;
	cout << "ƽ���֣�" << (sum / num) << "\n" << endl;
}// ����ѧ�Ų�ѯѧ��������ѡ�����

void deleteStudent(students *s, chooses *c) {
	int s_num;
	cout << "\n��������ɾ��ѧ����ѧ�ţ�";
	cin >> s_num;
	cout << "\n��ʼɾ��..." << endl;
	for (; s; s = s->next) {
		if (s->student->getStudentNum() == s_num) {
			s->last->next = s->next;
			s->next->last = s->last;
		}
	}
	for (; c; c = c->next) {
		if (c->choose->getStudentNum() == s_num) {
			c->last->next = c->next;
			c->next->last = c->last;
		}
	}
	cout << "\nɾ����ɣ�\n"<< endl;
}// ����ѧ��ɾ��ѧ��

void printStudents(students *head) {
	students *flag = (students*)malloc(sizeof(students));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "--------------------------" << endl;
		cout << flag->student->getStudentNum() << "\t" << flag->student->getStudentName() << " \t" << flag->student->getStudentGender() << "\t" << flag->student->getStudentClass() << endl;
	}
	cout << "--------------------------\n" << endl;
} // ��ʾ����ѧ����Ϣ

void printCourses(courses *head) {
	courses *flag = (courses*)malloc(sizeof(courses));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "-----------------" << endl;
		cout << flag->course->getCourseNum() << "\t" << flag->course->getCourseName() << "\t" << flag->course->getCourseCode() << endl;
	}
	cout << "-----------------\n" << endl;
}// ��ʾ���пγ���Ϣ

void printChooses(chooses *head) {
	chooses *flag = (chooses*)malloc(sizeof(chooses));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "\n---------------------" << endl;
		cout << flag->choose->getStudentNum() << "\t" << flag->choose->getCourseNum() << " \t" << flag->choose->getScore() << endl;
	}
	cout << "---------------------\n" << endl;
}// ��ʾ����ѡ����Ϣ

void save(students *studentsHead, courses *coursesHead, chooses *choosesHead) {
	ofstream outFile1;
	ofstream outFile2;
	ofstream outFile3;
	outFile1.open("F:\\student.csv", ios::out);
	outFile2.open("F:\\course.csv", ios::out);
	outFile3.open("F:\\choose.csv", ios::out);
	students *flag1 = studentsHead->next;
	courses *flag2 = coursesHead->next;
	chooses *flag3 = choosesHead->next;
	for (; flag1; flag1 = flag1->next) {
		outFile1 << flag1->student->getStudentNum() << ',' << flag1->student->getStudentName() << ',' << flag1->student->getStudentGender() << ',' << flag1->student->getStudentClass() << endl;
	}
	for (; flag2; flag2 = flag2->next) {
		outFile2 << flag2->course->getCourseNum() << ',' << flag2->course->getCourseName() << ',' << flag2->course->getCourseCode() << endl;
	}
	for (; flag3; flag3 = flag3->next) {
		outFile3 << flag3->choose->getStudentNum() << ',' << flag3->choose->getCourseNum() << ',' << flag3->choose->getScore() << endl;
	}
	outFile1.close();
	outFile2.close();
	outFile3.close();
}// ����ѧ����Ϣ

string getStudentName(int num, students *s) {
	students *flag = (students*)malloc(sizeof(students));
	for (flag = s; flag; flag = flag->next) {
		if (flag->student->getStudentNum() == num) {
			return flag->student->getStudentName();
		}
	}
	cout << "\nû�ҵ���Ӧ��ѧ��\n" << endl;
	return NULL;
}// ����ѧ������

string getCourseName(int num, courses *c) {
	courses *flag = (courses*)malloc(sizeof(courses));
	for (flag = c; flag; flag = flag->next) {
		if (flag->course->getCourseNum() == num) {
			return flag->course->getCourseName();
		}
	}
	cout << "\nû���ҵ���Ӧ�γ�\n" << endl;
	return NULL;
} // ���ؿγ�����