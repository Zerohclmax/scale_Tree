#include <iostream>
#include <sstream>

using namespace std;

struct Node {
    int wl, wr, dl, dr;
    Node *l = NULL, *r = NULL;
};
string s;
int T;

bool readInput(int &wl, int &dl, int &wr, int &dr) { // 读取输入
    if (getline(cin, s) && !s.empty()) {
        stringstream input(s);
        input >> wl >> dl >> wr >> dr;
        return true; // 成功
    } else return false; // 失败
}

Node* createtree() {//！！！！！！！！！！！！递归输入（输入函数中没有规定停止输入）
    Node *root = new Node;
    int wl, wr, dl, dr;
    if (readInput(wl, dl, wr, dr)) {
//        root = new Node;
        root->dr = dr;
        root->dl = dl;
        root->wl = wl;
        root->wr = wr;
        if (wl == 0)(root->l = createtree());
        if (wr == 0)(root->r=createtree());
    }
    return root;
}
int Dfs(Node* root){//求和(返回-1说明不成立)
    if(root==NULL){return -1;}
    if(root->l != NULL){root->wl= Dfs(root->l);}
    if(root->r != NULL){root->wr=Dfs(root->r);}
    if(root->wr==-1||root->wl==-1){return -1;}
    if(root->dl*root->wl==root->dr*root->wr){
        return root->wl+root->wr;
    }
    else{
        return -1;
    }

}

int main() {
    scanf("%d  ", &T); // 两个空格可吸收换行
    for (int i = 0; i < T; i ++) {
        Node* bt = createtree();
        printf("%s%s\n", Dfs(bt) != -1 ? "YES" : "NO", i != T-1 ? "\n" : "");
        if (i != T-1) getchar(); // 空行吸收
    }
    return 0;
}

