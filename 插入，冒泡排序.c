#include <stdio.h>
//插值排序
int main()
{
	int n;
    scanf("%d",&n);
	int arr[100];
	//输入数组
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("%d\n",arr[0]); //打印第一组
	//将新加的元素与排列顺序一定的序列比较，从右往左将小的放前面
	for(int j=1;j<n;j++){
		//遍历数组
		int num=arr[j];//新的元素
		int k=j-1;
		//将新加数组与原来的比较，若前面的数字大则后移
			while(k>=0&&num<arr[k]){
				arr[k+1]=arr[k];
				k--;
			}
		    arr[k+1]=num;//因为前一步自减，退出循环后，需加一之后再将新元素插入这个新的位置
			//打印数组
			for(int ii=0;ii<=j;ii++){
				printf("%d ",arr[ii]);
			}
			//换行
			printf("\n");
	}
    return 0;
}

//********************************************冒泡排序****************************************************
#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

		//把小的放前面，大的放后面
		for(int i=0;i<n-1;i++){
			for(int k=0;k<n-1-i;k++){
				if(arr[k]>arr[k+1]){
					int temp=arr[k];
					arr[k]=arr[k+1];
					arr[k+1]=temp;
				}
			}
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
       }
}
