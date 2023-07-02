add_defines("THIRD_PARTY")

-- debug
add_requires("gtest 1.12.1", {debug=true})

if is_plat("linux") then
    add_defines("mono")
end

target("third_party")

    -- debug
    add_packages("spdlog", "gtest", {public = true})



    if is_plat("linux") then
        add_packages("mono", {public = true})
    end
    
    set_kind("static")

    -- add_includedirs("src/", {public = true}) -- not necessary