#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student {
    string name;
    int age;
    double mark;
public:
    Student() {
        name = "dodik";
        age = 69;
        mark = 6.9;
    }

    void Writer() {
        ofstream outFile("StudentFile", ios::binary);
        if (!outFile) {
            cerr << "Error while openning file.\n";
        }
        outFile.write(reinterpret_cast<const char*>(&age), sizeof(age));
        outFile.write(reinterpret_cast<const char*>(&mark), sizeof(mark));

        size_t messageSize = name.size();
        outFile.write(reinterpret_cast<const char*>(&messageSize), sizeof(messageSize));
        outFile.write(name.c_str(), messageSize);
        outFile.close();
    }

    void Reader() {
        ifstream inFile("StudentFile", ios::binary);
        if (!inFile) {
            cerr << "Error while readding.\n";
        }

        int readAge;
        double readMark;
        size_t readMessageSize;
        string readMessage;

        inFile.read(reinterpret_cast<char*>(&readAge), sizeof(readAge));
        inFile.read(reinterpret_cast<char*>(&readMark), sizeof(readMark));

        inFile.read(reinterpret_cast<char*>(&readMessageSize), sizeof(readMessageSize));
        readMessage.resize(readMessageSize);
        inFile.read(&readMessage[0], readMessageSize);

        inFile.close();


        cout << "Info from file:\n";
        cout << "Age: " << readAge << "\n";
        cout << "Mark: " << readMark << "\n";
        cout << "Message: " << readMessage << "\n";
    }
};

int main()
{
    Student st;
    st.Writer();
    st.Reader();

    //const string filename = "example.bin";
    //
    //int number = 42;
    //double pi = 3.14159;
    //string message = "Hello, binary file!";
    //
    //ofstream outFile(filename, ios::binary);
    //if (!outFile) {
    //    cerr << "Error while openning file.\n";
    //    return 1;
    //}
    //
    //outFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
    //outFile.write(reinterpret_cast<const char*>(&pi), sizeof(pi));
    //
    //size_t messageSize = message.size();
    //outFile.write(reinterpret_cast<const char*>(&messageSize), sizeof(messageSize));
    //outFile.write(message.c_str(), messageSize);
    //
    //outFile.close();
    //cout << "Info successfully.\n";
    //
    //ifstream inFile(filename, ios::binary);
    //if (!inFile) {
    //    cerr << "Error while readding.\n";
    //    return 1;
    //}
    //
    //int readNumber;
    //double readPi;
    //size_t readMessageSize;
    //string readMessage;
    //
    //inFile.read(reinterpret_cast<char*>(&readNumber), sizeof(readNumber));
    //inFile.read(reinterpret_cast<char*>(&readPi), sizeof(readPi));
    //
    //inFile.read(reinterpret_cast<char*>(&readMessageSize), sizeof(readMessageSize));
    //readMessage.resize(readMessageSize);
    //inFile.read(&readMessage[0], readMessageSize);
    //
    //inFile.close();
    //
    //cout << "Info from file:\n";
    //cout << "Number: " << readNumber << "\n";
    //cout << "Number Pi: " << readPi << "\n";
    //cout << "Message: " << readMessage << "\n";
    //
    //return 0;



}