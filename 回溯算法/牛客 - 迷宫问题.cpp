//10 10
//0 1 0 1 0 0 0 0 0 0
//0 1 0 0 0 0 1 0 0 0
//0 0 0 1 0 0 0 1 0 1
//1 0 1 0 0 0 0 0 0 1
//1 0 0 0 0 0 0 0 1 1
//1 0 0 0 1 0 1 0 0 1
//1 0 1 0 0 0 0 0 0 0
//1 0 0 0 0 0 0 1 0 1
//1 0 0 0 0 0 1 0 0 0
//1 0 0 0 1 0 0 0 0 0

//使用path二维数组记录走过的路径的下标(x,y)
//使用best_path保存当前最优路径
//使用used数组记录某个结点是否被访问

//maze迷宫初始化的时候，向外扩展一圈，给最外圈填上1.这样就不用考虑数组越界问题了
#include <iostream>
#include <vector>
using namespace std;
//path存放当前路径
vector<vector<int>> path;
//best_path存放最优路径
vector<vector<int>> best_path;
vector<vector<int>> maze;

//这里传的x,y,endX,endY都是下标值
void backtracking(int x, int y, int endX, int endY, vector<vector<bool>>& used)
{
	if (x == endX && y == endY)
	{
		if (best_path.size() == 0 || path.size() < best_path.size())
			best_path = path;
		return;
	}
	used[x][y] = true;
	//按照右、下、左、上的顺序去搜索
	if (maze[x][y + 1] == 0 && used[x][y + 1] == false)
	{
		path.push_back({ x - 1, y - 1 + 1 });			// x - 1, y - 1 （都要-1的原因是：题里面要求返回的是数组的下标，而不是坐标）
		backtracking(x, y + 1, endX, endY, used);
	}
	if (maze[x + 1][y] == 0 && used[x + 1][y] == false)
	{
		path.push_back({ x - 1 + 1, y - 1 });
		backtracking(x + 1, y, endX, endY, used);
	}
	if (maze[x][y - 1] == 0 && used[x][y - 1] == false)
	{
		path.push_back({ x - 1, y - 1 - 1 });
		backtracking(x, y - 1, endX, endY, used);
	}
	if (maze[x - 1][y] == 0 && used[x - 1][y] == false)
	{
		path.push_back({ x - 1 - 1, y - 1 });
		backtracking(x - 1, y, endX, endY, used);
	}
	//无路可走 或 已经走完回来，pop到上一步
//    x = path[path.size() - 1][0];
//    y = path[path.size() - 1][1];
	path.pop_back();
}

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		//开辟maze的时候，多开辟一圈，最外面一圈全设置成障碍，这样就用判断越界问题了
		maze = vector<vector<int>>(N + 2, vector<int>(M + 2, 0));    //对迷宫数组进行初始化
		vector<vector<bool>> used(maze.size(), vector<bool>(maze[0].size(), false));
		path.clear();
		best_path.clear();
		for (int i = 0; i < M + 2; ++i)
		{
				maze[0][i] = 1;
				maze[N + 1][i] = 1;
		}
		for (int i = 0; i < N + 2; ++i)
		{
				maze[i][0] = 1;
				maze[i][M + 1] = 1;
		}
		int tmp;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> tmp;
				maze[i][j] = tmp;
			}
		}
		path.push_back({ 0, 0 });    //初始位置先push

		//回溯找路径
		backtracking(1, 1, N, M, used);

		//打印最优路径
		for (int i = 0; i < best_path.size(); ++i)
		{
			cout << "(" << best_path[i][0] << "," << best_path[i][1] << ")" << endl;
		}
	}
	return 0;
}


//下面的版本是省略了used数组，直接在迷宫地图maze数组上进行了visited还是没visit的标记

#include <iostream>
#include <vector>
using namespace std;
//path存放当前路径
vector<vector<int>> path;
//best_path存放最优路径
vector<vector<int>> best_path;
vector<vector<int>> maze;

//这里传的x,y,endX,endY都是下标值
void backtracking(int x, int y, int endX, int endY)
{
	if (x == endX && y == endY)
	{
		if (best_path.size() == 0 || path.size() < best_path.size())
			best_path = path;
		return;
	}
    maze[x][y] = 1;
	//按照右、下、左、上的顺序去搜索
	if (maze[x][y + 1] == 0)
	{
		path.push_back({ x - 1, y - 1 + 1 });
		backtracking(x, y + 1, endX, endY);
	}
	if (maze[x + 1][y] == 0)
	{
		path.push_back({ x - 1 + 1, y - 1 });
		backtracking(x + 1, y, endX, endY);
	}
	if (maze[x][y - 1] == 0)
	{
		path.push_back({ x - 1, y - 1 - 1 });
		backtracking(x, y - 1, endX, endY);
	}
	if (maze[x - 1][y] == 0)
	{
		path.push_back({ x - 1 - 1, y - 1 });
		backtracking(x - 1, y, endX, endY);
	}
	//无路可走 或 已经走完回来，pop到上一步
//    x = path[path.size() - 1][0];
//    y = path[path.size() - 1][1];
    maze[x][y] = 0;
	path.pop_back();
}

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		//开辟maze的时候，多开辟一圈，最外面一圈全设置成障碍，这样就用判断越界问题了
		maze = vector<vector<int>>(N + 2, vector<int>(M + 2, 0));    //对迷宫数组进行初始化
		//vector<vector<bool>> used(maze.size(), vector<bool>(maze[0].size(), false));
		path.clear();
		best_path.clear();
		for (int i = 0; i < M + 2; ++i)
		{
			maze[0][i] = 1;
			maze[N + 1][i] = 1;
		}
		for (int i = 0; i < N + 2; ++i)
		{
			maze[i][0] = 1;
			maze[i][M + 1] = 1;
}
		int tmp;
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> tmp;
				maze[i][j] = tmp;
			}
		}
		path.push_back({ 0, 0 });    //初始位置先push

		//回溯找路径
		backtracking(1, 1, N, M);

		//打印最优路径
		for (int i = 0; i < best_path.size(); ++i)
		{
			cout << "(" << best_path[i][0] << "," << best_path[i][1] << ")" << endl;
		}
	}
	return 0;
}