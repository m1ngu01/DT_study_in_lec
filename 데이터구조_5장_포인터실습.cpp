/*
프로그램 내용 : 5장 포인터와 연결리스트 실습
실습 날짜 : 2020.04.11
학번 : 202011309
이름 : 임민규
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct student {
	int id;
	char name[20];
	char dept[32];
}Student;

void test1(Student s);
void test2(Student *s);
Student test3(Student s);

int main() {
	Student s1, s2;
	Student* ps = &s2;

	s1.id = 10;
	strcpy(s1.name, "park");
	strcpy(s1.dept, "Computer eng");
	*ps = s1;
	printf("ps->id : %d, ps->name : %s, ps->dept : %s\n", ps->id, ps->name, ps->dept);
	test1(s2);
	printf("ps->id : %d, ps->name : %s, ps->dept : %s\n", ps->id, ps->name, ps->dept);
	test2(ps);
	printf("ps->id : %d, ps->name : %s, ps->dept : %s\n", ps->id, ps->name, ps->dept);
	s2 = test3(s2); // *ps = test3(s2)
	printf("ps->id : %d, ps->name : %s, ps->dept : %s\n", ps->id, ps->name, ps->dept);
	return 0;
}

void test1(Student s) {
	s.id = 20;
}

void test2(Student *s) {
	s->id = 20;
}

Student test3(Student s) {
	s.id = 30;
	return s;
}