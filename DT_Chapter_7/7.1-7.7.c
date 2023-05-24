/*
* 프로그램 내용 : 7.1 ~ 7.7 종합 프로그램
* 실습일 : 2023.05.24
* 실습자 : 임민규
* 학번 : 202011309
*/
#include <stdio.h>

//7.1 순환적인 팩토리얼 계산 함수 
int factorial(int n) {
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}
//7.2 출력문이 추가된 순환적인 팩토리얼 계산 프로그램
int factorial(int n) {
	printf("factorial(%2d)\n", n);
	if (n == 1) return 1;
	else return (n * factorial(n - 1));
}

//7.3 반복적인 팩토리얼 계산 함수
int factorial_iter(int n) {
	int k, result = 1;
	for (k = n; k > 0; k--)
		result = result * k;
	return result;
}

//7.4 반복적인 거듭제곱 계산 함수
double slow_power(double x, int n) {
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return result;
}
//7.5 순환적인 거듭 제곱 계산 함수
double power(double x, int n) {
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}

//7.6 순환적인 피보나치수열 계산 함수
int fib(int n) {
	if (n == 0) return 0;
	if (n == 1)return 1;
	return (fib(n - 1) + fib(n - 2));
}

//7.7 반복적인 피보나치 수열 계산 함수
int fib_iter(int n) {
	int i, tmp, current, last;
	if (n < 2) return n;
	else {
		last = 0;
		current - 1;
		for (i = 2; i <= n; i++) {
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

void main() {
	factorial(3);
}

