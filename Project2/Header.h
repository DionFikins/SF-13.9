#pragma once
#include <iostream>
#define SIZE 10

class Graph {
private:
	void find(std::string start, std::string curr, bool visited[], int shake, int wight);
	bool edgeExists(std::string current, std::string parent);
	bool vertexExists(std::string name);
	int matrix[SIZE][SIZE];
	std::string vertexes[SIZE];
	int vertexCount;
public:
	Graph();

	int GetIndex(std::string name);
	int GetEgde(std::string current, std::string parent);
	void Show(int shake);
	void Add(std::string name);
	void AddEdge(std::string current, std::string parent, int weight);
};