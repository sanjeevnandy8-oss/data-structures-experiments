# Data Structures Experiments in C

A collection of 10 lab experiments covering core Data Structures and Algorithms concepts, implemented in C. Each experiment is self-contained, compiles independently, and is structured for easy navigation and grading.

---

## Repository Structure

```
data-structures-experiments/
├── Makefile
├── .gitignore
├── README.md
└── experiments/
    ├── 1_functions_arrays/
    │   ├── 1_input_max_min.c
    │   ├── 2_insert_display.c
    │   └── 3_delete_display.c
    ├── 2_matrix_sparse/
    │   ├── 1_matrix_multiplication.c
    │   ├── 2_matrix_transpose.c
    │   └── 3_sparse_matrix.c
    ├── 3_pointers_dma/
    │   ├── 1_dynamic_max.c
    │   ├── 2_student_struct.c
    │   └── 3_products_dma.c
    ├── 4_stacks_queues/
    │   ├── 1_stack.c
    │   ├── 2_linear_queue.c
    │   └── 3_circular_queue.c
    ├── 5_searching_sorting/
    │   ├── 1_binary_search.c
    │   ├── 2_selection_sort.c
    │   └── 3_bubble_sort_string.c
    ├── 6_sorting_merging/
    │   ├── 1_merge_sorted_arrays.c
    │   ├── 2_insertion_sort.c
    │   └── 3_quick_sort.c
    ├── 7_singly_linked_list/
    │   ├── 1_linked_list_beginning.c
    │   ├── 2_linked_list_end.c
    │   └── 3_linked_list_location.c
    ├── 8_linked_stack_queue/
    │   ├── 1_linked_stack.c
    │   └── 2_linked_queue.c
    ├── 9_doubly_linked_list/
    │   ├── 1_doubly_beginning.c
    │   └── 2_doubly_end.c
    └── 10_advanced_linked_list/
        ├── 1_cricket_players.c
        └── 2_bank_accounts.c
```

---

## Experiments Overview

### Experiment 1 — Functions and Arrays
| File | Description |
|------|-------------|
| `1_input_max_min.c` | Input 10 numbers and find MAX and MIN using separate functions |
| `2_insert_display.c` | Insert an element at a given position in an array |
| `3_delete_display.c` | Delete an element from a given position in an array |

### Experiment 2 — Matrix and Sparse Matrix
| File | Description |
|------|-------------|
| `1_matrix_multiplication.c` | Multiply two 3×3 matrices |
| `2_matrix_transpose.c` | Compute and display the transpose of a 4×4 matrix |
| `3_sparse_matrix.c` | Check if a matrix is sparse and store non-zero elements |

### Experiment 3 — Pointers, Structures, and Dynamic Memory Allocation
| File | Description |
|------|-------------|
| `1_dynamic_max.c` | Dynamically allocate an array and find the largest element |
| `2_student_struct.c` | Store student records and display those with age ≥ 20 |
| `3_products_dma.c` | Dynamically allocate product records and filter by price range |

### Experiment 4 — Stack and Queue
| File | Description |
|------|-------------|
| `1_stack.c` | Array-based stack with push, pop, peek, and display |
| `2_linear_queue.c` | Array-based linear queue with enqueue, dequeue, and display |
| `3_circular_queue.c` | Circular queue implementation using a count-based approach |

### Experiment 5 — Searching and Sorting
| File | Description |
|------|-------------|
| `1_binary_search.c` | Binary search on a sorted integer array |
| `2_selection_sort.c` | Selection sort on an integer array |
| `3_bubble_sort_string.c` | Bubble sort applied to characters within a string |

### Experiment 6 — Sorting and Merging
| File | Description |
|------|-------------|
| `1_merge_sorted_arrays.c` | Merge two sorted arrays into a single sorted array |
| `2_insertion_sort.c` | Insertion sort on an integer array |
| `3_quick_sort.c` | Quick sort using the last element as pivot |

### Experiment 7 — Singly Linked List
| File | Description |
|------|-------------|
| `1_linked_list_beginning.c` | Insert and delete at the beginning of a singly linked list |
| `2_linked_list_end.c` | Insert and delete at the end of a singly linked list |
| `3_linked_list_location.c` | Insert at a specific position and search for a node |

### Experiment 8 — Linked Stack and Queue
| File | Description |
|------|-------------|
| `1_linked_stack.c` | Stack implemented using a singly linked list |
| `2_linked_queue.c` | Queue implemented using a singly linked list |

### Experiment 9 — Doubly Linked List
| File | Description |
|------|-------------|
| `1_doubly_beginning.c` | Insert/delete at beginning with forward and backward traversal |
| `2_doubly_end.c` | Insert/delete at end with forward and backward traversal |

### Experiment 10 — Advanced Programs Using Linked List
| File | Description |
|------|-------------|
| `1_cricket_players.c` | Store cricket player records and display those with batting average ≥ 50 |
| `2_bank_accounts.c` | Store bank account records and compute total balance using a linked list |

---

## Getting Started

### Prerequisites

- GCC compiler (`gcc`)
- Make utility (`make`)
- Linux / macOS / WSL on Windows

### Build All Programs

```bash
git clone https://github.com/yourusername/data-structures-experiments.git
cd data-structures-experiments
make
```

### Run a Specific Program

```bash
./experiments/1_functions_arrays/1_input_max_min
./experiments/4_stacks_queues/1_stack
./experiments/10_advanced_linked_list/2_bank_accounts
```

### Build a Single File Manually

```bash
gcc -Wall -std=c11 experiments/6_sorting_merging/3_quick_sort.c -o quick_sort
./quick_sort
```

### Clean Build Artifacts

```bash
make clean
```

---

## Sample Runs

**Binary Search**
```
Enter number of elements: 5
Element 1: 10
Element 2: 20
Element 3: 30
Element 4: 40
Element 5: 50

Enter element to search: 30
Element 30 found at position 3
```

**Stack Operations**
```
Stack Operations:
1. Push   2. Pop   3. Peek   4. Display   5. Exit

Enter choice: 1
Enter value to push: 42
Pushed 42 to stack

Enter choice: 4
Stack elements (top to bottom): 42
```

**Bank Accounts**
```
Enter number of account holders: 2

Account Holder 1:
Account number: 1001
Name: Rahul Sharma
Balance: 15000

Account Holder 2:
Account number: 1002
Name: Priya Nair
Balance: 22500

Account Details:
-----------------------------------
Account No: 1001
Name: Rahul Sharma
Balance: 15000.00
-----------------------------------
Account No: 1002
Name: Priya Nair
Balance: 22500.00
-----------------------------------
Total balance for all account holders: 37500.00
```

---

## Key Design Decisions

- **No global variables** — all state is passed through function parameters.
- **Proper memory management** — every `malloc` has a corresponding `free`.
- **Input validation** — boundary checks on positions, sizes, and empty containers.
- **Modular functions** — each operation (insert, delete, display) is a separate function with a single responsibility.
- **Standard C11** — compatible with GCC and Clang on any platform.

---

## License

This project is open source and available under the [MIT License](LICENSE).
