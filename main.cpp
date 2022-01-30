#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;



int main () {
    // first generate all the possible ascii characters
    string asci = "";
    char x;
    for (int i = 33; i < 127; ++i) {
        x = i;
        asci.append(1, x);
    }

    // Open pass.txt if exit else create it
    fstream file;
    file.open ("pass.txt", ios::app | ios::out);
    
    // check if error occured
    if (!file){
        cout << "error occured!" << endl;
    } else{
        // if no error occured generate 100 passwords
        int i = 100000;
        srand(time(NULL)); // set the seed to the current time
        
        while (i > 0)
        {
            // size of password random between 8 and 12
            int size = rand()%5 + 8;

            // password saved to this string
            string toBeSaved = "";

            for (int i = 0; i < size; i++)
                toBeSaved.append(1, asci[rand()%(asci.length())]);

            
            // string written to file
            file << toBeSaved << endl;
            i--;
        }
        file.close(); // file closed
    }  
}