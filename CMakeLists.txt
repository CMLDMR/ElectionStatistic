cmake_minimum_required(VERSION 3.5)

project(ElectionStatistic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus")

set(bsoncxx_DIR C:/Mongo/mongo-msvc2022x64-noBoost/lib/cmake/bsoncxx-3.7.0)
set(mongocxx_DIR C:/Mongo/mongo-msvc2022x64-noBoost/lib/cmake/mongocxx-3.7.0)



file(GLOB_RECURSE HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

include_directories("${CMAKE_SOURCE_DIR}")


add_executable(ElectionStatistic
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(ElectionStatistic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../mongocore/include")
target_link_directories(ElectionStatistic PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../mongocore/lib")
target_link_libraries(ElectionStatistic PRIVATE MongoCore)


find_package(mongocxx REQUIRED)
find_package(bsoncxx REQUIRED)
include_directories(${LIBMONGOCXX_INCLUDE_DIR})
include_directories(${LIBBSONCXX_INCLUDE_DIR})

target_link_libraries(ElectionStatistic PRIVATE mongo::bsoncxx_shared)
target_link_libraries(ElectionStatistic PRIVATE mongo::mongocxx_shared)


set(Wt_DIR C:/Wt_4.7.0_msvs2022_x64/lib/cmake/wt)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/Wt_4.7.0_msvs2022_x64/lib/cmake/wt")
FIND_PACKAGE( Wt REQUIRED )
#include_directories(${Wt_INCLUDE_DIR})
target_include_directories(ElectionStatistic PUBLIC "C:/Wt_4.7.0_msvs2022_x64/include")
target_link_directories(ElectionStatistic PUBLIC "C:/Wt_4.7.0_msvs2022_x64/lib")
target_link_libraries(ElectionStatistic PRIVATE Wt WtHttp)
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "/ignore:4251")


install(TARGETS ElectionStatistic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
