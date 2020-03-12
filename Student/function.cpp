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

	// 读取学生信息
	ifstream inFile("F:\\student.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //读取csv的一行数据并全部存入ss中
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //一行数据以vector保存
		strArray.push_back(lineArray);  //每一行vector存入strArray中
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
}// 从表格中获得学生信息

void getCourses(courses *head) {
	head->last = NULL;
	head->next = NULL;
	vector<vector<string>> strArray;

	// 读取课程信息
	ifstream inFile("F:\\course.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //读取csv的一行数据并全部存入ss中
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //一行数据以vector保存
		strArray.push_back(lineArray);  //每一行vector存入strArray中
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
}// 从表中获取课程信息

void getChooses(chooses *head) {
	head->last = NULL;
	head->next = NULL;
	vector<vector<string>> strArray;

	// 读取选课信息
	ifstream inFile("F:\\choose.csv", ios::in || ios::out);
	string lineStr;

	while (getline(inFile, lineStr)) {
		stringstream ss(lineStr);       //读取csv的一行数据并全部存入ss中
		string str;
		vector<string> lineArray;
		while (getline(ss, str, ','))
			lineArray.push_back(str);   //一行数据以vector保存
		strArray.push_back(lineArray);  //每一行vector存入strArray中
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
}// 从表中获取选课信息

void setScore(chooses *c) {
	int snum, cnum;
	cout << "\n输入你想修改学生的学号：";
	cin >> snum;
	cout << "\n输入你想删除的课程编号：";
	cin >> cnum;
	for (; c; c = c->next) {
		if (c->choose->getStudentNum() == snum) {
			if (c->choose->getCourseNum() == cnum) {
				int num;
				cout << "\n原始成绩为：" << c->choose->getScore() << endl;
				cout << "\n输入新成绩：";
				cin >> num;
				c->choose->setScore(num);
				cout << "\n修改完成!\n" << endl;
				return;
			}
		}
	}
	cout << "\n未找到对应成绩\n" << endl;
}// 修改学生成绩

void getStudent(students *s) {
	students *flag = (students*)malloc(sizeof(students));
	int s_num;
	cout << "\n你想查询学生的学号：";
	cin >> s_num;
	for (flag = s; flag; flag = flag->next) {
		if (flag->student->getStudentNum() == s_num) {
			cout << "\n--------------------------" << endl;
			cout << flag->student->getStudentNum() << "\t" << flag->student->getStudentName() << " \t" << flag->student->getStudentGender() << "\t" << flag->student->getStudentClass() << endl;
			cout << "--------------------------\n" << endl;
			return;
		}
	}
	cout << "\n未找到对应学生\n" << endl;
}// 输入学号显示学生信息

void getCourse(courses *c) {
	courses *flag = (courses*)malloc(sizeof(courses));
	int c_num;
	cout << "\n你想查询的课程编号：";
	cin >> c_num;
	for (flag = c; flag; flag = flag->next) {
		if (flag->course->getCourseNum() == c_num) {
			cout << "\n-------------------" << endl;
			cout << flag->course->getCourseNum() << "\t" << flag->course->getCourseName() << "\t" << flag->course->getCourseCode() << endl;
			cout << "-------------------\n" << endl;
			return;
		}
	}
	cout << "\n未找到对应课程\n" << endl;
}// 输入编号显示课程信息

void getStudentCourse(students *student, courses *course, chooses *choose) {
	chooses *flag = (chooses*)malloc(sizeof(chooses));
	int sum, num, s_num;
	sum = num = 0;
	cout << "\n你想查询的学生学号：";
	cin >> s_num;
	cout << "\n学生姓名：" << getStudentName(s_num, student) << endl;
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
	cout << "平均分：" << (sum / num) << "\n" << endl;
}// 根据学号查询学生的所有选课情况

void deleteStudent(students *s, chooses *c) {
	int s_num;
	cout << "\n输入你想删除学生的学号：";
	cin >> s_num;
	cout << "\n开始删除..." << endl;
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
	cout << "\n删除完成！\n"<< endl;
}// 根据学号删除学生

void printStudents(students *head) {
	students *flag = (students*)malloc(sizeof(students));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "--------------------------" << endl;
		cout << flag->student->getStudentNum() << "\t" << flag->student->getStudentName() << " \t" << flag->student->getStudentGender() << "\t" << flag->student->getStudentClass() << endl;
	}
	cout << "--------------------------\n" << endl;
} // 显示所有学生信息

void printCourses(courses *head) {
	courses *flag = (courses*)malloc(sizeof(courses));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "-----------------" << endl;
		cout << flag->course->getCourseNum() << "\t" << flag->course->getCourseName() << "\t" << flag->course->getCourseCode() << endl;
	}
	cout << "-----------------\n" << endl;
}// 显示所有课程信息

void printChooses(chooses *head) {
	chooses *flag = (chooses*)malloc(sizeof(chooses));
	cout << "\n";
	for (flag = head; flag; flag = flag->next) {
		cout << "\n---------------------" << endl;
		cout << flag->choose->getStudentNum() << "\t" << flag->choose->getCourseNum() << " \t" << flag->choose->getScore() << endl;
	}
	cout << "---------------------\n" << endl;
}// 显示所有选课信息

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
}// 保存学生信息

string getStudentName(int num, students *s) {
	students *flag = (students*)malloc(sizeof(students));
	for (flag = s; flag; flag = flag->next) {
		if (flag->student->getStudentNum() == num) {
			return flag->student->getStudentName();
		}
	}
	cout << "\n没找到对应的学生\n" << endl;
	return NULL;
}// 返回学生姓名

string getCourseName(int num, courses *c) {
	courses *flag = (courses*)malloc(sizeof(courses));
	for (flag = c; flag; flag = flag->next) {
		if (flag->course->getCourseNum() == num) {
			return flag->course->getCourseName();
		}
	}
	cout << "\n没有找到对应课程\n" << endl;
	return NULL;
} // 返回课程名称