#include <stdio.h>
//学会二维数组中的输入输出
//二维数组中的行与列的变换来改变矩阵
void zigzag(int m,int n){
	//zigzag中是以对角线形式填充的数组，所以先定义对角线个数
	int Array[m][n];
	int index;//其中index为对角线编号
	int number=1;//填充数字起始值
	//判断对角线个数
	//当对角线编号为偶数时，数字从左下至右上填充矩阵，为奇数时，数字从右上至左下填充矩阵
	for(index=0;index<(m+n-1);index++){
		//定位第一个编号的位置（row,col)
		if(index%2==0){
			int row= index<m?index:m-1;
			int col= index<m?0:index-(m-1);
			while(row>=0&&col<n){
			    Array[row][col]=number++;//将数字填入数组，第一个是正常填，之后的数字需要以下的行列变换后填入
			    row--;//斜向上填充数组
			    col++;
			}
		}
		else{//为奇数时同理
			int row= index<n?0:index-(n-1);
			int col= index<n?index:n-1;
			while(row<m&&col>=0){
				Array[row][col]=number++;
				row++;
				col--;
			}
		}
	}
	//打印矩阵
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%d ",Array[i][j]);
		}
		printf("\n");
	}

}

int main() {
	int m,n;
	scanf("%d %d",&m,&n);//输入行与列
	if(m>=1&&n<=100){
	zigzag(m,n);
    }
	return 0;
}
