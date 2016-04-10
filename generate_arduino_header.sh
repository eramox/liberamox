# this script will copy a tree of files and strip all header files

# The first parameter shall be the path to copy from
header_folder="arduino_headers/"
pattern="\.h"

# delete destination and copy tree
echo "Deleting "$header_folder
rm -R $header_folder
mkdir $header_folder

echo "Copying "$1" to "$header_folder
# We are doing a full copy because I could not find a way to simply copy files
# necessary keeping the folder organization
cp -R $1 $header_folder

# strip header file
echo "Stripping files"
find $header_folder -type f | grep -iv "$pattern" | xargs -i rm {}

echo "Done"
