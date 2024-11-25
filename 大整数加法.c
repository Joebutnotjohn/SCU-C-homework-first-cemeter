#include <stdio.h>
#include <string.h>

//当超出long long范围时，采用字符数组
            //用普通计算的方式一个个打印出数字，最后将数字反转，即为最后的结果
            //原理核心是：从最末位相加，加后的数记为num若大于十，则输出num%10,前一位进一,存储这个进位
            //直到前面一位没有字符，相加的循环结束
            //将存储的字符反转之后记为结果

void culculation(char* a, char* b, char* result) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    int carry = 0; // 进位初始化
    int index = 0; // 用于跟踪 result 数组位置

    // 从低位到高位逐位相加
    for (int j = len_a - 1, k = len_b - 1; j >= 0 || k >= 0 || carry; j--, k--, index++) {
        int sum = carry; // 从上一位进位开始
        if (j >= 0) sum += a[j] - '0'; // 加上 a 的当前位
        if (k >= 0) sum += b[k] - '0'; // 加上 b 的当前位

        result[index] = (sum % 10) + '0'; // 当前位存入 result
        carry = sum / 10; // 更新进位
    }
    
    result[index] = '\0'; // 在结束后添加空字符，确保字符串以 '\0' 结束

    // 反转 result 中的字符
    int Len = strlen(result);
    for (int m = 0; m < Len / 2; m++) {
        char temp = result[m];
        result[m] = result[Len - 1 - m];
        result[Len - 1 - m] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n); // 输入 n 组数据

    for (int i = 0; i < n; i++) {
        char a[501] = {0};
        char b[501] = {0};
        char result[502] = {0}; // 结果数组初始化

        scanf("%s %s", a, b);
        culculation(a, b, result);
        printf("%s\n", result);
    }
}
