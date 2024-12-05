cmake_minimum_required(VERSION 3.30)
project(caf_mail)

find_package(CAF REQUIRED)

add_executable(caf_mail caf_mail.cpp)
target_compile_features(caf_mail PRIVATE cxx_std_23)
target_link_libraries(caf_mail PRIVATE CAF::core)
