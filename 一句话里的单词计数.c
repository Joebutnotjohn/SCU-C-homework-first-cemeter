#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//这当然也不是我做的！
//我刚开始的想法根本无法输出！
//老师讲的也忘了，再自己写写
// 定义单词的结构体
typedef struct {
    char word[51]; // 单词
    int count;     // 出现次数
} Word;

// 比较函数，按题目排序规则
int compare(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return strcmp(wordA->word, wordB->word);
}

// 判断是否是单词分隔符（这里仅为简单的空格）
int is_separator(char c) {
    return c == ' ';
}

int main() {
    char input[30001]; // 输入的文本
    Word words[3000];  // 存储单词及其统计
    int word_count = 0; // 已记录的单词数

    // 初始化输入
    fgets(input, sizeof(input), stdin);

    // 解析输入文本
    char *token = strtok(input, " \n");
    while (token) {
        // 查找该单词是否已经存在
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i].word, token) == 0) {
                words[i].count++;
                found = 1;
                break;
            }
        }
        // 如果是新单词，添加到数组
        if (!found) {
            strcpy(words[word_count].word, token);
            words[word_count].count = 1;
            word_count++;
        }
        token = strtok(NULL, " \n");
    }

    // 按字典顺序排序
    qsort(words, word_count, sizeof(Word), compare);

    // 输出结果
    for (int i = 0; i < word_count; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    return 0;
}
