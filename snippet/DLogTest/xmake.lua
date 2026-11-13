add_requires("dlog")

target("DLogTest")
    set_kind("binary")
    add_files("main.cpp")
    add_packages("dlog")
target_end()
