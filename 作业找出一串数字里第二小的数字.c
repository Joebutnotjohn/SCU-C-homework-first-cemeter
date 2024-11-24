#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        //输入文本
        char text[100000];
        fgets(text,sizeof(text),stdin);
        text[strcspn(text, "\n")] = '\0';//消耗换行符
        int len=strlen(text);
        int arr[100000];
        int count=0;
       
       //当text里不是只有1和0时,提取数字至数组中
        //提取数字
      
            for(int j=0;j<len;j++){
                int sum=0;
                while(isdigit(text[j])&&j<=len-1){
                int num=text[j]-'0';
                sum=sum*10+num;
                j++;//获取数字
                 }
                arr[count++]=sum;//将最后获取到的数字放入arr中
                }
        
        //如果只有一个数字就输出error
        if(count<2){
            printf("ERROR\n");
            continue;
        }
        //排序这个数组
        for (int k = 1; k < count - 1; k++) {
            for (int l = 1; l < count - k ; l++) {
                if (arr[l] > arr[l + 1]) {
                    int temp = arr[l];
                    arr[l] = arr[l + 1];
                    arr[l + 1] = temp;
                }
            }
        }//将数组排好序
        
        //找出第二小的，由于可能有几个数字相同的情况，所以
        int state=-1;
        for(int m=1;m<count-1;m++){
            if(arr[m]!=arr[m+1]){
                printf("%d\n",arr[m+1]);
                state=1;
                break;
            }
        }
        if(state==-1){
        printf("ERROR\n");
        }
       
       }
        return 0;
    }
    
