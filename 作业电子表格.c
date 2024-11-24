#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 51

void SR(int matrix[][MAX], int row1, int row2, int row, int line);
void SC(int matrix[][MAX], int line1, int line2, int row, int line);
void DR(int matrix[][MAX], int row1, int line, int* row);
void DC(int matrix[][MAX], int line1, int row, int* line);
void IR(int matrix[][MAX], int row1, int line, int* row);
void IC(int matrix[][MAX], int line1, int row, int* line);
//学会用指针直接更改程序中的变量，注意每一次都要更新行与列，在行变化的时候，不要忘了对行最后用指针改变长度，同理列也是一样
//这里还用到一个技巧，也就是scanf不会读取空格，即使输入空格也不会将空格计入数组中，所以有时候也不要对空格太纠结，而且不是什么都要用字符串组来解决问题
int main(){
	// 输入矩阵大小
	int row, line;
	scanf("%d %d", &row, &line);
	int matrix[MAX][MAX];
	
	// 输入矩阵内容
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	
	// 输入操作的次数
	int n;
	scanf("%d", &n);
	getchar();  // 获取换行符，防止之后的读取问题
	
	// 处理操作命令
	for (int j = 0; j < n; j++) {
		char command[5];
		int x, y;
		scanf("%s", command);
		
		if (strcmp(command, "SR") == 0) {
			scanf("%d %d", &x, &y);
			SR(matrix, x-1, y-1, row, line);
		} 
		else if (strcmp(command, "SC") == 0) {
			scanf("%d %d", &x, &y);
			SC(matrix, x-1, y-1, row, line);
		} 
		else if (strcmp(command, "DR") == 0) {
			scanf("%d", &x);
			DR(matrix, x-1, line, &row);
		} 
		else if (strcmp(command, "DC") == 0) {
			scanf("%d", &y);
			DC(matrix, y-1, row, &line);
		} 
		else if (strcmp(command, "IR") == 0) {
			scanf("%d", &x);
			IR(matrix, x-1, line, &row);
		} 
		else if (strcmp(command, "IC") == 0) {
			scanf("%d", &y);
			IC(matrix, y-1, row, &line);
		}
	}
	
	// 输出最终矩阵
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < line; j++) {
			printf("%d", matrix[i][j]);
			if (j < line - 1) 
				printf(" ");  // 数字间空格
		}
		printf("\n");
	}
	
	return 0;
}

void SR(int matrix[][MAX], int row1, int row2, int row, int line) {
	for (int i = 0; i < line; i++) {
		int temp = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = temp;
	}
}

void SC(int matrix[][MAX], int line1, int line2, int row, int line) {
	for (int i = 0; i < row; i++) {
		int temp = matrix[i][line1];
		matrix[i][line1] = matrix[i][line2];
		matrix[i][line2] = temp;
	}
}

void DR(int matrix[][MAX], int row1, int line, int* row) {
	for (int i = row1; i < *row - 1; i++) {
		for (int j = 0; j < line; j++) {
			matrix[i][j] = matrix[i + 1][j];
		}
	}
	(*row)--;  // 更新行数
}

void DC(int matrix[][MAX], int line1, int row, int* line) {
	for (int i = 0; i < row; i++) {
		for (int j = line1; j < *line - 1; j++) {
			matrix[i][j] = matrix[i][j + 1];
		}
	}
	(*line)--;  // 更新列数
}

void IR(int matrix[][MAX], int row1, int line, int* row) {
	for (int i = *row; i > row1; i--) {
		for (int j = 0; j < line; j++) {
			matrix[i][j] = matrix[i - 1][j];
		}
	}
	for (int j = 0; j < line; j++) {
		matrix[row1][j] = 0;  // 插入行的元素初始化为0
	}
	(*row)++;  // 更新行数
}

void IC(int matrix[][MAX], int line1, int row, int* line) {
	for (int i = 0; i < row; i++) {
		for (int j = *line; j > line1; j--) {
			matrix[i][j] = matrix[i][j - 1];
		}
	}
	for (int i = 0; i < row; i++) {
		matrix[i][line1] = 0;  // 插入列的元素初始化为0
	}
	(*line)++;  // 更新列数
}
