aux_source_directory(. LIB_SRCS1)			# 添加当前目录下所有的源文件
add_library (organ ${LIB_SRCS1})				# 当前目录下的文件生成一个链接库
