#include <iostream>
#include "SearchEngine.h"
#include "Tokenizer.h"

using namespace std;

int main() {

    SearchEngine engine;

    engine.loadDocuments("documents.txt");

    cout << "\nTotal Documents: "
        << engine.getDocumentCount()
        << endl;
    
    engine.displayDocuments();

    cout << "\nTesting Tokenizer\n";

    vector<string> tokens = Tokenizer::tokenize("Hello, World!!! Search Engines.");

    for (string t : tokens) {
        cout << t << endl;
    }

    return 0;
}