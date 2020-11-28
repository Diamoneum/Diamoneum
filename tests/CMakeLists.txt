set(DiamoneumTests_INCLUDE_DIRS
    ${DiamoneumFramework_INCLUDE_DIRS}
    "${CMAKE_CURRENT_LIST_DIR}"
)

# DiamoneumTests

add_custom_target(DiamoneumTests)
add_dependencies(DiamoneumTests
    DiamoneumTests::CoreTests
    DiamoneumTests::CryptoTests
    DiamoneumTests::DifficultyTests
    DiamoneumTests::HashTargetTests
    DiamoneumTests::HashTests
    DiamoneumTests::NodeRpcProxyTests
    DiamoneumTests::PerformanceTests
    DiamoneumTests::SystemTests
    DiamoneumTests::UnitTests
)

# DiamoneumTests::CoreTests

set(DiamoneumTests_CoreTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/AccountBoostSerialization.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/BlockReward.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/BlockReward.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/BlockValidation.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/BlockValidation.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/BoostSerializationHelper.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/ChainSplit1.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/ChainSplit1.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/ChainSwitch1.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/ChainSwitch1.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Chaingen.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Chaingen.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Chaingen001.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Chaingen001.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/ChaingenMain.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/CryptoNoteBoostSerialization.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/DoubleSpend.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/DoubleSpend.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/IntegerOverflow.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/IntegerOverflow.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/RandomOuts.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/RandomOuts.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/RingSignature.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/RingSignature.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TestGenerator.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionBuilder.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionBuilder.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionTests.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionValidation.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/TransactionValidation.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/UnorderedContainersBoostSerialization.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Upgrade.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/Upgrade.h"
    "${CMAKE_CURRENT_LIST_DIR}/CoreTests/double_spend.inl"
)

set(DiamoneumTests_CoreTests_LIBS
    Boost::date_time
    Boost::program_options
    Boost::serialization
    codecov
    DiamoneumFramework::Common
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::InProcessNode
    DiamoneumFramework::Logging
    DiamoneumFramework::Serialization
    DiamoneumFramework::System
    DiamoneumTests::TestGenerator
)

add_executable(DiamoneumTests_CoreTests ${DiamoneumTests_CoreTests_SOURCES})
add_executable(DiamoneumTests::CoreTests ALIAS DiamoneumTests_CoreTests)
target_include_directories(DiamoneumTests_CoreTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_CoreTests PRIVATE ${DiamoneumTests_CoreTests_LIBS})
set_target_properties(DiamoneumTests_CoreTests PROPERTIES OUTPUT_NAME "core_tests")

add_test(
    NAME CoreTests
    COMMAND $<TARGET_FILE:DiamoneumTests_CoreTests> --generate_and_play_test_data
)

# DiamoneumTests::CryptoTests

set(DiamoneumTests_CryptoTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/crypto-ops-data.c"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/crypto-ops.c"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/crypto-tests.h"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/crypto.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/hash.c"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/main.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/CryptoTests/random.c"
)

set(DiamoneumTests_CryptoTests_LIBS codecov)

add_executable(DiamoneumTests_CryptoTests ${DiamoneumTests_CryptoTests_SOURCES})
add_executable(DiamoneumTests::CryptoTests ALIAS DiamoneumTests_CryptoTests)
target_include_directories(DiamoneumTests_CryptoTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_CryptoTests PRIVATE ${DiamoneumTests_CryptoTests_LIBS})
set_target_properties(DiamoneumTests_CryptoTests PROPERTIES OUTPUT_NAME "crypto_tests")

add_test(
    NAME CryptoTests
    COMMAND $<TARGET_FILE:DiamoneumTests_CryptoTests> ${CMAKE_CURRENT_LIST_DIR}/CryptoTests/tests.txt
)

# DiamoneumTests::Data (skipped, not a library or executable target)

# DiamoneumTests::DifficultyTests

set(DiamoneumTests_DifficultyTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/DifficultyTests/Difficulty.cpp"
)

set(DiamoneumTests_DifficultyTests_LIBS
    codecov
    DiamoneumFramework::Logging
    DiamoneumFramework::CryptoNoteCore
)

add_executable(DiamoneumTests_DifficultyTests ${DiamoneumTests_DifficultyTests_SOURCES})
add_executable(DiamoneumTests::DifficultyTests ALIAS DiamoneumTests_DifficultyTests)
target_include_directories(DiamoneumTests_DifficultyTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_DifficultyTests PRIVATE ${DiamoneumTests_DifficultyTests_LIBS})
set_target_properties(DiamoneumTests_DifficultyTests PROPERTIES OUTPUT_NAME "difficulty_tests")

