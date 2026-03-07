#include <iostream>
#include "SearchEngine.h"

using namespace std;

int main() {

    SearchEngine engine;

    engine.loadDocuments("documents.txt");

    cout << "\nTotal Documents: "
        << engine.getDocumentCount()
        << endl;
    
    engine.displayDocuments();

    return 0;
}