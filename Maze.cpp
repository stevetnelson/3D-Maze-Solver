#include "Maze.h"

void Maze::setValue(int height, int width, int layer, int value) {
	maze[height][width][layer] = value;
}

bool Maze::find_maze_path() {
	mazeAttemptedSolved = true;
	mazeSolved = findExit(0, 0, 0);
	return mazeSolved;
}

std::string Maze::toString() const {
	if (!mazeAttemptedSolved) {
		std::string mazeOutput = "Solve Maze:\n";
		for (int i = 0; i < mazeLayers; ++i) {
			mazeOutput += "Layer " + std::to_string(i + 1) + "\n";
			for (int j = 0; j < mazeHeight; ++j) {
				for (int k = 0; k < mazeWidth; ++k) {
					if (maze[j][k][i] == 1) {
						mazeOutput += "X ";
					}
					else {
						mazeOutput += "_ ";
					}
				}
				mazeOutput += "\n";
			}
			mazeOutput += "\n";
		}
		return mazeOutput;
	}
	else {
		if (!mazeSolved) {
			return "No Solution Exists!";
		}
		std::string mazeOutput = "Solution:\n";
		for (int i = 0; i < mazeLayers; ++i) {
			mazeOutput += "Layer " + std::to_string(i + 1) + "\n";
			for (int j = 0; j < mazeHeight; ++j) {
				for (int k = 0; k < mazeWidth; ++k) {
					if (maze[j][k][i] == 1) {
						mazeOutput += "X ";
					}
					else if (maze[j][k][i] == 0 || maze[j][k][i] == 4) {
						mazeOutput += "_ ";
					}
					else if (maze[j][k][i] == 2) {
						mazeOutput += "2 ";
					}
					else if (maze[j][k][i] == 3) {
						mazeOutput += "3 ";
					}
				}
				mazeOutput += "\n";
			}
			mazeOutput += "\n";
		}
		return mazeOutput;
	}
}

bool Maze::findExit(int height, int width, int layer) {
	//return false if out of bounds call
	if (height > (mazeHeight - 1) || height < 0 || 
		width > (mazeWidth - 1) || width < 0 || 
		layer > (mazeLayers - 1) || layer < 0) {
		return false;
	}
	else if (maze[height][width][layer] != 0) {
		return false;
	}
	else if (height == (mazeHeight - 1) && width == (mazeWidth - 1) && layer == (mazeLayers - 1)) {
		maze[height][width][layer] = 3;
		return true;
	}
	maze[height][width][layer] = 2;
	if (findExit(height, width - 1, layer) || findExit(height, width + 1, layer) ||
		findExit(height - 1, width, layer) || findExit(height + 1, width, layer) ||
		findExit(height, width, layer - 1) || findExit(height, width, layer + 1)) {
		return true;
	}
	maze[height][width][layer] = 4;
	return false;
}