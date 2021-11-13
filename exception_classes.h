#ifndef exception_classes
#define exception_classes

#include<strstream>
#include<string>

using namespace std;

class baseException{
    public:
    baseException(const string& str = ""):
        msgString(str)
        {
            if(msgString == ""){
                msgString = "Unspecified exception";
            }
        }

        string what() const{
            return msgString;
        }

        protected:
        string msgString;

};

class memoryAllocationError: public baseException{
    public:
    memoryAllocationError(const string& msg = ""): 
        baseException(msg)
        {

        }
};

class QueueEmpty: public baseException{
    public:
    QueueEmpty(const string& msg = ""): 
        baseException(msg)
        {

        }
};

class StackEmpty: public baseException{
    public:
    StackEmpty(const string& msg = ""): 
        baseException(msg)
        {

        }
};

class StackFull: public baseException{
    public:
    StackFull(const string& msg = ""): 
        baseException(msg)
        {

        }
};

#endif 
