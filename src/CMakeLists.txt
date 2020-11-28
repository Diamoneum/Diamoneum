set(DiamoneumTools_INCLUDE_DIRS
    ${DiamoneumFramework_INCLUDE_DIRS}
    "${CMAKE_CURRENT_LIST_DIR}"
)

set(DiamoneumTools_INCLUDE_DIRS ${DiamoneumTools_INCLUDE_DIRS} PARENT_SCOPE)

# DiamoneumTools

add_custom_target(DiamoneumTools)
add_dependencies(DiamoneumTools
    DiamoneumTools::ConnectivityTool
    DiamoneumTools::Daemon
    DiamoneumTools::Miner
    DiamoneumTools::Optimizer
    DiamoneumTools::PaymentGateService
    DiamoneumTools::SimpleWallet
)

# DiamoneumTools::BinaryInfo # NOTE: Ignore this. It's not a target.

# DiamoneumTools::ConnectivityTool

set(DiamoneumTools_ConnectivityTool_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/ConnectivityTool/ConnectivityTool.cpp"
)

if(WIN32)
    list(APPEND DiamoneumTools_ConnectivityTool_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/connectivity_tool.rc"
    )
endif()

set(DiamoneumTools_ConnectivityTool_LIBS
    Boost::program_options
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::P2p
    DiamoneumFramework::Rpc
    DiamoneumFramework::Serialization
    DiamoneumFramework::System
)

if(WIN32)
    list(APPEND DiamoneumTools_ConnectivityTool_LIBS ws2_32)
endif()

add_executable(DiamoneumTools_ConnectivityTool ${DiamoneumTools_ConnectivityTool_SOURCES})
add_executable(DiamoneumTools::ConnectivityTool ALIAS DiamoneumTools_ConnectivityTool)
target_include_directories(DiamoneumTools_ConnectivityTool PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_ConnectivityTool ${DiamoneumTools_ConnectivityTool_LIBS})
set_target_properties(DiamoneumTools_ConnectivityTool PROPERTIES OUTPUT_NAME "connectivity_tool")

# DiamoneumTools::Daemon

set(DiamoneumTools_Daemon_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/Daemon/Daemon.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Daemon/DaemonCommandsHandler.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Daemon/DaemonCommandsHandler.h"
)

if(WIN32)
    list(APPEND DiamoneumTools_Daemon_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/daemon.rc"
    )
endif()

set(DiamoneumTools_Daemon_LIBS
    Boost::filesystem
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::Global
    DiamoneumFramework::Logging
    DiamoneumFramework::P2p
    DiamoneumFramework::Rpc
    DiamoneumFramework::Serialization
    DiamoneumFramework::System
)

add_executable(DiamoneumTools_Daemon ${DiamoneumTools_Daemon_SOURCES})
add_executable(DiamoneumTools::Daemon ALIAS DiamoneumTools_Daemon)
target_include_directories(DiamoneumTools_Daemon PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_Daemon PRIVATE ${DiamoneumTools_Daemon_LIBS})
set_target_properties(DiamoneumTools_Daemon PROPERTIES OUTPUT_NAME "Diamoneumd")

# DiamoneumTools::Miner

set(DiamoneumTools_Miner_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/Miner/BlockchainMonitor.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/BlockchainMonitor.h"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/Miner.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/Miner.h"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/MinerEvent.h"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/MinerManager.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/MinerManager.h"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/MiningConfig.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/MiningConfig.h"
    "${CMAKE_CURRENT_LIST_DIR}/Miner/main.cpp"
)

if(WIN32)
    list(APPEND DiamoneumTools_Miner_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/miner.rc"
    )
endif()

set(DiamoneumTools_Miner_LIBS
    Boost::program_options
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::Logging
    DiamoneumFramework::Rpc
    DiamoneumFramework::Serialization
    DiamoneumFramework::System
)

if(WIN32)
    list(APPEND DiamoneumTools_Miner_LIBS ws2_32)
endif()

add_executable(DiamoneumTools_Miner ${DiamoneumTools_Miner_SOURCES})
add_executable(DiamoneumTools::Miner ALIAS DiamoneumTools_Miner)
target_include_directories(DiamoneumTools_Miner PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_Miner PRIVATE ${DiamoneumTools_Miner_LIBS})
set_target_properties(DiamoneumTools_Miner PROPERTIES OUTPUT_NAME "miner")

# DiamoneumTools::Optimizer

