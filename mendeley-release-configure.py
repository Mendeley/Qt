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

QT_VERSION="4.8.7"
OPENSSL_VERSION="1.0.2f"

parser = argparse.ArgumentParser('Configure Qt 4 for use with Mendeley Desktop')
parser.add_argument('--x64-only', help='Build for 64bit only on Mac', action='store_true', dest='x64_only')
opts = parser.parse_args()

if sys.platform == 'win32':
    staging_dir = 'c:\mendeley\desktop'
    configure_script = 'configure.exe'
else:
    staging_dir = '/opt/mendeley/desktop'
    configure_script = 'configure'

destdir = os.path.join(staging_dir, 'Qt', QT_VERSION)

# basic arguments:
config_args = [
    '-opensource',
    '-confirm-license',
    '-nomake examples',
    '-nomake demos',
    '-no-qt3support',
    '-webkit',
    '-prefix',
    destdir]


# Adding SSL:
openssl_path = os.path.join(staging_dir, 'openssl', OPENSSL_VERSION)
os.environ['OPENSSL_LIBS'] = '-L%s -lssl -lcrypto' % os.path.join(openssl_path, 'lib')
if not os.path.exists(openssl_path):
    print('OpenSSL build not found in %s' % openssl_path, file=sys.stderr)
    sys.exit(1)

config_args += [
    '-openssl-linked',
    '-I',
    os.path.join(openssl_path, 'include')]

# OS X arch args
if sys.platform == 'darwin':
    # Release builds need to support 32 and 64bit Intel Macs.
    # For local development builds, x64 only will be faster
    config_args += ['-arch x86_64']
    if not opts.x64_only:
        config_args += ['-arch x86']
    config_args += [
        '-debug-and-release',
        '-platform',
        'unsupported/macx-clang']

# Spec args
if sys.platform == 'win32':
    config_args += [
        '-platform',
        'win32-msvc2013']

src_dir = os.path.dirname(__file__)
config_cmd = '%s %s' % (os.path.join(src_dir, configure_script), " ".join(config_args))

print("Running '%s'" % config_cmd)
os.system(config_cmd)
