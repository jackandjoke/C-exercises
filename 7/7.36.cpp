
struct X{
    X (int i, int j) : base(i),rem(base %j){}
    int base, rem;
};


int main(){
    X a(1,2);
    return 0;
}
