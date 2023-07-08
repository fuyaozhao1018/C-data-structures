/*
 * Name: Fuyao Zhao
 * Email: fuyaozhao1018@gmail.com
 *
 * This file provides a skeleton for graph. 
 */

#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <iostream>
#include <map>
#include "Graph.h"
#include <bits/stdc++.h>
#include <queue>
/**
 * find the string
 *
 * @param name string to find
 * @retern the found string
 */
string Union::find(string name){
    // find root and make root as parent of i (path
    // compression)
    if (unionMap[name]!= name){

        unionMap[name] = find(unionMap[name]);
    }
 
    return unionMap[name];
}

/**
 * unite the two strings
 *
 * @param str1 string to union
 * @param str2 string to union
 */
void Union::UNION (string str1, string str2){
    string p1 = find(str1);
    string p2 = find(str2);
    unionMap[p1] = p2;
}


Graph::Graph(const string &edgelist_csv_fn) {
    num_edge = 0;
    ifstream my_file(edgelist_csv_fn);      // open the file
    string line;     
    int i=0;
    while(getline(my_file, line)){  // read one line from the file
        istringstream ss(line);      // create istringstream of current line
        string u, v,w;  
        getline(ss, u, ',');     // store first column in "first"
        getline(ss, v, ',');    // store second column in "second"
        getline(ss, w, '\n');    // store third column column in "third"
        a.insert(u,i);
        i++;
        a.insert(v,i);
        adjList[i]={a[v],w}
        i++;
        nameV.push_back(u);
        nameV.push_back(v);
        num_edge++;
    }
    my_file.close();


}

/**
 * Return the number of nodes in this graph.
 *
 * @return The number of nodes in this graph.
 */
unsigned int Graph::num_nodes() {
    unordered_set<string> nodes;
    int num=0;
    for(int i = 0; i < num_edge; i++){
        string l = get<0>(adjList[i]);
        string r = get<1>(adjList[i]);
        if(nodes.count(l) == 0){
            nodes.insert(l);
            num++;
        }
        if(nodes.count(r) == 0){
            nodes.insert(r);
            num++;
        }
    }
    return num;
}

/**
 * Return the number of (undirected) edges in this graph.
 *
 * @return The number of (undirected) edges in this graph.
 */
unsigned int Graph::num_edges(){
    return num_edge;

}
/**
 * Return a `unordered_set` of node labels of all nodes in this graph.
 *
 * @return A `unordered_set` containing the labels of all nodes in this
 * graph.
 */
unordered_set<string> Graph::nodes() {
    unordered_set<string> nodes;
    for(int i = 0; i < num_edge; i++){
        string l = get<0>(adjList[i]);
        string r = get<1>(adjList[i]);
        if(nodes.count(l) == 0){
            nodes.insert(l);}
        if(nodes.count(r) == 0){
            nodes.insert(r);
        }
    }
    return nodes;

}

/**
 * Return the number of neighbors of a given node.
 *
 * @param node_label The label of the query node.
 * @return The number of neighbors of the node labeled by `node_label`.
 */
unsigned int Graph::num_neighbors(string const &node_label) {
    unordered_set<string> nodes;
    //number of neighbours
    int num_neighbour = 0;

    nodes.insert(adjList[a[node_label]]);
    return nodes.size();

}

/**
 * Return the weight of the edge between a given pair of nodes, or -1 if
 * there does not exist an edge between the pair of nodes.
 *
 * @param u_label The label of the first node.
 * @param v_label The label of the second node.
 * @return The weight of the edge between the nodes labeled by `u_label` and
 * `v_label`, or -1 if there does not exist an edge between the pair of
 * nodes.
 */
int Graph::edge_weight(string const &u_label, string const &v_label) {
    //iterate through the list
    for(int i=0;i<num_edge;i++){
        //if found the edge case 1
        if (std::get<1>(adjList[i])==v_label
                &&std::get<0>(adjList[i])==u_label) {
            return std::get<2>(adjList[i]);
        }
        //if found the edge case 2
        if (std::get<0>(adjList[i])==v_label
                &&std::get<1>(adjList[i])==u_label) {
            return std::get<2>(adjList[i]);
        }
    }
    //when not found
    return -1;
}

/**
 * Return a `unordered_set` containing the labels of the neighbors of a 
 * given node.
 * Example: If our graph has edges "A"<-(1)->"B" and "A"<-(2)->"C", if
 * we call this function on "A", we would return the following set:
 * {"B", "C"}
 *
 * @param node_label The label of the query node.
 * @return An `unordered_set` containing the labels of the neighbors of the
 * node labeled by `node_label`.
 */
unordered_set<string> Graph::neighbors(string const &node_label) {
    unordered_set<string> nodes;
    //number of neighbours
    int num_neighbour = 0;

    nodes.insert(adjList[a[node_label]]);
    return nodes.size();
}



