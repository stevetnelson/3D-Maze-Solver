#ifndef MAZE_H
#define MAZE_H

#include "MazeInterface.h"

class Maze : public MazeInterface {
private:
	int*** maze;
	int mazeHeight;
	int mazeWidth;
	int mazeLayers;
	bool mazeAttemptedSolved = false;
	bool mazeSolved = false;
	bool findExit(int height, int width, int layer);

public:
	Maze(int height, int width, int layers) : mazeHeight(height), mazeWidth(width), mazeLayers(layers) { //initialize maze sizes
		maze = new int** [height];
		for (int i = 0; i < height; ++i) {
			maze[i] = new int* [width];
			for (int j = 0; j < width; ++j) {
				maze[i][j] = new int[layers];
			}
		}
	}
	~Maze(void) {
		for (int i = 0; i < mazeHeight; ++i) {
			for (int j = 0; j < mazeWidth; ++j) {
				delete[]  maze[i][j];
			}
			delete[] maze[i];
		}
		delete[] maze;
	}

	virtual void setValue(int height, int width, int layer, int value);

	virtual bool find_maze_path();

	virtual std::string toString() const;
};


#endif //MAZE_H