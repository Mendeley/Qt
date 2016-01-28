SOURCES = openssl.cpp
CONFIG -= x11 qt
mac:CONFIG -= app_bundle

    CONFIG(debug, debug|release) {
        LIBS_PRIVATE += $$OPENSSL_LIBS_DEBUG
    } else {
        LIBS_PRIVATE += $$OPENSSL_LIBS_RELEASE
    }

    LIBS_PRIVATE += $$OPENSSL_LIBS

include(openssl.pri)
