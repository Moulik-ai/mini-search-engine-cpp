# Mini Search Engine (C++)

A modular **mini search engine implemented in C++** that demonstrates the use of **Discrete Mathematics concepts such as Set Theory, Relations, and Hashing** in real-world systems.

This project implements the **core idea behind search engines** using an **Inverted Index** data structure to efficiently process search queries.

The goal of this project is to bridge the gap between **theoretical computer science concepts** and **practical system design**.

---

## Project Motivation

Search engines must quickly find relevant documents among thousands or millions of files.

Instead of scanning every document for each query, search engines build a special data structure called an **Inverted Index**, which maps:

```
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

```
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

```
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

- Load documents from a text file
- Assign unique **document IDs**
- Store documents in memory
- Display stored documents

**Example input file:**
```
hello world
hello chatgpt
world of ai
search engines are fun
hello ai world
```

**Example output:**
```
Doc 1: hello world
Doc 2: hello chatgpt
Doc 3: world of ai
Doc 4: search engines are fun
Doc 5: hello ai world
```


---

# Project Structure
mini-search-engine-cpp
│
├── main.cpp
├── SearchEngine.cpp
├── SearchEngine.h
├── documents.txt
└── README.md

---

# Complexity Analysis

Let:
N = number of documents

Document loading complexity:

Time Complexity:

O(N) 

Space Complexity:
O(N)

---

# Future Phases

The project will be expanded in the following phases:

### Phase 2
Tokenizer for text normalization.

### Phase 3
Inverted index construction.

### Phase 4
Boolean query engine (`AND`, `OR`).

### Phase 5
Basic ranking using term frequency.

### Phase 6
Command-line search interface.

---

# Technologies Used

- **C++**
- Standard Template Library (STL)
- File I/O
- Hash Tables
- Set Data Structures

---

# Learning Goals

This project demonstrates:

- Data Structures in C++
- Hash Tables and Sets
- Information Retrieval Basics
- Discrete Mathematics in real systems
- Modular system design

---

# Author

**Moulik Choudhary**  
Computer Science Engineering Student  
Chandigarh University

GitHub:  
https://github.com/Moulik-ai