set(DiamoneumTools_Optimizer_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/Optimizer/Optimizer.cpp"
)

if(WIN32)
    list(APPEND DiamoneumTools_Optimizer_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/optimizer.rc"
    )
endif()

set(DiamoneumTools_Optimizer_LIBS
    Boost::filesystem
    Boost::program_options
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::Global
    DiamoneumFramework::InProcessNode
    DiamoneumFramework::Logging
    DiamoneumFramework::Rpc
    DiamoneumFramework::System
)

if(WIN32)
    list(APPEND DiamoneumTools_Optimizer_LIBS ws2_32)
endif()

add_executable(DiamoneumTools_Optimizer ${DiamoneumTools_Optimizer_SOURCES})
add_executable(DiamoneumTools::Optimizer ALIAS DiamoneumTools_Optimizer)
target_include_directories(DiamoneumTools_Optimizer PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_Optimizer ${DiamoneumTools_Optimizer_LIBS})
set_target_properties(DiamoneumTools_Optimizer PROPERTIES OUTPUT_NAME "optimizer")

# DiamoneumTools::PaymentGateService

set(DiamoneumTools_PaymentGateService_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/ConfigurationManager.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/ConfigurationManager.h"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/PaymentGateService.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/PaymentGateService.h"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/PaymentServiceConfiguration.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/PaymentServiceConfiguration.h"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/RpcNodeConfiguration.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/RpcNodeConfiguration.h"
    "${CMAKE_CURRENT_LIST_DIR}/PaymentGateService/main.cpp"
)

if(WIN32)
    list(APPEND DiamoneumTools_PaymentGateService_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/walletd.rc"
    )
endif()

set(DiamoneumTools_PaymentGateService_LIBS
    Boost::filesystem
    Boost::program_options
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::Global
    DiamoneumFramework::InProcessNode
    DiamoneumFramework::Logging
    DiamoneumFramework::Rpc
    DiamoneumFramework::System
)

add_executable(DiamoneumTools_PaymentGateService ${DiamoneumTools_PaymentGateService_SOURCES})
add_executable(DiamoneumTools::PaymentGateService ALIAS DiamoneumTools_PaymentGateService)
target_include_directories(DiamoneumTools_PaymentGateService PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_PaymentGateService ${DiamoneumTools_PaymentGateService_LIBS})
set_target_properties(DiamoneumTools_PaymentGateService PROPERTIES OUTPUT_NAME "walletd")

# DiamoneumTools::SimpleWallet

set(DiamoneumTools_SimpleWallet_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/SimpleWallet/PasswordContainer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SimpleWallet/PasswordContainer.h"
    "${CMAKE_CURRENT_LIST_DIR}/SimpleWallet/SimpleWallet.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SimpleWallet/SimpleWallet.h"
)

if(WIN32)
    list(APPEND DiamoneumTools_SimpleWallet_SOURCES
        "${CMAKE_CURRENT_LIST_DIR}/BinaryInfo/simplewallet.rc"
    )
endif()

set(DiamoneumTools_SimpleWallet_LIBS
    Boost::filesystem
    Boost::program_options
    DiamoneumFramework::Breakpad
    DiamoneumFramework::Common
    DiamoneumFramework::Global
    DiamoneumFramework::Logging
    DiamoneumFramework::NodeRpcProxy
    DiamoneumFramework::Rpc
    DiamoneumFramework::Serialization
    DiamoneumFramework::Wallet
)

if(WIN32)
    list(APPEND DiamoneumTools_SimpleWallet_LIBS ws2_32)
endif()

add_executable(DiamoneumTools_SimpleWallet ${DiamoneumTools_SimpleWallet_SOURCES})
add_executable(DiamoneumTools::SimpleWallet ALIAS DiamoneumTools_SimpleWallet)
target_include_directories(DiamoneumTools_SimpleWallet PRIVATE ${DiamoneumTools_INCLUDE_DIRS})
target_link_libraries(DiamoneumTools_SimpleWallet ${DiamoneumTools_SimpleWallet_LIBS})
set_target_properties(DiamoneumTools_SimpleWallet PROPERTIES OUTPUT_NAME "simplewallet")

# Installation

install(TARGETS
            DiamoneumTools_ConnectivityTool
            DiamoneumTools_Daemon
            DiamoneumTools_Miner
            DiamoneumTools_Optimizer
            DiamoneumTools_PaymentGateService
            DiamoneumTools_SimpleWallet
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
)
