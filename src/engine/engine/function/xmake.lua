add_defines("FUNCTION")

target("function")
    add_deps("core", "platform")

    set_pcxxheader("function/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
