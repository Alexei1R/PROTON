# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.8)

project ("PROTON")

# Включите подпроекты.
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glfw/")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/glew/")
add_subdirectory ("PROTON")



target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include )
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glm)
target_include_directories(${PROJECT_NAME}    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)