#include <iostream>
using namespace std;
#include "BookInterface.h"

int main() {
	BookInterface* book = new BookInterface();
	book->start();
	delete book;
	return 0;
}