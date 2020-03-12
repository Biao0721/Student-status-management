#include<iostream>
#include"student.h"
using namespace std;
student::student() {}

int student::getStudentNum() {
	return this->s_num;
}

string student::getStudentName() {
	return this->s_name;
}

string student::getStudentGender() {
	return this->s_gender;
}

string student::getStudentClass() {
	return this->s_class;
}

void student::setStudentNum(int s_num) {
	this->s_num = s_num;
}

void student::setStudentName(string s_name) {
	this->s_name = s_name;
}

void student::setStudentGender(string s_gender) {
	this->s_gender = s_gender;
}

void student::setStudentClass(string s_class) {
	this->s_class = s_class;
}
