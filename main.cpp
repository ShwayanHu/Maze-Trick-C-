//
//  main.cpp
//  数据结构与算法期末大作业_迷宫求解
//
//  Created by 胡雪岩 on 2022/7/7.
//

#include <iostream>
#include <iterator>
#include<cstdlib>
#include<ctime>
using namespace std;

typedef bool Status;
const Status OK = true;
const Status Error = false;
const int N = 7;//Global constant N is the length and width of the maze.
float threshold = 0.3;//Global constant threshold controls the probability of whether the maze has a solution. Threshold==0.3 means the probability for each Node that is placeable is 1-0.3=0.7. The greater the Threshold is , the more difficult it is to find a solution.


struct Node {
    int placeable;//The variable placeable means whether the Node is on a road. When placeable==0, it is a "wall" instead of road.
    Node* n, * s, * w, * e;//Respectively points to the Node on north, south, west, and east.
};
struct Maze {
    Node board[N][N];//The length and width of Maze are N.
};

Maze* Init_Maze() { //Creat a maze without any useful info.
    Maze* M = new Maze;
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            M->board[row][column].placeable = 0;//All nodes are not placeable
            M->board[row][column].n = NULL;//Pointers for each node are set to NULL.
            M->board[row][column].s = NULL;
            M->board[row][column].w = NULL;
            M->board[row][column].e = NULL;
        }
    }
    return M;
}

Status Random_Creat_Maze(int N, Maze* M) {
    // 首先，初始化placeble
    srand((unsigned)time(NULL));//Set random seeds relating to time.
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            for (int i = 0; i < 5; i++) {
                if (rand() % 1000 / (float)(1000) > threshold) { M->board[row][column].placeable = 1; }
                else { M->board[row][column].placeable = 0; }
            }
        }
    }
    // 其次，初始化四个指针n、s、w和e
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            //Set the pointers of Nodes on the boundary as NULL.
            if (row == 0) { M->board[row][column].n = NULL; }
            if (row == N - 1) { M->board[row][column].s = NULL; }
            if (column == 0) { M->board[row][column].w = NULL; }
            if (column == N - 1) { M->board[row][column].e = NULL; }
            
            //Set the pointers of non-boundary Nodes as the correct Nodes.
            if (row != 0 || row != N - 1 || column != 0 || column != N - 1) {
                M->board[row][column].n = &M->board[row - 1][column];
                M->board[row][column].s = &M->board[row + 1][column];
                M->board[row][column].w = &M->board[row][column - 1];
                M->board[row][column].e = &M->board[row][column + 1];
            }
        }
    }
    return OK;
};

Status Mannual_Creat_Maze(int N, Maze* M) {
    int temp;//Temporary variable is used to judge the legality of cin.
    cout << "Please enter the maze manually. Make sure the Node(1,1) and Node("<<N<<","<<N<<") is road(equals to 1)." << endl;
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            cout << "Currently creating Node(" << row + 1 << "," << column + 1 << ")……";
            cout << "Please enter whether this Node is road(1 means road, 0 means wall)" << endl;
            cin >> temp;
            while (temp != 0 && temp != 1) { cout << "Cin illegal, please enter again!(1 means road, 0 means wall)" << endl; cin >> temp; }
            M->board[row][column].placeable = temp;
        }
    }
    //Set the pointers of each Node.
    for (int row = 0; row < N; row++) {
        for (int column = 0; column < N; column++) {
            //Set the pointers of Nodes on the boundary as NULL.
            if (row == 0) { M->board[row][column].n = NULL; }
            if (row == N - 1) { M->board[row][column].s = NULL; }
            if (column == 0) { M->board[row][column].w = NULL; }
            if (column == N - 1) { M->board[row][column].e = NULL; }
            //Set the pointers of non-boundary Nodes as the correct Nodes.
            if (row != 0 || row != N - 1 || column != 0 || column != N - 1) {
                M->board[row][column].n = &M->board[row - 1][column];
                M->board[row][column].s = &M->board[row + 1][column];
                M->board[row][column].w = &M->board[row][column - 1];
                M->board[row][column].e = &M->board[row][column + 1];
            }
        }
    }
    return OK;
};

Status Creat_Maze(Maze* M) {
    cout << "Creating maze of " << N << "^2……" << endl;
    cout << "Enter 1 to creat maze mannually, enter 0 to creat maze automatically(recommended):" << endl;
    int choose_creating_method;
    cin >> choose_creating_method;
    switch (choose_creating_method) {
    case 0: {
        cout << "Creating maze automatically……" << endl;
        Random_Creat_Maze(N, M);
        break;
    }
    case 1: {
        cout << "Creating maze mannually……" << endl;
        Mannual_Creat_Maze(N, M);
        break;
    }
    }
    M->board[0][0].placeable = 1; //确保迷宫入口可走
    M->board[N-1][N-1].placeable = 1; //确保迷宫出口可走
    return OK;
};




