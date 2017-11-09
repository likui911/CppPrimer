#include <string>
#include <set>

#ifndef EX13_37_H
#define EX13_37_H
class Folder;

class Message
{
  public:
    friend class Folder;
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = "") : contents(str) {}
    // copy control to manage pointers to this Message
    Message(const Message &);            // copy constructor
    Message &operator=(const Message &); // copy assignment
    ~Message();                          // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);

  private:
    std::string contents;       // actual message text
    std::set<Folder *> folders; // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    // remove this Message from every Folder in folders
    void remove_from_Folders();
};

class Folder
{
    friend class Message;

    //public:
  private:
    void addMsg(Message *);
    void remMsg(Message *);

    std::set<Message *> messages;
};
#endif //EX13_37_H