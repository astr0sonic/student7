#include "lzw.h"

std::vector<int> compress(const std::string& text) {
    std::map<std::string, int> dict;
    std::string currrentStr = "";
    std::vector<int> compress;
    
    for (int i = 0; i < 256; i++)
    {
        dict[std::string(1, char(i))] = i;
    }
    
    for (char symbol : text)
    {
        std::string comb = currrentStr + symbol;
        if (dict.find(comb) != dict.end())
        {
            currrentStr = comb;
        }
        else
        {
            compress.push_back(dict[currrentStr]);
            dict[comb] = dict.size();
            currrentStr = std::string(1, symbol);
        }
    }
    
    if (!currrentStr.empty())
    {
        compress.push_back(dict[currrentStr]);
    }
    
    return compress;
}

std::string decompress(const std::vector<int>& compressed) {
    std::map<int, std::string> dict;
    std::string prev = dict[compressed[0]];
    std::string decompress = prev;

    for (int i = 0; i < 256; i++)
    {
        dict[i] = std::string(1, char(i));
    }

    for (int i = 0; i < compressed.size(); i++)
    {
        std::string currentStr;

        currentStr = (dict.find(compressed[i]) != dict.end()) ? dict[compressed[i]] : prev + prev[0];

        decompress += currentStr;
        dict[dict.size()] = prev + currentStr[0];
        prev = currentStr;
    }
    return decompress;
}