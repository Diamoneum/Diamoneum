// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018-2020, The Qwertycoin Group.
//
// This file is part of Qwertycoin.
//
// Qwertycoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Qwertycoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Qwertycoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <CryptoNoteCore/CryptoNoteBasic.h>
#include <CryptoNoteCore/Difficulty.h>

namespace CryptoNote {

struct IMinerHandler
{
    virtual bool handle_block_found(Block &b) = 0;
    virtual bool get_block_template(
        Block &b,
        const AccountPublicAddress &adr,
        difficulty_type &diffic,
        uint32_t &height,
        const BinaryArray &ex_nonce) = 0;

    enum stat_period
    {
        hour,
        day,
        week,
        month,
        halfyear,
        year
    };

    virtual bool get_difficulty_stat(
            uint32_t height,
            stat_period period,
            uint32_t &block_num,
            uint64_t &avg_solve_time,
            uint64_t &stddev_solve_time,
            uint32_t &outliers_num,
            difficulty_type &avg_diff,
            difficulty_type &min_diff,
            difficulty_type &max_diff) = 0;

protected:
    ~IMinerHandler() = default;
};

} // namespace CryptoNote
