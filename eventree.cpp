#include <vector>
#include <iostream>

using namespace std;

pair<bool,int> getIsForestOddAndEvenForestCountPair(int parent_id, vector <vector <int>>&  child_list_map){

    int odd_forest_count = 0;
    int even_forest_count = 0;

    if(child_list_map[parent_id].empty()){
        return make_pair(true,0);
    }

    for(int child_id : child_list_map[parent_id]){
        pair<bool,int> childs_pair = getIsForestOddAndEvenForestCountPair(child_id, child_list_map);

        if( childs_pair.first == true ){
            odd_forest_count++;
        }
        even_forest_count += childs_pair.second;
    }

    //That means with parent node we have an even forest!
    if (odd_forest_count % 2 == 1 ){
        return make_pair(false,even_forest_count+1);
    }
    else {
        return make_pair(true,even_forest_count);
    }
}

void constructChildListMap(int  t_nodes, int t_edges, vector<int> const &t_from, vector<int> const &t_to , vector <vector <int> >& child_list_map){
    for(int i = 0 ; i<=t_nodes +1 ; i++){
        child_list_map.push_back({});
    }

    for ( int i =0 ; i<t_edges; i++ ){
        int child_id = t_from[i];
        int parent_id = t_to[i];
        child_list_map[parent_id].push_back(child_id);
    }
}


int calculateMaxCutsForEvenForests(int t_nodes, int t_edges, vector<int> const & t_from, vector<int> const & t_to) {

    vector < vector<int> > child_list_map;

    if (t_nodes % 2 == 1){
        cout << "Odd number of nodes!" << endl;
        exit(-1);
    }

    constructChildListMap(t_nodes,t_edges,t_from,t_to, child_list_map);

    return getIsForestOddAndEvenForestCountPair(1, child_list_map).second - 1; // As max cut count is even forest count minus 1, we reduce by 1.
}

int main()
{
    // TEST CASES
    {
        int t_nodes = 10;
        int t_edges = 9;
        vector < int> t_from = {2,3,4,5,6,7,8,9,10};
        vector <int> t_to = {1,1,3,2,1,2,6,8,8};
        cout <<  "Expected : 2 - Result : " << calculateMaxCutsForEvenForests( t_nodes, t_edges,  t_from,  t_to) << endl;
    }
    {
        int t_nodes = 10;
        int t_edges = 9;
        vector < int> t_from = {2,3,4,5,6,7,8,9,10};
        vector <int> t_to = {1,2,3,4,5,6,7,8,9};
        cout << "Expected 4 - Result : " << calculateMaxCutsForEvenForests( t_nodes, t_edges,  t_from,  t_to) << endl;
    }
    {
        int t_nodes = 10;
        int t_edges = 9;
        vector < int> t_from =   {2,3,4,5,6,7,8,9,10};
        vector <int> t_to =      {1,1,1,1,1,1,1,1,1};
        cout << "Expected 0 - Result : " << calculateMaxCutsForEvenForests( t_nodes, t_edges,  t_from,  t_to) << endl;
    }
}
