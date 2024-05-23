#include "huffman.h"

void buildHuffmanCodes(node* root, string str, map<char, string>& huffman_code)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        if (!str.empty())
        {
            huffman_code[root->info] = str;
        }
        else
        {
            huffman_code[root->info] = "1";
        }
    }
    buildHuffmanCodes(root->left, str + "0", huffman_code);
    buildHuffmanCodes(root->right, str + "1", huffman_code);
}

string encode(const std::string& text) {
    string encoded = "";
    priority_queue<node*, vector<node*>, comp> priorityQueue;
    map<char, int> mp;
    for (char c : text)
    {
        mp[c] += 1;
    }
    for (auto element : mp)
    {
        priorityQueue.push(new node{ element.first, element.second, NULL, NULL });
    }
    while (priorityQueue.size() != 1)
    {
        node* left = priorityQueue.top();
        priorityQueue.pop();
        node* right = priorityQueue.top();
        priorityQueue.pop();
        priorityQueue.push(new node{ '\0', left->freq + right->freq, left, right });
    }
    node* root = priorityQueue.top();
    map<char, string> huffman_code;
    buildHuffmanCodes(root, encoded, huffman_code);
    for (char symbol : text)
    {
        encoded += huffman_code[symbol];
    }
    return encoded;
}

string decode(const std::string& encoded, std::map<char, std::string>& codes) {
    string decoded = "";
    map<string, char> new_codes;
    for (auto element : codes)
    {
        new_codes[element.second] = element.first;
    }
    string tempString = "";
    for (char symbol : encoded)
    {
        tempString += symbol;
        if (new_codes.find(tempString) != new_codes.end())
        {
            decoded += new_codes[tempString];
            tempString.clear();
        }
    }
    return decoded;
}
