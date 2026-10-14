# CMakeList.txt: projeto de CMake para Lust, incluir origem e definir
# lógica específica a um projeto aqui.
#

# Adicione a origem ao executável deste projeto.

set_property(TARGET Lust PROPERTY CXX_STANDARD 20)

set(TARGET_NAME SandCoffin)

file(GLOB_RECURSE SAND_COFFIN_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.hpp")
file(GLOB_RECURSE SAND_COFFIN_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp")

add_executable(${TARGET_NAME} ${SAND_COFFIN_SRCS} ${SAND_COFFIN_HDRS})
target_link_libraries(${TARGET_NAME} PRIVATE Lust)

set_cxx_project_standards(${TARGET_NAME} 20 FALSE)
set_artifacts_dir(${TARGET_NAME} ${PROJECT_BINARY_DIR})
set_msvc_target_utf8(${TARGET_NAME})
set_msvc_debug_improvements(${TARGET_NAME})
target_installation_behaviour(
	CONFIG_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
	TARGET_NAME ${TARGET_NAME}
	VERSION ${PROJECT_VERSION}
	PROJECT_NAME ${PROJECT_NAME}
	NAMESPACE "Lust"
	COMPONENT Lust)

# TODO: Adicione testes e instale destinos, se necessário.
