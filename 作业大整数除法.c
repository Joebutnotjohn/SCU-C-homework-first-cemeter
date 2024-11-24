#include<stdio.h>
#include<string.h>
//方法1，但被说超时了！！！！！
//也尝试用二分法，但是那个好像不适用于巨大的整数所以就没写了

void reverse(char* string) {
	int len = strlen(string);
	for (int i = 0; i < len / 2; i++) {
		char temp = string[i];
		string[i] = string[len - 1 - i];
		string[len - 1 - i] = temp;
	}
}

//传递两个字符组至a和b中        定义一个自变量temp接收结果
void minus(char* a,char* b,char* temp){
    int len_a=strlen(a);
    int len_b=strlen(b);
    int p[1000]={0};int q[1000]={0};
    int index=0;
    //将字符组a的每一个数字存入数组p
    for(int i=len_a-1;i>=0;i--){
        p[index++]=a[i]-'0';
    }
    index=0;
    for(int j=len_b-1;j>=0;j--){
        q[index++]=b[j]-'0';
    }
    int carry=0;index=0;
    for(int i=0;i<len_a;i++){
        int num=p[i]-(i<len_b?q[i]:0)-carry;
        if(num<0){
            num+=10;
            carry=1;
        }else if(num>=0){
            carry=0;
        }
        temp[index++]=num+'0';
    }
    int len_t=strlen(temp);
   // 去掉前导零
    while ( len_t> 1 && temp[len_t - 1] == '0') len_t--;
    temp[len_t] = '\0';

    // 反转结果
    reverse(temp);
}

//将b字符与大致确定的这个字符进行判断二者的大小
int comparison(const char*b,const char* define_string){
    int len_b=strlen(b);
    int len_def=strlen(define_string);
    if(len_b>len_def) return -1;
    if(len_b<len_def) return 1;
    
        for(int i=0;i<len_b;i++){
            if(b[i]>define_string[i]){
                return -1;
            }
            if(b[i]<define_string[i]){
                return 1;
            }
        }
        return 0;//二者相等时返回0
    
}


int main(){
    int n;
	scanf("%d", &n);
	getchar();//消费换行符
	for (int i = 0; i < n; i++) {
		char text[3000];
		fgets(text, sizeof(text), stdin); //获取数据
		text[strcspn(text, "\n")] = '\0';//消耗换行符
        //strcspn是string函数里查找字符的一个函数，当查找到"\n"换行符，就把换行符替换为结束符。
		char a[2000];
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
        if(b[0]=='0'){
            return 0;
        }
        //获取a里面的数字，再将b转换为数字
        char temp_res[1000]={0};
        int count=1;
        char current[2000];
        strcpy(current,a);//将a的字符复制到current中，不修改a的值
        while(1){
            minus(current,b,temp_res);
            strcpy(current,temp_res);//更新这个被减数，看得更清楚一点
            int mode=comparison(b,temp_res);
            if(mode==1){
                count++;
            }
            if(mode==0){
                count++;
                printf("%d\n",count);
            }
            if(mode==-1){
                break;
            }
        }
        
}
return 0;
}
//之前写得二分法，留存一下
/*void multiple(int* a,int alen,const int* b,int blen,char* temp_result){
	int j=0;int i=0;
    int ans[10000]={0};
	//存好之后进行每一位的逐位乘法计算
	for(i=0;i<=alen-1;i++){
		for(j=0;j<=blen-1;j++){
			ans[i+j]+=a[i]*b[j];
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
            int index=0;
			for(j=i;j>=0;j--){
				temp_result[index++]=ans[j]+'0';
			}
            temp_result[index]='\0';
			break;
		}
	}
    
}*/
/*void binary_search(int min,const int* q,const int len_b,int max,char* a){
    int temp[3000];
    char result[3000]={0};
    int mid=(min+max)/2;
                int m=0;int judge=1;
                while((min<=max)&&judge!=0){
                    mid=(min+max)/2;
                    //将mid存入temp这个数组中
                    while(mid>0){
                    temp[m++]=(mid%10);//取低位数字
                    mid=mid/10;//去掉低位数字
                }
                multiple(temp,m,q,len_b,result);
                int judge=comparison(result,a);
                if(judge==0){
                    //倒序输出temp中的每个元素，即为商
                    for(int d=0;d<m;d++){
                        printf("%d",temp[d]);
                    }
                    return;
                }
                if(judge==-1){
                    //res要大一点
                    max=mid-1;
                }
                if(judge==1){
                    //res小一点
                    min=mid+1;
                }
                if(min>max&&judge!=0){
                    return;
                }
}
}*/
