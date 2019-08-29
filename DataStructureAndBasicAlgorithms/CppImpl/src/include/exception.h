//
// Created by pengcheng.zhang on 2019/8/28.
//

#ifndef CPPIMPL_EXCEPTION_H
#define CPPIMPL_EXCEPTION_H

#include <exception>
namespace patrick{
    class OutofIndexException:std::exception{};
    class StorageOverflow:std::exception{};
    class NullContainer:std::exception{};
}
#endif //CPPIMPL_EXCEPTION_H
