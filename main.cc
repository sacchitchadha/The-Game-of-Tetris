#include "Game.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	Game g;
	srand(time(NULL));
	for(int i = 1; i < argc; ++i){
		string flag = argv[i];
		if(flag == "-text"){
			g.setTextOnly();
		}else if(flag == "-startlevel"){
			g.setLevel(stoi(argv[i+1]));
		}else if(flag == "-seed"){
			int seed = stoi(argv[i+1]);
			srand(seed);
		}else if(flag == "-scriptfile"){
			string filename = argv[i+1];
			// cout << "scriptfile is" << argv[i+1] << endl;
			g.setScriptFile(filename);
		}
	}
	g.start();
}

