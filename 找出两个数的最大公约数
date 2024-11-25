#include<stdio.h>
//AC版
// 定义一个函数来求最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;//5 2 1
        b = a % b;//2%5=2 5%2=1 0
        a = temp;//5 1
    }
    return a;
}

int main() {
    int T;
    scanf("%d", &T);  // 输入测试次数
    for (int i = 1; i <= T; i++) {
        int m, n;
        scanf("%d %d", &m, &n);  // 输入 m 和 n
        printf("%d\n", gcd(m, n));  // 输出最大公约数
    }
    return 0;
}

//自己写的超时版
#include<stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	int i, m, n, k;
	for (i = 1; i <= T; i++) {
		scanf("%d %d", &m, &n); //输入数据
		//循环判断
		if (m > n) {
			for (k = m - 1; k >= 1; k--) {
				if (m % k == 0) {
					if (n % k == 0) {
						printf("%d\n", k);
						break;
					}
				}
				if (m % k != 0) {
					continue;
				}

			}
		}
		else if (m < n) {
			for (k = n - 1; k >= 1; k--) {
				if (n % k == 0) {
					if (m % k == 0) {
						printf("%d\n", k);
						break;
					}
				}
				if (n % k != 0) {
					continue;
				}

			}
		}
		else{
			printf("%d\n", m);
		}
	}
	return 0;
}
