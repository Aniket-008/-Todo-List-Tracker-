# 📝 C To-Do List Manager (Doubly Linked List)

A lightweight, menu-driven command-line To-Do List application written in **C**. This mini-project demonstrates the practical implementation of a **Doubly Linked List** and dynamic memory management (`malloc` and `free`) to manage daily tasks efficiently.

---

## 🚀 Features

* **Add Tasks:** Dynamically allocate memory to store new tasks in real time.
* **Display All Tasks:** View all tasks in reverse-chronological order along with their current status (`Pending` or `Completed`).
* **Mark Tasks as Completed:** Update the status of one or multiple tasks by selecting their task numbers.
* **Filter Pending Tasks:** Quickly view only the tasks that are yet to be completed.
* **Delete Tasks:** Remove specific tasks from the list and immediately free the associated heap memory.
* **Safe Memory Cleanup:** Automatically traverses and frees all allocated nodes upon exiting the program to prevent memory leaks.

---

## 🛠️ Data Structure Used

The core of this application is a **Doubly Linked List**, allowing bidirectional traversal (`prev` and `next` pointers) for seamless insertion, display, and deletion.

```c
struct todo {
    struct todo *prev;  // Pointer to the previous task node
    int status;         // 0 = Pending, 1 = Completed
    char work[20];      // Task description
    struct todo *next;  // Pointer to the next task node
};
```

### Why a Doubly Linked List?
1. **Dynamic Sizing:** Unlike arrays, the task list grows and shrinks dynamically at runtime without a fixed task limit.
2. **Efficient Deletion:** Deleting a task from the middle or beginning of the list only requires updating neighboring `prev` and `next` pointers—no array shifting needed.
3. **Bidirectional Traversal:** Allows displaying the most recently added tasks first by traversing backward from the tail pointer (`ptr->prev`) while indexing tasks sequentially from the `head`.

---

## 💻 Getting Started

### Prerequisites
* A C compiler such as **GCC** (MinGW on Windows, or built-in GCC/Clang on Linux/macOS).

### Compilation & Execution

1. **Clone the repository (or save the code as `todo.c`):**
   ```bash
   git clone [https://github.com/your-username/c-todo-list.git](https://github.com/your-username/c-todo-list.git)
   cd c-todo-list
   ```

2. **Compile the program:**
   ```bash
   gcc todo.c -o todo
   ```

3. **Run the executable:**
   * **On Windows:**
     ```bash
     todo.exe
     ```
   * **On Linux / macOS:**
     ```bash
     ./todo
     ```

---

## 📸 Sample Console Output

```text
============= TO-DO LIST MENU ============
1. Add Task
2. Display Tasks
3. Mark Task as Completed
4. Task not completed
5. Delete Task
6. Exit
ENTER >>> 1
Enter The Task : Study Data Structures

============= TO-DO LIST MENU ============
1. Add Task
2. Display Tasks
3. Mark Task as Completed
4. Task not completed
5. Delete Task
6. Exit
ENTER >>> 2
1. Study Data Structures : Pending
```

---

## 🔮 Future Enhancements

* **Timestamps (`<time.h>`):** Automatically record and display the exact date and time each task is created.
* **File Handling (`FILE *`):** Save tasks to a local `.txt` or `.dat` file so the list persists after the program closes.
* **Android NDK Port:** Wrap the C doubly linked list logic with **JNI (Java Native Interface)** to power a native Android mobile app.

---

## 👨‍💻 Author

**Developed by Aniket Kumar**
