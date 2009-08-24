CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

################################################
##
## Pour avoir une version release, utiliser la ligne de commande suivante :
##    (c)cmake . -DCMAKE_BUILD_TYPE:STRING=Release
## Pour la version debug (par defaut ...), je vous laisse deviner ;-)
##
################################################

#Nom du projet
PROJECT(GilViewer)
INCLUDE_DIRECTORIES( /usr/local/include /usr/include)

# Ca, je ne sais plus trop a quoi ca sert ... Surement apres un passage a la version 2.6 de cmake ...
IF(COMMAND cmake_policy)
	CMAKE_POLICY(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

####
#### Ajout du fichier contenant les regles de construction des libs externes : shapelib et tinyxml
####
INCLUDE( GilViewer_build_external_lib.cmake )

####
#### Repertoire de sortie de toutes les librairies
####
SET( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

####
#### On recherche tous les fichiers ".h", ".hpp", ".hxx" et "*.inl"
####
FILE( GLOB ALL_CONVENIENT_HEADER_FILES src/convenient/*.h src/convenient/*.hpp src/convenient/*.hxx src/convenient/*.inl )
FILE( GLOB ALL_GUI_HEADER_FILES src/gui/*.h src/gui/*.hpp src/gui/*.hxx src/gui/*.inl )
FILE( GLOB ALL_GUI_BITMAPS_HEADER_FILES src/gui/bitmaps/*.xpm )
FILE( GLOB ALL_GUI_WXFB_HEADER_FILES src/gui/wxFB/*.h src/gui/wxFB/*.hpp src/gui/wxFB/*.hxx src/gui/wxFB/*.inl )
FILE( GLOB ALL_IO_HEADER_FILES src/convenient/*.h src/convenient/*.hpp src/convenient/*.hxx src/convenient/*.inl )
FILE( GLOB ALL_ITK_HEADER_FILES src/itk/*.h src/itk/*.hpp src/itk/*.hxx src/itk/*.inl )
FILE( GLOB ALL_LAYERS_HEADER_FILES src/layers/*.h src/layers/*.hpp src/layers/*.hxx src/layers/*.inl )
#FILE( GLOB ALL_PLUGINS_HEADER_FILES src/plugins/*.h src/plugins/*.hpp src/plugins/*.hxx src/plugins/*.inl )
FILE( GLOB ALL_TOOLS_HEADER_FILES src/tools/*.h src/tools/*.hpp src/tools/*.hxx src/tools/*.inl )
FILE( GLOB ALL_VECTORUTILS_HEADER_FILES src/vectorutils/*.h src/vectorutils/*.hpp src/vectorutils/*.hxx src/vectorutils/*.inl )
FILE( GLOB ALL_WRAPPERS_HEADER_FILES src/wrappers/*.h src/wrappers/*.hpp src/wrappers/*.hxx src/wrappers/*.inl )
# Une variable regroupant tous les headers
SET( ALL_VIEWER_HEADERS ${ALL_CONVENIENT_HEADER_FILES}
                        ${ALL_GUI_HEADER_FILES}
                        ${ALL_GUI_BITMAPS_HEADER_FILES}
                        ${ALL_GUI_WXFB_HEADER_FILES}
                        ${ALL_IO_HEADER_FILES}
                        #${ALL_ITK_HEADER_FILES}
                        ${ALL_LAYERS_HEADER_FILES}
                        #${ALL_PLUGINS_HEADER_FILES}
                        ${ALL_TOOLS_HEADER_FILES}
                        ${ALL_VECTORUTILS_HEADER_FILES}
                        ${ALL_WRAPPERS_HEADER_FILES} )

#### Definition des dossiers contenant les sources
#### ATTENTION : toutes les sources de ces dossiers seront incluses
#### ATTENTION : si un fichier est ajoute dans un de ces dossiers mais que le CMakeLists.txt n'est pas modifie, il faut relancer le cmake 
####  a la main avant de compiler par make (ca, c'est pas vrai sous windows ! en fait je n'en suis pas si sur ...)
SET(SRC_DIR src/)
#AUX_SOURCE_DIRECTORY(${SRC_DIR}itk  SRC_ITK)
#AUX_SOURCE_DIRECTORY(${SRC_DIR}itk/gdal_reader  SRC_ITK_GDAL)
AUX_SOURCE_DIRECTORY(${SRC_DIR}layers SRC_CALQUES)
AUX_SOURCE_DIRECTORY(${SRC_DIR}convenient SRC_CONVENIENT)
AUX_SOURCE_DIRECTORY(${SRC_DIR}gui SRC_GUI)
AUX_SOURCE_DIRECTORY(${SRC_DIR}tools SRC_OUTILS)
AUX_SOURCE_DIRECTORY(${SRC_DIR}vectorutils SRC_VECTOR_UTILS)
AUX_SOURCE_DIRECTORY(${SRC_DIR}io SRC_IO)
AUX_SOURCE_DIRECTORY(${SRC_DIR}wrappers SRC_WRAPPERS)
AUX_SOURCE_DIRECTORY(${SRC_DIR}gui/wxFB SRC_WXFB)
#AUX_SOURCE_DIRECTORY(${SRC_DIR}plugins SRC_PLUGINS)
# Une variable regroupant toutes les sources ...
SET( ALL_VIEWER_SOURCES 
    #${SRC_ITK} ${SRC_ITK_GDAL}
     ${SRC_CALQUES} ${SRC_CONVENIENT} ${SRC_GUI} ${SRC_OUTILS} ${SRC_VECTOR_UTILS} ${SRC_IO} ${SRC_WRAPPERS} ${SRC_WXFB} ${SRC_PLUGINS} )

#########
##OPTION Pour générer automatiquement VisuITK.cpp avec le bon nombre de canaux
#SET( MAX_NB_CHANNELS_IMAGE "4" CACHE STRING "Max number of channels" )
#CONFIGURE_FILE( ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/itk/config_visu.h.cmake.in ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/itk/config_visu.h @only immediate)


#####################################
### Recherche des packages necessaires a la compilation ###
#####################################
# Find ITK.
#FIND_PACKAGE(ITK REQUIRED)
#IF(ITK_FOUND)
#    INCLUDE(${ITK_USE_FILE})
#ELSE()
#   # For convenience. When we cannot continue, inform the user
#   MESSAGE(FATAL_ERROR "ITK not found ! Please set ITK path ...")
#ENDIF()

#Find wxWidgets
FIND_PACKAGE(wxWidgets REQUIRED adv base core xml aui)
IF(wxWidgets_FOUND)  
	INCLUDE(${wxWidgets_USE_FILE})
ELSE()
	# For convenience. When we cannot continue, inform the user
	MESSAGE(FATAL_ERROR "wxWidgets not found ! Please set wxWidgets path ...")
ENDIF()
		
# Find BOOST
FIND_PACKAGE( Boost 1.34.1 COMPONENTS filesystem system thread )
IF( NOT Boost_FOUND AND UNIX )
	MESSAGE(FATAL_ERROR "Boost not found ! Please set Boost path ...")
ELSE()
	INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIRS} )
ENDIF()
#####################################
###                     Fin recherche des packages                         ###
#####################################

####
#### Construction de la librarie
####
INCLUDE( GilViewer_build_library.cmake )

####
#### Construction du sample
####
INCLUDE( GilViewer_build_sample.cmake )
		
# Ajout du repertoire d'include des lib externes (pour l'instant,  shapelib et tinyxml)
INCLUDE_DIRECTORIES( ${INCLUDE_DIRECTORIES} "extern/" )
# Ajout du repertoire d'include des sources du viewer
INCLUDE_DIRECTORIES( ${INCLUDE_DIRECTORIES} "src/" )

# Ajout d'une dependance du viewer a la shapelib. Ca permet de compiler la shapelib AVANT le viewer ...		
ADD_DEPENDENCIES( GilViewer shapelib )
# Idem pout Tinyxml
ADD_DEPENDENCIES( GilViewer tinyxml )
# Et enfin, le viewer depend de la lib ...
ADD_DEPENDENCIES( GilViewerApp GilViewer )