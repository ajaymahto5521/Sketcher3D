// Geometry3D_dll.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Geometry3D_dll.h"


// This is an example of an exported variable
GEOMETRY3DDLL_API int nGeometry3Ddll=0;

// This is an example of an exported function.
GEOMETRY3DDLL_API int fnGeometry3Ddll(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CGeometry3Ddll::CGeometry3Ddll()
{
    return;
}
