#include<stdio.h>
//思路是借鉴chatgpt的，忘记我当时写出来了没
int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    if(k>=1&&m>=2&&m<=100&&n>=m&&n<=100){
        int arr[100];
        //填充数组
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        int count=n;
        int index=k-1;//第一个人对应的索引  
        while(count!=2){
            index = (index + m - 1) % count; // 找到出列的人
            for(int j=index;j<n;j++){
                arr[j]=arr[j+1];//将后面的数向前移动,直到最后数组仅剩下两个元素时输出
            }
            count--;
        }
        //将数组按照大小顺序输出
        if(arr[0]>arr[1]){
            printf("%d %d\n",arr[1],arr[0]);
        }
        else{
            printf("%d %d\n",arr[0],arr[1]);
        }
    }
}
