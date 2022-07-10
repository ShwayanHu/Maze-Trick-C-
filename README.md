# Maze Trick (C++)

# Read at First

All the important functions and variables are introduced in this file. As they are in Italian and Bold, you will find recognizing them easy. 

The complete code is uploaded to github. **Before using the code i.e. copying or etc., please contact the developer to acquire access.** 

# Introduction

We programmed this game in order to enhance our competence on applying data structures into real-world problems. Maze problem is a common problem that has various usages in every aspects of social life such as retriving survivers in a firegroud. Actually, every problem with a complex map has its place for Maze Trick. 

The programme is entirely based on C++. With a given or randomly created maze, the program will calculate and output it’s solving process and final solution, which can be freely changed in the main function. 

We focused on the realization of the maze and the algorithm of getting the solution of the maze. To be convenient, we haven’t developed the interaction between users and programme apart from letting users enter the maze. 

# Usage Detail

In this part, we are going to address the details of the code and tell you about how to use this programme to push it to the best. The order of the following content is cooresbonding with the code. 

## Playing rules

As soon as you run the file, maze game begins. At the beginning of the code, you will receive a message like this. 

```
———————————Creating the maze————————
Creating maze of 10^2……
Enter 1 to creat maze mannually, enter 0 to creat maze automatically(recommended):
```

If you enter “1”, you need to creat a maze by your self. The message is:

```
Creating maze mannually……
Please enter the maze manually. Make sure the Node(1,1) and Node(10,10) is road(equals to 1).
Currently creating Node(1,1)……Please enter whether this Node is road(1 means road, 0 means wall)
```

As the message shows, now you’re deciding the Node(1,1) is whether road or wall by entering 1 or 0. 

On the contrast, if you wenter “0”, the programme will automatically creat a maze. The creating of the maze is controled by a threshold float called $threshold$. This variable represents the probability for each node to be set to wall. Please pay attention, there’s prabability that the maze doesn’t have a solution. After you enter 1, you will receive a message like this:

```
Creating maze automatically……
```

After the maze has been created, A series of command will be excecuted. The programme excecutes the following functions in order: reading and printing the maze, show the solving process of the maze, and printing the solution of the maze. The messages are:

```
———————————Reading the maze—————————
The maze is:（1 for road and 0 for wall）
   1  2  3  4  5  6  7  8  9  10  
  ——————————————————————————————
1 |1  0  0  0  0  0  0  1  0  1  
2 |1  0  0  1  0  0  1  0  1  1  
3 |1  1  0  1  1  1  1  1  1  0  
4 |1  1  1  1  0  0  1  1  1  1  
5 |1  1  1  1  0  0  1  0  1  1  
6 |1  1  1  0  0  0  0  1  1  1  
7 |1  1  1  0  0  0  1  0  1  1  
8 |1  1  1  1  1  1  1  1  1  0  
9 |1  1  0  1  1  1  1  0  0  1  
10|0  1  0  1  1  1  1  1  1  1  

———————————Solve the maze———————————
(1,1) -> (2,1) -> (3,1) -> (3,2) -> (4,2) -> (4,3) -> (4,4) -> (5,4) -> (5,3) -> (6,3) -> (7,3) -> (8,3) -> (8,4) -> (8,5) -> (8,6) -> (8,7) -> (8,8) -> (8,9) -> (7,9) -> (7,10) -> (6,10) -> (6,9) -> (6,8) -> (5,9) -> (5,10) -> (4,10) -> (4,9) -> (4,8) -> (4,7) -> (5,7) -> (3,7) -> (3,8) -> (3,9) -> (2,9) -> (2,10) -> (1,10) -> (3,6) -> (3,5) -> (3,4) -> (2,4) -> (2,7) -> (9,7) -> (10,7) -> (10,8) -> (10,9) -> (10,10) -> (9,10) -> Successfully Solved!

———————————Getting the path—————————
The path to solve the maze is:
Entrance -> (0,0) -> (1,0) -> (2,0) -> (2,1) -> (3,1) -> (3,2) -> (3,3) -> (4,3) -> (4,2) -> (5,2) -> (6,2) -> (7,2) -> (7,3) -> (7,4) -> (7,5) -> (7,6) -> (8,6) -> (9,6) -> (9,7) -> (9,8) -> (9,9) -> (9,9) -> (9,10) -> (10,10) -> Exit
```

When there’s no solution for this maze, you will also receive a message to let you know what’s happening:

```
———————————Reading the maze—————————
The maze is:（1 for road and 0 for wall）
   1  2  3  4  5  6  7  8  9  10  
  ——————————————————————————————
1 |1  0  1  1  0  0  0  0  1  1  
2 |1  0  1  1  1  0  0  1  1  1  
3 |0  1  1  1  1  1  1  1  1  1  
4 |0  1  1  1  1  1  1  1  1  0  
5 |1  0  0  1  1  0  1  1  1  1  
6 |1  0  1  0  1  0  0  0  1  1  
7 |1  0  1  1  0  0  0  0  0  1  
8 |0  1  0  0  0  1  1  1  0  1  
9 |0  1  0  1  1  1  1  0  0  1  
10|1  0  0  1  1  1  1  0  0  1  

———————————Solve the maze———————————
(1,1) -> (2,1) -> Unsolvable!

———————————Getting the path—————————
The maze is unsolvable!
```

