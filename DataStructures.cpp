// Templates for C++ data structures

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
// OR
template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
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
struct UnionFind{
    vector<int> parents;
    
    UnionFind(n){
        for(int i = 0; i < n; i++) parents.push_back(i);
    }

    int find(int node){
        while(node != parents[node]) node = parents[node];
        return node;
    }

    // Return true if union happens
    bool unify(int a, int b){
        int aNode = find(a);
        int bNode = find(b);
        if(aNode == bNode) return false;
        parents[bNode] = aNode;
        return true;
    }

};

