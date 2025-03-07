// 312에 있는 문제 2번
#include <iostream>
#include <cstring>
using namespace std;

// Book와 Ebook의 상속관계 구성

class Book
{
private:
    char *title; // 책의 제목
    char *isbn;  // 국제표준도서번호
    int price;   // 책의 정가
public:
    Book(char *name, char *num, int money)
        : price(money)
    {
        title = new char[strlen(name) + 1];
        isbn = new char[strlen(num) + 1];

        strcpy(title, name);
        strcpy(isbn, num);
    }
    void ShowBookInfo()
    {
        cout << "Title: " << title << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Price: " << price << endl;
    }
    ~Book()
    {
        delete title;
        delete isbn;
    }
};

class EBook : public Book
{
private:
    char *DRMKey; // 보안키
public:
    EBook(char *name, char *num, int money, char *key)
        : Book(name, num, money)
    {
        DRMKey = new char[strlen(name) + 1];

        strcpy(DRMKey, key);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "DRMKey: " << DRMKey << endl;
    }
    ~EBook()
    {
        delete DRMKey;
    }
};

int main()
{ // main이 실행될 수 있도록 class를 짜기
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;
    EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}