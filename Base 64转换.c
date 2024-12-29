#include<stdio.h>
#include<string.h>

//十分的满分不知道为什么才6分。，
//学会了十进制如何快速转换为二进制
//按位与
//若转换为一个字节的二进制，则依次将数字右移，先复制一个数字，再对这个数字进行右移j位，j依次从7开始递减，然后让这个右移之后的数字与1进行与运算(num>>j)&1;
//最后直接将每次按位与运算之后的结果存到新的数组里

int get_char(int num) {

	if (num >= 0 && num <= 25) {
		return 'A' + num;
	}

	else if (num >= 26 && num <= 51) {
		return 'a' + (num - 26);
	}

	else if (num >= 52 && num <= 61) {
		return '0' + (num - 52);
	}

	else if (num == 62) {
		return '+';
	}
	else if (num == 63) {
		return '/';
	}
	return -1;
}

int main() {
	char ch;
	char text[100];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		text[i++] = ch;
	}
	text[i] = '\0';
	int len = strlen(text);
	//先录入这些字符的二进制，用按位与操作
	//定义一个存放二进制的数组，
	i = 0;
	int binary_arr[1000];
	int m = 0;
	for (i = 0; i < len; i++) {
		if (text[i] != ' ') {
			for (int j = 7; j >= 0; j--) {
				int num = text[i];
				int bit = (num >> j) & 1;
				binary_arr[m++] = bit;
			}
		} else if (text[i] == ' ') {
			continue;
		}
	}
	//存好之后开始切6位bit
	int index = m;
	if (m % 6 != 0) {
		int step = m % 6;
		for (index = m; index < m + step; index++) {
			binary_arr[index] = 0;
		}
	}
	//开始切6个bit
	int k = 0;
	int count = 0;
	int sum = 0;
	for (k = 0; k < index; k++) {
		sum = binary_arr[k] + sum * 2;
		if (sum != 0) {
			if ((k + 1) % 6 == 0) {
				int number=get_char(sum);
				printf("%c",number);
				sum = 0;
				count++;
			} else {
				continue;
			}
		}
	}
	if (count % 4 != 0) {
		printf("=");
	}
	return 0;
}

//学会了十进制如何快速转换为二进制
//按位与
//若转换为一个字节的二进制，则依次将数字右移，先复制一个数字，再对这个数字进行右移j位，j依次从7开始递减，然后让这个右移之后的数字与1进行与运算(num>>j)&1;
//最后直接将每次按位与运算之后的结果存到新的数组里
