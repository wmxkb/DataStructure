#include "SqStack.h"
// 8 * 8迷宫
#define N 16
//函数原型声明
Status print(Elemtype* p, int i, int j);
void Search(int** maze, SqStack& S, Pos now);
void PrintMazeMap(int** maze);
void LoadMaze(int** maze);
void PrintMazeMapN(int** maze, SqStack S);
//路径条数
int path = 0;

//start
int main(){
  //入口坐标
  Pos now = {0, 0};
  //定义N*N二维数组
  int** maze = (int**)malloc(sizeof(int*)*N);
  for(int i = 0 ; i < N ; ++i){
    *(maze + i) = (int*)malloc(sizeof(int)*N);
  }

  //定义栈来存储路径
  SqStack s;
  InitStack(s);
  //将起点压入栈
  Push(s, now);
  //从文件中加载迷宫地图
  LoadMaze(maze);
  //输出迷宫地图
  //PrintMazeMap(maze);
  //开始寻找通路
  Search(maze, s, now);
  return 0;
}

//dfs
void Search(int** maze, SqStack& S, Pos now){
  //到达出口，输出当前通路
  if(now.x ==  N - 1 && now.y == N - 1){
    ++path;

    printf("Find %d path:\n", path);
    /*
    //遍历栈，输出路径
    printf("begin -> ");
    //StackTraverse(S, print);
    printf("end\n");
    */
    PrintMazeMapN(maze, S);
    Pos e;
    //退回一步，继续寻找其他通路
    Pop(S, e);
    //重设出口为未走过
    maze[e.x][e.y] = 0;
    return;
  }

  //上方是通路
  if((now.y - 1 >= 0) && (maze[now.x][now.y - 1] == 0)){
    //定义下一步坐标
    Pos np;
    np.x = now.x;
    np.y = now.y - 1;
    Push(S, np);
    //标记走过
    maze[now.x][now.y - 1] = -1;
    //前进一步
    Search(maze, S, np);
  }

  //左侧是通路
  if((now.x - 1 >= 0) && (maze[now.x - 1][now.y] == 0)){
    //定义下一步坐标
    Pos np;
    np.x = now.x - 1;
    np.y = now.y;
    Push(S, np);
    //标记走过
    maze[now.x - 1][now.y] = -1;
    //前进一步
    Search(maze, S, np);
  }

  //下方是通路
  if((now.y + 1 <= N - 1) && (maze[now.x][now.y + 1] == 0)){
    //定义下一步坐标
    Pos np;
    np.x = now.x;
    np.y = now.y + 1;
    Push(S, np);
    //标记走过
    maze[now.x][now.y + 1] = -1;
    //前进一步
    Search(maze, S, np);
  }

  //右侧是通路
  if((now.x + 1 <= N - 1) && (maze[now.x + 1][now.y] == 0)){
    //定义下一步坐标
    Pos np;
    np.x = now.x + 1;
    np.y = now.y;
    Push(S, np);
    //标记走过
    maze[now.x + 1][now.y] = -1;
    //前进一步
    Search(maze, S, np);
  }

  //若此路不通，退回上一步继续寻找
  Pos e;
  Pop(S,e);
  maze[e.x][e.y] = 0;
  return;
}
//通路用*表示
Status print(Elemtype* p, int i, int j){
  if(p -> x == i && p -> y == j){
    printf("* ");
    return 2;
  }

  return OK;
}
//输出迷宫通路解法
void PrintMazeMapN(int** maze, SqStack S){
  for(int i = 0 ; i < N ; ++i){
    for(int k = 0 ; k < N ; ++k){
      if(maze[i][k] == -1)
        printf("0 ");
      else
        printf("%d ", maze[i][k]);
    }
    if(i == N / 2)
      printf("---->");
    else
      printf("     ");
    for(int j = 0 ; j < N ; ++j){
      if(StackTraverse(S, print ,i , j) != 2)
          printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

//加载迷宫数据
void LoadMaze(int** maze){
  FILE *p = fopen("Maze.txt", "a+");
  for(int i = 0 ; i < N ; ++i){
    for(int j = 0 ; j < N ; ++j){
      fscanf(p, "%d",*(maze + i) + j);
      printf("Reading Maze! %%%d\n", int((1.0*(i*N + j) /(N*N))*100));
    }
  }
  fclose(p);
  printf("Load Maze Success\n");
}

//输出迷宫地图
void PrintMazeMap(int** maze){
  for(int i = 0 ; i < N ; ++i){
    for(int j = 0 ; j < N ; ++j){
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}
