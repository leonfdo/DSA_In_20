#include <iostream>
#include <vector>

using namespace std;

int mini(int len[6],bool visited[6], vector<vector<int>> graph,int star) {
	int min = INT_MAX;
	int k=star;
	
	for (int i = 0; i < 6; i++) {
		if (!visited[i] && len[i] < min) {
			min = len[i];
			k = i;
		}
	}
	return k;
}

int dij(vector<vector<int>> graph, int star) {
	bool visited[6];
	int len[6];

	for (int i = 0; i < 6; i++) {
		visited[i] = false;
		len[i] = INT_MAX;
	}

	visited[star] = true;
	len[star] = 0;

	for (int j = 0; j < 5; j++) {
		int min_city = mini(len, visited, graph,star);
		visited[min_city] = true;

		for (int k = 0; k < 6; k++) {
			if (graph[min_city][k] != 0 && len[min_city] + graph[min_city][k] < len[k] && !visited[k]) {
				len[k] = len[min_city] + graph[min_city][k];
			}
		}
	}


	int max = 0;
	for (int p = 0; p < 6; p++) {
		if (p == star) {
			continue;
		}
		max += len[p];
		/*cout << "distance to city " << p << " is : " << len[p];
		cout << endl;
		cout << endl;*/
	}
	cout << "average time to a city from "<< star <<" is : " << max / 5.0;
	cout << endl;
}

int main() {

	vector<vector<int>> graph = {
	{0,10,0,0,15,5},
	{10,0,10,30,0,0},
	{0,10,0,12,5,0},
	{0,30,12,0,0,20},
	{15,0,5,0,0,0},
	{5,0,0,20,0,0}};

	int star=0 ;
	for (int i = 0; i < 6; i++) {
		dij(graph, star);
		star++;
	}
}
