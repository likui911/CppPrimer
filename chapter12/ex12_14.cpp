/*
Write your own version of a function that uses a
shared_ptr to manage a connection.
*/
#include <memory>
#include <string>
#include <iostream>
using namespace std;

// represents what we are connecting to
struct destination
{
    destination(string i, int p) : ip{i}, port{p} {};
    string ip;
    int port;
};

// information needed to use the connection
struct connection
{
    connection(string i, int p) : ip{i}, port{p} {};
    string ip;
    int port;
};

// open the connection
connection connect(destination *pDest)
{
    cout << "connect " << pDest->ip << ":" << pDest->port << endl;
    return connection(pDest->ip, pDest->port);
}

// close the given connection
void disconnect(connection conn)
{
    cout << "disconnect " << conn.ip << ":" << conn.port << endl;
}

// deleter for shared_ptr
void end_connect(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d /* other parameters */)
{
    connection conn = connect(&d);
    // use the connection
    shared_ptr<connection> c{&conn, end_connect};
    /*
    do some work 
    */
}

int main()
{
    destination dest{"192.168.2.34", 80};
    f(dest);
    return 0;
}