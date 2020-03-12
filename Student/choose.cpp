#include<iostream>
#include"choose.h"
using namespace std;

choose::choose(){}

int choose::getStudentNum(){
	return this->snum;
}

int choose::getCourseNum() {
	return this->cnum;
}

int choose::getScore() {
	return this->score;
}

void choose::setStudentNum(int snum) {
	this->snum = snum;
}

void choose::setCourseNum(int cnum) {
	this->cnum = cnum;
}

void choose::setScore(int score) {
	this->score = score;
}
