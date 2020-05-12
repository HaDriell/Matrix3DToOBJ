workspace "3DMatrixToOBJ"
    configurations { "debug", "release" }

    warnings "Default"

    filter { "configurations:debug" }
        symbols "On"
    filter {}

    filter { "configurations:release" }
        optimize "On"
    filter {}

    -- MatrixToOBJ Project
    project "MatrixToOBJ"
        location "%{prj.name}"
        language "C++"
        architecture "x64"
        kind "ConsoleApp"
        cppdialect "gnu++17"
        files {
            "%{prj.name}/src/**"
        }
        includedirs {
            "D:/msys64/mingw64/include"
        }
        libdirs {
            "D:/msys64/mingw64/lib"
        }
        links {
        }