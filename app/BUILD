load("@rules_cc//cc:defs.bzl", "cc_binary","cc_library")



cc_binary(
    name="proto_example",
    srcs = glob(["*.cpp"]),
    deps=["//lib:cpp_message_proto","//lib:proto_utility"],
)