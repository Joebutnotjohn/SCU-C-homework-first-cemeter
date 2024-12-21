#include<stdio.h>
#include<string.h>
#include<ctype.h>


//定义一个编号连锁的结构体
typedef struct {
	char text[50];
	int rank;
} Data;

//将字符转变为数字的函数，index2表示其text的索引
int change(char text[], int len,  int index2 ) {
	int sum = 0;
	for (int i = index2; i < len; i++) {
		if (isdigit(text[i])) {
			int num = text[i] - '0';
			sum = sum * 10 + num;
		}
		if (isalpha(text[i])) {
			return -1;//缺考之人
		}
	}
	return sum;
}

//寻找成绩那一个字段,len表示text的长度
int search(char text[], int len) {
	int count = 0;
	for (int i = 0; i < len - 1; i++) {
		if (isdigit(text[i])) {
			count++;
		}
		if (count == 18 ) {
			return i + 1;//返回下一个索引
		}
		if ( count == 17 && text[i + 1] == 'x') {
			return i + 2;
			break;
		}
	}
	return -1;
}

int Get_number(char text[], int len) {
	int num = search(text, len);//先找到成绩那个字段
	int number = change(text, len,  num);
	return number;
}

//交换两个字符组的位置
void swap(Data* a, Data* b) {
	Data temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char search_string[50];
	scanf("%s", search_string);
	getchar();
	Data data[101];
	//定义一个结构体字符组
	int i = 0;
	for (i = 0; i < n; i++) {
		char ch;
		int j = 0;
		memset(data[i].text, 0, sizeof(data[i].text));
		while ((ch = getchar()) != '\n' && j < 101) {
			data[i].text[j++] = ch;
		}
		data[i].text[j] = '\0';
	}
	i = 0;
	//将名字进行大小写排序
	for (i = 0; i < n - 1; i++) {
		//如果前面的人名字字典序较大，就将结构体字符组的两个位置交换
		for (int x = 0; x < n - 1 - i; x++) {
			int num1 = strcmp(data[x].text, data[x + 1].text); //大于0则前者大于后者
			if (num1 > 0) {
				swap(&data[x], &data[x + 1]);
			}
		}
	}
	//比较分数
	i = 0;
	for (i = 0; i < n - 1; i++) {
		for (int r = 0; r < n - 1 - i; r++) {
			int len1 = strlen(data[r].text);
			int len2 = strlen(data[r + 1].text);
			int number1 = Get_number(data[r].text, len1);
			int number2 = Get_number(data[r + 1].text, len2);
			if (number1 < number2) {
				swap(&data[r], &data[r + 1]); //分数低的交换
			}
		}
	}
	//给这几个小伙伴排个名先
	i = 0;
	int rank = 1;
	for (i = 0; i < n - 1 ; i++) {
		int len3 = strlen(data[i].text);
		int len4 = strlen(data[i + 1].text);
		int number3 = Get_number(data[i].text, len3);
		int number4 =  Get_number(data[i + 1].text, len4);
		if (number3 > number4) {
			data[i].rank = rank;
			data[i + 1].rank = rank + 1;
			rank++;
		}
		if (number3 == number4) {
			data[i].rank = rank;
			data[i + 1].rank = rank;
		}
	}
	//再查找
	int N = 0;
	for (N = 0; N < n; N++) {
		Data* p = &data[N];
		if ((strstr(p->text, search_string)) != NULL) {
			int c = 0;
			while (isalpha(data[N].text[c])) {
				printf("%c", data[N].text[c]);
				c++;
			}
			printf(" ");
			//输出身份证号
			int count = 0;
			while (1) {
				if (data[N].text[c] == 'x' && count == 17) {
					printf("%c", data[N].text[c]);
					break;
				}
				if (isdigit(data[N].text[c]) && count <= 17) {
					count++;
					printf("%c", data[N].text[c]);
				}
				c++;
				if (count == 18) {
					break;
				}
			}
			printf(" ");
			//输出成绩
			int Len = strlen(data[N].text);
			int grade = Get_number(data[N].text, Len);
			if (grade != -1) {
				printf("%d ", grade);
				printf("%d\n", data[N].rank);
			} else {
				int index = search(data[N].text, Len);
				for (int q = index; q < Len; q++) {
					if(data[N].text[q]!=' '){
						printf("%c", data[N].text[q]);
					}
				}
				printf(" ");
				printf("n/a\n");
			}
		
		
		}
	}
	
	return 0;
}


//没啥想说的，只感觉恶心，因为要求的实在太多了哈，改来改去我要鼠。。。。。
