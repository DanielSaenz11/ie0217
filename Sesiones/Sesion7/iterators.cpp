

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> languages = {"Python", "C++", "Java"};
    
    vector<string>::iterator itr;

    // Iterar sobre todos los elementos
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", ";
    }

    return 0;
}