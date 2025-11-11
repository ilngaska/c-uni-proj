# 📘 C++ Educational and Laboratory Programs ( Faculty of Engineering and Technology,
**Uzhhorod National University (UzhNU)**
**Major:** Computer Engineering (123/F7))

This repository contains several **C++** programs created for educational purposes, covering basic algorithms, data processing, and programming exercises.
Each file demonstrates a different concept or algorithm.

---

## 🔐 1. `caesar_cipher_ofc.cpp`

### 📄 Description

Implements the **Caesar Cipher**, a classical symmetric encryption algorithm that shifts each letter in the text by a specified number of positions in the alphabet.

### ⚙️ Features

* Reads a text string from user input.
* Accepts a **key (shift value)** as an integer.
* Allows choosing between:

  * `e` — **encryption**
  * `d` — **decryption**
* Displays the resulting encoded or decoded text.

### ▶️ Example Output

```
Enter text: hello
Enter key (shift): 3
Choose mode (e for encryption, d for decryption): e
Result: khoor
```

---

## 🧮 2. `factorials_task_school.cpp`

### 📄 Description

Counts how many **prime factors** a given number has in its factorization.
If the number is prime, it returns `0`.

### ⚙️ Features

* Checks if a number is prime.
* Counts the number of factors if it’s composite.
* Outputs the count to the console.

### ▶️ Example Output

```
Input: 12
Output: 3
```

*(because 12 = 2 × 2 × 3)*

---

## 🔁 3. `lab_5_programming_1st_year.cpp`

### 📄 Description

Performs **matrix transposition** (swapping rows and columns).

### ⚙️ Features

* Input matrix size: 3×4
* Output matrix size: 4×3
* Displays the transposed matrix.

### ▶️ Example Output

```
1 5 9 
2 6 10 
3 7 11 
4 8 12
```

---

## 🔎 4. `search_lab.cpp`

### 📄 Description

Compares two substring search algorithms:

* **Naive Search**
* **KMP Algorithm (Knuth–Morris–Pratt)**

### ⚙️ Features

* Finds the position of the first occurrence of a pattern in a text.
* Measures execution time for both algorithms in milliseconds.
* Displays comparison results.

### ▶️ Example Output

```
Search results:
Naive search: position = 28, time = 0.013 ms
KMP search:   position = 28, time = 0.007 ms
```

---

## 🔍 5. `search_lab_1.cpp`

### 📄 Description

Compares the performance of **linear search** and **binary search** algorithms on a large dataset.

### ⚙️ Features

* Generates an array of 50,000 random integers.
* Performs linear search on the unsorted array.
* Sorts the array using **selection sort**.
* Performs binary search on the sorted array.
* Measures the execution time for both methods.

### ▶️ Example Output

```
Linear search completed in: 3.42 ms, index: -1
Binary search completed in: 0.01 ms, index: -1
```

---

## 🧰 Technologies Used

* **Language:** C++17
* **Compiler:** `g++`
* **Libraries:** `<iostream>`, `<ctime>`, `<string>`, `<cstdlib>`

---

## 🧪 Running the Programs

Compile and run using a terminal (Linux / Windows PowerShell):

```bash
g++ filename.cpp -o program
./program
```

Example:

```bash
g++ caesar_cipher_ofc.cpp -o cipher
./cipher
```
