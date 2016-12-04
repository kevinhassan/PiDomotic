echo "Compilation du programme en cours ..."
g++ openCam.cpp -o openCam -I/usr/local/include/ -lraspicam -lraspicam_cv -lopencv_core -lopencv_highgui
echo "Compilation du programme termin√e avec succ√s"
