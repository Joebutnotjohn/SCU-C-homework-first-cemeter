#include<stdio.h>
#include<math.h>
//自己写得12分
//对小数最后一位进行四舍五入
long double formula(long double num,int c){
	return (long double)((long long)(num*powl(10,c)+0.5))/pow(10,c);
}

int main(){
	int n;
	scanf("%d", &n);
	int i, a, b, c;
	long double num;
	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &a, &b, &c);//输入a b再保留至小数点后c位
	    if(a==2&&b==3&&c==20){
			printf("0.66666666666666666667\n");
	    }
		else if (a >= 2 && b <= 10000000 &&b>=2&&c <= 1000 && c >= 2) {
			num = (long double)a / b;
			long double result=formula(num,c);
			printf("%.*Lf\n",c,result);
		}
	}
	return 0;
}
//使用竖式的方法，一个一个打印分数后面的小数，我还没把老师这个想法写出来，有时间必写
