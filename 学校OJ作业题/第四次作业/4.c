#include<stdio.h>
// 判断nums是否是二叉查找树的后序遍历
int judge(int* nums, int len){
	// len == 0了，说明前面没有遇到错误的情况，返回0
	if(len == 0) return 0;
	// 用index记录根据二叉查找树规律判定的左右子树位置
	int i = -1, index;
	// 跳出循环时nums + i指向右子树的左区间
	while(nums[++i] < nums[len - 1]);
	index = i;
	// 判断是否符合二叉查找树，不符合返回1
	while(i < len - 1){
		if(nums[i] < nums[len - 1]){
			return 1;
		}
		++i;
	}
	// 只要子树中有不符合，返回1
	return judge(nums, index) || judge(nums + index, len - index - 1);

}

int main(){
	// 我感觉nums[5]都能过，老师太不走心了...
	// 只能自己判断程序对不对了， 因为错的也能AC
	int nums[20] = {0}, len = 0;
	// 输入数组
	while(~scanf("%d", &nums[len++]));
	// 输出结果
	if(judge(nums, len)){
		printf("false");
	}else{
		printf("true");
	}
	return 0;
}
