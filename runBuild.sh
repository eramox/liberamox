cd liberamox
mkdir build
cd build
echo "Running cmake with following parameters: "$1
cmake $1 .. && cmake --build .
ret=$?
echo "Build finished"
exit $ret
