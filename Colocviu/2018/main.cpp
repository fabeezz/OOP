#include <iostream>
using  namespace  std;
class Stream{
public:
    friend istream& operator>>(istream& in, Stream& s);
    friend ostream& operator<<(ostream& out, const Stream& s);
    virtual void read(istream& in) = 0;
    virtual void print(ostream& out) const = 0;
};

istream &operator>>(istream &in, Stream &s) {
    s.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Stream &s) {
    s.print(out);
    return out;
}

//################################

class Companie{
    string denumire;
    unsigned int codFisal;
    float tarif;
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
