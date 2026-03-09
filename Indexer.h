#ifndef INDEXER_H
#define INDEXER_H

#include <unordered_map>
#include <set>
#include <string>
#include <vector>

class Indexer{
    private:
        std::unordered_map<std::string, std::set<int>> invertedIndex;

    public:
    void buildIndex(const std::vector<std::string>& documents);

    void displayIndex() const;

    std::set<int> getDocuments(const std::string& word) const;

};
#endif