#------------------------------------------------------------------------------#
# Copyright (c) 2014 Los Alamos National Security, LLC
# All rights reserved.
#------------------------------------------------------------------------------#

from cmakelists import cmakelists_template

import os
import shutil
import subprocess
import sys
import tempfile

def execute(verbose, debug, build):

    """
    """

    # Create a temporary directory for the build
    cwd = os.getcwd()
    tmpdir = tempfile.mkdtemp(dir=cwd)
    os.chdir(tmpdir)

    # Do substitutions to create the CMakeLists.txt file
    cmakelists_txt = cmakelists_template.substitute(
        CMAKE_MINIMUM_REQUIRED='2.8',
        PROJECT='flecsit_compile_' + build['deck'],
        TARGET=build['deck'],
        DRIVER=cwd + '/' + build['driver'],
        FLECSI_RUNTIME_MAIN=build['main'],
        FLECSI_RUNTIME_DRIVER=build['prefix'] +
            '/share/FleCSI/runtime/runtime_driver.cc',
        INSTALL_PREFIX=cwd,
        FLECSI_DEFINES=build['defines'],
        FLECSI_LIBRARIES=build['libraries']
    )

    fd = open('CMakeLists.txt', 'w')
    fd.write(cmakelists_txt[1:-1])
    fd.close()

    if verbose:
        devnull = None
    else:
        devnull = open(os.devnull, 'w')

    # Setup compiler and flags
    cxx_compiler = '-DCMAKE_CXX_COMPILER=' + build['compiler']
    cxx_flags = '-DCMAKE_CXX_FLAGS=' + build['flags']

    # Call CMake and make to build the example
    subprocess.call(['/usr/bin/cmake', cxx_compiler, cxx_flags, '.'],
        stdout=devnull, stderr=devnull)
    subprocess.call(['/usr/bin/make', 'install'], stdout=devnull,
        stderr=devnull)

    if not debug:
        shutil.rmtree(tmpdir)
# execute

#------------------------------------------------------------------------------#
# Formatting options for vim.
# vim: set tabstop=4 shiftwidth=4 expandtab :
#------------------------------------------------------------------------------#
