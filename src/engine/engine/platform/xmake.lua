add_defines("PLATFORM")

-- vulkun
add_requires("vulkansdk")

-- opengl
add_requires("opengl", "glad")

-- linux
add_requires("glm", "glfw")

add_requires("imgui docking", "imguizmo", "stb")

add_requires("shaderc","spirv-cross", {configs = {vs_runtime = "MT"}})

target("platform")
    add_deps("core")

    -- vulkun
    add_packages("vulkansdk")

    -- opengl
    add_packages("opengl")

    -- linux
    add_packages("glm", "glfw", "glad", "shaderc", "spirv-cross", {public = true}) 

    add_packages("imgui", "imguizmo", "stb", {public = true}) 

    set_pcxxheader("platform/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
