#include <iostream>
#include "Header.h"

int main() {
	Graph g;
	
	g.Add("Nick");
	g.Add("Fred");
	g.Add("Nicole");
	g.Add("Marry");
	g.Add("Ange");
	g.Add("Lyis");
	g.Add("Alex");
	g.Add("Dasty");
	g.Add("Greg");
	g.Add("Milone");

	g.AddEdge("Nick", "Fred", 1);
	g.AddEdge("Fred", "Nicole", 1);

	g.AddEdge("Nicole", "Marry", 1);
	g.AddEdge("Marry", "Ange", 1);

	g.AddEdge("Ange", "Lyis", 1);
	g.AddEdge("Lyis", "Alex", 1);

	g.AddEdge("Alex", "Dasty", 1);
	g.AddEdge("Dasty", "Greg", 1);

	g.AddEdge("Greg", "Milone", 1);
	g.AddEdge("Milone", "Nick", 1);

	g.Show(3);
}