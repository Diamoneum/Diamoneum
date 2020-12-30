![image](http://diamoneum.xyz/wp-content/uploads/2020/10/Diamoneum-Logo-Example-1-1.png)
#### Master Build Status
[![Build Status](https://github.com/Diamoneum/Diamoneum/workflows/Build/badge.svg?branch=master)](https://github.com/Diamoneum/Diamoneum/actions)


#### Development Build Status
[![Build Status](https://github.com/Diamoneum/Diamoneum/workflows/Build/badge.svg?branch=dev)](https://github.com/Diamoneum/Diamoneum/actions)


# Table of contents
1. [Project Specs](#coinspecs)
2. [How to Compile Diamoneum](#howtocompile)
    1. [Diamoneum for Linux](#build-linux)
    2. [Diamoneum for Windows](#build-windows)
    3. [Diamoneum for macOS](#build-apple)
    4. [Diamoneum for Android](#build-android)
    5. [Diamoneum for FreeBSD](#build-freebsd)
3. [Downloads](#downloads)
4. [Useful Links](#usefullinks)
5. [Donate & Thanks](#donate)
6. [Copyright / License](#copypasta)

## Installing <a name="installing"></a>
We offer binary images of the latest releases here: https://releases.diamoneum.xyz

If you would like to compile yourself, read on.

### Downloads <a name="downloads"></a>
| Operating System   | Download                                 |
| ----------------   | ---------------------------------------- |
| Windows 32         | https://releases.diamoneum.xyz/get/cli/latest/win32 |
| Windows 64         | https://releases.diamoneum.xyz/get/cli/latest/win64 |
| macOS 10.8 & Later | https://releases.diamoneum.xyz/get/cli/latest/macos |
| Linux DEB          | https://releases.diamoneum.xyz/get/cli/latest/linux/deb |
| Linux RPM          | https://releases.diamoneum.xyz/get/cli/latest/linux/rpm |
| Android            | https://releases.diamoneum.xyz/get/cli/latest/arm64 |
| Other platforms    | https://releases.diamoneum.xyz |

### Coin Specs <a name="coinspecs"></a>
<table>
<tr><td>Ticker Symbol</td><td>DIAM</td></tr>
<tr><td>Algorithm</td><td>Cryptonight</td></tr>
<tr><td>Type</td><td>Proof of Work (PoW)</td></tr>
<tr><td>Block Time</td><td>120 Seconds</td></tr>
<tr><td>Premine</td><td>0.0 %</td></tr>
<tr><td>Decimals</td><td>8 Digits</td></tr>
<tr><td>Block Reward</td><td>Decrease by each block</td></tr>
<tr><td>Max Coin Supply </td><td>750,000,000 DIAM</td></tr>
<tr><td>P2P | RPC Port</td><td>57575 | 57576</td></tr>
</table>

More information at [Diamoneum.xyz](https://diamoneum.xyz/)

# How To Compile <a name="howtocompile"></a>

#### Linux  <a name="build-linux"></a>

##### Prerequisites

- You will need the following packages: build-essential, [cmake (3.10 or higher)](https://docs.diamoneum.xyz/developer/compiling-from-source/untitled) and git;
- Most of these should already be installed on your system. For example on Ubuntu by running:
```
sudo apt-get install build-essential cmake git
```

##### Building

- After installing dependencies run simple script:
```
git clone --recurse-submodules https://github.com/Diamoneum/Diamoneum.git
cd ./Diamoneum
mkdir ./build
cd ./build
cmake -DBUILD_ALL:BOOL=TRUE ..
cmake --build . --config Release
```
- If all went well, it will complete successfully, and you will find all your binaries in the `./build/src` directory.

#### Windows 10 <a name="build-windows"></a>

##### Prerequisites

- Install [Visual Studio 2017 Community Edition](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&page=inlineinstall);
- When installing Visual Studio, it is **required** that you install **Desktop development with C++** and the **VC++ v140 toolchain** when selecting features. The option to install the v140 toolchain can be found by expanding the "Desktop development with C++" node on the right. You will need this for the project to build correctly;
- Make sure that bundled cmake version is 3.10 or higher.

##### Building

- From the start menu, open "x64 Native Tools Command Prompt for vs2017";
- And the run the following commands:
```
git clone https://github.com/Diamoneum/Diamoneum.git
cd Diamoneum
md build
cd build
cmake -G "Visual Studio 15 2017 Win64" -DBUILD_ALL:BOOL=TRUE ..
cmake --build . --config Release
```
- If all went well, it will complete successfully, and you will find all your binaries in the `.\build\src\Release` directory;
- Additionally, a `.sln` file will have been created in the `build` directory. If you wish to open the project in Visual Studio with this, you can.

#### Apple macOS <a name="build-apple"></a>

##### Prerequisites

- Install Xcode and Developer Tools;
- Install [cmake](https://cmake.org/). See [here](https://stackoverflow.com/questions/23849962/cmake-installer-for-mac-fails-to-create-usr-bin-symlinks) if you are unable to call `cmake` from the terminal after installing;
- Install git.

##### Building

- After installing dependencies run simple script:
```
git clone https://github.com/Diamoneum/Diamoneum.git
cd ./Diamoneum
mkdir ./build
cd ./build
cmake -DBUILD_ALL:BOOL=TRUE ..
cmake --build . --config Release
```
- If all went well, it will complete successfully, and you will find all your binaries in the `./build/src` directory.

#### Android (building on Linux) <a name="build-android"></a>

##### Prerequisites

- You will need the following packages: build-essential, cmake (3.10 or higher), git, unzip and wget;
- Most of these should already be installed on your system. For example on Ubuntu by running:
```
sudo apt-get install build-essential cmake git unzip wget
```
- Download and extract Android NDK:
```
mkdir -p "$HOME/.android"
wget -O "$HOME/.android/android-ndk-r18b-linux-x86_64.zip" "https://dl.google.com/android/repository/android-ndk-r18b-linux-x86_64.zip"
unzip -qq "$HOME/.android/android-ndk-r18b-linux-x86_64.zip" -d "$HOME/.android"
export ANDROID_NDK_r18b="$HOME/.android/android-ndk-r18b"
```

##### Building

- After installing dependencies run simple script:
```
git clone https://github.com/Diamoneum/Diamoneum.git
cd ./Diamoneum
mkdir ./build
cd ./build
cmake -DCMAKE_TOOLCHAIN_FILE=cmake/polly/android-ndk-r18b-api-21-x86-clang-libcxx.cmake -DBUILD_ALL:BOOL=TRUE -DBUILD_WITH_TESTS:BOOL=FALSE -DSTATIC=ON -DBUILD_64=OFF -DANDROID=true -DBUILD_TAG="android" ..
cmake --build . --config Release
```
- If all went well, it will complete successfully, and you will find all your binaries in the `./build/src` directory.

#### FreeBSD  <a name="build-freebsd"></a>

##### Prerequisites

- You will need the following packages: cmake (3.10 or higher) and git;
- Most of these should already be installed on your system. For example on FreeBSD by running:
```
sudo pkg install cmake git
```

##### Building

- After installing dependencies run simple script:
```
git clone --recurse-submodules https://github.com/Diamoneum/Diamoneum.git
cd ./Diamoneum
mkdir ./build
cd ./build
cmake -DBUILD_ALL:BOOL=TRUE ..
cmake --build . --config Release
```
- If all went well, it will complete successfully, and you will find all your binaries in the `./build/src` directory.

## Donate <a name="donate"></a>

```
DIAM: diamowieNXVVxGW2GbJERHgawnfvWokZ6bHnzYC2w67KMyV1BiT9Aux6JzY1wg4HmJHMoYJQdyj5LHKKEsFP2FBsA5aimMoQ46
```
```
BTC: 16GLbf566NGF3893gZmB9hY4HiaNbh3GVe
```
```
ETH: 0xA6792e1704d2A77A15d504c98e006bc7d939Ee0b
```
```
XMR: 83LixYjeNejZFiGzDWRoLS6qjbtHUxLJUHh9KwsmWsiqPi3tu8qcP7w2veX3xm3c7t6AVgy3m7EKXSugmt3VxhLRGdAjpE4
```
```
ETN: etnjzZn6KVHHgZf7MDrcYcCg7tVuKN1vYSqjQoYD4sF1hGnGMK5FKtc4TH5ytggf4q2L19kEfxQtKMx21fxhqEyiA97Nzurpkk
```

### Useful Links <a name="usefullinks"></a>
<table>
<tr><td>Website</td><td>https://diamoneum.xyz</td></tr>
<tr><td>Bitcointalk ANN</td><td>Coming Soon</td></tr>
<tr><td>Explorer</td><td>https://explorer.diamoneum.xyz</td></tr>
<tr><td>Pool Explorer</td><td>https://explorer.diamoneum.xyz/#network</td></tr>
<tr><td>Node Map</td><td>https://nodes.diamoneum.xyz</td></tr>
<tr><td>Wallets</td><td>https://releases.diamoneum.xyz</td></tr>
<tr><td>Web Wallet</td><td>https://wallet.diamoneum.xyz</td></tr>
<tr><td>Masternode Setup</td><td>https://github.com/Diamoneum/Diamoneum/wiki</td></tr>
<tr><td>Blockfolio</td><td>https://blockfolio.com/#get-app</td></tr>
<tr><td>CoinGecko</td><td>https://www.coingecko.com/en/coins/Diamoneum</td></tr>
<tr><td>Delta</td><td>https://delta.app</td></tr>
<tr><td>Discord</td><td>https://discord.gg/YVwYZ6Z</td></tr>
<tr><td>Facebook</td><td>https://www.facebook.com/Diamoneum.Diam</td></tr>
</table>

#### Thanks <a name="thanks"></a>

Cryptonote Developers, Bytecoin Developers, Monero Developers, Karbo Developers, Diamoneum Community, Diamoneum Community

### Copypasta for license when editing files  <a name="copypasta"></a>

Hi Diamoneum contributor, thanks for forking and sending back Pull Requests. Extensive docs about contributing are in the works or elsewhere. For now this is the bit we need to get into all the files we touch. Please add it to the top of the files, see [src/config/CryptoNoteConfig.h](https://github.com/Diamoneum/Diamoneum/blob/master/src/config/CryptoNoteConfig.h) for an example.

```
# Copyright 2020-2020 (c) The Diamoneum Team.
# Licensed under the GNU General Public License, Version 3.
# See the file LICENSE from this package for details.
```