add_test(
    NAME DifficultyTests
    COMMAND $<TARGET_FILE:DiamoneumTests_DifficultyTests> ${CMAKE_CURRENT_LIST_DIR}/DifficultyTests/data.txt
)

# DiamoneumTests::HashTargetTests

set(DiamoneumTests_HashTargetTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/HashTargetTests/HashTarget.cpp"
)

set(DiamoneumTests_HashTargetTests_LIBS
    codecov
    DiamoneumFramework::CryptoNoteCore
)

add_executable(DiamoneumTests_HashTargetTests ${DiamoneumTests_HashTargetTests_SOURCES})
add_executable(DiamoneumTests::HashTargetTests ALIAS DiamoneumTests_HashTargetTests)
target_include_directories(DiamoneumTests_HashTargetTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_HashTargetTests PRIVATE ${DiamoneumTests_HashTargetTests_LIBS})
set_target_properties(DiamoneumTests_HashTargetTests PROPERTIES OUTPUT_NAME "hash_target_tests")

add_test(
    NAME HashTargetTests
    COMMAND $<TARGET_FILE:DiamoneumTests_HashTargetTests>
)

# DiamoneumTests::HashTests

set(DiamoneumTests_HashTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/HashTests/main.cpp"
)

set(DiamoneumTests_HashTests_LIBS
    codecov
    DiamoneumFramework::Crypto
)

add_executable(DiamoneumTests_HashTests ${DiamoneumTests_HashTests_SOURCES})
add_executable(DiamoneumTests::HashTests ALIAS DiamoneumTests_HashTests)
target_include_directories(DiamoneumTests_HashTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_HashTests PRIVATE ${DiamoneumTests_HashTests_LIBS})
set_target_properties(DiamoneumTests_HashTests PROPERTIES OUTPUT_NAME "hash_tests")

foreach(hash IN ITEMS extra-blake extra-groestl extra-jh extra-skein fast slow tree)
    add_test(
        NAME HashTests-${hash}
        COMMAND $<TARGET_FILE:DiamoneumTests_HashTests> ${hash} ${CMAKE_CURRENT_LIST_DIR}/HashTests/tests-${hash}.txt
    )
endforeach()

# DiamoneumTests::NodeRpcProxyTests

set(DiamoneumTests_NodeRpcProxyTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/NodeRpcProxyTests/NodeRpcProxyTests.cpp"
)

set(DiamoneumTests_NodeRpcProxyTests_LIBS
    codecov
    DiamoneumFramework::Common
    DiamoneumFramework::Logging
    DiamoneumFramework::NodeRpcProxy
    DiamoneumFramework::Rpc
    DiamoneumFramework::Serialization
)

add_executable(DiamoneumTests_NodeRpcProxyTests ${DiamoneumTests_NodeRpcProxyTests_SOURCES})
add_executable(DiamoneumTests::NodeRpcProxyTests ALIAS DiamoneumTests_NodeRpcProxyTests)
target_include_directories(DiamoneumTests_NodeRpcProxyTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_NodeRpcProxyTests PRIVATE ${DiamoneumTests_NodeRpcProxyTests_LIBS})
set_target_properties(DiamoneumTests_NodeRpcProxyTests PROPERTIES OUTPUT_NAME "node_rpc_proxy_tests")

add_test(
    NAME NodeRpcProxyTests
    COMMAND $<TARGET_FILE:DiamoneumTests_NodeRpcProxyTests>
)

# DiamoneumTests::PerformanceTests

set(DiamoneumTests_PerformanceTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/CheckRingSignature.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/ConstructTransaction.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/CryptoNoteSlowHash.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/DerivePublicKey.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/DeriveSecretKey.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/GenerateKeyDerivation.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/GenerateKeyImage.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/GenerateKeyImageHelper.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/IsOutToAccount.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/MultiTransactionTestBase.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/PerformanceTests.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/PerformanceUtils.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/SingleTransactionTestBase.h"
    "${CMAKE_CURRENT_LIST_DIR}/PerformanceTests/main.cpp"
)

set(DiamoneumTests_PerformanceTests_LIBS
    Boost::chrono
    codecov
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::Logging
)

add_executable(DiamoneumTests_PerformanceTests ${DiamoneumTests_PerformanceTests_SOURCES})
add_executable(DiamoneumTests::PerformanceTests ALIAS DiamoneumTests_PerformanceTests)
target_include_directories(DiamoneumTests_PerformanceTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_PerformanceTests PRIVATE ${DiamoneumTests_PerformanceTests_LIBS})
set_target_properties(DiamoneumTests_PerformanceTests PROPERTIES OUTPUT_NAME "performance_tests")

