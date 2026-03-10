#include "SearchEngine.h"
#include <iostream>
#include <fstream>

using namespace std;

void SearchEngine::loadDocuments(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    string line;

    while (getline(file, line)) {
        documents.push_back(line);
    }

    file.close();

    cout << "Documents loaded successfully.\n";
}

void SearchEngine::displayDocuments() const{
    cout << "\nDocuments in the system: \n";

    for (int i = 0; i < documents.size(); i++) {
        cout << "Doc" << i + 1 << ": " << documents[i] << endl;
    }
}

int SearchEngine::getDocumentCount() const{
    return documents.size();
}

void SearchEngine::buildIndex() {
    indexer.buildIndex(documents);
}

void SearchEngine::displayIndex() const 
{
    indexer.displayIndex();
}

void SearchEngine::searchQuery(const string& query) const {
    QueryEngine qe(indexer);

    set<int> results = qe.search(query);

    cout << "\nSearch Results:\n";

    if (results.empty())
    {
        cout << "No documents found.\n";
        return;
    }

    for (int id : results) {
        cout << "Doc " << id << ": "
             << documents[id-1] << endl;
    }
}