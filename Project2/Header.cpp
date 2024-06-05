#include "Header.h"

void Graph::find(std::string first, std::string second, bool visited[], int shake, int wight)
{
	if (wight <= shake && wight > 0) {
		std::cout << first << " and " << second << std::endl;
	}
	visited[GetIndex(second)] = true;
	for (int i = 0; i < vertexCount; i++) {
		if (edgeExists(second, vertexes[i]) && !visited[i]) {
			wight += GetEgde(second, vertexes[i]);
			find(first, vertexes[i], visited, shake, wight);
		}
	}
}

bool Graph::edgeExists(std::string current, std::string parent)
{
	return matrix[GetIndex(current)][GetIndex(parent)] > 0;
}

bool Graph::vertexExists(std::string name)
{
	for (int i = 0; i < vertexCount; i++) {
		if (vertexes[i] == name) {
			return true;
		}
	}
	return false;
}

Graph::Graph()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = 0;
		}
	}
	vertexCount = 0;
}

int Graph::GetIndex(std::string name)
{
	for (int i = 0; i < vertexCount; i++) {
		if (vertexes[i] == name) {
			return i;
		}
	}
	return -1;
}

int Graph::GetEgde(std::string current, std::string parent)
{
	return matrix[GetIndex(current)][GetIndex(parent)];
}

void Graph::Show(int shake)
{
	std::cout << "Users threed handshakes(who is who): " << std::endl;

	bool visited[SIZE];
	for (int i = 0; i < SIZE; i++) {
		visited[i] = false;
	}
	int wight = 0;
	for (int i = 0; i < vertexCount; i++) {
		find(vertexes[i], vertexes[i], visited, shake, wight);
		visited[i] = true;
	}
}

void Graph::Add(std::string name)
{
	vertexes[vertexCount++] = name;
}

void Graph::AddEdge(std::string current, std::string parent, int weight)
{
	matrix[GetIndex(current)][GetIndex(parent)] = weight;
	matrix[GetIndex(parent)][GetIndex(current)] = weight;
}
