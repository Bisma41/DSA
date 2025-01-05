#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
struct Player {
    static int count;
    int playerNumber;
    int matches;
    float average;
    int totalRuns;
    int notOut;
    int highestScore;
    int fours;
    int sixes;

    Player() {
        playerNumber=count++;
        matches=rand()%200 + 1;
        average=float(rand()%55+5);
        totalRuns=matches*average;
        notOut=rand()%(matches/2+1);
        highestScore=rand()%150+average;
        fours=rand()%(totalRuns/4+1);
        sixes=rand()%((totalRuns-fours*4)/6+1);
    }
};

int Player::count = 1;

struct Node {
    int key;
    int index;
    Node* left;
    Node* right;
    int height;
};

// AVL Tree
class AVLTree {
public:
    Node* root;

    AVLTree(); root(nullptr) {}

    // Inserting node
    void insert(int key,int index) {
        Node* newNode = new Node{key, index,nullptr,nullptr,1};
        root=insertNode(root,newNode);
    }

    // Searching node
    int search(int key){
        return searchNode(root,key);
    }
private:
    // Inserting 
    Node* insertNode(Node* node,Node* newNode){
        if (!node) return newNode;

        if (newNode->key<node->key) {
            node->left=insertNode(node->left,newNode);
        } else if (newNode->key>node->key) {
            node->right=insertNode(node->right,newNode);
        } else {
            // agr key already exist krti ha then update index
            node->index=newNode->index;
        }

        // Updateing height and balance 
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);

        // if needed then balabce again

        if (balanceFactor > 1) {
            if (newNode->key < node->left->key) {
                return rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }

        if (balanceFactor < -1) {
            if (newNode->key > node->right->key) {
                return leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    // Search node recursively
    int searchNode(Node* node, int key) {
        if (!node) return -1;

        if (key < node->key) {
            return searchNode(node->left, key);
        } else if (key > node->key) {
            return searchNode(node->right, key);
        } else {
            return node->index;
        }
    }

    int getHeight(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }
    Node* leftRotate(Node* node) {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }

    Node* rightRotate(Node* node) {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        temp->height = 1 + max(getHeight(temp->left), getHeight(temp->right));
        return temp;
    }
};

int main() {
    srand(time(0)); 

    // 2
    vector<Player> players;
    for (int i=0; i<10000; ++i) {
        players.push_back(Player());
    }

    // 3
    AVLTree avlTrees[4];
    for (int i = 0; i < 10000; ++i) {
        avlTrees[0].insert(players[i].totalRuns,i);
        avlTrees[1].insert(players[i].average,i);
        avlTrees[2].insert(players[i].fours,i);
        avlTrees[3].insert(players[i].sixes,i);
    }
    
     // 4
  clock_t start = std::clock();
    for (int i = 0; i < 1000; ++i) {
        int query = rand() % 10000;
        for (auto& player : players) {
            if (player.totalRuns == query) {
                // Found matching record
                break;
            }
        }
        
    }
    clock_t end = std::clock();
    double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken to print numbers: " << duration << " milliseconds\n";
    auto end=chrono::high_resolution_clock::now();
    auto vectorTime=chrono::duration_cast<chrono::microseconds>(end - start).count();

    start=chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        int query = rand() % 10000;
        avlTrees[0].search(query);
    }
    end=chrono::high_resolution_clock::now();
    auto avlTime=chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout<<"Vector query time: " <<vectorTime<<" microseconds"<<endl;
    cout<<"AVL tree query time: "<<avlTime<<" microseconds"<<endl;

    return 0;
}
