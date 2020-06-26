#pragma once

#include "paTestData.hpp"

class ICompressor
{
public:
    virtual ~ICompressor() = default;
    virtual unsigned char *encode(paTestData) = 0;
};