# MemDBLite: An In-Memory Key-Value Store


**MemDBLite** is a minimalistic yet powerful in-memory key-value database implemented in C++.

## ✨ Features

- **⚡ In-Memory Storage**: All data is stored in memory, ensuring blazing-fast access and retrieval times.
- **🔑 Simple Key-Value Interface**: Store and retrieve key-value pairs using a straightforward interface. The current version of MemDBLite supports string-string key-value pairs.
- **⏱️ Approximate LRU Eviction**: The database implements the Clock algorithm for approximate Least Recently Used (LRU) eviction to manage memory usage efficiently.
- **💻 Command-Line Interface (CLI)**: Interact with the database using a user-friendly command-line interface.

## 🚀 Commands

- `SET key value`: Store a string-string key-value pair in the database.
- `GET key`: Retrieve the value associated with the given string key.
- `DELETE key`: Remove the string key-value pair from the database.
- `EXIT`: Quit the database and terminate the program.

## 🎥 Demo
<!-- TODO: -->

## 🚀 Future Milestones

- **📝 Write-Ahead Logging (WAL)**: Implement write-ahead logging to ensure data durability and crash recovery.
- **💾 Partial Persistence**: Periodically persist data to disk for improved resilience.
- **🌐 TCP/IP Interface**: Enable interaction with the database over a TCP/IP connection.
- **🌐 I/O Multiplexing**: Support multiple concurrent connections while maintaining a single-threaded event loop for the database.
- **🧰 Support for Multiple Data Types**: Extend to support various data types for keys and values, such as integers, floats, and binary data.

## 🚀 Getting Started

### 📋 Prerequisites

- C++ compiler (supporting C++xx or later)
- `make` (for building the project)

### 🛠️ Building the Project

<!-- TODO: -->

### ▶️ Running the Database

<!-- TODO: -->

## 🤝 Contributing

Contributions to MemDBLite are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

<div align="center">
  Made with ❤️ by Mithil Dani
</div>