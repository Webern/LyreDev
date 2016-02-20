#pragma once

#define PRIVATE_UNUSED_PARAMETER_STRINGIFY(argument) #argument

#define UNUSED_PARAMETER(arg) _Pragma(PRIVATE_UNUSED_PARAMETER_STRINGIFY(unused(arg)))
