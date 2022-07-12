#include "Message.h"

void Message::move_folders(Message *m) {
    folders = std::move(m->folders);
    for(auto f: folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_Folders(const Message &msg) {
    for(auto f : msg.folders) {
        f->addMsg(this);
    }
}

void Message::remove_from_Floders() {
    for(auto f : folders) {
        f->remMsg(this);
    }
}

Message::Message(const Message &rhs): contents(rhs.contents), folders(rhs.folders) {
    add_to_Folders(rhs);
}

Message::Message(Message &&rhs): contents(std::move(rhs.contents)) {
    move_folders(&rhs);
}

Message &Message::operator=(const Message &rhs) {
    if(this != &rhs) {
        remove_from_Floders();
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
    }
    return *this;
}

Message &Message::operator=(Message &&rhs) {
    if(this != &rhs) {
        remove_from_Floders();
        contents = std::move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

Message::~Message() {
    remove_from_Floders();
}

void swap(Message &lhs, Message &rhs) {
    lhs.remove_from_Floders();
    rhs.remove_from_Floders();
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);
    lhs.add_to_Folders(lhs);
    rhs.add_to_Folders(rhs);
}

void Folder::add_to_message(const Folder &rhs) {
    for(auto m : rhs.messages) {
        m->addFld(this);
    }
}

void Folder::remove_from_message() {
    for(auto m : messages) {
        m->remFld(this);
    }
}

Folder::Folder(const Folder &rhs): messages(rhs.messages) {
    add_to_message(rhs);
}

Folder::~Folder() {
    remove_from_message();
}

Folder &Folder::operator=(const Folder &rhs) {
    if(this != &rhs) {
        remove_from_message();
        messages = rhs.messages;
        add_to_message(rhs);
    }
    return *this;
}

void swap(Folder &lhs, Folder &rhs) {
    lhs.remove_from_message();
    rhs.remove_from_message();
    swap(lhs.messages, rhs.messages);
    lhs.add_to_message(lhs);
    rhs.add_to_message(rhs);
}
