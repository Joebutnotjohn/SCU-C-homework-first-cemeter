#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	char ch;
	char text[1001];char res[1001];
	int i = 0;
	//输入语句
	while (1) {
		ch = getchar();
		text[i++] = ch;
		if (ch == '\n') {
			break;
		}
	}
	text[i] = '\0';
	//将text复制到res中
	int len = strlen(text);
    for (int j = 0; j < len; j++) {
        res[j] = text[j];
    }
	//找到单词的起始位置
	int index=0;
	while(index<len){
	while(!isalpha(res[index])){
		index++;
	}
	int word_start=index;
	//找到末尾位置
	while(isalpha(res[index])){
         index++;
	}
	int word_end=index-1;
	if(word_end>=word_start){
		for(int j=0;j<=(word_end-word_start)/2;j++){
			char temp=res[j+word_start];
			res[j+word_start]=res[word_end-j];
			res[word_end-j]=temp;
		}
	}
	
	}
	printf("%s\n",res);
} 
