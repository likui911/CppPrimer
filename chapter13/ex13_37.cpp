/*
    Write the Message class as described in this section.
*/
#include "ex13_37.h"

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
    Message m1, m2;
    Folder f1;
    m1.save(f1);
    m2.save(f1);
    return 0;
}