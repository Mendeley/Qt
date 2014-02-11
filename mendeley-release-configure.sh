#!/bin/sh

QT_VERSION=4.8.6
#SDK_ARG=-sdk /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk 

if [ -z "$ARCH_ARGS" ]
then
	ARCH_ARGS="-arch x86_64 -arch x86"
fi

if [ -z "$BUILD_TYPE_ARGS" ]
then
	BUILD_TYPE_ARGS="-debug-and-release"
fi

LICENSE_ARGS="-opensource -confirm-license"
COMPONENT_ARGS="-nomake examples -nomake demos -no-qt3support"
CONFIGURE_ARGS="$BUILD_TYPE_ARGS $COMPONENT_ARGS $ARCH_ARGS -prefix /usr/local/Qt/$QT_VERSION $SDK_ARG $LICENSE_ARGS"
SRC_DIR=$( dirname $0 )

if [ "$#" -gt 0 ]; then
  $SRC_DIR/configure $CONFIGURE_ARGS "$@"
else
  $SRC_DIR/configure $CONFIGURE_ARGS
fi
