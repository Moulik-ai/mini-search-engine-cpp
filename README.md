# Mini Search Engine (C++)

A modular **mini search engine implemented in C++** that demonstrates the practical use of **Discrete Mathematics concepts such as Set Theory, Relations, and Hashing** in real-world systems.

This project implements the **core idea behind modern search engines** using an **Inverted Index** to efficiently process search queries.

The goal of this project is to bridge the gap between **theoretical computer science concepts** and **practical system design**.

---

# Project Motivation

Search engines must quickly retrieve relevant documents from very large collections of text.

A naive search approach scans **every document for every query**, which becomes inefficient as the dataset grows.

To solve this problem, search engines build a special data structure called an **Inverted Index**, which maps:

```
word → documents containing that word
```

Example:

```
hello → {1,2}
world → {1,3}
ai → {3}
```

Using this structure allows queries to be answered using **fast set operations instead of scanning all documents**.

---

# Discrete Mathematics Concepts Used

This project demonstrates how discrete mathematics concepts appear in real software systems.

## 1. Set Theory

Each word corresponds to a **set of documents** that contain it.

Example:

```
hello → {1,2}
world → {1,3}
```

Query:

```
hello AND world
```

Mathematically:

```
{1,2} ∩ {1,3} = {1}
```

This corresponds to **set intersection**.

Other operations include:

```
A ∪ B  (Union)
A ∩ B  (Intersection)
```

These operations power **Boolean search queries**.

---

## 2. Relations

The inverted index represents a mathematical relation:

```
R ⊆ Words × Documents
```

Example relation pairs:

```
(hello,1)
(hello,2)
(world,1)
(world,3)
(ai,3)
```

Each pair means **a word appears in a document**.

---

## 3. Hashing

To allow fast lookup of words, the inverted index uses a **hash table**:

```cpp
unordered_map<string, set<int>>
```

This allows:

```
Average Lookup Time → O(1)
```

Which makes searching extremely efficient.

---

# Current Implementation

The project is being developed in **incremental phases**, similar to how real software systems evolve.

---

# Phase 1 — Document Storage System

This phase implements the **document storage layer** of the search engine.

Features:

## Features

• Document storage system  
• Text tokenization and normalization  
• Inverted index construction  
• Boolean query processing (AND / OR)  
• Term frequency based ranking  
• Interactive command-line interface  
• Fast word lookup using hash tables  

Example input file:

```
hello world
hello chatgpt
world of ai
search engines are fun
hello ai world
```

Example output:

```
Doc 1: hello world
Doc 2: hello chatgpt
Doc 3: world of ai
Doc 4: search engines are fun
Doc 5: hello ai world
```

---

# Phase 2 — Tokenizer Engine

The tokenizer converts raw document text into **normalized tokens (words)** that can be indexed.

Steps performed:

* Convert text to lowercase
* Remove punctuation
* Split text into individual words

Example:

Input:

```
Hello, WORLD!!! Search Engines.
```

Output tokens:

```
hello
world
search
engines
```

This preprocessing step ensures that **different textual forms of a word are treated uniformly**.

---

# Phase 3 — Inverted Index Construction

This phase builds the **core data structure of the search engine**.

The inverted index maps each word to the set of documents containing it.

Example index:

```
hello → {1,2,5}
world → {1,3,5}
ai → {3,5}
chatgpt → {2}
search → {4}
engines → {4}
```

Data structure used:

```cpp
unordered_map<string, set<int>>
```

This allows the search engine to retrieve documents containing a word **without scanning every document**.

---

# Phase 4 — Boolean Query Engine

The search engine now supports **Boolean search queries**, allowing users to retrieve documents using logical operations.

Supported query types:

## Single Word Search

Returns all documents containing the given word.

Example:

```
hello
```

Output:

```
Doc 1: hello world
Doc 2: hello chatgpt
Doc 5: hello ai world
```

---

## AND Queries

Finds documents that contain **both words**.

Mathematically this corresponds to **set intersection**.

```
A ∩ B
```

Example:

```
hello AND world
```

Index lookup:

```
hello → {1,2,5}
world → {1,3,5}
```

Computation:

```
{1,2,5} ∩ {1,3,5} = {1,5}
```

Result:

```
Doc 1: hello world
Doc 5: hello ai world
```

---

## OR Queries

Finds documents containing **either word**.

Mathematically this corresponds to **set union**.

```
A ∪ B
```

Example:

```
hello OR ai
```

Computation:

```
{1,2,5} ∪ {3,5} = {1,2,3,5}
```

---

# Example Execution

```
Enter search query:
hello AND world
```

Output:

```
Doc 1: hello world
Doc 5: hello ai world
```

---

# Phase 6 — Interactive Command Line Interface

This phase introduces an interactive **Command Line Interface (CLI)** that allows users to interact with the search engine through a menu-driven system.

Instead of manually modifying code to test queries, users can now perform operations directly through the terminal.

The interface provides the following options:

Mini Search Engine

1. Show Documents
2. Show Inverted Index
3. Boolean Search
4. Ranked Search
5. Exit

Users can now:

• View all stored documents  
• Inspect the generated inverted index  
• Perform Boolean queries (`AND`, `OR`)  
• Run ranked searches based on **Term Frequency**  
• Exit the application safely  

---

## Example Execution

Mini Search Engine

1. Show Documents  
2. Show Inverted Index  
3. Boolean Search  
4. Ranked Search  
5. Exit  

Enter your choice:

Example Boolean query:

hello AND world

Output:

Doc 1: hello world  
Doc 5: hello ai world

Example ranked search:

hello

Output:

Doc 5 (score 2): hello ai world  
Doc 1 (score 1): hello world  
Doc 2 (score 1): hello chatgpt

---

## System Architecture

The complete search engine pipeline now looks like this:

Documents  
↓  
Tokenizer  
↓  
Indexer (Inverted Index)  
↓  
Query Engine  
↓  
Ranking System  
↓  
CLI Interface

# Project Structure

```
mini-search-engine-cpp
│
├── main.cpp
├── SearchEngine.cpp
├── SearchEngine.h
├── Tokenizer.cpp
├── Tokenizer.h
├── Indexer.cpp
├── Indexer.h
├── QueryEngine.cpp
├── QueryEngine.h
├── documents.txt
└── README.md
```

---

# Complexity Analysis

Let:

```
N = number of documents
W = total number of words
```

Document loading:

```
Time Complexity: O(N)
Space Complexity: O(N)
```

Index construction:

```
O(W log N)
```

Search query lookup:

```
O(1) average (hash lookup)
```

Set operations:

```
Intersection: O(k)
Union: O(k)
```

Where **k is the size of the document sets**.

---

# Technologies Used

* **C++**
* Standard Template Library (STL)
* File I/O
* Hash Tables (`unordered_map`)
* Sets (`std::set`)
* String Processing

---

# Learning Goals

This project demonstrates:

* Data Structures in C++
* Hash Tables and Sets
* Information Retrieval Basics
* Discrete Mathematics in real systems
* Modular system design
* Boolean search algorithms

---

# Future Phases

The project will be extended with additional features:


## Phase 7

Performance improvements and advanced query handling.

---

# Author

**Moulik Choudhary**
Computer Science Engineering Student
Chandigarh University

GitHub:
https://github.com/Moulik-ai
