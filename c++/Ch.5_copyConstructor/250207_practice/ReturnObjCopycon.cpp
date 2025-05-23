// 232p의 예제
// 작동 순서를 알아보기

#include <iostream>
using namespace std;

class SoSimple{
    private:
    int num;
    public:
    SoSimple(int n) : num(n){ }
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
    }
    SoSimple& AddNum(int n){
        num+=n;
        return *this;
    }
    void ShowData(){
        cout<<"num: "<<num<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob){
    cout<<"return 이전"<<endl;
    return ob;
}

int main(){
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}