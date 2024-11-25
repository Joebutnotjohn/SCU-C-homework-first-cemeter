#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//不出意外，也是chatgpt
// 提取方程两侧的变量系数和常数项
void parse_side(const char *side, char *variable, int *coeff, int *constant) {
    int len = strlen(side);
    int sign = 1, i = 0, num = 0; // 符号、数字缓存
    *coeff = 0;
    *constant = 0;

    while (i < len) {
        if (side[i] == '+') {
            sign = 1;
            i++;
        } else if (side[i] == '-') {
            sign = -1;
            i++;
        }
        
        // 解析数字或变量
        if (isdigit(side[i])) { // 是数字
            num = 0;
            while (i < len && isdigit(side[i])) {
                num = num * 10 + (side[i] - '0');
                i++;
            }
            if (i < len && isalpha(side[i])) { // 紧接变量
                *coeff += sign * num;
                *variable = side[i];
                i++;
            } else { // 普通常数
                *constant += sign * num;
            }
        } else if (isalpha(side[i])) { // 没有明确系数的变量，默认为1
            *coeff += sign * 1;
            *variable = side[i];
            i++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // 读入方程组数
    char equation[101]; // 每个方程长度不超过100

    for (int t = 0; t < n; t++) {
        scanf("%s", equation);

        // 分割方程为左右两侧
        char *equal_sign = strchr(equation, '=');
        *equal_sign = '\0';
        char *left = equation;
        char *right = equal_sign + 1;

        char variable = '\0'; // 保存未知数的字符
        int left_coeff = 0, right_coeff = 0; // 左右两侧变量的系数
        int left_const = 0, right_const = 0; // 左右两侧的常数

        parse_side(left, &variable, &left_coeff, &left_const);
        parse_side(right, &variable, &right_coeff, &right_const);

        // 合并方程，转化为 ax = b
        int a = left_coeff - right_coeff;
        int b = right_const - left_const;

        if (a == 0) {
            if (b == 0) {
                printf("%c=Infinite solutions\n", variable);
            } else {
                printf("%c=No solution\n", variable);
            }
        } else {
            double solution = (double)b / a;
            printf("%c=%.6f\n", variable, solution);
        }
    }

    return 0;
}
