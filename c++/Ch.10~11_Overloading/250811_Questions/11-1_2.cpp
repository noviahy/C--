// 453p
// 깊은 복사를 하는 대입 연산자의 정의
// Ch.7의 문제 07-2의 두번째의 추가 문제

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
    Book(char *name = "", char *num= "", int money = 0)
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

    Book &operator=(const Book &book)
    {
        delete[] title;
        delete[] isbn;

        title = new char[strlen(book.title) + 1];
        strcpy(title, book.title);
        isbn = new char[strlen(book.isbn) + 1];
        strcpy(isbn, book.isbn);
        price = book.price;
        return *this;
    }

    ~Book()
    {
        delete[] title;
        delete[] isbn;
    }
};

class EBook : public Book
{
private:
    char *DRMKey; // 보안키
public:
    EBook(char *name = "", char *num = "", int money = 0, char *key = "")
        : Book(name, num, money)
    {
        DRMKey = new char[strlen(key) + 1];

        strcpy(DRMKey, key);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "DRMKey: " << DRMKey << endl;
    }

    EBook &operator=(const EBook &ebook)
    {
        Book::operator=(ebook);
        delete[] DRMKey;
        DRMKey = new char[strlen(ebook.DRMKey) + 1];
        strcpy(DRMKey, ebook.DRMKey);
        
        return *this;
    }

    ~EBook()
    {
        delete[] DRMKey;
    }
};

int main()
{ // main이 실행될 수 있도록 class를 짜기
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    Book book1;
    book1 = book;
    book1.ShowBookInfo();
    cout << endl;

    EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    cout << endl;

    EBook ebook1;
    ebook1 = ebook;
    ebook1.ShowEBookInfo();

    return 0;
}