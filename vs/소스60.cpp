#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* result = new Point;
	
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	return *result;
}

int main() {
	Point* k = new Point;
	Point* d = new Point;

	cin >> k->xpos;
	cin >> k->ypos;

	cin >> d->xpos;
	cin >> d->ypos;

	Point& result = PntAdder(*k, *d);

	cout << result.xpos<<" "<< result.ypos << endl;

	delete k;
	delete d;
	delete& result;
	return 0;
}