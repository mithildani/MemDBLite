# MemDBLite: An In-Memory Key-Value Store


**MemDBLite** is a minimalistic yet powerful in-memory key-value database implemented in C++.

## Features

- **In-Memory Storage**
- **Simple Key-Value Store**
- **Approximate LRU Eviction (Clock algorithm)**
- **Command-Line Interface (CLI)**
## Commands

- `SET key value`: Store a string-string key-value pair in the database.
- `GET key`: Retrieve the value associated with the given string key.
- `DELETE key`: Remove the string key-value pair from the database.
- `EXIT`: Quit the database and terminate the program.

## Demo
<div align="center">
  <img src="https://raw.githubusercontent.com/mithildani/MemDBLite/main/demo.gif" alt="MemDBLite Demo" width="600">
</div>

## Future Milestones

- **Write-Ahead Logging (WAL)**: Implement write-ahead logging to ensure data durability and crash recovery.
- **Partial Persistence**: Periodically persist data to disk for improved resilience.
- **TCP/IP Interface**: Enable interaction with the database over a TCP/IP connection.
- **I/O Multiplexing**: Support multiple concurrent connections while maintaining a single-threaded event loop for the database.
- **Support for Multiple Data Types**: Extend to support various data types for keys and values, such as integers, floats, and binary data.

## Getting Started

### Prerequisites

- C++ compiler (supporting Cxx or later)
- `make` (for building the project)

### Building the Project
```sh
cd MemDBLite
make compile
```

### Running the Database
```sh
make run
```

## Contributing

Contributions to MemDBLite are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.
