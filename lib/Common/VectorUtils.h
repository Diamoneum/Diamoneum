// Copyright (c) 2018-2020, The Qwertycoin Group.
// Copyright (c) 2020 The Diamoneum Group.
//
// This file is part of Diamoneum.
//
// Diamoneum is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Diamoneum is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Diamoneum.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace Common {

namespace VectorUtils {

template<typename T, class UnaryPredicate>
std::vector<T> filter(const std::vector<T> &original, UnaryPredicate pred)
{
    std::vector<T> filtered;

    std::copy_if(begin(original), end(original), std::back_inserter(filtered), pred);

    return filtered;
}

template<typename T2, typename T1, class UnaryOperation>
std::vector<T2> map(const std::vector<T1> &original, UnaryOperation mappingFunction)
{
    std::vector<T2> mapped;

    std::transform(begin(original), end(original), std::back_inserter(mapped), mappingFunction);

    return mapped;
}

template<typename T>
void append(std::vector<T> &appendedTo, const std::vector<T> &appended)
{
    appendedTo.insert(end(appendedTo), begin(appended), end(appended));
}

} // namespace VectorUtils

} // namespace Common
