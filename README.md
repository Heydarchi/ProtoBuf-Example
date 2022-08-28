# ProtoBuf-Example
A simple example to show how to use protobuf in C++ with Bazel.

#### Prerequisites:

To build and run the example there're some prerequisites. So if you don't have them try to use the commands below to install them:

- Install Bazel

```
sudo apt-get install bazel
```
*If you have any problem for installing bazel, the link below will be helpful.*

[Installing Bazel on Ubuntu](https://bazel.build/install/ubuntu)




- Install ProtoBuf-Compiler

```
sudo apt-get install protobuf-compiler
```

#### How to build the example
Just run the command below inside the folder that you've cloned the example.

```
bazel build //app:proto_example
```


