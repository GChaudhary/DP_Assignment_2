#include <bits/stdc++.h>

using namespace std;

long long int avoidRoads(int height, int width, string bad_roads){
	int x_coordinate,y_coordinate;
	int n,num;
	long long int result[101][101] = {0};
	string temporary;
	bool b[101][101] = {0};

	// Processing the bad roads
	int count = 0;
	for(int i=0; i<bad_roads.size(); i++){
		if((int)bad_roads[i] > 47 && (int)bad_roads[i] < 58){
			num = (int)bad_roads[i]-48;

			count++;
			if(count == 1)
				x_coordinate = num;
			else{
				y_coordinate = num;
				count = 0;
				b[x_coordinate][y_coordinate] = 1;
			}
		}
	}

	// Filling the table entries
	result[0][0] = 1;
	for(int i=0;i<=height;i++){
		for(int j=0;j<=width;j++){
			if(b[i][j]){
				if(!b[i+1][j])
					result[i+1][j] += result[i][j];
				if(!b[i][j+1])
					result[i][j+1] += result[i][j];
			}
			else{
				result[i+1][j] += result[i][j];
				result[i][j+1] += result[i][j];
			}
		}
	}

	return result[height][width];
}

int main() {
	// Declare the basic variables
	int height,width;
	string bad_roads;
	long long int distinctPaths;
	
	// Test Cases
	// #1
	height = 6;
	width = 6;
	bad_roads = "{\"0 0 0 1\",\"6 6 5 6\"}";

	distinctPaths = avoidRoads(height, width, bad_roads);
	cout << "Height = " << height << "\tWidth = " << width << endl;
	cout << "Bad roads = " << bad_roads << endl;
	cout << "Number of distinct paths are = " << distinctPaths << endl << endl;


	// #2
	height = 1;
	width = 1;
	bad_roads = "{ }";

	distinctPaths = avoidRoads(height, width, bad_roads);
	cout << "Height = " << height << "\tWidth = " << width << endl;
	cout << "Bad roads = " << bad_roads << endl;
	cout << "Number of distinct paths are = " << distinctPaths << endl << endl;


	// #3
	height = 35;
	width =31;
	bad_roads = "{ }";

	distinctPaths = avoidRoads(height, width, bad_roads);
	cout << "Height = " << height << "\tWidth = " << width << endl;
	cout << "Bad roads = " << bad_roads << endl;
	cout << "Number of distinct paths are = " << distinctPaths << endl << endl;


	// #4
	height = 2;
	width = 2;
	bad_roads = "{\"0 0 1 0\", \"1 2 2 2\", \"1 1 2 1\"}";

	distinctPaths = avoidRoads(height, width, bad_roads);
	cout << "Height = " << height << "\tWidth = " << width << endl;
	cout << "Bad roads = " << bad_roads << endl;
	cout << "Number of distinct paths are = " << distinctPaths << endl << endl;

	

	return 0;
}