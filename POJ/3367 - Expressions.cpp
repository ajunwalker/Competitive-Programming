#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Node{
    char value;
    Node *left;
    Node *right;
};

int main(){

    int count;
    scanf("%d", &count);
    Node node_memory[10000];

    for (int j = 0; j < count; ++j){
        string str;
        cin >> str;
        stack<Node*> stack;

        for (int i = 0, k = 0; i < str.length(); ++i, ++k){
            if (islower(str[i])){
                Node *head = &node_memory[k];
                head->value = str[i];
                head->left = NULL;
                head->right = NULL;
                stack.push(head);
            }
            else {
                Node *head = &node_memory[k];
                head->value = str[i];
                head->right = stack.top();
                stack.pop();
                head->left = stack.top();
                stack.pop();
                stack.push(head);
            }
        }

        queue<Node*> queue;
        queue.push(stack.top());
        stack.pop();

        while (!queue.empty()){
            Node *curr = queue.front();
            queue.pop();
            if (curr->left){
                queue.push(curr->left);
            }
            if (curr->right){
                queue.push(curr->right);
            }
            stack.push(curr);
        }
        while(!stack.empty()){
            cout << stack.top()->value;
            stack.pop();
        }
        cout << endl;
    }

    return 0;
}
