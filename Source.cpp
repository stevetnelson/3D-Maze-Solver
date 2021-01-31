#include <iostream>
#include <fstream>
#include <sstream>
#include "Maze.h"
using namespace std;


int main(int argc, char* argv[]) {

	//open input/output files and check for errors that may have occured while opening
	if (argc < 3) {
		cerr << "Please provide name of input and output files";
	}
	ifstream in(argv[1]);
	if (!in) {
		cerr << "Unable to open " << argv[1] << " for input";
	}
	ofstream out(argv[2]);
	if (!out) {
		in.close();
		cerr << "Unable to open " << argv[2] << " for output";
	}

	//pull in initial maze size information and initialize a maze object
	int height;
	int width;
	int layers;
	string line; 
	getline(in, line);
	istringstream dimensions(line);
	dimensions >> height;
	dimensions >> width;
	dimensions >> layers;
	Maze myMaze(height, width, layers);

	int holder;
	istringstream row;
	//read in maze info and initialize
	for (int i = 0; i < layers; ++i) {
		getline(in, line);
		for (int j = 0; j < height; ++j) {
			getline(in, line);
			row.clear();
			row.str(line);
			for (int k = 0; k < width; ++k) {
				row >> holder;
				myMaze.setValue(j, k, i, holder);
			}
		}
	}

	out << myMaze.toString();
	out << endl;
	myMaze.find_maze_path();
	out << myMaze.toString();

	//close files
	in.close();
	out.close();

	return 0;
}