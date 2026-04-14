#include <iostream>
#include <string>

void make_matrix(int size = 3)
{
    std::clog << "Making matrix..." << std::endl;
}

class User {
public:
    User(std::string name) : name(name) {}  
private:
    std::string name;
};

int main() {
    
    std::cout << "Hello Server!" << std::endl;

    User user("Alice"); 
    
    int matrix_size = (int)5.0;

    make_matrix(10);

    return 0;
}