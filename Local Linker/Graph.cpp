#include "Graph.h"

#include<iostream>
#include<queue>

using namespace std;

Graph::Graph(const int& users)
{
	v_ = users;
	adj_ = new vector<int>(v_, 0);
	user_id = vector<string>(v_, "NOT SET");
}

void Graph::map_user_data(const string& id, Data* address)
{
	this->user_data[id] = address;
}

void Graph::register_userID(const string& username, int slot)
{
	this->user_id[slot] = username;
}

Data* Graph::login(const string& user, const string& pass)
{
	if (user_data[user])
	{
		if(user_data[user]->get_password() == pass)
		{
			return user_data[user];
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		cout << "incorrect username. please try again!" << endl;
		return nullptr;
	}
}

Data* Graph::get_user_data(const string& user)
{
	return this->user_data[user];
}

int Graph::get_graph_size() const
{
	return v_;
}

bool Graph::is_slot_empty(const int& i)
{
	return user_id[i] == "NOT SET" ? true : false;
}

bool Graph::is_unique(const string& username)
{
	return !user_data[username] ? true : false;
}

void Graph :: connect(int u, int v) const
{
	adj_[u].push_back(v);
	adj_[v].push_back(u);
}

void Graph :: print() const
{
	for (int i = 0; i < v_; i++) {
		if(adj_[i][0])
		{
			cout << i << "->";
			for (auto ele : adj_[i]) {
				cout << ele << " ";
			}
		}
		cout << endl;
	}
}

//returns list of MUTUAL FRIENDS of u and v!
vector<int> Graph :: find_mutual(int u, int v) const
{
	vector<bool> nebr(this->v_, false);
	vector<int> lst;
	for (auto ele : adj_[u]) {
		nebr[ele] = true;
	}
	for (auto ele : adj_[v]) {
		if (nebr[ele] == true) {
			lst.push_back(ele);
		}
	}
	return lst;
}

//returns list of friends of friends(SUGGESTION)
vector<int> Graph :: m_friends(int u) const
{
	vector<bool> visited(this->v_, false);
	vector<int> lst;
	visited[u] = true;
	for (auto frd : adj_[u]) {
		for (auto frdf : adj_[frd]) {
			if (!visited[frdf]) {
				visited[frdf] = true;
				lst.push_back(frdf);
			}
		}
	}
	return lst;
}

//return SHORTEST PATH between s and e!
vector<int> Graph :: short_path(int s, int e) const
{
	vector<bool> visited(v_, false);
	vector<int> prev(v_, -1);
	queue<int> q;

	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		int index = q.front();
		q.pop();
		vector<int> neighbors = adj_[index];
		for (auto next : neighbors) {
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
				prev[next] = index;
			}
		}
	}
	vector<int> path;
	for (int at = e; at != -1; at = prev[at]) {
		path.push_back(at);
	}
	reverse(path.begin(), path.end());
	return path;
}
