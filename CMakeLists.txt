cmake_minimum_required(VERSION 3.0.0)
project(NIlang VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 14
set(CMAKE_CXX_STANDARD 14)

set(LLVM_LIBS all)

find_program(LLVM_CONFIG NAMES llvm-config DOC "Path to llvm-config utility")
if (${LLVM_CONFIG} STREQUAL "LLVM_CONFIG-NOTFOUND")
	message(SEND_ERROR "llvm-config not found, please manually set path with -DLLVM_CONFIG")
endif()
message(STATUS "Using llvm-config: ${LLVM_CONFIG}")

# Define LLVM version macros so that we can support multiple versions in the source.
exec_program(${LLVM_CONFIG}
	ARGS --version
	OUTPUT_VARIABLE LLVM_VER)
exec_program(${LLVM_CONFIG}
	ARGS --cxxflags
	OUTPUT_VARIABLE LLVM_CXXFLAGS)
exec_program(${LLVM_CONFIG}
	ARGS --libs ${LLVM_LIBS}
	OUTPUT_VARIABLE LLVM_LIBS_FLAGS)
exec_program(${LLVM_CONFIG}
	ARGS --ldflags
	OUTPUT_VARIABLE LLVM_LDFLAGS)
exec_program(${LLVM_CONFIG}
	ARGS --system-libs
	OUTPUT_VARIABLE LLVM_SYSTEMLIBS)
exec_program(${LLVM_CONFIG}
	ARGS --libdir
	OUTPUT_VARIABLE LLVM_LIBDIR)
exec_program(${LLVM_CONFIG}
	ARGS --bindir
	OUTPUT_VARIABLE LLVM_BINDIR)
exec_program(${LLVM_CONFIG}
	ARGS --includedir
  OUTPUT_VARIABLE LLVM_INCLUDE_DIR)
string(REGEX REPLACE "([0-9]*).([0-9]*).*" "-DLLVM_MAJOR=\\1 -DLLVM_MINOR=\\2"  LLVM_VERSION "${LLVM_VER}")

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)
# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})
include_directories(${LLVM_INCLUDE_DIR})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${CMAKE_CURRENT_SOURCE_DIR}/libs/antlr-4.9-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(GrammarLexer grammars/NILexer.g4 VISITOR OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/)
antlr_target(GrammarParser grammars/NIParser.g4 VISITOR OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/libs/)

# add our project source directories
include_directories(${PROJECT_SOURCE_DIR}
					 ${PROJECT_SOURCE_DIR}/libs/
  )


add_executable(nilang main.cpp
							 autogen/NILexer.cpp autogen/NIParser.cpp
               autogen/NIParserBaseListener.cpp
							 autogen/NIParserBaseVisitor.cpp
               autogen/NIParserListener.cpp
							 autogen/NIParserVisitor.cpp
							 AST.cpp ErrorListeners.cpp NIVisitor.cpp Compiler.cpp
               ${ANTLR_GrammarNIParser_CXX_OUTPUTS})

# link required libraries
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LLVM_VERSION}")
target_link_libraries(nilang antlr4_static ${SYSTEM_LIBS} ${LLVM_LIBS_FLAGS})

if (LLVM_VER VERSION_GREATER 3.4)
	string(STRIP ${LLVM_SYSTEMLIBS} LLVM_SYSTEMLIBS)
	if ("x${LLVM_SYSTEMLIBS}" STREQUAL "x")
	else()
		target_link_libraries(nilang ${LLVM_SYSTEMLIBS})
	endif()
endif()
set(CMAKE_EXE_LINKER_FLAGS "${LLVM_LDFLAGS} ${LIBGC} ${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,${LLVM_LIBDIR}")

# Make sure that we use the LLVM path as an rpath so that we can dynamically
# link to LLVM.  Don't let CMake specify its own rpath
set(CMAKE_SKIP_RPATH true)

# Make sure that LLVM is able to find functions in the main executable
SET_TARGET_PROPERTIES(nilang PROPERTIES
       ENABLE_EXPORTS TRUE)
