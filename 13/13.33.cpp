#include<iostream>
#include<set>
#include<string>


using std::cout;
using std::set;
using std::string;
using std::endl;

class Folder;

class Message{
    friend class Folder;
public:

    explicit Message(const string &s = string("") ):contents(s){}
    Message(const Message &);

    void save(Folder &);
    void remove(Folder &);
    Message & operator=(const Message &);
    ~Message();


    void print();

private:
    string contents;
    set<Folder*> folders;
    void add_to_folders(const Message &);
    void remove_from_folders();

};

class Folder{
    friend class Message;
    static int uid;
public:
    Folder():name(uid++){}
    void rmMessage(Message* );
    void addMessage(Message*);
    void print();
     
private:
    set<Message*> msgs;
    int name;
};
int Folder::uid = 0;

void Folder::rmMessage(Message* m){
    msgs.erase(m);
}
void Folder::addMessage(Message *m){
    msgs.insert(m);
}
void Message::save(Folder &f){
    f.addMessage(this);
    folders.insert(&f);
}

void Message::remove(Folder &f){
    f.rmMessage(this);
    folders.erase(&f);
}
void Message::remove_from_folders(){
    for(auto f: folders)
        f->rmMessage(this);
}
void Message::add_to_folders(const Message &m){
    for(auto f: m.folders){
        f->addMessage(this);
    }
}



Message::Message(const Message &m):contents(m.contents),folders(m.folders){
    add_to_folders(m);
}

Message & Message::operator=(const Message &rhs){
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message::~Message(){
    remove_from_folders();
}

void Message:: print(){
        cout << contents << " in ";
        for(const auto f: folders)
            cout <<f->name << " ";
        cout <<endl;
}
void Folder::print(){
    cout << name << " has ";
    for(const auto m: msgs)
        cout << m->contents << " ";
    cout << endl;

}


int main(){
    Folder f1,f2,f3;
    Message m1("h"),m2("e");
    m1.save(f1);
    m1.save(f3);
    m2.save(f2);

    m1.print();
    m2.print();
    //test message in which folders

    f1.print();
    f2.print();
    f3.print();
    //test folder has what messages


    Message m5("jack");
    m5.save(f1);
    f1.print();

    {
        Message m3(m1);
        m3.print();
        f1.print();
    }
        f1.print();
    //test ~Message();

    Message m4 = m2;
    m4.print();
    f2.print();

    return 0;
}




