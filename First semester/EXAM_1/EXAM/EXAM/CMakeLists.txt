cmake_minimum_required(VERSION 3.21) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME EXAM)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("inc/")
include_directories("src/")
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" EXAM.cpp 
								inc/Map.hpp 
								src/Map.cpp 
								src/Game.cpp
								inc/Game.hpp
								inc/Menu.hpp
								inc/Button.hpp
								src/Functions.cpp 
								inc/Functions.hpp)
											
target_link_libraries("${PROJECT_NAME}" 
                          sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
						  
target_link_libraries("${PROJECT_NAME}" 
					    debug sfml-graphics-s-d 
						debug sfml-window-s-d
						debug sfml-system-s-d
						debug sfml-audio-s-d)
						
target_link_libraries("${PROJECT_NAME}" 
					    optimized sfml-graphics-s 
						optimized sfml-window-s
						optimized sfml-system-s
						optimized sfml-audio-s)
	
file(COPY "images" DESTINATION "/")
file(COPY "fonts" DESTINATION "/")


					  

