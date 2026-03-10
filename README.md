# Mini Search Engine (C++)

A modular **mini search engine implemented in C++** that demonstrates the use of **Discrete Mathematics concepts such as Set Theory, Relations, and Hashing** in real-world systems.

This project implements the **core idea behind search engines** using an **Inverted Index** data structure to efficiently process search queries.

The goal of this project is to bridge the gap between **theoretical computer science concepts** and **practical system design**.

---

## Project Motivation

Search engines must quickly find relevant documents among thousands or millions of files.

Instead of scanning every document for each query, search engines build a special data structure called an **Inverted Index**, which maps:

```text
Example:
hello → {1,2}
world → {1,3}
ai → {3}
```

This allows queries to be answered using **fast set operations**.

---

## Discrete Mathematics Concepts Used

This project demonstrates the practical use of several discrete mathematics concepts:

### Set Theory

Each word corresponds to a **set of documents** containing it.

```text
Example:
hello → {1,2}
world → {1,3}

Query:
hello AND world

Mathematically:
{1,2} ∩ {1,3} = {1}
```

---

### Relations

The inverted index represents a relation:

```text
R ⊆ Words × Documents

Example pairs:
(hello,1)
(hello,2)
(world,1)
(world,3)
```

---

### Hashing

To allow fast lookup of words, the inverted index will use a **hash table**.

```cpp
unordered_map<string, set<int>>
```

This provides **O(1) average lookup time**.

---

## Current Implementation

### Phase 1 — Document Storage System

The first phase implements the **document storage layer** of the search engine.

**Features:**

- Document storage system
- Text tokenization and normalization
- Inverted index construction
- Boolean query engine
- Fast word lookup using hash tables
- Set-based query processing

**Example input file:**

```text
hello world
hello chatgpt
world of ai
search engines are fun
hello ai world
```

**Example output:**

```text
Doc 1: hello world
Doc 2: hello chatgpt
Doc 3: world of ai
Doc 4: search engines are fun
Doc 5: hello ai world
```

### Phase 2 — Tokenizer Engine

The tokenizer converts raw document text into normalized tokens (words) that can be indexed.

Steps performed:

- Convert text to lowercase
- Remove punctuation
- Split text into individual words

Example:

```text
Input:
Hello, WORLD!!! Search Engines.

Output tokens:
hello
world
search
engines
```

This preprocessing step ensures that different textual representations of the same word are treated uniformly during indexing.

---

### Phase 4 — Boolean Query Engine

The search engine now supports Boolean search queries, allowing users to retrieve documents using logical operations.

Supported query types:

**Single Word Search**

Returns all documents containing the given word.

Example:

```text
hello
```

Output:

```text
Doc 1: hello world
Doc 2: hello chatgpt
Doc 5: hello ai world
```

**AND Queries**

Finds documents that contain both words.

Mathematically this corresponds to set intersection.

```text
A ∩ B
```

Example:

```text
hello AND world
```

Index lookup:

```text
hello → {1,2,5}
world → {1,3,5}
```

Computation:

```text
{1,2,5} ∩ {1,3,5} = {1,5}
```

Result:

```text
Doc 1: hello world
Doc 5: hello ai world
```

**OR Queries**

Finds documents containing either word.

Mathematically this corresponds to set union.

```text
A ∪ B
```

Example:

```text
hello OR ai
```

Computation:

```text
{1,2,5} ∪ {3,5} = {1,2,3,5}
```

**Example Execution**

Enter search query:

```text
hello AND world
```

Output:

```text
Doc 1: hello world
Doc 5: hello ai world
```

---

## Project Structure

```text
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

## Complexity Analysis

Let:

N = number of documents

Document loading complexity:

Time Complexity:

O(N)

Space Complexity:

O(N)

---

## Future Phases

The project will be expanded in the following phases:

### Phase 3

Inverted index construction.

### Phase 4

Boolean query engine (`AND`, `OR`).

### Phase 5

Basic ranking using term frequency.

### Phase 6

Command-line search interface.

---

## Technologies Used

- **C++**
- Standard Template Library (STL)
- File I/O
- Hash Tables
- Set Data Structures

---

## Learning Goals

This project demonstrates:

- Data Structures in C++
- Hash Tables and Sets
- Information Retrieval Basics
- Discrete Mathematics in real systems
- Modular system design

---

## Author

**Moulik Choudhary**
Computer Science Engineering Student
Chandigarh University

GitHub:
https://github.com/Moulik-ai