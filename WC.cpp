#include <stdio.h>

void main() {

	int WordCount(FILE *p);
	int CharCount(FILE *p);
	int LineCount(FILE *p);
	int number;
	char FileName[100];
	FILE *fp;
	char se;
	printf("�������û����wc.exe -");
	scanf("%c", &se);
	if (se == 'c') {
		printf("�������ļ�����");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = CharCount(fp);
		printf("�ַ���Ϊ��%d\n", number);
		fclose(fp);
	}
	else if (se == 'w') {
		printf("�������ļ�����");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = WordCount(fp);
		printf("�ʵ���ĿΪ��%d\n", number);
		fclose(fp);
	}
	else if (se == 'l') {
		printf("�������ļ�����");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = LineCount(fp);
		printf("����Ϊ��%d\n", number);
		fclose(fp);
	}
	else {
		printf("�������");
	}

}


int CharCount(FILE *p) {
	if (NULL == p) {
		printf("�Ҳ������ļ���");
	}
	char a;
	int charcount = 0;
	while (!feof(p)) {
		a = fgetc(p);
		if (a != '\n') {
			charcount++;
		}
	}
	return --charcount;
}

int WordCount(FILE *p) {
	if (NULL == p) {
		printf("�Ҳ������ļ�����");
	}
	char b;
	int wordcount = 1;
	b = fgetc(p);
	if (feof(p)) return 0;
	while (!feof(p)) {
		b = fgetc(p);
		if (b == ' ') {
			wordcount++;
		}
	}
	return wordcount;
}

int LineCount(FILE *p) {
	if (NULL == p) {
		printf("�Ҳ������ļ���");
	}
	char c[100];
	int linecount = 0;
	fgetc(p);
	while (!feof(p)) {
		fgets(c, 100, p);
		linecount++;
	}
	return linecount;
}
