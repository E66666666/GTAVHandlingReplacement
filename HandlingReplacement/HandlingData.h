#pragma once
#include <cstdint>

#include "atArray.h"

class CBaseSubHandlingData
{
public:
    virtual ~CBaseSubHandlingData() = default;
    virtual void* GetParser() = 0;
    virtual int GetUnk() = 0;
    virtual void ProcessOnLoad() = 0;
};

class CHandlingData {
public:
    uint32_t m_name;
    char m_pad[332]; // 1290, 1365, 1493, 1604
    atArray<CBaseSubHandlingData*> m_subHandlingData; // this thing is 16 bytes
    // ^ find offset using a variant of 48 85 C9 74 13 BA 04 00 00 00 E8 (and go to the call in there)
    char m_pad2[1000];

    virtual ~CHandlingData() = default;

    //inline uint32_t GetName()
    //{
    //    return m_name;
    //}

    inline atArray<CBaseSubHandlingData*>& GetSubHandlingData()
    {
        return m_subHandlingData;
    }
};
