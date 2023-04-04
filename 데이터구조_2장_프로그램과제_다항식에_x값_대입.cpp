/*
프로그램 내용 : 교재 2장 프로그램 과제 (다항식에 x 값 대입 계산)
실습일 : 2023-04-04
실습자 : 임민규
학번 : 202011309
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DEGREE 101 // 다항식의 최고 차수 + 1


typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} Polynomial;

void print_poly(Polynomial p, const char str[])
{
	int i;
	printf("\t%s", str);
	for (i = 0; i < p.degree; i++)
		printf("%5.1f x^%d + ", p.coef[i], p.degree - i);
	printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial read_poly()
{
	int i;
	Polynomial p;
	printf("다항식의 최고 차수를 입력하시오: ");
	scanf_s("%d", &p.degree);
	printf("각 항의 계수를 입력하시오 (총 %d개): ", p.degree + 1);
	for (i = 0; i <= p.degree; i++)
		scanf_s("%f", p.coef + i);
	return p;
}


Polynomial add_poly(Polynomial a, Polynomial b)
{
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++)
			p.coef[i + (p.degree - a.degree)] +=	 a.coef[i];
	}
	return p;
}


//교재 2장 프로그램 과제
double Cal_poly(Polynomial p, double x) {
	double sum = 0;
	int i = 0;

	for (i; i < p.degree + 1; i++) {
		sum += p.coef[i] * pow(x, p.degree - i);
	}

	return sum;
}

void main()
{
	Polynomial a, b, c;
	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, "A+B= ");
	printf("%f", Cal_poly(c, 1));

}