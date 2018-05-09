#include<stdio.h>

struct personal {

	char name[10];
	char sex;
	char addr[20];
	char depart[20];
	float avg;
	int height;
	int weight;
};

int main(void) {

	struct personal p1[100];
	char str[256];

	FILE * fp = fopen("list.txt", "r + t");

	if (fp == NULL) {
		puts("Failed to open File");
		exit(0);
	}

	for(int i = 0; i<100; i++) {
		//파일 읽기.
		if (fgets(str, 256, fp) == NULL)
			break;
		//파일의 내용을 구조체 멤버변수에 저장.
		fscanf(fp, "%s %c %s %s %f %d %d", p1[i].name, &(p1[i].sex), p1[i].addr, p1[i].depart, &(p1[i].avg), &(p1[i].height), &(p1[i].weight));
		//콘솔창에 출력함.
		printf("%s %c %s %s %0.2f %d %d\n", p1[i].name, p1[i].sex, p1[i].addr, p1[i].depart, p1[i].avg, p1[i].height, p1[i].weight);
	}

	fclose(fp);
	return 0;
}