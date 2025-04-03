# Compiler and tools
CXX = g++
PROTOC = protoc

# Directories
SRC_DIR = app
LIB_DIR = lib
BUILD_DIR = build

# Files
PROTO_FILE = $(LIB_DIR)/message.proto
PROTO_SRC = $(LIB_DIR)/message.pb.cc
PROTO_HDR = $(LIB_DIR)/message.pb.h
APP_SRC = $(SRC_DIR)/proto_example.cpp
APP_OBJ = $(BUILD_DIR)/proto_example.o
PROTO_OBJ = $(BUILD_DIR)/message.pb.o
TARGET = $(BUILD_DIR)/proto_example

# Flags
CXXFLAGS = -std=c++11 -I$(LIB_DIR)
LDFLAGS = -lprotobuf

# Targets
all: $(TARGET)

$(TARGET): $(APP_OBJ) $(PROTO_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(APP_OBJ): $(APP_SRC) $(PROTO_HDR)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROTO_OBJ): $(PROTO_SRC)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PROTO_SRC) $(PROTO_HDR): $(PROTO_FILE)
	$(PROTOC) --proto_path=$(LIB_DIR) --cpp_out=$(LIB_DIR) $<

clean:
	rm -rf $(BUILD_DIR) $(PROTO_SRC) $(PROTO_HDR)

.PHONY: all clean
