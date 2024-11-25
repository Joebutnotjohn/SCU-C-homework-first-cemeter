#include<stdio.h>
#include<string.h>
#include<ctype.h>

//我自己的写法，但是提交到作业系统就是错的！！
//老师讲的那个我忘记记录下来了。。。。
int main(){
    char ch;
    char text[31];
    while(1){
        memset(text, 0, sizeof(text));  // 清空数组
        int i=0;
        while((ch=getchar())!='\n'&&i<30){
        text[i++]=ch;
    }
    text[i]='\0';
    if(strcmp(text,"End of file")==0){
        break;
    }
    int len=strlen(text);
    int dots=0;
     //统计.的数量
    for(int m=0;m<len;m++){
        if(text[m]=='.'){
            dots++;
        }
    }
    
    int count=0;
    int tak=0;
    char temp[31];
    for(int j=0;j<len;j++){
        if(text[j]!='.'){
        temp[count++]=text[j];
        }
        if((text[j]=='.'||j==len-1)){
            temp[count]='\0';
            int len_1=strlen(temp);
            int sum=0;
            for(int k=0;k<len_1;k++){
                if(!isdigit(temp[k])){
                    tak=0;
                    break;
                }
                int num=temp[k]-'0';
                sum=sum*10+num;
            }
            if((sum/256)==0){
                tak++;
            }
            else{tak=0;}
            count=0;
        }
        }
    if(tak==4&&dots==3){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
return 0;
}
