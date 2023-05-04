/*
* 프로그램 내용 : (강의중 실습) 재귀함수 시간측정 프로그램
* 실습자 : 임민규
* 실습일 : 2023.05.04
* 학번: 202011309
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//	Recursion
int fib(int n);
//	Iteration
int fib_iter(int n);

//	Recursion
double power(double x, int n);
//	Iteration
double slow_power(double x, int n);

int main() {
	int ret, n;
	clock_t start, finish;
	double duration;
	double ret1;
	 
	printf("Pleaes enter number");
	scanf("%d", &n);

	start = clock();
	//ret = fib(n) 
	ret1 = power(2, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Recursion (power %d) : %lf\n", n, ret1);
	printf("%f 초입니다", duration);

	start = clock();
	//ret = fib(n) 
	ret1 = slow_power(2, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Iteration (power %d) : %lf\n", n, ret1);
	printf("%f 초입니다", duration);

	return 0;
}