#include<stdio.h>
#include<string.h>
#include<ctype.h>

//定义一个结构体，这样就可以将一个单词与一个值相对应，不会出现定义很多个变量来存每个单词分别的数量了

typedef struct{
    char word[100];
    int count;
}Wordfrequency;

int search(Wordfrequency Wordlist[],char* word,int wordcount){
    for(int i=0;i<wordcount;i++){
        if(strcmp(Wordlist[i].word,word)==0){
            return i;
        }
    }
    return -1;
}
int main(){
    char text[10000];
    char ch;
    int i=0;
    while((ch=getchar())!=EOF){
        text[i++]=ch;
    }
    text[i]='\0';
    //将大写全部转换为小写
    int len=strlen(text);
    for(int i=0;i<len;i++){
        if(isupper(text[i])){
            text[i]=text[i]+' ';
        }
    }
    //初始化结构体  
    Wordfrequency WORD[5000];
    char word[100];
    int wordcount=0;//表示结构体中已找到的单词个数，即结构体中的索引
    //先获取一个单独的单词
    int wordindex=0;
    for(int j=0;j<len;j++){
        if(isalpha(text[j])){
            word[wordindex++]=text[j];
        }else {
            if(wordindex>0){
        word[wordindex]='\0';wordindex=0;//对其清零，清零后再存储单词
        //再从已统计的单词中查找是否已经找到了
        int num=search(WORD,word,wordcount);
        if(num==-1){
            strcpy(WORD[wordcount].word,word);//将word放置到结构体的word部分里。
            WORD[wordcount].count=1;//增加单词出现频率个数
            wordcount++;//已统计的单词个数增加，即结构体组索引增加
        }
        if(num!=-1){
            WORD[num].count++;//找到对应索引并增加频率
        }
        
            }
        }
    }

    //全部找完之后，再比较count最大的
    for(int m=0;m<wordcount-1;m++){
        if(WORD[m].count>WORD[m+1].count){
            //交换结构体中的位置
            Wordfrequency temp=WORD[m];
            WORD[m]=WORD[m+1];
            WORD[m+1]=temp;
        }
        if(WORD[m].count==WORD[m+1].count){
            continue;
        }
    }
    // 按照频率从大到小排序，如果频率相同，则按照字典序排序
    int number=0;
    for(int x=0;x<wordcount;x++){
        if(WORD[x].count==WORD[wordcount-1].count){
            number++;
        }
    }
    if(number>1){
        for(int h=wordcount-1-number+1;h<wordcount-1;h++){
            int NUM=strcmp(WORD[h].word,WORD[h+1].word);
            if(NUM>0){
                Wordfrequency temp_string=WORD[h];
                WORD[h]=WORD[h+1];
                WORD[h+1]=temp_string;
            }
        }
        //输出字典序
    printf("%s %d",WORD[0].word,WORD[0].count);
    }
    if(number==1){
        printf("%s %d",WORD[0].word,WORD[0].count);
    }
    return 0;
    
}
//我的错误排序。。。，。
/*
    */
   
   /*for (int i = 0; i < wordcount - 1; i++) {
        for (int j = i + 1; j < wordcount; j++) {
            if (WORD[i].count < WORD[j].count || 
                (WORD[i].count == WORD[j].count && strcmp(WORD[i].word, WORD[j].word) < 0)) {
                // 如果频率较小或频率相同但字典序较大，交换
                Wordfrequency temp = WORD[i];
                WORD[i] = WORD[j];
                WORD[j] = temp;
            }
        }
    }

    // 输出字典序最大的单词及其频率
    printf("%s %d\n", WORD[0].word, WORD[0].count);*/
