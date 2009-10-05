#################################################
###           INSTALL 						  ###
#################################################
GET_FILENAME_COMPONENT(GILVIEWER_CMAKE_SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)

IF(UNIX)
	SET(INSTALL_PREFIX "/usr/local" CACHE PATH " install path" )
	SET(GilViewer_INSTALL_PATH ${INSTALL_PREFIX})
	SET(GilViewer_INCLUDE_PATH ${INSTALL_PREFIX}/include/GilViewer)
	SET(shapelib_INCLUDE_PATH ${INSTALL_PREFIX}/include/shapelib)
	SET(tinyxml_INCLUDE_PATH ${INSTALL_PREFIX}/include/tinyxml)
	SET(RELATIVE_INCLUDE_PATH "../../include/GilViewer")
	SET(RELATIVE_INCLUDE_PATH_TINYXML "../../include/tinyxml")
	SET(RELATIVE_INCLUDE_PATH_SHAPELIB "../../include/shapelib")
	SET(TARGET_CONFIG_INSTALL_PATH ${INSTALL_PREFIX}/lib/GilViewer)
ENDIF(UNIX)
IF(WIN32)
	SET(GilViewer_INSTALL_DIR "GilViewer")
	SET(INSTALL_PREFIX "C:/Program Files/MATIS" CACHE PATH " install path")
	SET(GilViewer_INSTALL_PATH ${INSTALL_PREFIX}/${GilViewer_INSTALL_DIR})
	SET(GilViewer_INCLUDE_PATH ${INSTALL_PREFIX}/${GilViewer_INSTALL_DIR}/include)
	SET(shapelib_INCLUDE_PATH ${GilViewer_INSTALL_PATH}/../shapelib/include)
	SET(tinyxml_INCLUDE_PATH ${GilViewer_INSTALL_PATH}/../tinyxml/include)
	SET(RELATIVE_INCLUDE_PATH "../GilViewer/include")
	SET(RELATIVE_INCLUDE_PATH_TINYXML "../tinyxml/include")
	SET(RELATIVE_INCLUDE_PATH_SHAPELIB "../shapelib/include")
	SET(TARGET_CONFIG_INSTALL_PATH ${INSTALL_PREFIX}/cmake)
ENDIF(WIN32)
SET(CMAKE_INSTALL_PREFIX ${INSTALL_PREFIX} CACHE INTERNAL  " real install path" FORCE)

SET(export_lib "")
SET(GilViewer_SHAPELIB_SHARED ON)
SET(GilViewer_TINYXML_SHARED ON)

IF( BUILD_GILVIEWERLIB_SHARED )
	MESSAGE(STATUS " INSTALL : libGilViewer Shared ")
	SET( export_lib GilViewer )
ELSE(BUILD_GILVIEWERLIB_SHARED)
	MESSAGE(STATUS " INSTALL : libGilViewer Static ")
ENDIF(BUILD_GILVIEWERLIB_SHARED)

IF( BUILD_SHAPELIB_SHARED )
	MESSAGE(STATUS " INSTALL : libshapelib Shared ")
	SET( export_lib ${export_lib} shapelib )
	MESSAGE(STATUS " ALL_SHPLIB_INC_FILES" ${ALL_SHPLIB_INC_FILES})
	INSTALL(FILES ${ALL_SHPLIB_INC_FILES} DESTINATION ${shapelib_INCLUDE_PATH})
ELSE(BUILD_SHAPELIB_SHARED)
	MESSAGE(STATUS " INSTALL : libshapelib Static ")
	SET(GilViewer_SHAPELIB_SHARED OFF)
ENDIF(BUILD_SHAPELIB_SHARED)

IF( BUILD_TINYXML_SHARED )
	MESSAGE(STATUS " INSTALL : libtinyxml Shared ")
	SET( export_lib ${export_lib} tinyxml )
	MESSAGE(STATUS " ALL_TINYXML_INC_FILES" ${ALL_TINYXML_INC_FILES})
	INSTALL(FILES ${ALL_TINYXML_INC_FILES} DESTINATION ${tinyxml_INCLUDE_PATH})
ELSE(BUILD_TINYXML_SHARED)
	MESSAGE(STATUS " INSTALL : libtinyxml Static ")
	SET(GilViewer_TINYXML_SHARED OFF)
ENDIF(BUILD_TINYXML_SHARED)



CONFIGURE_FILE(${GILVIEWER_CMAKE_SELF_DIR}/GilViewerConfig.cmake.in ${CMAKE_CURRENT_SOURCE_DIR}/GilViewerConfig.cmake @ONLY)
#install header of gilviewer
INSTALL(FILES ${ALL_CONVENIENT_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/convenient)
INSTALL(FILES ${ALL_GUI_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/gui )
INSTALL(FILES ${ALL_GUI_WXFB_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/gui/wxFB )
INSTALL(FILES ${ALL_IO_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/io )
INSTALL(FILES ${ALL_LAYERS_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/layers )
INSTALL(FILES ${ALL_TOOLS_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/tools )
INSTALL(FILES ${ALL_VECTORUTILS_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/vectorutils )
INSTALL(FILES ${ALL_WRAPPERS_HEADER_FILES} DESTINATION ${GilViewer_INCLUDE_PATH}/wrappers )
#install lib and export target
INSTALL (TARGETS ${export_lib} EXPORT GilViewer-targets DESTINATION ${GilViewer_INSTALL_PATH}/lib COMPONENT library ) 

#install config file
INSTALL (EXPORT GilViewer-targets DESTINATION ${TARGET_CONFIG_INSTALL_PATH} )
INSTALL (FILES GilViewerConfig.cmake DESTINATION ${TARGET_CONFIG_INSTALL_PATH})
