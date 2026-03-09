#include "Indexer.h"
#include "Tokenizer.h"
#include <iostream>

using namespace std;

void Indexer::buildIndex(const vector<string>& documents) {
    for (int docID = 0; docID < documents.size(); docID++) {
        vector<string> tokens = Tokenizer::tokenize(documents[docID]);

        for (const string& word : tokens) {
            invertedIndex[word].insert(docID + 1);
        }
    }
}

void Indexer::displayIndex() const {
    cout << "\nInverted Index:\n\n";

    for (const auto& pair : invertedIndex) {
        cout << pair.first << " -> { ";

        for (int doc : pair.second) {
            cout << doc << " ";
        }

        cout << "}\n";
    }
}

set<int> Indexer::getDocuments(const string& word) const {
    if (invertedIndex.find(word) != invertedIndex.end())
        return invertedIndex.at(word);

    return {};
}
