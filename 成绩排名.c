#include<stdio.h>
#include<string.h>
#include<ctype.h>


//定义一个编号连锁的结构体
typedef struct {
	char text[50];
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
	int c = 0;
	while (isalpha(data[0].text[c])) {
		printf("%c", data[0].text[c]);
		c++;
	}
	printf(" ");
	int count = 0;
	while (1) {
		if (data[0].text[c] == 'x' && count == 17) {
			printf("%c", data[0].text[c]);
			break;
		}
		if (isdigit(data[0].text[c]) && count <= 17) {
			count++;
			printf("%c", data[0].text[c]);
		}
		c++;
		if (count == 18) {
			break;
		}
	}
	printf("\n");
	c = 0;
	count = 0;
	//可能有缺考的，所以要找到第一个缺考出现的位置的上一个就是分最低且名字字母序最大的
	for (int d = n - 1; d >= 0; d--) {
		Data* p1 = &data[d];
		int length = strlen(p1->text);
		if ((Get_number(data[d].text, length)) != -1) {
			while (isalpha(data[d].text[c])) {
				printf("%c", data[d].text[c]);
				c++;
			}
			printf(" ");
			int count = 0;
			while (1) {
				if (data[d].text[c] == 'x' && count == 17) {
					printf("%c", data[d].text[c]);
					break;
				}
				if (isdigit(data[d].text[c]) && count <= 17) {
					count++;
					printf("%c", data[d].text[c]);
				}
				c++;
				if (count == 18) {
					break;
				}
			}
			printf("\n");
			break;
		}
	}
	return 0;
}

/***************************************************浅浅总结一下啊，这是本人没有问任何ai只问了语法的内容，剩下纯自己printf调试出来的代码！！！！！祝贺**************************************************
来回顾下偶感到疑惑的语法点
一、
结构体如何定义：
typedef struct{
  char text[50];//定义一个字符组在结构体里
}Data;//结构体的变量类型定义！！！很重要，这相当于你自己定义了一个新的变量，congratulation!!!!

二、
关于memset函数：
memset(data[i].text, 0, sizeof(data[i].text));//其中第一个传入的是字符组的内容，第二个是你需要以什么清空它，一般都是0，表示用\0清空！，第三个是测量text的字符长度
这就引申出测量长度的函数strlen:
关于strlen吧，它要求传入字符组的指针，如果你想要直接测量data[0]中text的长度，直接写strlen(data[0].text)
如果你要找data[i]中text的长度，则需要先用一个指针p来接收data的地址，最后将作为指针结构体的p指向text
char* p=&data[i];
int len=strlen(p->text);

三、
当需要做修改字符组or数组的操作时，将字符组/数组传入函数中需要用其指针，在调用时要取地址！！这非常重要
比如我写的swap函数，就要直接更改结构体的位置
void swap(Data* a, Data* b) {
	Data temp = *a;
	*a = *b;
	*b = temp;
}
之后传入时我也用了
swap(&data[x], &data[x + 1]);
取地址取地址！！！

四、
笨人居然连冒泡排序都写错了？？？？
罚我再写329遍。。。/。。，。。，
  for(int i=0;i<n-1;i++){
      for(int j=0;j<n-1-i;j++){
          剩下的就是对i和i+1进行一系列比较之后交换位置
            如何比较，拿什么比较的都写在这个for循环里哈，因为是相当于，这个才是主要的，最外层的循环只是用来刷新你找的数字，之后的操作还要继续
      }
}
加油吧、、、








