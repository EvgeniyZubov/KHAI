#include <iostream>

using namespace std;

struct TTriangle {
	struct TPoint {
		float X, Y;
	};
	TPoint A;
	TPoint B;
	TPoint C;

	void enter(TTriangle& Triangle) {
		cout << "Enter X of A point: ";
		cin >> Triangle.A.X;
		cout << "Enter Y of A point: ";
		cin >> Triangle.A.Y;

		cout << "Enter X of B point: ";
		cin >> Triangle.B.X;
		cout << "Enter Y of B point: ";
		cin >> Triangle.B.Y;

		cout << "Enter X of C point: ";
		cin >> Triangle.C.X;
		cout << "Enter Y of C point: ";
		cin >> Triangle.C.Y;

		cout << "Square of the area = " << len(Triangle);
	}

	float lenght(float AX, float BX, float AY, float BY) {
		return sqrt(pow((AY - AX), 2) + pow((BY - BX), 2));
	}

	float len(TTriangle Triangle) {
		float AB = lenght(Triangle.A.X, Triangle.A.Y, Triangle.B.X, Triangle.B.Y);
		float BC = lenght(Triangle.B.X, Triangle.B.Y, Triangle.C.X, Triangle.C.Y);
		float AC = lenght(Triangle.A.X, Triangle.A.Y, Triangle.C.X, Triangle.C.Y);

		return area(AB, BC, AC);
	}

	float area(float AB, float BC, float AC) {
		float p = (AB + BC + AC) / 2;

		return sqrt(p * (p - AB) * (p - BC) * (p - AC));
	}
};

struct CCords {
	int x1, y1, x2, y2;

	void enter(CCords& C) {
		cout << "Enter x1: ";
		cin >> C.x1;
		cout << "Enter y1: ";
		cin >> C.y1;

		cout << "Enter x2: ";
		cin >> C.x2;
		cout << "Enter y2: ";
		cin >> C.y2;

		Calc(x1, x2, y1, y2);
	}

	void Calc(int x1, int x2, int y1, int y2) {
		int xLen = fabs(x2 - x1);
		int yLen = fabs(y2 - y1);

		int Perimeter = (xLen * 2) + (yLen * 2);
		int Square = (xLen * yLen);

		cout << "Perimeter is " << Perimeter << endl;
		cout << "Square is " << Square << endl;
	}
};

struct BBlean {
	int A, B, C;

	void is(BBlean& N) {
		cout << "Enter A: ";
		cin >> N.A;
		cout << "Enter B: ";
		cin >> N.B;

		cout << "Are A and B is equally paired?  =  " << boolalpha << isPaired(N.A, N.B) << endl;
	}

	bool isPaired(int A, int B) {
		return (A % 2 == 0 && B % 2 == 0);
	}
};

void param66();

void begin19();

void boolean11();


int main() {
	int choice = -1;

	while (choice != 0) {

		cout << "Choose the task: "
			"\n1.Param66"
			"\n2.Begin19"
			"\n3.Boolean11"
			"\n0.Exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			param66();		//Task param66
			break;
		}
		case 2: {
			begin19();		//Task begin19
			break;
		}
		case 3: {
			boolean11();		//Task boolean11
			break;
		}
		case 4: {
			cout << "Program is end!";
			break;
		}
		default: {
			cout << "Wrong one, try again!\n";
		}
		}
	}
}

//Start param 66 
void param66() {
	TTriangle Triangle;

	Triangle.enter(Triangle);
}


//End Param66

//Start begin19

void begin19() {
	CCords Cords;

	Cords.enter(Cords);
}
//End begin19

//Start boolean11
void boolean11() {
	BBlean B;

	B.is(B);
}

//End boolean11

