This is a Tool For Display Of 3D Data Interfacing with Any Camera
===================================================================

# 3DCameraViewer
Library for rendering of 3d images built as Release 
	* cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="F:/solve/3DCameraViewer/install"  -DCMAKE_PREFIX_PATH="F:/solve/3DCameraViewer/install" ..
	* cmake --build . --config Release --clean-first --target install
	
# external/zlib
Library for compression
	* cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX="F:/solve/3DCameraViewer/install"
	* cmake --build . --config Release --clean-first --target install
	
# Examples
Examples for OSG 
	* cmake -DCMAKE_PREFIX_PATH="F:\solve\3DCameraViewer\install" -DCMAKE_INSTALL_PREFIX="F:\solve\3DCameraViewer\install" ..
	* cmake --build . --config Release --clean-first --target install