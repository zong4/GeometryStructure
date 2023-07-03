add_defines("ENGINE")

-- includes sub-projects
includes("engine/core",
         "engine/platform",
         "engine/function"
         )

target("engine")
    add_deps("core", "platform", "function")

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")

    add_headerfiles("./engine/engine.h")
    add_includedirs(".", {public = true}) 
