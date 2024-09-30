#include <iostream>  
using namespace std;

class Reservoir {
private:
    char name[50];
    double width;  
    double length; 
    double maxDepth;
    char type[20]; 

public:

    Reservoir() {
        name[0] = '\0';
        width = 0;
        length = 0;
        maxDepth = 0;
        type[0] = '\0';  
    }

   
    explicit Reservoir(const char* name, double width, double length, double maxDepth, const char* type) {
        setName(name);
        this->width = width;
        this->length = length;
        this->maxDepth = maxDepth;
        setType(type);
    }

   
    ~Reservoir() {}

    
    Reservoir(const Reservoir& other) {
        setName(other.name);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        setType(other.type);
    }

    
    double getVolume() const {
        return width * length * maxDepth;
    }

   
    double getSurfaceArea() const {
        return width * length;
    }

  
    bool isSameType(const Reservoir& other) const {
        return strcmp(type, other.type) == 0;
    }

   
    bool compareSurfaceArea(const Reservoir& other) const {
        if (!isSameType(other)) {
            cout << "Reservoirs are of different types." << endl;
            return false;
        }
        return getSurfaceArea() > other.getSurfaceArea();
    }

   
    void copy(const Reservoir& other) {
        setName(other.name);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        setType(other.type);
    }

    
    void setName(const char* name) {
        strncpy(this->name, name, sizeof(this->name) - 1);
        this->name[sizeof(this->name) - 1] = '\0';
    }

  
    const char* getName() const {
        return name;
    }

   
    void setType(const char* type) {
        strncpy(this->type, type, sizeof(this->type) - 1);
        this->type[sizeof(this->type) - 1] = '\0'; 
    }

    
    const char* getType() const {
        return type;
    }

   
    void display() const {
        cout << "Reservoir Name: " << getName() << endl;
        cout << "Width: " << width << ", Length: " << length << ", Max Depth: " << maxDepth << endl;
        cout << "Type: " << getType() << endl;
    }
};


int main() {
    Reservoir r1("Lake Superior", 300, 500, 72, "Lake");
    Reservoir r2("Lake Michigan", 200, 400, 40, "Lake");

    r1.display();
    r2.display();

   cout << "Volume of r1: " << r1.getVolume() << endl;
    cout << "Surface Area of r1: " << r1.getSurfaceArea() << endl;

    if (r1.isSameType(r2)) {
        cout << "r1 and r2 are of the same type." << endl;
    }
    else {
        cout << "r1 and r2 are of different types." <<endl;
    }

    return 0;
}