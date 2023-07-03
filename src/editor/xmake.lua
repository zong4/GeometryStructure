add_defines("EDITOR")

target("editor")
    add_deps("engine")

    set_kind("binary")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
