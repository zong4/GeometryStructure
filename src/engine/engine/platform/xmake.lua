add_defines("PLATFORM")

-- vulkun
add_requires("vulkansdk")

-- opengl
add_requires("opengl", "glad")

-- linux
add_requires("glm", "glfw")

-- common
add_requires("imgui docking", "imguizmo")

target("platform")
    add_deps("core")

    -- vulkun
    add_packages("vulkansdk")

    -- opengl
    add_packages("opengl", "glad")

    -- linux
    add_packages("glm", "glfw")

    -- common
    add_packages("imgui", "imguizmo")

    set_pcxxheader("platform/pch.h")
    add_files("./**/*.cpp")
    add_headerfiles("./**/*.h")
    add_includedirs(".", {public = true}) 

    set_kind("static")
    -- add_rules("BuildLibrary")
    -- set_kind("$(kind)")
