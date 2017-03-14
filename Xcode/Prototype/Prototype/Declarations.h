//  Copyright (c) by Matthew James Briggs. All rights reserved.

#pragma once

#define LYRE_FORWARD_DECLARE(lyre_class_name)                                                \
class lyre_class_name;                                                                       \
using lyre_class_name##Ptr = std::shared_ptr<lyre_class_name>;                               \
using lyre_class_name##WPtr = std::weak_ptr<lyre_class_name>;                                \
using lyre_class_name##UPtr = std::unique_ptr<lyre_class_name>;                              \
                                                                                             \
using lyre_class_name##PtrVec = std::vector<std::shared_ptr<lyre_class_name>>;               \
using lyre_class_name##UPtrVec = std::vector<std::unique_ptr<lyre_class_name>>;              \
using lyre_class_name##WPtrVec = std::vector<std::weak_ptr<lyre_class_name>>;                \
using lyre_class_name##s = std::vector<lyre_class_name>;                                     \
                                                                                             \
using Const##lyre_class_name##Ptr = std::shared_ptr<const lyre_class_name>;                  \
using Const##lyre_class_name##WPtr = std::weak_ptr<const lyre_class_name>;                   \
using Const##lyre_class_name##UPtr = std::unique_ptr<const lyre_class_name>;                 \
                                                                                             \
using Const##lyre_class_name##PtrVec = std::vector<std::shared_ptr<const lyre_class_name>>;  \
using Const##lyre_class_name##UPtrVec = std::vector<std::unique_ptr<const lyre_class_name>>; \
using Const##lyre_class_name##WPtrVec = std::vector<std::weak_ptr<const lyre_class_name>>;   \
using Const##lyre_class_name##s = std::vector<const lyre_class_name>;
