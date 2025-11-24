#include"Export.h"

// This class is exported from the dll
class GEOMETRY3DDLL_API CGeometry3Ddll {
public:
	CGeometry3Ddll(void);
	// TODO: add your methods here.
};

extern GEOMETRY3DDLL_API int nGeometry3Ddll;

GEOMETRY3DDLL_API int fnGeometry3Ddll(void);
