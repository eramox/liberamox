build_success=1
test_success=1

sh ./runBuild.sh "-DCONTINUOUS_INTEGRATION_BUILD=ON -DBUILD_LIB_TEST=ON"
build_success=$?
sh ./runTest.sh
test_success=$?

echo "build_success: "$build_success " test_success: "$test_success

if [ "$build_success" -eq 0 ]
then
	if [ "$test_success" -eq 0 ]
	then
		echo "No errors"
		exit 0
	else
		echo "Error detected"
		exit 1
	fi
else
	echo "Error detected"
	exit 1
fi
