add_defines("PLATFORM")

target("platform")
    add_deps("core")

    set_pcxxheader("platform/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
