add_defines("CORE")

target("core")
    add_deps("third_party")

    set_pcxxheader("core/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
