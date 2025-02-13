#### 生成java调用的dll
1. 生成头文件: javac DllTest.java -h .
2. 导入jni.h和jni_md.h 
3. clang++ -shared -o libexample.dylib com_t13max_test_dll_DllTest.cpp -I../include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -L${JAVA_HOME}/lib/server -ljvm
4. public native int Add(int a,int b);
    static {
        System.load("D:\\ideaWorkspace\\waterTransfer\\src\\main\\java\\com\\jc\\transfer\\utils\\dllDemo.dll");
    }
5. cmake
# 设置项目名称和 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)
project(MyJavaCppProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 指定头文件目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 设置源文件
set(SOURCES
    src/example.cpp
    src/another_module.cpp
    src/other_module.cpp
)
file(GLOB SOURCES "src/*.cpp")

# 生成共享库 (dll/dylib)
if(WIN32)
    add_library(example SHARED ${SOURCES})
    target_link_libraries(example jvm)  # 链接 JNI 库
elseif(APPLE)
    add_library(example SHARED ${SOURCES})
else()
    add_library(example SHARED ${SOURCES})
    target_link_libraries(example jvm)  # 链接 JNI 库
endif()

# 设置生成的库名称
set_target_properties(example PROPERTIES PREFIX "")