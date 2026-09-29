add_requires("dlog")

target("LoggerTest")
    set_kind("binary")
    add_files("main.cpp")
    add_packages("dlog")
target_end()
