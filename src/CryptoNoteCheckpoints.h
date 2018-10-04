// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2018, The TurtleCoin Developers, The Qwertycoin Developers
//
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

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {  
	{  5000,"f44ad7e79c4dc4b8cce6100460444f8fc61096a6cf4d9a53107abde0b8750b4f"},
	{  8473,"e131c96f6105604ea3f7dd2b55d73d430b28bed133112c9992a38c26b5239e14"},
	{ 10000,"fb021fd69f78a60a365c16692777e7f699215404366545e072eba7dddbf1d61d"},
	{ 20000,"d32286163e2a5cfbbab35007438e7bf90564afee70c715930606710e96f2ce19"},
	{ 30000,"1d32bbca2149eeb27ff9e2c19d1b6ace4a160764839a4da7031328f7ea49e6f6"},
	{ 40000,"60a9694b18cf470bcfd9f36f32ad01f86b5538fe1f88a3bd2717ca6ad1c7ce80"},//2.0
	{ 40001,"17132deac10a3661f56eb4b19dbaea77cbf2ef8a131f78df04c7df023b687158"},
	{ 46000,"51e2f9e09278cb66b08efcecfdf3208053ee53030c6fc5a6a647565a6b318cd5"},//3.0
	{ 46001,"15853b6a46d3fcf1554935dadc8988a0de95b0a9e711cfb845d6fe3fde5aa98a"},
	{ 50000,"5599ca3d8ac58f377187b5a43c00103496244ec95299e4ae3dff3be6016488bf"},
	{ 60000,"796e0037bed22ec317dc165bdfcc331322fe3fcc7ca162827ab374a7d17107f0"},
	{ 70000,"9b035668d72b17ceaabbd4b341089f090aa5ebad37f33513509d9f6e102c7c0c"},
	{ 80000,"02bdbd6cab951c0685796598b353524d450f947c58d8e1a8efbc05c334663ad7"},
	{ 90000,"96e00099a12e4e50a84d361942a05ff026f2e0f413f0f9afefc8af7085dde9da"},
	{100000,"d5b20487d7a4b76d80dc2ae5e51da7feb9190a88264492ecc2f965e4f30b737d"},
	{110000,"5ab0a23ddce02083003619bcef60d6f9e262f4777c3edd1b6964500be25d2b89"},
	{110520,"a2d08d171265aa0c4ee9e5e5baebd191940f86ccc7b01cd8ebfa2276db98736c"},//4.0
	{110521,"da28b56d63c1be49b6c89f16b4c3d2da3da14dcc98ec38079aedef9b83e627ce"},
	{120000,"b31f8f2284f51cecf8028876ddd6df7c812b7fbc274ff7bab303f1fcc3b3310b"},
	{130000,"7c171f2a4d40a136ba9f309895cc695f957a783736f492a4bb9613905cd62256"},
	{140000,"60c532ab429aaba8027528d39499fb935d00c53a0b73559a03434b2fc6b01c9f"},
	{150000,"0d693d183d662d53101d9729a5e03f4fe87a378c4dacbb642842cdaf6a75c224"},
	{160000,"d372a4f56bb020bbeef7dc3543ebde9076110bbc3390a70f302a4565743a2fcd"},
	{170000,"b7df3e82d6798ab93bf56314ef619ae9709af1750530446e4981637c46c91f1f"}
	};
}
