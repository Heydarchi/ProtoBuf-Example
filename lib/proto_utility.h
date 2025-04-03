#include<fstream>
#include <iostream>
#include "message.pb.h"

using namespace std;

namespace proto_example{
class ProtoUtility{

public:
    ProtoUtility(){}

    bool readFromFile(const char* filename, Message* msg){
            fstream  ifile(filename, ios::binary | ios::in);
            if (!msg->ParseFromIstream(&ifile)) {
                cerr << "Failed to parse Message." << endl;
                return -1;
            }
            cout<<"Read successfully !"<<endl;
            return true;

    }

    bool writeToFile(const char* filename, Message* msg){
            fstream  ofile(filename, ios::binary | ios::out  | ios::trunc);
            if (!msg->SerializeToOstream(&ofile)) {
                cerr << "Failed to write Message." << endl;
                return false;
            }
            cout<<"Written successfully !"<<endl;
            return true;

    }


};
}