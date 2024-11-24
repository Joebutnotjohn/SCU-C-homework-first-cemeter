#include<stdio.h>
#include<string.h>

/*一位位地乘，再将乘过后的数字按照逐位相加得到一串字符，注意一位乘过之后要添加0来占位。
找到每次的结果之后，再使用大整数加法的函数，来进行结果的处理
先全部为倒序的，最后再将字符串倒过来
最后不要忘记把字符颠倒*/

/****************************方法1 也是最麻烦的方法**********************************/

void reverse(char* string) {
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++) {
		char temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}
}
void addition(char* res1, char* res2, char* rev_result) {
	int len_1 = strlen(res1);
	int len_2 = strlen(res2);
	int carry = 0; //进位
	int index = 0;
    //把两个字符组都反转
    reverse(res1);
    reverse(res2);
	//当三者条件均不成立时跳出循环，说明所有位数均已找完
	for (int i = 0; i < len_1 || i < len_2 || carry > 0; i++) {
		int digit_r1 = (i < len_1) ? (res1[i] - '0') : 0; //res1的当前位数
		int digit_r2 = (i < len_2) ? (res2[i] - '0') : 0; //res2的当前位数
		int sum = digit_r1 + digit_r2 + carry;
		carry = sum / 10;
		rev_result[index++] = (sum % 10 )+ '0';

	}
	rev_result[index] = '\0';
    reverse(rev_result);
}
//逐位相乘的函数
void multiple(char* a, int digit, char* rev_result) {
	//将a固定，用b中的数字逐位与其相乘，最后的结果存入倒转的字符里，将字符转好位置之后再进行大整数相加的函数运用
	int len_a = strlen(a);
	int carry = 0; //进位
	int number = 0;
	for (int i = 0; i < len_a || carry > 0; i++) {
		int digit_a = (i < len_a) ? (a[i] - '0') : 0;
		int sum = digit_a*digit + carry;
		carry = sum / 10;
		rev_result[number++] = (sum % 10) + '0';
	}
	rev_result[number] = '\0';

}

int main() {
	int n;
	scanf("%d", &n);
	getchar();//消费换行符
	for (int i = 0; i < n; i++) {
		char text[1000];
		fgets(text, sizeof(text), stdin); //获取数据
		text[strcspn(text, "\n")] = '\0';//消耗换行符
        //strcspn是string函数里查找字符的一个函数，当查找到"\n"换行符，就把换行符替换为结束符。
		char a[1000];
		char b[1000];
		int j = 0;
		int index = 0;
		//获得a和b两个字符组
		while (text[j] != ' ') {
			a[j] = text[j];
			j++;
		}
		a[j] = '\0';
		int m = j + 1;
		while (text[m] != '\0') {
			b[index] = text[m];
			m++;
			index++;
		}
		b[index] = '\0';
        if(a[0]=='-'||b[0]=='-'){
            return 0;
        }
		int len_b = strlen(b);
        reverse(b);

		char temp[1000] = {0}; //存储每一次单独乘之后的结果，因为它只是一个存放临时结果的字符组，就直接全部令为空字符，也没有影响
		char rev_result[1000] = "0"; //存储最后结果，并且要使第一个元素为字符0，其他为空字符，这样才能使之后在大整数加法里不进行死循环
		//由于倒序相乘，多出的位次要用0填满，以便于在大整数相加的计算里可行
		
		for (int k = 0; k < len_b; k++) {
			int digit_b = b[k] - '0'; //转换为数字
			memset(temp, 0, sizeof(temp));//清空temp，它只作为单次运算后结果的存储，不能带有之前的值
            //乘以第一位
			multiple(a, digit_b, temp);
            int len_temp=strlen(temp);
			for (int z = 0; z <k; z++) {
			//补齐空位，第一个不添0，从第二个digit开始添0,k表示temp从第一位开始的偏移量，k=0时无偏移，不需要添加0
                temp[len_temp++]='0';
			}
            temp[len_temp]='\0';
			//做加法，与前一个结果相加
			addition(rev_result, temp, rev_result);

		}
		//反转字符组
		reverse(rev_result);

		printf("%s\n", rev_result);
	}
	return 0;
}
/****************************方法1 也是最麻烦的方法**********************************/
/****************************方法1 也是最麻烦的方法**********************************/
/****************************方法1 也是最麻烦的方法**********************************/









/****************************方法2 优化后的算法**********************************/
/****************************方法2 优化后的算法**********************************/
/****************************方法2 优化后的算法**********************************/
/*纯粹的将问题以数组的形式来解决，也用到了逐位相乘，但并没有单一地使用字符，而是用数组来存储每一次逐位相乘的结果，最后再处理每一个数组里的数字
若大于十，就对十取余数，后面一个再加一，然后存入数组
最后输出时再倒序输出*/
#include<stdio.h>
#include<string.h>


int main(){
	int n;
	scanf("%d",&n);
	getchar();
	for(int k=0;k<n;k++){
	int i,j;
	char a[510],b[510];
	int p[510],q[510];
	int ans[10001]={0};
	int alen,blen;
	char text[1020];
		fgets(text, sizeof(text), stdin); //获取数据
		text[strcspn(text, "\n")] = '\0';//消耗换行符
		//strcspn是string函数里查找字符的一个函数，当查找到"\n"换行符，就把换行符替换为结束符。
		j = 0;
		int index = 0;
		//获得a和b两个字符组
		while (text[j] != ' ') {
			a[j] = text[j];
			j++;
		}
		a[j] = '\0';
		int m = j + 1;
		while (text[m] != '\0') {
			b[index] = text[m];
			m++;
			index++;
		}
		b[index] = '\0';
		if(a[0]=='-'||b[0]=='-'){
			return 0;
		}
	alen=strlen(a);
	blen=strlen(b);
	j=0;
	//将每个位的数字存入数字数组里
	for(i=alen-1;i>=0;i--){
		p[j++]=a[i]-'0';
	}
	j=0;
	for(i=blen-1;i>=0;i--){
		q[j++]=b[i]-'0';
	}
	//存好之后进行每一位的逐位乘法计算
	for(i=0;i<=alen-1;i++){
		for(j=0;j<=blen-1;j++){
			ans[i+j]+=p[i]*q[j];
		}
	}
	//再对每一个位的结果检查，若大于十则进1，加到下一个元素里
	for(i=0;i<10000;i++){
		if(ans[i]>=10){
			ans[i+1]+=ans[i]/10;
			ans[i]=ans[i]%10;
		}
	}
	//倒序打印这个数组的每一个元素
	for(i=10000;i>=0;i--){
		if(ans[i]!=0){
			for(j=i;j>=0;j--){
				printf("%d",ans[j]);
			}
			break;
		}
	}
	if(i==-1) printf("0");
	printf("\n");
	}
	return 0;
}

/****************************方法2 优化后的算法**********************************/
/****************************方法2 优化后的算法**********************************/
/****************************方法2 优化后的算法**********************************/
