#include <iostream>

using namespace std;

int main(int argc,char** argv) {

    if(argc<2) {
        cout << "Usage: hello <name>" << endl;
        return 1;
    } else {
        cout << "Hello, " << argv[1] << endl;
        return 0;
    }
}