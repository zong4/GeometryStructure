add_defines("CORE")

add_requires("spdlog 1.11.0", {debug = true})

target("core")
    add_packages("spdlog", {public = true}) 

    set_pcxxheader("core/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
