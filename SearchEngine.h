#ifndef SEARCH_ENGINE_H
#define SEARCH_ENGINE_H

#include <vector>
#include <string>

class SearchEngine {
    private:

        std::vector<std::string> documents;

    public:
        void loadDocuments(const std::string& filename);

        void displayDocuments() const;

        int getDocumentCount() const;
};
#endif