echo "Compilation du programme en cours ..."
g++ $1 -o $2 -I/usr/local/include/ -lopencv_core -lopencv_highgui
echo "Compilation du programme termin√e avec succ√s"
