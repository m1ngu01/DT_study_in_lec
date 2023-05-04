#include <stdio.h>
#include <time.h>

//7.1 ��ȯ���� ���丮�� ��� �Լ� 
int factorial(int n) {
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}
//7.2 ��¹��� �߰��� ��ȯ���� ���丮�� ��� ���α׷�
int factorial(int n) {
	printf("factorial(%2d)\n", n);
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}

//7.3 �ݺ����� ���丮�� ��� �Լ�
int factorial_iter(int n) {
	int k, result = 1;
	for (k = n; k > 0; k--)
		result = result * k;
	return result;
}

//7.4 �ݺ����� �ŵ����� ��� �Լ�
double slow_power(double x, int n) {
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return result;
}
//7.5 ��ȯ���� �ŵ� ���� ��� �Լ�
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}

//7.6 ��ȯ���� �Ǻ���ġ���� ��� �Լ�
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1)return 1;
	return (fib(n - 1) + fib(n - 2));
}

//7.7 �ݺ����� �Ǻ���ġ ���� ��� �Լ�
int fib_iter(int n) {
	int i, tmp, current, last;
}

void main() {

	clock_t start = NULL, finish = NULL;
	double duration = NULL;

	start = clock();
	factorial(3);
	finish = clock();
	duration = (finish - start) / CLOCKS_PER_SEC;
}

