# CMakeList.txt: projeto de CMake para Lust, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
set(TARGET_NAME LustDevUtils)

file(GLOB_RECURSE DEVUTILS_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.hpp")
file(GLOB_RECURSE DEVUTILS_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

trace_dependency(NAME spdlog INSTALL_SCRIPT "${PROJECT_SOURCE_DIR}/installers/spdlog.cmake.json" WORKING_DIR "${FETCHERS_LOCATION}")

add_library(${TARGET_NAME} ${DEVUTILS_SRCS} ${DEVUTILS_HDRS})
target_link_libraries(${TARGET_NAME} PUBLIC spdlog::spdlog)
target_include_directories(${TARGET_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/Utils>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/pch>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEVUTILS_DEBUG_MODE)
endif()

if(BUILD_SHARED_LIBS)
	if(WIN32)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEVUTILS_WIN32)
	elseif(LINUX)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEVUTILS_LINUX LUST_DEVUTILS_UNIX)
	elseif(APPLE)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEVUTILS_MACOS LUST_DEVUTILS_UNIX)
	elseif(BSD)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEVUTILS_BSD LUST_DEVUTILS_UNIX)
	else()
		message(FATAL_ERROR "Unknown platform, this project can only be built on Windows, Linux, MacOS or FreeBSD")
	endif()
	target_compile_definitions(${TARGET_NAME} PRIVATE LUST_DEVUTILS_BUILD_DLL)
	target_compile_definitions(${TARGET_NAME} INTERFACE LUST_DEVUTILS_CONSUME_DLL)
endif()


set_cxx_project_standards(${TARGET_NAME} 20 FALSE)
target_installation_behaviour(
	CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
	TARGET_NAME ${TARGET_NAME}
	VERSION ${PROJECT_VERSION}
	PROJECT_NAME ${PROJECT_NAME}
	NAMESPACE "Lust"
	COMPONENT Lust
	HEADER_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/Utils
	HEADER_OUTPUT include/LustDevUtils/Utils)