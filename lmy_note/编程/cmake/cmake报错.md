1、CMakeCache.txt is different 错误
https://blog.csdn.net/wuzuyu365/article/details/52438302
把caffe目录拷贝到faster_rcnn-master下然后编译报错

wzy@wzy-ubuntu:~/faster_rcnn-master2/external/caffe/build$ sudo cmake .. 
CMake Error: The current CMakeCache.txt directory /home/wzy/faster_rcnn-master2/external/caffe/.build_release/CMakeCache.txt is different than the directory /home/wzy/caffe/build where CMakeCache.txt was created. This may result in binaries being created in the wrong place. If you are not sure, reedit the CMakeCache.txt
CMake Error: The source "/home/wzy/faster_rcnn-master2/external/caffe/CMakeLists.txt" does not match the source "/home/wzy/caffe/CMakeLists.txt" used to generate cache.  Re-run cmake with a different source directory.

进入build目录，删除CMakeCache.txt即可
