#pragma once

#include <vector>

#include "stlio.h"

class StlInMock : public stlio::StlIn
{
public:
    StlInMock()
    {
        InitialiseResult = true;
        InitialiseCalled = false;
        TriangleCount = 0;
        PushFacetResult = true;
        PushFacetCalled = false;
        FinaliseResult = true;
        FinaliseCalled = false;
    }

    virtual bool Initialise(const std::string& name, int count)
    {
        InitialiseCalled = true;
        return InitialiseResult;
    }

    virtual bool PushFacet(const stlio::Facet& facet)
    {
        Facets.push_back(facet);
        PushFacetCalled = true;
        return PushFacetResult;
    }

    virtual bool Finalise(const std::string& name)
    {
        FinaliseCalled = true;
        return FinaliseResult;
    }

public:
    bool InitialiseResult;
    bool InitialiseCalled;
    int TriangleCount;
    bool PushFacetResult;
    bool PushFacetCalled;
    bool FinaliseResult;
    bool FinaliseCalled;
    std::vector<stlio::Facet>   Facets;
};
