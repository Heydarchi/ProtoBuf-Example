load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_proto_grpc//cpp:defs.bzl", "cpp_proto_library")


proto_library(
    name = "message_proto",
    srcs = ["message.proto"],
    deps = ["@com_google_protobuf//:any_proto"],
)

cpp_proto_library(
    name = "cpp_message_proto",
    protos = [":message_proto"],
    visibility=["//app:__pkg__"],
)