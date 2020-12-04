cmake_minimum_required(VERSION 3.18)

project(obs-basic)


set(obs-basic_SOURCES
	https-server.c
	obs-basic.c	
	)

add_library(obs-basic MODULE
	${obs-basic_SOURCES})

include_directories(
	${LIBOBS_INCLUDE_DIR}	
)

target_link_libraries(obs-basic
	${LIBOBS_LIB}	
	${obs-basic_PLATFORM_DEPS})
# set_target_properties(image-source PROPERTIES FOLDER "plugins")

# install_obs_plugin_with_data(image-source data)
