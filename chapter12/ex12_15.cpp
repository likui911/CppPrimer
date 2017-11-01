/*
 Rewrite the first exercise to use a lambda (§ 10.3.2, p.388) 
 in place of the end_connection function.
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

void f(destination &d /* other parameters */)
{
    connection conn = connect(&d);
    // use the connection
    shared_ptr<connection> c{&conn, [](connection *pConn){disconnect(*pConn);}};
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