/**
 * Return the shortest weighted path from a given start node to a given end
 * node as a `vector` of (`from_label`, `to_label`, `edge_weight`) tuples.
 * If there does not exist a path from the start node to the end node,
 * return an empty `vector`.
 *
 * If there are multiple equally short weighted paths from the start node
 * to the end node, you can return any of them.
 *
 * If the start and end are the same, the vector should just contain a
 * single element: (`node_label`, `node_label`, 0)
 *
 * Example: If our graph has edges
 * "A"<-(1)->"B", "A"<-(5)->"C", "B"<-(1)->"C", and "C"<-(1)->"D",
 * if we start at "A" and end at "D", we would return the following
 * `vector`: {("A", "B", 1), ("B", "C", 1), ("C", "D", 1)}
 *
 * Example: If we start and end at "A", we would return the following
 * `vector`: {("A", "A", 0)}
 *
 * @param start_label The label of the start node.
 * @param end_label The label of the end node.
 * @return The shortest weighted path from the node labeled by `start_label`
 * to the node labeled by `end_label`, or an empty `vector` if no such path
 * exists.
 */
vector<tuple<string, string, int>> Graph::shortest_path_weighted(string const &start_label,
                                             string const &end_label) {
    //vector for the answer
    vector<tuple<string, string, int>> answer;

    //if start is equal to end
    if(start_label==end_label){
        //return the vector with 0
        answer.push_back(make_tuple(start_label,end_label,0));
        return answer;
    }

    //node list 
    unordered_set<string> VertexList = nodes();

    //vertex map
    map<string, Vertex> tempMap;

    //fill in the map
    for (auto v : VertexList){
        tempMap[v] = Vertex();
    }
    //set the start distance to 0
    tempMap[start_label].distance = 0;

    //define compare
    auto compare = [](tuple<string,int> &p1, tuple<string,int> &p2){
        return get<1>(p1) > get<1>(p2);
    };
    //initialize the priority queue
    priority_queue< tuple<string,int>, vector<tuple<string,int>>,
                             decltype(compare)> queue(compare);

    //push the start in
    queue.push(make_tuple(start_label,0));

    //while the queue is not empty
    while (queue.size()!=0){
        //store the current pair
        tuple<string,int> current = queue.top();
        queue.pop();
        //store the string 
        string label = get<0>(current);

        //if not visited
        if(tempMap[label].visited == false){

            //set visited to true
            tempMap[label].visited = true;

            //iterate through the neighbour list
            for(auto neighbour : neighbors(label)){

                //get the weight
                int weightNei = edge_weight(label,neighbour);

                //calculate the new weight
                int newWeight = weightNei + tempMap[label].distance;



                //if new weight is smaller
                if( newWeight < tempMap[neighbour].distance 
                            ||tempMap[neighbour].distance == -1 ){

                    //set the previous and distance
                    tempMap[neighbour].previous = label;
                    tempMap[neighbour].distance = newWeight;

                    //push the new pair in 
                    queue.push(make_tuple(neighbour,newWeight));
                }
            }
        }
    }
    //store the end label
    string tempString = end_label;

    //while is not the first
    while(tempMap[tempString].previous != ""){

        //insert the tuple
        answer.insert(answer.begin(), make_tuple(tempMap[tempString].previous,
             tempString, edge_weight(tempMap[tempString].previous,tempString)));

        //set the string 
        tempString = tempMap[tempString].previous;
    }
    //return the answer
    return answer;
}


/**
 * Return the smallest `threshold` such that, given a start node and an end
 * node, if we only considered all edges with weights <= `threshold`, there
 * would exist a path from the start node to the end node.
 *
 * @param start_label The label of the start node.
 * @param end_label The label of the end node.
 * @return The smallest `threshold` such that, if we only considered all
 * edges with weights <= `threshold, there would exist a path connecting the
 * nodes labeled by `start_label` and `end_label`,
 * or -1 if no such threshold exists.
 */
int Graph::smallest_connecting_threshold(string const &start_label, 
                                string const &end_label) {
    //if start is end
    if(start_label == end_label){
        //return 0
        return 0;
    }

    //start the new union
    Union u;

    //define compare
    auto compare = [](tuple<string,string,int>&t1, 
                    tuple<string,string,int>&t2){
        return get<2>(t1) > get<2>(t2);
    };

    //initialize the priority queue
    priority_queue<tuple<string,string,int>, 
                    vector<tuple<string,string,int>>,    
                        decltype(compare)> queue(compare);

    //fill in the queue
    for (auto e : adjList) {
        queue.push(e);
    }
    //while queue is not empty
    while (!queue.empty()) {

        //store the current element
        auto now = queue.top();
        queue.pop();
        //unite the two string
        u.UNION(get<0>(now), get<1>(now));

        //store the two string
        auto l = u.find(start_label);
        auto r = u.find(end_label);

        //return the shortest
        if (l == r) {
            return get<2>(now);
        }
    }
    //not found
    return -1;  
}