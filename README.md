# ProtoBuf-Example

A simple example demonstrating how to use Protocol Buffers (protobuf) in C++ using a Makefile.



## Prerequisites

Before building and running the example, make sure the following tools are installed:

### Install Protobuf Compiler

```bash
sudo apt-get install protobuf-compiler libprotobuf-dev
```

For macOS:

```bash
brew install protobuf
```

### Install a C++ Compiler

Make sure `g++` is available. On Ubuntu/Debian:

```bash
sudo apt-get install build-essential
```



## Build the Example

Clone this repo and run:

```bash
make
```

This will:
- Compile the `.proto` file (`lib/message.proto`)
- Build the main application (`app/proto_example.cpp`)
- Output the binary to: `build/proto_example`



## ▶Run the Example

```bash
./build/proto_example
```



## Clean Build Artifacts

To remove all generated files:

```bash
make clean
```



## 📁 Project Structure

```
ProtoBuf-Example/
├── app/
│   └── proto_example.cpp        # Main C++ application
├── lib/
│   ├── message.proto            # Protobuf definition
│   └── proto_utility.h          # Helper functions
├── Makefile                     # Replaces Bazel
└── README.md
```
