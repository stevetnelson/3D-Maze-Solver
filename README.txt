This program takes a 3D maze and provides a recursive function that finds a solution to that maze.
This program assumes that the maze starts in the top left corner of the bottom layer and the exit is on the bottom right corner of the upmost layer.
The input for the program first takes a line that provides width, length, and height (given in integers and with a space between each number).
Following this first line, each layer should be presented (layer by layer) with a 0 representing a space and a 1 representing a wall. Each layer should have a empty space between each of the following layers.
The file with the maze should be included as the only command line argument.
The output file first presents the maze that was provided with "X" as walls and "_" as an open space. Then, the program solves the maze and outputs the solution with "X" characters representing walls, "2" characters representing the path, "3" characters representing the exit location, and "_" characters representing any open space that wasn't used in the solution. If there is no solution, the program will output "No Solution Exists!" instead. 
The output of the program will be stored in a file called "out.txt".
An example input is the following:
"3 4 2

0 0 1 0
1 0 1 0
1 0 1 0

0 1 1 1
0 0 0 0
1 0 1 0"

And the output is:
"Solve Maze:
Layer 1
_ _ X _ 
X _ X _ 
X _ X _ 

Layer 2
_ X X X 
_ _ _ _ 
X _ X _ 


Solution:
Layer 1
2 2 X _ 
X 2 X _ 
X 2 X _ 

Layer 2
_ X X X 
_ 2 2 2 
X 2 X 3"

The program is solved using a simple recursive search function. The order that spaces are checked from each open space to find the next step is:
left (width - 1)
right (width + 1)
up (height - 1)
down (height + 1)
out (layer - 1)
in (layer + 1)

