#!/bin/sh
if [ "$#" -gt 0 ]; then
  ./configure -nomake examples -nomake demos -no-qt3support -arch x86_64 -arch x86 -prefix /usr/local/Qt/4.8.1 -confirm-license "$@"
else
  ./configure -nomake examples -nomake demos -no-qt3support -arch x86_64 -arch x86 -prefix /usr/local/Qt/4.8.1 -confirm-license
fi
