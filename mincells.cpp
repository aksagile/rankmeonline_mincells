#include <iostream>
#include<queue>
using namespace std;
class node{
    public:
    int row,col,dist;
    node( int r, int c, int d){
        row=r;
        col=c;
        dist=d;
    }
};

int mincells(int grid[5][5]){
    
    node src(0,0,0);
    
    bool visited[5][5];
    for(int i=0;i<5;i++){
        for( int j=0;j<5;j++){
            if(grid[i][j]==1){
                visited[i][j]=true;
            }
            else{
                visited[i][j]=false;
            }
            if(grid[i][j]==2){
                src.row=i;
                src.col=j;
            }
        }
    }
    //BFS
    queue <node> q;
    q.push(src);
    visited[src.row][src.col]=true;
    while(!q.empty()){
        node x = q.front();
        q.pop();
        if(grid[x.row][x.col]==3){
            return x.dist;
        }
        //up
        if (x.row - 1 >= 0 && visited[x.row - 1][x.col] == false) {
            q.push(node(x.row - 1, x.col, x.dist + 1));
            visited[x.row - 1][x.col] = true;
        }
 
        //down
        if (x.row + 1 < 5 && visited[x.row + 1][x.col] == false) {
            q.push(node(x.row + 1, x.col, x.dist + 1));
            visited[x.row + 1][x.col] = true;
        }
 
        //left
        if (x.col - 1 >= 0 && visited[x.row][x.col - 1] == false) {
            q.push(node(x.row, x.col - 1, x.dist + 1));
            visited[x.row][x.col - 1] = true;
        }
 
        //right
        if (x.col + 1 < 5 && visited[x.row][x.col + 1] == false) {
            q.push(node(x.row, x.col + 1, x.dist + 1));
            visited[x.row][x.col + 1] = true;
        }
    }
    return -1;
    
}



int main() {
    // src = 2;
    // dest = 3;
    int grid[5][5] = {{0,0,0,0,1},
                    {1,2,0,1,0},
                    {1,0,1,0,1},
                    {1,0,0,0,3},
                    {0,0,1,0,0}};
                    
    int grid1[5][5] ={{0,0,0,0,1},
                    {1,2,0,1,0},
                    {1,0,1,0,1},
                    {1,0,1,0,3},
                    {0,0,1,0,0}};
    if(mincells(grid)!=-1){
        cout<<mincells(grid)<<endl;
    }
    else{
        cout<<"no path can be derived";
    }
    if(mincells(grid1)!=-1){
        cout<<mincells(grid1);
    }
    else{
        cout<<"no path can be derived";
    }
}