## Key Variables

There are two key variables in this programme, the first one is $N$, and the second one is $threshold$. $N$controls the lenth and width of the maze. As we set the length and width the same, the maze will be of $N\times N$. $threshold$  controls the difficulty for each node to be road. The greater $threshold$ is, the easier to have a solution. $threshold$ only affects when the user choose to creat maze automatically. 

## Declearations and Definitions

In order to operate the programme, we make some useful declearations and definitions. Concretely, two main structures are included in this programme. The first data structure is creating the maze board, the second data structure is a sequential stack. 

The maze board is defined with the following code. The maze is constructed by $N^2$ Nodes. Each node is constructed with an 0-1 variable called $placeable$ and four pointers called $n,s,w$, and $e$ respectively. The variable $placeable$ indicates whether the node is road or wall, and the four pointers point to nodes in its north, south, west, and east respectively. 

```cpp
struct Node {
    int placeable;//The variable placeable means whether the Node is on a road. When placeable==0, it is a "wall" instead of road.
    Node* n, * s, * w, * e;//Respectively points to the Node on north, south, west, and east.
};
struct Maze {
    Node board[N][N];//The length and width of Maze are N.
};
```

The sequential stack in defined as follows. $Loc$ is a struct with two int. $Loc$ is used to record the position in the board. $SqStack$  is a sequential stack with a $N^2$ array and a vatiable $top$ to indicate the top of the stack. 

```cpp
struct Loc{
    int x,y;//Record position
};

struct SqStack{
    Loc road[N*N];
    int top ;
};
```

## Functions

In this part, we introduces the functions of this programme. Input, output and how to use this function is included. Similarly, we arrange the contents in the order of code. 

All functions we have created are listed bellow. Return value $Status$ is a mannually created bool used to tell whether functions are excecuted correctly or not. As you can see,  the maze is initiated and passed to the function in the form of pointer, that is a pointer to the struct $Maze$.

```cpp
Maze* Init_Maze();
Status Random_Creat_Maze(int N, Maze* M);
Status Mannual_Creat_Maze(int N, Maze* M);
Status Creat_Maze(Maze* M);
Status Read_Maze(Maze* M);
Status Solve_Maze(Maze* M,int i,int j,SqStack& S );
Status Get_Path(Maze* M,SqStack S);
```

Let’s look at the above-mentioned functions respectively. 

Function $Init\_Maze()$ creats a maze,  sets all the points as $NULL$ and all $placeable$ as 0.

Function $Random\_Creat\_Maze(int\ N, Maze*\ M)$ creats a maze automatically. In detail, it generates a random number from 0 to 1, and use the $threshold$ to decide weather it is wall or road, and change it into 0 or 1. Attention: the boundary of the maze is possible to be road, some pointers of the boundary nodes are set to $NULL$, such as the $n$ and $w$ of the Node(1,1). 

Function $Mannual\_Creat\_Maze(int\ N, Maze*\ M)$ allows you to creat a maze mannually. by entering the 1 or 0 with instructions of the programme you can set any node to be road or wall. 

Function $Creat\_Maze(Maze*\ M)$ allows you to decide whether excecute $Random\_Creat\_Maze(int\ N, Maze*\ M)$ or $Mannual\_Creat\_Maze(int\ N, Maze*\ M)$.

Function $Read\_Maze(Maze* M)$ prints the maze to the terminal. In current version($N=10$), the output is tidy and beautiful. But as the $N$ changes, it may suffer from messy. This is a point needed to improve!

Function $Solve\_Maze(Maze*\ M,int\ i,int\ j,SqStack\&\ S )$ shows the process of solving the maze. Using stack, you will find the player(computer, at least for right now) meet the wall times after times and go backward for many times.

Function $Get\_Path(Maze*\ M,SqStack\ S)$ prints the solution if it is solvable, or simply tell the user that the maze is unsolvable. 

# Expected Improvements

As far as we have discussed, we raised some points need to be improved. Although they are still not complete, they can be a reference. The freedom is all yours!!

1. Improve the programme to be interactive with users. For instance, letting the users try out the maze, letting different users compete with mazes, etc. 
2. Improve the programme to be able to beautifully print maze with different $N$ by making changes to the function $Read\_Maze(Maze* M)$. 

# Developers

The game belongs to a team of four students from Central University of Finance and Economy(CUFE), Beijing China. The developers are (alphabetically) Fei Wang, Ruijie Yuan, Xueyan Hu, and Ziyuan Zhang

If you are interested in this programme or would like to upgrade this program, feel free to folk or reach me by **2020310221@email.cufe.edu.cn** or **1033739554@qq.com**.