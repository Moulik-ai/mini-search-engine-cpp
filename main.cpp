#include <iostream>
#include "SearchEngine.h"
#include "Tokenizer.h"
#include "Indexer.h"

using namespace std;

int main() {

    SearchEngine engine;

    engine.loadDocuments("documents.txt");
    engine.buildIndex();

    int choice;
    string query;

    while (true)
    {
        cout << "\nMini Search Engine\n";
        cout << "--------------------\n";
        cout << "1. Show Documents\n";
        cout << "2. Show Inverted Index\n";
        cout << "3. Boolean Search\n";
        cout << "4. Ranked Search\n";
        cout << "5.Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            engine.displayDocuments();
        }
        else if (choice == 2) {
            engine.displayIndex();
        }
        else if (choice == 3) {
            cout << "Enter query : ";
            getline(cin, query);
            
            engine.searchQuery(query);
        }
        else if (choice == 4) {
            cout << "Enter word for ranked search: ";
            getline(cin, query);

            engine.rankedSearch(query);
        }
        else if (choice == 5) {
            cout << "\nExiting search engine....\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}