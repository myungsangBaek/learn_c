#include <stdio.h>

struct Student { //학생 구조체 정의
	char studentId[10];
	char name[10];
	int grade;
	char major[51];
};

int main(void){
	struct Student s; // 구조체 변수 선언
	strcpy(s.studentId, "73013739");//구조체 변수에 접근
	strcpy(s.name, "Han");
	s.grade = 4;
	strcpy(s.major, "컴퓨터교육과");
	printf("학번: %s\n", s.studentId); //구조체 내용 출력
	printf("이름: %s\n", s.name);
	printf("학년: %s\n", s.grade);
	printf("학과: %s\n", s.major);
	system("pause");
	return 0;
}