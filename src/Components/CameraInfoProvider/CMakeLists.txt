# Include the directory itself as a path to include directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

# Create a variable containing all .cpp files:
FILE(GLOB files *.cpp)

# Create an executable file from sources:
ADD_LIBRARY(CameraInfoProvider SHARED ${files})

# Link external libraries
TARGET_LINK_LIBRARIES(CameraInfoProvider ${DisCODe_LIBRARIES} )

# Add another libraries if necessary, for example:
TARGET_LINK_LIBRARIES(CameraInfoProvider ${DisCODe_LIBRARIES} ${OpenCV_LIBS} )

INSTALL_COMPONENT(CameraInfoProvider)
