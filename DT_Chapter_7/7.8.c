/*
* 프로그램 내용: 7.8 하노이의 탑 문제 프로그램
* 실습날짜 : 2023.05.04
* 실습자 : 임민규
* 학번 : 202011309
*/
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		print("원판 1을 %c에서 %c으로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, tmp);
	}
}
void main() {
	hanoi_tower(4, 'A', 'B', 'C');
}