#include <fstream>
#include <catch2/catch_test_macros.hpp>
#include "utils.h"

void ReadStl(stlio::StlIn& stlin, const std::string& path)
{
    std::ifstream f(path);
    REQUIRE(f);

    std::string err;
    bool result = stlio::ReadStlFile(f, stlin, err);
    CAPTURE(err);
    REQUIRE(result);
}

void ReadDataStl(stlio::StlIn& stlin, const std::string& path)
{
    std::string fullPath = data_path(path);

    ReadStl(stlin, fullPath);
}

void WriteStl(stlio::StlOut& stlout, std::string& path, bool ascii)
{
    path = temporary_filename();

    std::ofstream f(path);
    REQUIRE(f);

    std::string err;
    bool result = ascii
        ? stlio::WriteAsciiStlFile(f, stlout, err)
        : stlio::WriteBinaryStlFile(f, stlout, err);

    CAPTURE(err);
    REQUIRE(result);
}
