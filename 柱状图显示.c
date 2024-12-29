#include<stdio.h>
#include<string.h>
#include<ctype.h>
//注意各种情况要分好类啊bb
//搞清楚这个矩阵是咋移动的



int change(char text[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(text[i])) {
			int num = text[i] - '0';
			sum = sum * 10 + num;
		}
	}
	return sum;
}


int main() {
	//先定义一个大矩阵
	char matrix[31][50];
	int i = 0;
	int j = 0;
	for (i = 0; i < 31; i++) {
		for (j = 0; j < 50; j++) {
			matrix[i][j] = ' ';
		}
	}
	//输入m表示多少组
	int m;
	scanf("%d", &m);
	getchar();//消费空格
	
	//提前把横线打好
	for (int k = 0; k < (2 * m) - 1; k++) {
		matrix[15][k] = '-';
	}
	
	//输入存放内容的字符组
	i = 0;
	char text[100];
	char ch;
	while ((ch = getchar()) != '\n') {
		text[i++] = ch;
	}
	text[i] = '\0';
	j = 0;
	char temp[4];
	for (int n = 0; n < m; n++) {
		    int x = 0;
			memset(temp, 0, sizeof(temp)); //清空temp
			while (text[j] != ' ' && text[j] != '\0') {
					temp[x++] = text[j++];
			}
		    temp[x]='\0';
		    j++;
			int num = 0;
			int length = strlen(temp);
			//为正数时
			int k = 0;
			int state=0;
			if (temp[0] != '-') {
				num = change(temp, length); //转换为数字
				if(num==0){
					continue;
				}
				//如果有字母的话
				for (k = 0; k < length; k++) {
					if (isalpha(temp[k])) {
						state=1;
						break;
					}
					//如果没有字母
					if (!isalpha(temp[k])) {
						state=0;	
					}
				}
				if(state==1){
                    //向上走
					for (int f = 0; f < num; f++) {
						matrix[14 - f][n * 2] = temp[k];
					}
				}
				if(state==0){
					for (int f = 0; f < num; f++) {
						matrix[14 - f][n * 2] = '+';
					}
				}
			}
			k = 0;
			state=0;
			//为负数时
			if (temp[0] == '-') {
				num = change(temp, length); //转换为数字
				if(num==0){
					continue;
				}
				//如果有字母的话
					for (k = 0; k < length; k++) {
						if (isalpha(temp[k])) {
							state=1;
							break;
						}
						//如果没有字母
						if (!isalpha(temp[k])) {
							state=0;	
						}
					}
					if(state==1){
						//向下走
						for (int f = 0; f < num; f++) {
							matrix[16 + f][n * 2] = temp[k];
						}
					}
					if(state==0){
						for (int f = 0; f < num; f++) {
							matrix[16 + f][n * 2] = '+';
						}
					}
			
		}
	}
	//把空格给删了哈
	int index1=-1;
	//先找上面的
	for (int g = 0; g < 15; g++) {
		for (int d = 0; d < (2 * m) - 1; d++) {
		    if(matrix[g][d]=='+'){
				index1=g;
				break;
			}
			if(isalpha(matrix[g][d])){
				index1=g;
				break;
			}
		}
		if(index1!=-1){
			break;
		}
	}
	if(index1==-1){
		index1=15;
	}
	//再找下面的
	int index2=-1;
	for(int h=30;h>15;h--){
		for (int d = 0; d < (2 * m) - 1; d++) {
			if(matrix[h][d]=='+'){
				index2=h;
				break;
			}
			if(isalpha(matrix[h][d])){
				index2=h;
				break;
			}
		}
		if(index2!=-1){
			break;
		}
	}
	if(index2==-1){
		index2=15;
	}
	//打印矩阵
	if(index1==index2&&index1==15){
		for (int d = 0; d < (2 * m) - 1; d++) {
			printf("%c", matrix[15][d]);
		}
	}
	else{
	for (int t=index1; t<=index2; t++) {
		for (int d = 0; d < (2 * m) - 1; d++) {
			printf("%c", matrix[t][d]);
		}
		printf("\n");
	}
	}
	return 0;
}