add_test(
    NAME PerformanceTests
    COMMAND $<TARGET_FILE:DiamoneumTests_PerformanceTests>
)

# DiamoneumTests::SystemTests

set(DiamoneumTests_SystemTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/ContextGroupTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/ContextGroupTimeoutTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/ContextTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/DispatcherTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/ErrorMessageTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/EventLockTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/EventTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/Ipv4AddressTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/Ipv4ResolverTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/OperationTimeoutTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/RemoteContextTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/TcpConnectionTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/TcpConnectorTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/TcpListenerTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/TimerTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/SystemTests/main.cpp"
)

set(DiamoneumTests_SystemTests_LIBS
    codecov
    GTest::gtest_main
    DiamoneumFramework::System
)

add_executable(DiamoneumTests_SystemTests ${DiamoneumTests_SystemTests_SOURCES})
add_executable(DiamoneumTests::SystemTests ALIAS DiamoneumTests_SystemTests)
target_include_directories(DiamoneumTests_SystemTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_SystemTests PRIVATE ${DiamoneumTests_SystemTests_LIBS})
set_target_properties(DiamoneumTests_SystemTests PROPERTIES OUTPUT_NAME "system_tests")

add_test(
    NAME SystemTests
    COMMAND $<TARGET_FILE:DiamoneumTests_SystemTests>
)

# DiamoneumTests::TestGenerator

set(DiamoneumTests_TestGenerator_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/TestGenerator/TestGenerator.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/TestGenerator/TestGenerator.h"
)

set(DiamoneumTests_TestGenerator_LIBS codecov)

add_library(DiamoneumTests_TestGenerator ${DiamoneumTests_TestGenerator_SOURCES})
add_library(DiamoneumTests::TestGenerator ALIAS DiamoneumTests_TestGenerator)
target_include_directories(DiamoneumTests_TestGenerator PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_TestGenerator PRIVATE ${DiamoneumTests_TestGenerator_LIBS})

# DiamoneumTests::UnitTests

set(DiamoneumTests_UnitTests_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ArrayRefTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ArrayViewTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/Base58.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/BinarySerializationCompatibility.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/BlockReward.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/BlockingQueue.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/Chacha8.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/Checkpoints.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/DecomposeAmountIntoDigits.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/EventWaiter.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/EventWaiter.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ICoreStub.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ICoreStub.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ICryptoNoteProtocolQueryStub.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ICryptoNoteProtocolQueryStub.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/INodeStubs.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/INodeStubs.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/MulDiv.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/ParseAmount.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/PaymentGateTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/Serialization.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/SerializationKV.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/Shuffle.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/StringBufferTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/StringViewTests.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestBcS.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestBlockchainExplorer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestBlockchainGenerator.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestBlockchainGenerator.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestCurrency.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestFileMappedVector.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestFormatUtils.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestInprocessNode.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestJsonValue.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestMessageQueue.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestPath.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestPeerlist.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestProtocolPack.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransactionPoolDetach.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransfers.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransfersConsumer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransfersContainer.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransfersContainerKeyImage.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestTransfersSubscription.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestUpgradeDetector.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestWallet.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestWalletLegacy.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TestWalletService.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TransactionApi.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TransactionApiHelpers.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TransactionApiHelpers.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TransactionPool.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/TransfersObserver.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/UnitTestsUtils.h"
    "${CMAKE_CURRENT_LIST_DIR}/UnitTests/main.cpp"
)

set(DiamoneumTests_UnitTests_LIBS
    codecov
    GTest::gtest_main
    DiamoneumFramework::CryptoNoteCore
    DiamoneumFramework::CryptoNoteProtocol
    DiamoneumFramework::Http
    DiamoneumFramework::InProcessNode
    DiamoneumFramework::Logging
    DiamoneumFramework::Rpc
    DiamoneumFramework::Wallet
    DiamoneumTests::TestGenerator
)

add_executable(DiamoneumTests_UnitTests ${DiamoneumTests_UnitTests_SOURCES})
add_executable(DiamoneumTests::UnitTests ALIAS DiamoneumTests_UnitTests)
target_include_directories(DiamoneumTests_UnitTests PRIVATE ${DiamoneumTests_INCLUDE_DIRS})
target_link_libraries(DiamoneumTests_UnitTests PRIVATE ${DiamoneumTests_UnitTests_LIBS})
set_target_properties(DiamoneumTests_UnitTests PROPERTIES OUTPUT_NAME "unit_tests")

add_test(
    NAME UnitTests
    COMMAND $<TARGET_FILE:DiamoneumTests_UnitTests>
)
