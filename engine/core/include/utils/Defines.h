#pragma once

namespace rendering
{
#define SafeDelete(ptr) \
	if(ptr) \
	{\
		delete ptr; \
		ptr = nullptr;\
	}\
	ptr = nullptr;

#define SafeDeleteArray(ptr) \
	if(ptr) \
	{\
		delete[] ptr; \
		ptr = nullptr;\
	}\
	ptr = nullptr;

}