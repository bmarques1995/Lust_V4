# CMakeList.txt: projeto de CMake para Lust, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.
set(TARGET_NAME Lust)

file(GLOB_RECURSE LUST_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.hpp")
file(GLOB_RECURSE LUST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_library(${TARGET_NAME} ${LUST_SRCS} ${LUST_HDRS})
target_include_directories(${TARGET_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/Core>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/pch>
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	target_compile_definitions(${TARGET_NAME} PUBLIC LUST_DEBUG_MODE)
	target_link_libraries(${TARGET_NAME} PUBLIC LustDevUtils)
endif()

if(BUILD_SHARED_LIBS)
	if(WIN32)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_WIN32)
	elseif(LINUX)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_LINUX LUST_UNIX)
	elseif(APPLE)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_MACOS LUST_UNIX)
	elseif(BSD)
		target_compile_definitions(${TARGET_NAME} PUBLIC LUST_BSD LUST_UNIX)
	else()
		message(FATAL_ERROR "Unknown platform, this project can only be built on Windows, Linux, MacOS or FreeBSD")
	endif()
	target_compile_definitions(${TARGET_NAME} PRIVATE LUST_BUILD_DLL)
	target_compile_definitions(${TARGET_NAME} INTERFACE LUST_CONSUME_DLL)
endif()


set_cxx_project_standards(${TARGET_NAME} 20 FALSE)
target_installation_behaviour(
	CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
	TARGET_NAME ${TARGET_NAME}
	VERSION ${PROJECT_VERSION}
	PROJECT_NAME ${PROJECT_NAME}
	NAMESPACE "Lust"
	COMPONENT Lust
	HEADER_INPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/Core
	HEADER_OUTPUT include/Lust/Core)

# TODO: Adicione testes e instale destinos, se necessário.
