#pragma once
#include <memory>
#include <vector>

#ifndef FORWARD_DECLARE

#define FORWARD_DECLARE(nameofclass) class nameofclass; \
using nameofclass##UP = std::unique_ptr<nameofclass>; \
using nameofclass##SP = std::shared_ptr<nameofclass>; \
using nameofclass##UPC = std::unique_ptr<const nameofclass>; \
using nameofclass##SPC = std::shared_ptr<const nameofclass>; \
using Vec##nameofclass##UP = std::vector<nameofclass##UP>; \
using Vec##nameofclass##SP = std::vector<nameofclass##SP>; \
using Vec##nameofclass##UPC = std::vector<nameofclass##UPC>; \
using Vec##nameofclass##SPC = std::vector<nameofclass##SPC>; \
using Vec##nameofclass##UPIter = std::vector<nameofclass##UP>::iterator; \
using Vec##nameofclass##SPIter = std::vector<nameofclass##SP>::iterator; \
using Vec##nameofclass##UPCIter = std::vector<nameofclass##UPC>::iterator; \
using Vec##nameofclass##SPCIter = std::vector<nameofclass##SPC>::iterator; \
using Vec##nameofclass##UPIterC = std::vector<nameofclass##UP>::const_iterator; \
using Vec##nameofclass##SPIterC = std::vector<nameofclass##SP>::const_iterator; \
using Vec##nameofclass##UPCIterC = std::vector<nameofclass##UPC>::const_iterator; \
using Vec##nameofclass##SPCIterC = std::vector<nameofclass##SPC>::const_iterator; \

#endif
