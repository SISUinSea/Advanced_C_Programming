----------------------------------
* [ 문제 1 ] 포인터  
----------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int* sel_max(int* arr, int m);
void	input(int* arr, int m);
void	output(int* arr, int m);

int main(void) {
	int in[100], out[100], * max, i, N, M;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) {
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}

void	input(int* arr, int m)
{
	for (int* ptr = arr; ptr < arr + m; ptr++)
		scanf("%d", ptr);

}

int* sel_max(int* arr, int m)
{
	int max = 0;
	int* max_ptr = arr;
	int count = 0;
	for (int* ptr = arr; ptr < arr + m; ptr++)
	{
		count = 0;

		for (int* ptr2 = arr; ptr2 < arr + m; ptr2++)
		{
			if (*ptr == *ptr2)
				count++;
			//printf("num: %d, int: %d\n", *ptr, count);
			if (count > max)
			{
				//printf("max num : %d\n", *ptr);
				max = count;
				max_ptr = ptr;
			}
		}
	}
	return(max_ptr);
}

void	output(int* arr, int m)
{
	for (int* ptr = arr; ptr < arr + m; ptr++)
		printf(" %d", *ptr);
}
-------------------------------
* [ 문제 2-2 ]   
-------------------------------
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int input(int* p);
int* sel_next(int* p);
int number(int* p, int* q);
int main() {
	int arr[100], len;
	len = input(arr);
	for (int* p = arr; p < arr + len - 1; p++) {
		int* q = sel_next(p);
		int result = number(p, q);
		printf("%d\n", result);
		p = q - 1;
	}
}

int input(int* p) {
	int cnt = 0;
	for (int* q = p; q < p + 100; q++) {
		scanf("%d", q);
		if (*q == -1) return cnt;
		cnt++;
	}
}
int* sel_next(int* p) {
	int* remember = p;
	if (*p < *(p + 1)) { //값이 증가
		for (int* q = p; q < p + 100; q++) {
			if (*(q + 1) == -1) return remember;
			if (*q < *(q + 1))
				remember = q + 1;
			else return remember;
		}
	}
	else {
		for (int* q = p; q < p + 100; q++) {
			if (*(q + 1) == -1) return remember;
			if (*q > *(q + 1))
				remember = q + 1;
			else return remember;
		}
	}
}
int number(int* p, int* q) {
	int result = 0;
	for (int* i = p; i <= q; i++) {
		if (*i >= 0 && *i < 10)
			result = result * 10 + *i;
	}
	return result;
}
----------------------------------
* [ 문제 3 ] 문자열 
----------------------------------
#include<stdio.h>
#include <string.h>
#pragma warning(disable:4996)
void StringAdd(char arr[], char ch, int index);
int Convertor(char x);
int main(void) {
	char str[16];
	scanf("%s", str);
	int len = 0;
	len = strlen(str);
	char ch;
	for (int i = 0; i<len-1; i++) {
		if (Convertor(str[i]) % 2 == 0 && (Convertor(str[i+1]) % 2 == 0)) {
			ch='*';
			StringAdd(str, ch, i + 1);
			len++;
			i++;
		}
		else if (Convertor(str[i]) % 2 != 0 && (Convertor(str[i + 1]) % 2 != 0)) {
			ch='+';
			StringAdd(str, ch, i + 1);
			len++;
			i++;
		}
		else {
			continue;
		}
	}
	printf("%s", str);
}
void StringAdd(char arr[16], char ch, int index) {
	int len = 0;
	len=strlen(arr);
	for (int i = len; i >= index; i--) {
		arr[i+1]=arr[i];
	}
	if (Convertor(arr[index]) % 2 == 0) {
		arr[index]=ch;
	}
	else {
		arr[index]= ch;
	}
}
int Convertor(char x) {
	int num;
	num = x - '0';
	return num;
}

----------------------------------
* [ 문제 4-2 ]  
----------------------------------

int main(void){
    	char str1[101], str2[101], str3[101][50], str4[101][50];
	char res[251]={0}, *p;
	int i, j, N1, N2, N3, N4, T, flag;

    	gets(str1);
	gets(str2);

	N1=strlen(str1);
	p=str1;
	for (i=0, N3=0; i<=N1; i++){
		if (str1[i]==' '||str1[i]=='\0'){
			str1[i]='\0';
			strcpy(str3[N3], p);
			p=str1+i+1;
			N3++;
		}
	}

	N2=strlen(str2);
	p=str2;
	for (i=0, N4=0; i<=N2; i++){
		if (str2[i]==' '||str2[i]=='\0'){
			str2[i]='\0';
			strcpy(str4[N4], p);
			p=str2+i+1;
			N4++;
		}
	}

	T=0;
	for (i=0; i<N3; i++){
		flag=0;
		for (j=0; j<i; j++){
			if (strcmp(str3[i], str3[j])==0){
				flag=1;
				break;
			}
		}
		if (flag==1){
			strcat(res, str4[T]);
			strcat(res, " ");
			T++;
		}
		else{
			strcat(res, str3[i]);
			strcat(res, " ");
		}
	}

    	printf("%s\n", res);
    	return 0;
}


 

------------------------------------
* [ 문제 5-3 ]  
------------------------------------

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct person {
	char name[11];
	int one, two;
	double total;
	int year, month, day;
};
void swap(struct person* p, struct person* q);
int main() {
	int n, m;
	struct person P[100];
	scanf("%d %d", &n, &m);
	for (struct person* p = P; p < P + n; p++) {
		getchar();
		scanf("%s %d-%d-%d %d %d", p->name, &p->year, &p->month, &p->day, &p->one, &p->two);
		p->total = p->one * 0.8 + p->two * 0.2;
	}
	for (struct person* p = P; p < P + n - 1; p++) {
		for (struct person* pp = P; pp < P + n - 1; pp++) {
			if (pp->total < (pp + 1)->total)
				swap(pp, pp + 1);
			else if (pp->total == (pp + 1)->total) {
				if (pp->one < (pp + 1)->one)
					swap(pp, pp + 1);
				else if (pp->one == (pp + 1)->one) {
					if (pp->year < (pp + 1)->year)
						swap(pp, pp + 1);
					else if (pp->year == (pp + 1)->year) {
						if (pp->month < (pp + 1)->month)
							swap(pp, pp + 1);
						else if (pp->month == (pp + 1)->month) {
							if (pp->day < (pp + 1)->day)
								swap(pp, pp + 1);
						}
					}
				}
			}
		}
	}
	for (struct person* p = P; p < P + m; p++)
		printf("%s %.1f\n", p->name, p->total);
}
void swap(struct person* p, struct person* q) {
	struct person tmp = *p;
	*p = *q;
	*q = tmp;
}