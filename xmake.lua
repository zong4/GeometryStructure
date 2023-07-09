-- define project
set_project("Engine")
set_xmakever("2.7.0")
set_version("1.0.0", {build = "%Y%m%d%H%M"})

-- set common flags
-- set_warnings("all", "error")
set_languages("c++20")
add_mxflags("-Wno-error=deprecated-declarations", "-fno-strict-aliasing", "-Wno-error=expansion-to-defined")

-- add build modes
add_rules("mode.release", "mode.debug")

set_runtimes("MT")

-- includes sub-projects
includes("src/engine")

-- choose test or not
isTest = false; 

-- choose no linux
isNoLinux = true;

if isTest then
    add_defines("TEST")
    add_defines("DEBUG")
    includes("src/test")
else 
    includes("src/editor")

    -- add macro
    if is_mode("debug") then
        add_defines("DEBUG")
    elseif is_mode("release") then
        add_defines("RELEASE")
    end

    -- add macro
    if isNoLinux then 
        add_defines("WINDOWS")
    else
        if is_plat("windows") then
            add_defines("WINDOWS")
            add_ldflags("-subsystem:windows")
        elseif is_plat("linux") then
            add_defines("LINUX")
        end
    end
end

-- library rule
rule("BuildLibrary")
    on_load(function (target)
        if is_mode("debug") then
            target:set("kind", "shared")
            if is_plat("windows") then
                import("core.project.rule")
                local rule = rule.rule("utils.symbols.export_all")
                target:rule_add(rule)
                target:extraconf_set("rules", "utils.symbols.export_all", {export_classes = true})
            end
        elseif is_mode("release") then
            target:set("kind", "static")
        else
            assert(false, "Unknown build kind")
        end
    end)
rule_end()