//将已经创建好的迷宫打印出来
Status Read_Maze(Maze* M) {
    cout << "The maze is:（1 for road and 0 for wall）" << endl;
    cout << "   ";
    for(int k = 1;k<N+1;k++){
        cout << k<<"  ";
    }
    cout <<endl;
    cout <<"  ";
    for(int k = 1;k<N+1;k++){
        cout << "———";
    }
    cout <<endl;

    for (int i = 0,k=1; i < N-1; i++) {
        cout<<k<<" |";
        for (int j = 0; j < N; j++) {
            cout << M->board[i][j].placeable << "  ";
        }
        k++;
    cout << endl;
    }
    cout <<N<<"|";
    for (int j = 0; j < N; j++) {
        cout << M->board[N-1][j].placeable << "  ";
    }

    cout <<endl;
    return OK;
}

struct Loc{
    int x,y;//Record position
};

int visited[N][N];//Record visited Nodes.

struct SqStack{
    Loc road[N*N];
    int top ;
};

Status InitStack(SqStack &S){
    S.top=-1;
    return OK;
};

Status Push(SqStack &S,int i,int j){
    S.top++;
    S.road[S.top].x=i;
    S.road[S.top].y=j;
    return OK;
}

void visit(int i,int j){
    visited[i][j]=1;
    cout<<"("<<i+1<<","<<j+1<<") -> ";
}


//Solve the maze.
Status Solve_Maze(Maze* M,int i,int j,SqStack& S ){//(i,j) represents the entrance.
    visit(i,j);
    Push(S,i,j);
    // cout <<"s1:"<<S.top<<endl;
    while(S.top>-1){ //When the stack isn't empty.
        if(i== N-1 && j == N-1){Push(S,i,j);break;break;}//Judge have we got the exit.
        
        //Move to east if possible.
        while(M->board[i][j].e!=NULL && M->board[i][j].e->placeable!=0 && visited[i][j+1]==0 && j<N-1){
        j++;
        Push(S,i,j);//Push current Node to Stack.
        visit(i,j);
        }
        if(M->board[i][j].s!=NULL && M->board[i][j].s->placeable!=0 && visited[i+1][j]==0 && i<N-1){
            i++;
            Push(S,i,j);
            visit(i,j);
            // cout <<"s";
            if(i== N-1 && j == N-1){break;}
        }
        else if(M->board[i][j].w!=NULL && M->board[i][j].w->placeable!=0 && visited[i][j-1]==0 && j>0){
            j--;
            Push(S,i,j);
            visit(i,j);
            if(i== N-1 && j == N-1){break;}
        }
        else if(M->board[i][j].n!=NULL && M->board[i][j].n->placeable!=0 && visited[i-1][j]==0 && i>0){
            i--;
            Push(S,i,j);
            visit(i,j);
            if(i== N-1 && j == N-1){break;}
        }
        else {
            if(i== N-1 && j == N-1){break;break;}
            S.top--;
            i = S.road[S.top].x;
            j = S.road[S.top].y;
        }

    }
    if(S.top==-1){cout <<"Unsolvable!"<<endl;return Error;}
    else{cout << "Successfully Solved!"<<endl;}
    return OK;
}

Status Get_Path(Maze* M,SqStack S){
    if (S.top==-1){cout << "The maze is unsolvable!"<<endl;return Error;}
    cout <<"The path to solve the maze is:"<<endl;
    cout << "Entrance -> ";
    for(int i=0;i<=S.top;i++){
        cout<<"("<<S.road[i].x<<","<<S.road[i].y<<") -> ";
    }
    if(M->board[N-2][N-1].placeable==1){cout <<"("<<N-1<<","<<N<<") -> ";}
    else{cout <<"("<<N<<","<<N-1<<") -> ";}
    cout << "(10,10) -> Exit"<<endl;
    return OK;
}

int main() {
    cout <<"———————————Creating the maze————————"<<endl;
    Maze* M = Init_Maze();
    Creat_Maze(M);
    cout <<endl;
    cout <<"———————————Reading the maze—————————"<<endl;
    Read_Maze(M);
    SqStack S;
    InitStack(S);
    cout <<endl;
    cout <<"———————————Solve the maze———————————"<<endl;
    Solve_Maze(M,0,0,S);//Path is saved in S.
    cout <<endl;
    cout <<"———————————Getting the path—————————"<<endl;
    Get_Path(M,S);
    return 0;
}
