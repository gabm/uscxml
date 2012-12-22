FIND_PATH(GLOG_INCLUDE_DIR glog/logging.h
  PATH_SUFFIXES include src
  PATHS
  /usr/local
  /usr
  /sw # Fink
  /opt/local # DarwinPorts
  /opt/csw # Blastwave
  /opt
  HINTS $ENV{GLOG_SRC}
)

FIND_LIBRARY(GLOG_LIBRARY_RELEASE
  NAMES glog libglog_static
  HINTS $ENV{GLOG_SRC}/.libs/
)
if (GLOG_LIBRARY_RELEASE)
	list(APPEND GLOG_LIBRARY optimized ${GLOG_LIBRARY_RELEASE})
endif()

FIND_LIBRARY(GLOG_LIBRARY_DEBUG
  NAMES glog libglog_static_d
  HINTS $ENV{GLOG_SRC}/.libs/
)
if (GLOG_LIBRARY_DEBUG)
	list(APPEND GLOG_LIBRARY debug ${GLOG_LIBRARY_DEBUG})
endif()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GLOG DEFAULT_MSG GLOG_LIBRARY GLOG_INCLUDE_DIR)
MARK_AS_ADVANCED(GLOG_LIBRARY GLOG_INCLUDE_DIR)