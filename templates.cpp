// Templates for C++ data structures & algorithms

#include <bits/stdc++.h>;

using namespace std;



// merge sort: divide and conquer
// O(nlogn) time, O(n) space
// divide array into two halves, sort each half, then merge
// divide: O(logn) time, O(logn) space
// merge: O(n) time, O(n) space
// total: O(nlogn) time, O(n) space
void mergeSort(vector<int> &nums, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

// merge sort helper function
// O(n) time, O(n) space
// merges two sorted arrays
// left array: nums[left, mid]
// right array: nums[mid + 1, right]
// merges into nums[left, right] 
void merge(vector<int> &nums, int left, int mid, int right){
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right){
        if(nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while(i <= mid)
        temp[k++] = nums[i++];
    while(j <= right)
        temp[k++] = nums[j++];
    for(int p = 0; p < temp.size(); p++)
        nums[left + p] = temp[p];
}


// quick sort: divide and conquer
// O(nlogn) time, O(logn) space
// divide array into two halves, sort each half
// divide: O(logn) time, O(logn) space
// sort: O(n) time, O(1) space
// total: O(nlogn) time, O(logn) space
// worst case: O(n^2) time, O(logn) space
// worst case: array is already sorted
// best case: O(nlogn) time, O(logn) space
// best case: array is sorted in reverse order
// average case: O(nlogn) time, O(logn) space
// average case: array is randomly ordered
// quick sort is faster than merge sort
// quick sort is in-place

// quick sort
void quickSort(vector<int> &nums, int left, int right){
    if(left >= right) return;
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}
// partition
// O(n) time, O(1) space
// partitions array into two halves
// left array: nums[left, pivot - 1]
// right array: nums[pivot + 1, right]
// returns pivot index
int partition(vector<int> &nums, int left, int right){
    int pivot = nums[right];
    int i = left;
    for(int j = left; j < right; j++){
        if(nums[j] < pivot)
            swap(nums[i++], nums[j]);
    }
    swap(nums[i], nums[right]);
    return i;
}



// Linked List
template <typename> t
struct ListNode{
    T data;
    shared_ptr<ListNode<T>> next;
} 

// Binary Tree
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val){
        this.val = val;
        left = NULL;
        right = NULL;
    }
}
// Binary Tree vers 2
template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
}

// Trie
class TrieNode{
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            for(int i = 0; i < 26; i++)
                children[i] = NULL;
            isWord = false;
        }
}

// Trie insert
void insert(string word){
    TrieNode *curr = root;
    for(char c : word){
        if(curr->children[c - 'a'] == NULL)
            curr->children[c - 'a'] = new TrieNode();
        curr = curr->children[c - 'a'];
    }
    curr->isWord = true;
}

// Trie search
bool search(string word){
    TrieNode *curr = root;
    for(char c : word){
        if(curr->children[c - 'a'] == NULL)
            return false;
        curr = curr->children[c - 'a'];
    }
    return curr->isWord;
}

// Trie delete
void delete(string word){
    TrieNode *curr = root;
    for(char c : word){
        if(curr->children[c - 'a'] == NULL)
            return;
        curr = curr->children[c - 'a'];
    }
    curr->isWord = false;
}

// Trie starts with
bool startsWith(string prefix){
    TrieNode *curr = root;
    for(char c : prefix){
        if(curr->children[c - 'a'] == NULL)
            return false;
        curr = curr->children[c - 'a'];
    }
    return true;
}



// Stack
class Stack{
    public:
        bool Empty() const{

        }
        int Max() const {

        }
        int Top() const{

        }
        int Pop(){

        }
        void Push(int x){

        }
    private:
        struct data{int element, max};
        stack<data> stk;
}


// Queue
class Queue{
    public:
        void Enqueue(int x){

        }
        int Dequeue(){

        }
    private: 
    stack
}


// BFS, finds target node and returns # of steps
int BFS(Node *root, Node *target){
    queue<Node> que;
    int step = 0;
    que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            Node curr = que.top();
            if(curr.val == target.val)
                return step;
            for(Node next : curr neighbors)
                que.push(next);
            que.pop();
        }
        step++;
    }
    return -1;
}

