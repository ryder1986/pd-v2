export LD_LIBRARY_PATH=/root/repo-github/libs/third-party/opencv/opencv-linux-x86/lib
rm -rf * ; cd .. ;make ; make install ; cp client install ; cd install ;./client
