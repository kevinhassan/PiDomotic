echo "Compilation du programme en cours ..."
g++ $1 -o $2 ` pkg-config --cflags --libs opencv`
echo "Compilation du programme termin√e avec succ√s"
