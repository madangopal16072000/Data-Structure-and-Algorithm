#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10], int soln[10][10], int i, int j, int N, int M)
{
	if(i == N-1 && j == M-1)
	{
		soln[i][j] = 1;
		for(int row = 0; row < N; row++)
		{
			for(int col = 0; col < M; col++)
			{
				cout << soln[row][col] << " ";
			}
			cout << endl;
		}
        cout << endl;
		return true;
	}

	if(i >= N || j >= M)
	return false;

	if(maze[i][j] == 'X')
	return false;

	soln[i][j] = 1;
	bool right = ratInMaze(maze, soln, i, j+1, N, M);
	bool down = ratInMaze(maze, soln, i+1, j, N, M);
	soln[i][j] = 0;

	if(left || right)
	return true;


	return false;
}
int main()
{
	int soln[10][10] = {0};
	// int N, M;
	// cin >> N >> M;
	// char maze[10][10];
	// for(int i=0; i<N; i++)
	// {
	// 	for(int j=0; j<M; j++)
	// 	cin >> maze[i][j];
	// }
        char maze[10][10] = {
        "OXOO",
        "OOOX",
        "OOXO",
        "XOOO",
        "XXOO"};
    int N = 5, M = 4;

	cout << ratInMaze(maze, soln, 0, 0, N, M);
	return 0;
}