#include <stdio.h>
#include <string.h>
#include <math.h>
//不是我自己写得！！自己写得在下面，但是是错的，也不知道为啥
// 判断是否为素数
int is_prime(int x) {
    if (x < 2) return 0; // 非素数
    for (int j = 2; j * j <= x; j++) {
        if (x % j == 0) return 0; // 非素数
    }
    return 1; // 素数
}

// 因数分解函数
void factorize(int x, int arr[], int *count) {
    int index = 0;
    for (int j = 2; j * j <= x; j++) { // 从2开始试探
        while (x % j == 0) { // 如果 j 是因数
            arr[index++] = j;
            x /= j; // 减少 x 的大小
        }
    }
    if (x > 1) { // 如果最后剩下的是一个质数
        arr[index++] = x;
    }
    *count = index; // 保存最终因数的个数
}

// 构造结果字符串
void build_result(int arr[], int count, char res[]) {
    int pos = 0;
    for (int i = 0; i < count; i++) {
        pos += sprintf(res + pos, "%d", arr[i]); // 将数字转换为字符串
        if (i != count - 1) {
            res[pos++] = '*'; // 添加乘号
        }
    }
    res[pos] = '\0'; // 添加字符串结束符
}

int main() {
    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);

        if (x >= 10000 || x < 2) {
            return 0;
        }

        // 判断是否是素数
        if (is_prime(x)) {
            printf("%d\n", x);
            continue;
        }

        // 因数分解
        int arr[500]; // 用更小的数组保存因数
        int count = 0;
        factorize(x, arr, &count);

        // 构造结果字符串
        char res[1000];
        build_result(arr, count, res);

        // 输出结果
        printf("%s\n", res);
    }

    return 0;
}
//自己写得在这

#include<stdio.h>
#include<string.h>
#include<math.h>


int main(){
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int x;
        scanf("%d",&x);
        if(x>=10000||x<2){
            return 0;
        }
        //先判断是否是素数 13
        int state=1; 
        for(int j=2;j*j<=x;j++){
           if(x%j==0){
            state=0;
            break;
           }
          }
          if(state==1){
            printf("%d\n",x);
            continue;
          }
        //不为素数时
        int arr[50000];
        int index=0;
        //在x被重新赋值之后，再从j=2开始，所以j++的循环在内部
        int j=2;
        for(int t=2;t*t<=x;t++){
            if(x%t==0){
                arr[index++]=t;//第一个因数存入数组中
                x=x/t;//131
            }
            }
        if(x>1){
                arr[index]=x;
            }
        //存好数字数组之后填充至字符组
        int len_a=index+1;
        char res[10000];
        //将数字填入字符串中。
        int pos=0;
        for(int q=0;q<len_a;q++){
        pos+=sprintf(res+pos,"%d",arr[q]);
            if(q!=len_a-1){
                res[pos++]='*';
            }
            else{res[pos]='\0';}
        }
        printf("%s\n",res);
        memset(res,'\0',sizeof(res));//清空res字符组

        }
        return 0;
}






