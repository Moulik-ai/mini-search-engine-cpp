#include <iostream>
#include "SearchEngine.h"
#include "Tokenizer.h"
#include "Indexer.h"

using namespace std;

int main() {

    SearchEngine engine;

    engine.loadDocuments("documents.txt");

    cout << "\nTotal Documents: "
        << engine.getDocumentCount()
        << endl;
    
    engine.displayDocuments();

    engine.buildIndex();
    engine.displayIndex();
    string query;

    while (true) {
        cout << "\nEnter search query (type exit to quit): ";
        getline(cin, query);

        if (query == "exit")
            break;

        engine.searchQuery(query);
    }

    return 0;
}