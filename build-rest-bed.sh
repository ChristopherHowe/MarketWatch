#git clone --recursive https://github.com/corvusoft/restbed.git
mkdir restbed/build
cd restbed/build
cmake -DBUILD_SSL=NO -DBUILD_TESTS=NO ..
make install
make test

cd ..
cp distribution/include* /usr/local/include
cp distribution/library* /usr/local/lib
ldconfig # responsible for refreshing the libraries after reloaded
echo copied distribution include and library into /usr/local