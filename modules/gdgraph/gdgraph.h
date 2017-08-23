/* gdgraph.h */
#ifndef GDGRAPH_H
#define GDGRAPH_H

#include <vector>

struct Vertex;
struct Edge;

struct Vertex {
	std::vector<Edge*> edges;
};

struct Edge {
	Vertex* v1;
	Vertex* v2;
};

class Graph : public Reference {
	OBJ_TYPE(Graph,Reference);

protected:
	static void _bind_methods();

public:
	Graph();
	void add_vertex(Vertex* v);
    void add_edge(Edge* e);
    void random_triconnected(int n);
    void clear();

private:
	std::vector<Edge> edges;
	std::vector<Vertex> vertices;

};

#endif

// #include "reference.h"
// #include "ustring.h"

// #include "map.h"
// #include "sqlite/sqlite3.h"

// class SQLite : public Reference {
// 	OBJ_TYPE(SQLite,Reference);

// protected:
// 	static void _bind_methods();

// public:
// 	SQLite();
	
// 	int open(String path);
	
// 	void prepare(String query);
// 	int step();
// 	int step_assoc();
// 	Array fetch_assoc();
// 	Array fetch_one();
// 	Array fetch_array(String query);
// 	int query(String query);
// 	int get_data_count();
// 	int get_column_count();
// 	int get_column_int(int col);
// 	double get_column_double(int col);
// 	String get_column_text(int col);
// 	int get_column_int_assoc(String col);
// 	double get_column_double_assoc(String col);
// 	String get_column_text_assoc(String col);
	
// 	void finalize();
// 	String get_errormsg();
// 	void close();

// private:
// 	sqlite3 *db;
// 	sqlite3_stmt *stmt;

// 	Map<String, unsigned int> _row_names;
// };

