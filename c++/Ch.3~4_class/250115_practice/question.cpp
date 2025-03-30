class CONTAC600{
    private:
    SinivelCap sin;
    SneexeCap sne;
    SnuffleCap snu;

    public:
    void Take() const{
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient{
    public:
    void TakeCONTAC600(const CONTAC600 &cap) const{cap.Take();}
};//main 함수에 왜 CONTAC600가 아닌 ColdPatient를 부르는지에 대한 질문
//캡슐화에 대한 설명을 받음