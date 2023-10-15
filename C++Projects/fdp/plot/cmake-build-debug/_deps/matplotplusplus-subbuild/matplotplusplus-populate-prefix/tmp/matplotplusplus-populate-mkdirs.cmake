# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-src"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-build"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/tmp"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src"
  "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/giammy/CLionProjects/fdp/plot/cmake-build-debug/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
