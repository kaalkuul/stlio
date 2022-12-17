#pragma once

#include <vector>

#include "stlio.h"

class StlOutMock : public stlio::StlOut
{
public:
    StlOutMock()
    {
        InitialiseResult = true;
        InitialiseCalled = false;
        GetFacetResult = true;
        GetFacetCalled = false;
    }

    virtual bool Initialise(std::string& name, int& count)
    {
        name = "foo";
        count = Facets.size();
        return InitialiseResult;
    }

    virtual bool GetFacet(int index, stlio::Facet& facet)
    {
        facet = Facets.at(index);
        GetFacetCalled = true;
        return GetFacetResult;
    }

public:
    bool InitialiseResult;
    bool InitialiseCalled;
    bool GetFacetResult;
    bool GetFacetCalled;
    std::vector<stlio::Facet>   Facets;
};
