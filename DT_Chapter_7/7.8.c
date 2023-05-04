/*
* ���α׷� ����: 7.8 �ϳ����� ž ���� ���α׷�
* �ǽ���¥ : 2023.05.04
* �ǽ��� : �ӹα�
* �й� : 202011309
*/
#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1)
		print("���� 1�� %c���� %c���� �ű��.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �ű��\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, tmp);
	}
}
void main() {
	hanoi_tower(4, 'A', 'B', 'C');
}