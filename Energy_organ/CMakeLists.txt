cmake_minimum_required (VERSION 2.8)
project (test)	

find_package(OpenCV REQUIRED) 

include_directories( ${OpenCV_INCLUDE_DIRS} )  
include_directories(./ ./class/organ/include)	#添加頭文件

aux_source_directory(. ALL_SRCS)		# 添加当前目录下所有的源文件

add_subdirectory(class/organ)

add_executable(test ${ALL_SRCS})	        # 指定生成目标

target_link_libraries(test organ)	# 添加链接库
target_link_libraries(test ${OpenCV_LIBS})

