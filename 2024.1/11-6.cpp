#include <iostream>
#include <fstream>
using namespace std;

class Dog {
public:
    int weight;
    int age;

    Dog() : weight(0), age(0) {}

    Dog(int w, int a) : weight(w), age(a) {}

    void writeToFile(const string &filename) {
        ofstream file(filename);
        file << weight << " " << age;
        file.close();
    }

    void writeToBinaryFile(const string &filename) {
        ofstream file(filename, ios::binary);
        file.write(reinterpret_cast<char*>(&weight), sizeof(weight));
        file.write(reinterpret_cast<char*>(&age), sizeof(age));
        file.close();
    }

    void readFromFile(const string &filename) {
        ifstream file(filename);
        file >> weight >> age;
        file.close();
    }

    void readFromBinaryFile(const string &filename) {
        ifstream file(filename, ios::binary);
        file.read(reinterpret_cast<char*>(&weight), sizeof(weight));
        file.read(reinterpret_cast<char*>(&age), sizeof(age));
        file.close();
    }
};

int main() {
    Dog dog1(5, 10);
    Dog dog2;

    // 使用文本方式写入和读取
    dog1.writeToFile("dog.txt");
    dog2.readFromFile("dog.txt");

    // 使用二进制方式写入和读取
    dog1.writeToBinaryFile("dog_binary.txt");
    dog2.readFromBinaryFile("dog_binary.txt");

    return 0;
}
