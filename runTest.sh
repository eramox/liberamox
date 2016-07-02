echo "Starting test"

# moving to test folder
cd liberamox/build/testing

# Google test
if [ $run_gtest -eq 1 ]; then
echo "Running GTest:"
./completetestlib
res_gtest=$?
fi

cd -
echo "Test Finished"

exit $res_gtest

if [ "$1" == "" ]
then
	echo "no parameter, executing all";
	run_gtest=1;
else
	if [ "$1" == "--gtest" ]
	then
		run_gtest=1;
fi

