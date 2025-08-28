cc_library(
	name = "src-library",
	srcs = glob(["src/*.cpp"]),
	hdrs = glob(["src/*.h"]),
)

cc_binary(
	name="text-editor",
	srcs=["main.cpp"],
	deps = [":src-library"],
)	
