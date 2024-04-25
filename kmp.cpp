#include "kmp.h"

/*

 ..https://www.youtube.com/watch?v=S2I0covkyMc&ab_channel=selfedu

    my_template = образ ??
    text = текст, в котором ищем.

    Если не нашли - return -1????

    Префикс - символы, стоящие в начале образа.
    Суффикс - символы в конце образа


    в массиве Pi будем хранить суффиксы максимальной длины, так как это будет гарантировать нам, что мы не пропустим образец в тексте
*/

std::vector<int> getIndices(const std::string& pattern, const std::string& text) {
    std::vector<int> result;

    std::vector<int> pi = getPi(pattern);

    int patternLength = pattern.size();  
    int textLength = text.size();          

    int textIndex = 0;  
    int patternIndex = 0; 
    
    while (textIndex < textLength) {
        if (text[textIndex] == pattern[patternIndex]) { 
            textIndex++;  
            patternIndex++; 
            if (patternIndex == patternLength) { 
                result.push_back(textIndex - patternIndex); 
                patternIndex = pi[patternIndex - 1]; 
            }
        }
        else {
            if (patternIndex != 0) { 
                patternIndex = pi[patternIndex - 1]; 
            }
            else {
                textIndex++; 
            }
        }
    }

    return result;
}

std::vector<int> getPi(const std::string& text)
{
    std::vector<int>pi(text.size(), 0);
    std::fill(pi.begin(), pi.end(), 0);

    int index_i = 1, index_j = 0;
    
    while (index_i < text.size()) {
        if (text[index_i] == text[index_j]) {
            pi[index_i++] = index_j + 1;
            index_j++;
        }
        else {
            if (index_j == 0) {
                pi[index_i++] = 0;
            }
            else {
                index_j = pi[index_j - 1];
            }
        }
    }

    return pi;
}

