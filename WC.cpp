#include <stdio.h>

void main() {

	int WordCount(FILE *p);
	int CharCount(FILE *p);
	int LineCount(FILE *p);
	int number;
	char FileName[100];
	FILE *fp;
	char se;
	printf("请输入用户命令：wc.exe -");
	scanf("%c", &se);
	if (se == 'c') {
		printf("请输入文件名：");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = CharCount(fp);
		printf("字符数为：%d\n", number);
		fclose(fp);
	}
	else if (se == 'w') {
		printf("请输入文件名：");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = WordCount(fp);
		printf("词的数目为：%d\n", number);
		fclose(fp);
	}
	else if (se == 'l') {
		printf("请输入文件名：");
		scanf("%s", &FileName);
		fp = fopen(FileName, "r");
		number = LineCount(fp);
		printf("行数为：%d\n", number);
		fclose(fp);
	}
	else {
		printf("输入错误！");
	}

}


int CharCount(FILE *p) {
	if (NULL == p) {
		printf("找不到该文件！");
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
		printf("找不到该文件！！");
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
		printf("找不到该文件！");
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
