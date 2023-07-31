#include <bits/stdc++.h>

using namespace std;



int getEventForestCount(int parent, vector <vector <int>>  child_list_map){
    
    
    bool is_forest_odd = true;
    int even_forest_count = 0;
    
    
    if(child_list_map[parent].empty()) return 0;
    
    for(int child : child_list_map[parent]){
        
        int child_even_forest_count = getEventForestCount(child,child_list_map);
        
        if (child_even_forest_count){
    
            even_forest_count += child_even_forest_count;
        }
        
        else {
            is_forest_odd = !is_forest_odd;
        }
    }
    
    if(!is_forest_odd) even_forest_count++;
    
    return even_forest_count;
}


int calculateMaxCuts(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
    
    vector < vector<int> > child_list_map;
    
    int even_forest_count = 0;
    
    if (t_nodes % 2 == 1){
        cout << "Odd number of nodes!" << endl;
    }   
    
    for(int i = 0 ; i<=t_nodes +1 ; i++){
        child_list_map.push_back({});
    }
    
    for ( int i =0 ; i<t_edges; i++ ){
        int child = t_from[i];
        int parent = t_to[i];
        
        child_list_map[parent].push_back(child);
    }
    
    return getEventForestCount(1, child_list_map);
}

int main()
{
    int t_nodes = 10;
    int t_edges = 9;
    vector < int> t_from = {2,3,4,5,6,7,8,9,10};
    vector <int> t_to = {1,2,3,4,5,6,7,8,9};
    
    cout << "Result : " << calculateMaxCuts( t_nodes, t_edges,  t_from,  t_to) << endl;
}

// TEST CASES 
//  int t_nodes = 10;
//     int t_edges = 9;
//     vector < int> t_from = {2,3,4,5,6,7,8,9,10};
//     vector <int> t_to = {1,1,3,2,1,2,6,8,8};


    // int t_nodes = 10;
    // int t_edges = 9;
    // vector < int> t_from = {2,3,4,5,6,7,8,9,10};
    // vector <int> t_to = {1,2,3,4,5,6,7,8,9};


    // int t_nodes = 10;
    // int t_edges = 9;
    // vector < int> t_from =   {2,3,4,5,6,7,8,9,10};
    // vector <int> t_to =      {1,1,1,1,1,1,1,1,1};

    
    // int t_nodes = 11;
    // int t_edges = 10;
    // vector < int> t_from =   {2,3,4,5,6,7,8,9,10,11};
    // vector <int> t_to =      {1,1,1,1,1,1,1,1,1,2};
