#pragma once

#include<map>
#include<string>
#include<vector>
#include "Data.h"

using namespace std;

class Graph {
private:
	vector<int>* adj_ = nullptr;
	int v_ = 0;
	map<string, Data*> user_data;
	vector<string> user_id;

public:
	explicit Graph(const int& users);
	
	void map_user_data(const string& id, Data* address);

	Data* login(const string& user, const string& pass);

	Data* get_user_data(const string& user);

	int get_graph_size() const;

	bool is_slot_empty(const int& i);

	bool is_unique(const string& username);

	void connect(int u, int v) const;
	
	void print() const;
	
	vector<int> find_mutual(int u, int v) const;
	
	vector<int> m_friends(int u) const;
	
	vector<int> short_path(int s, int e) const;
	
	void register_userID(const string& username, int slot);
};
