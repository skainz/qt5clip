cmake_minimum_required(VERSION 3.4.0)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED Core Widgets Xml)


# Set up static builds

if(MSVC)
  option(BUILD_STATIC "Build static binary" ON)
  if(BUILD_STATIC)
    message("Building static binary")
    foreach(flag_var CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE)
      if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
      endif(${flag_var} MATCHES "/MD")
    endforeach(flag_var)
  endif(BUILD_STATIC)

find_package(OpenGL)
SET (MSVC_STATIC_LIBS imm32.lib Ws2_32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib version.lib winmm.lib Netapi32.lib userenv.lib ws2_32.lib iphlpapi.lib dwmapi.lib d3d9.lib dxguid.lib)
SET (MSVC_QT5_EXTRA_STATIC_LIBS
    "${_qt5Widgets_install_prefix}/lib/Qt5fontdatabasesupport.lib"
	"${_qt5Widgets_install_prefix}/lib/Qt5eventdispatchersupport.lib"
	"${_qt5Widgets_install_prefix}/lib/Qt5themesupport.lib"
	"${_qt5Widgets_install_prefix}/lib/qt5accessibilitysupport.lib"
	"${_qt5Widgets_install_prefix}/lib/qtpcre2.lib"
	"${_qt5Widgets_install_prefix}/lib/qtlibpng.lib"
	"${_qt5Widgets_install_prefix}/lib/qtharfbuzz.lib"
	"${_qt5Widgets_install_prefix}/lib/preprocessor.lib"
	"${_qt5Widgets_install_prefix}/lib/qtfreetype.lib"
	"${_qt5Widgets_install_prefix}/lib/libglesv2.lib"
	"${_qt5Widgets_install_prefix}/lib/libegl.lib"
	"${_qt5Widgets_install_prefix}/lib/translator.lib"
)
endif(MSVC)


add_executable(getclip
  getclip.cpp
  ${RESOURCES}
)
target_link_libraries(getclip
  Qt5::Widgets Qt5::QOffscreenIntegrationPlugin Qt5::QWindowsIntegrationPlugin 
  Qt5::QMinimalIntegrationPlugin ${MSVC_QT5_EXTRA_STATIC_LIBS} ${MSVC_STATIC_LIBS}
)

