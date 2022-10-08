#include <fstream>
#include <iostream>
#include "lib/message.pb.h"
#include "lib/proto_utility.h"


using namespace std;
using namespace proto_example;

int main(){
    cout<<"ProtoBuf example starting ..."<<endl;

    Message msg;
    Message msg_read;
    ProtoUtility protoUtility;

    msg.set_id(2);
    msg.set_title("TestMessage");
    msg.set_date_time("2022-10-08");
    msg.set_sender_name("M.H.H");
    msg.set_priority(Message_Priority::Message_Priority_REGULAR);

    Message_OtherReceiver* receiver1=msg.add_receivers();
    receiver1->set_receiver_name("PersonNo-1");
    Message_OtherReceiver* receiver2=msg.add_receivers();
    receiver2->set_receiver_name("PersonNo-2");

    cout<<endl<<"Write to file ..."<<endl;

    protoUtility.writeToFile((const char*)"test.bin",&msg);

    protoUtility.readFromFile((const char*)"test.bin",&msg_read);

    cout<<endl<<"Read from file ..."<<endl;
    cout<<"Title :"<<msg_read.title()<<endl;
    cout<<"Id :"<<msg_read.id()<<endl<<endl;
    cout<<"ReceiverName size :"<<msg_read.receivers_size()<<endl;
    for(int i=0;i<msg_read.receivers_size();i++)
    {
            const Message_OtherReceiver& receiver=msg_read.receivers(i);
            cout<<"receiver_name :"<<receiver.receiver_name()<<endl;
    }

    google::protobuf::ShutdownProtobufLibrary();

}