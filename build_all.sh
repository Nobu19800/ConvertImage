#!/bin/sh
cd `dirname $0`
cmake ./ -G "%VC%" -DEIGEN_DIRECTORIY="%EIGEN_DIRECTORIY%" -DODE_DIRECTORIY="%ODE_DIRECTORIY%" -DQWT_DIRECTORIY="%QWT_DIRECTORIY%" -DLUABIND_PATH="%LUABIND_PATH%"
cmake --build . --config %BuildType%
