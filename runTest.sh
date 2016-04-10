echo "Starting test"

run_ctest=1
run_gtest=1

res_ctest=0
res_gtest=0

# moving to test folder
cd liberamox/build/testing

# Cmake Test
if [ $run_ctest -eq 1 ]; then
echo "Running CTest:"
ctest
res_ctest=$?
fi

# Google test
if [ $run_gtest -eq 1 ]; then
echo "Running GTest:"
./completetestlib
res_gtest=$?
fi

cd -
echo "Test Finished"

exit $res_ctest + $res_gtest

if [ "$1" == "" ]
then
	echo "no parameter, executing all";
	run_ctest=1;
	run_gtest=1;
else
	if [ "$1" == "--gtest" ]
	then
		run_gtest=1;
	elif [ "$1" == "--ctest" ]
	then
		run_ctest=1;
	fi
fi

