ADD_EXECUTABLE(argcv_seed main.cc)

ADD_DEPENDENCIES(argcv_seed argcv)


# http://www.gnu.org/software/libc/manual/html_node/Feature-Test-Macros.html#index-_005fPOSIX_005fSOURCE 
#ADD_DEFINITIONS( " -D_POSIX_SOURCE ") 
#INCLUDE(ExternalProject) # IF NEED EXTEND PROJECT
#INCLUDE(ExternalLeveldb)
#MESSAGE(STATUS "$$$$$$$$$$ INCLUDE LEVELDB DIR " ${LEVELDB_INCLUDE_DIR})
#INCLUDE_DIRECTORIES(${LEVELDB_INCLUDE_DIR})

TARGET_LINK_LIBRARIES(argcv_seed argcv_static)
TARGET_LINK_LIBRARIES(argcv_seed argcv_sys_static)
TARGET_LINK_LIBRARIES(argcv_seed argcv_wrapper_leveldb_static)
TARGET_LINK_LIBRARIES(argcv_seed pthread)

#  executable properties
SET_TARGET_PROPERTIES(argcv_seed PROPERTIES OUTPUT_NAME "argcv_seed")





