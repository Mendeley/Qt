#!/usr/bin/env python

# This script configures Qt on the current platform
# ready for use with Mendeley Desktop.
#
# Prerequisites:
#
# Linux: build-essential
# OS X: Xcode
# Windows: Visual Studio, nasm, OpenSSL (see comments below)

from __future__ import print_function
import argparse
import os
import sys

parser = argparse.ArgumentParser('Configure Qt for use with Mendeley Desktop')
parser.add_argument('--x64-only', help='Build for 64bit only on Mac', action='store_true', dest='x64_only')
opts = parser.parse_args()

QT_VERSION="4.8.6"

config_args = []

# License args
config_args += ['-opensource', '-confirm-license']

# Component args
config_args += ['-nomake examples', '-nomake demos', '-no-qt3support']
config_args += ['-webkit']

# OpenSSL support on Windows.
#
# OpenSSL is not included as part of Qt and needs to be installed separately
# as follows:
#  1. Get the source for current stable version from openssl.org/source
#  2. Untar and follow the instructions in the INSTALL.W32 file
#     to build with MSVC, setting the prefix to C:\Qt\openssl
#  3. Verify that the libraries and includes were installed to the expected
#     locations
if sys.platform == 'win32':
    openssl_inc_path = 'C:\Qt\openssl\include'
    openssl_lib_path = 'C:\Qt\openssl\lib'

    if not os.path.exists(openssl_inc_path) or \
       not os.path.exists(openssl_lib_path):
        print('OpenSSL build not found in %s' % openssl_inc_path, file=sys.stderr)
        sys.exit(1)

    config_args += ['-openssl', '-I %s' % openssl_inc_path, '-L %s' % openssl_lib_path]

# OS X arch args
if sys.platform == 'darwin':
    # Release builds need to support 32 and 64bit Intel Macs.
    # For local development builds, x64 only will be faster
    config_args += ['-arch x86_64']
    if not opts.x64_only:
        config_args += ['-arch x86']
    config_args += ['-debug-and-release']

# Spec args
if sys.platform == 'win32':
    config_args += ['-platform win32-msvc2013']

# Prefix arg
prefix = ''
config_script = 'configure'

if sys.platform == 'win32':
    config_script = 'configure.exe'
    prefix = 'C:/Qt/%s' % QT_VERSION
else:
    prefix = '/usr/local/Qt/%s' % QT_VERSION

config_args += ['-prefix %s' % prefix]
src_dir = os.path.dirname(__file__)
config_cmd = '%s/%s %s' % (src_dir, config_script, " ".join(config_args))

print("Running '%s'" % config_cmd)
os.system(config_cmd)
