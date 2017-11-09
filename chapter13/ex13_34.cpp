/*
    Write the Message class as described in this section.
*/
#include <string>
#include <set>

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

Message::Message(const Message &rhs)
    : contents(rhs.contents), folders(rhs.folders)
{
    add_to_Folders(rhs);
}

Message &Message::operator=(const Message &rhs)
{
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : this->folders)
    {
        f->remMsg(this);
    }
}

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

////////Folder Implements///////////
void Folder::addMsg(Message *m)
{
    messages.insert(m);
}

void Folder::remMsg(Message *m)
{
    messages.erase(m);
}

int main()
{
    return 0;
}