// BFS that skips over visited nodes
// Finds target nodes and returns num of steps
int BFS(Node root, Node target){
    queue<Node> que;
    unordered_set<Node> visited;
    int step = 0;
    
    que.push(root);
    visited.insert(root);
    while(!que.empty()){
        int size = que.size();
        for(int i = 0; i < size; i++){
            Node curr = que.top();
            if(curr.val == target.val)
                return step;
            for(Node next : curr neighbors){
                if(visited.count(next) != 0){
                    visited.insert(next);
                    que.push(next);
                }
            }
            que.pop()
        }
        step++;
    }
    return -1;
}



// Union Find
// naive implementation 0(N)
struct UnionFind{
    vector<int> parents;
    
    UnionFind(n){
        for(int i = 0; i < n; i++) 
            parents.push_back(i);
    }

    int find(int node){
        while(node != parents[node]) 
            node = parents[node];
        return node;
    }

    // Return true if union happens
    bool union(int a, int b){
        int aNode = find(a);
        int bNode = find(b);
        if(aNode == bNode) return false;
        parents[bNode] = aNode;
        return true;
    }

};


// backtracking template
void backtrack(vector<vector<int>> &res, vector<int> &temp, int start, int n){
    res.push_back(temp);
    for(int i = start; i < n; i++){
        temp.push_back(i);
        backtrack(res, temp, i + 1, n);
        temp.pop_back();
    }
}


// Sliding window problems: substrings
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }

// Split by space function
vector<string> split(string sentence) {
    int left = 0, right = 0;
    vector<string> words;
    while(right < sentence.size()) {
        if(sentence[right] == ' ') {
            words.push_back(sentence.substr(left, right-left));
            left = right + 1;
        }
        right++;
    }
    words.push_back(sentence.substr(left, right-left));
    return words;
}

// Split by delimeter
vector<string> split(const string &s, char delim) { 
    stringstream ss(s); 
    string item; 
    vector<string> tokens; 
    while (getline(ss, item, delim)) { 
        tokens.push_back(item); 
    } 
    return tokens; 
} 


// binary search

left = 0, right = n-1
while left <= right {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) 
        return mid;
    else if (nums[mid] < target) 
        left = mid + 1;
    else 
        right = mid - 1;
}

left = 0, right = n
while left < right {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) 
        return mid;
    else if (nums[mid] < target) 
        left = mid + 1;
    else 
        right = mid;
}



// Topological sort
// Kahn's algorithm
// Idea: find nodes with no incoming edges and remove them
// have a list of 0 indegree nodes. Add to queue
// Pop from queue and check each neighbor subtract indegrees. If indegree is 0, add to queue

// 1. Create a graph G(V, E)
// 2. Create a list L that will contain the sorted elements
// 3. Set S to a set of all nodes with no incoming edges
// 4. while S is non-empty do
//      remove a node n from S
//      add n to tail of L
//      for each node m with an edge e from n to m do
//          remove edge e from the graph
//          if m has no other incoming edges then
//              insert m into S
// 5. if graph has edges then
//      return error (graph has at least one cycle)
// 6. else
//      return L (a topologically sorted order)


// Dijkstra's algorithm
// Idea: find the shortest path from a source node to all other nodes
// 1. Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree
// 2. Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex so that it is picked first.
// 3. While sptSet doesn't include all vertices
//      a. Pick a vertex u which is not there in sptSet and has minimum distance value.
//      b. Include u to sptSet.
//      c. Update distance value of all adjacent vertices of u. To update the distance values, iterate through all adjacent vertices. For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, then update the distance value of v.


// Bellman-Ford algorithm
// Idea: find the shortest path from a source node to all other nodes
// 1. This step initializes distances from source to all vertices as infinite and distance to source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.
// 2. This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
//      a) Do following for each edge u-v
//          If dist[v] > dist[u] + weight of edge uv, then update dist[v]
//              dist[v] = dist[u] + weight of edge uv
// 3. This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
//      If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
// The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle



