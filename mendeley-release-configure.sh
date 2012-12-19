#!/bin/sh
if [ "$#" -gt 0 ]; then
  ./configure -nomake examples -nomake demos -no-qt3support -arch x86_64 -arch x86 -prefix /usr/local/Qt/4.8.1 -sdk /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -confirm-license "$@"
else
  ./configure -nomake examples -nomake demos -no-qt3support -arch x86_64 -arch x86 -prefix /usr/local/Qt/4.8.1 -sdk /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.6.sdk -confirm-license
fi
