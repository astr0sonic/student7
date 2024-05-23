#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

struct node
{
    char info;
    int freq;
    node* left;
    node* right;
    node(char ch, int frequ, node* l = nullptr, node* r = nullptr) : info(ch), freq(frequ), left(l), right(r) {}
};

struct comp
{
    bool operator()(const node* l, const node* r) const
    {
        return l->freq > r->freq;
    }
};


void buildHuffmanCodes(node* root, string str, map<char, string>& huffman_code);
string encode(const std::string& text);
string decode(const std::string& encoded, std::map<char, std::string>& codes);