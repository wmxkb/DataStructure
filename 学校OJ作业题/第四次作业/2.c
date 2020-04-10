#include<stdio.h>

/** 解题思路
*按照题目意思，读取广义表表示的二叉树。
*题目中要求存储二叉树，但没说怎么存，那我就顺序存储，就按题目广义表存储了。
*但是显然没必要，直接输出算了...
*直接数组存每层元素，然后输出就好了...
*/
int main(){
	// 存储每层的节点值
	int a[10][20];
	// 存储最大深度
	int depth = 0, maxdepth = 0;
	// 存储每层宽度
	int len[20] = {0};
	char c;
	// 获取根节点
	c = getchar();
	// 填入根节点，初始化长度
	len[0] = 1; a[0][0] = c - '0';
	// 因为跳出条件是depth为0，所以加一个flag保证一开始能进入循环
	int flag = 1;
	c = getchar();
	while(flag || depth != 0){
		flag = 0;
		// 左右括号分别代表层数+1 和 -1
		if(c == '(') depth++;
		else if(c == ')') depth--;
		// 逗号不处理，直接空语句...
		else if(c == ',');
		else{
			int num = c - '0';
			c = getchar();
			// 位数大于1的数据处理
			while(c != ',' && c != '(' && c != ')'){
				num = num * 10 + c - '0';
				c = getchar();
			}
			// 更新深度和层节点
			a[depth][len[depth]++] = num;
			//printf("add %d, %d\n", depth,len[depth] - 1);
			// 记录最大值
			maxdepth = maxdepth > depth ? maxdepth : depth;
			continue;
		}
		// 获取下一个字符
		c = getchar();
	}

	// 从底层往上输出
	for(int i = maxdepth; i >= 0; --i){
		for(int j = 0; j < len[i]; ++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
