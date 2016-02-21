// PUBLIC
#pragma once
#include "Lyre/LyreApiExport.h"
#include "Lyre/TypeDefs.h"
#include "Lyre/ForwardDeclare.h"
#include "Lyre/IStreameable.h"
#include "Lyre/unusedParameter.h"

// seriously, microsoft?
#ifdef _MSC_VER
    #define noexcept
	#if _MSC_VER >= 1900
		#undef noexcept
	#endif
#endif
