cmake_minimum_required(VERSION 3.20)

project(Colorlog)

add_executable(colorlog colorlog.cc)
target_compile_features(colorlog PUBLIC cxx_std_20)
