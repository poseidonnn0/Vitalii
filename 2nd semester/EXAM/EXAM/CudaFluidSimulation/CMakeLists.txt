cmake_minimum_required(VERSION 3.21) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

#set(PROJECT_NAME EXAM)				 # имя проекта		 
#project("${PROJECT_NAME}")
project(MY_PROJECT LANGUAGES CUDA CXX)
enable_language(CUDA)

include(CheckLanguage)
check_language(CUDA)
find_package(CUDAToolkit)

set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
							
add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("C:/SFML/include/")	# добавляем директории
include_directories("/")
link_directories("C:/SFML/lib/")

add_executable(MY_PROJECT Source.cpp 
								kernel.cu
								CudaFluidSimulation.vcxproj)
								
target_link_libraries(MY_PROJECT CUDA::cudart CUDA::cublas CUDA::cufft CUDA::cusolver CUDA::curand CUDA::nppicc CUDA::nppial CUDA::nppist CUDA::nppidei CUDA::nppig CUDA::nppitc CUDA::npps)
											
target_link_libraries(MY_PROJECT 
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