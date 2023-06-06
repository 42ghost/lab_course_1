#include <iostream>
#include "IMatrix.h"
#include "UsualMatrix.h"
#include "SparseMatrix.h"


int main()
{
	/*UsualMatrix M1(5, 5);
	UsualMatrix M;

	std::cout << "Matrix:\n";
	M1.print();

	std::cout << "Roteted Matrix (90 degree)\n";

	M = M1.rotate(1);

	M.print();
	std::cout << "Roteted Matrix (180 degree)\n";

	M = M1.rotate(2);

	M.print();  
	std::cout << "Roteted Matrix (270 degree)\n";

	M = M1.rotate(3);

	M.print();  */ 

	std::cout << "Test 1:\n";
	UsualMatrix M1(5, 3);
	SparseMatrix M2(5, 3);

	M1.print();
	std::cout << "\n";
	M2.print();

	std::cout << "\nSum:\n";

	UsualMatrix SUM;
	SUM = M1.add(M2);
	SUM.print();

	//################################
	std::cout << "\nTest 2:\n";

	UsualMatrix M3(2, 3);
	SparseMatrix M4(3, 2);

	M3.print();
	std::cout << "\n";
	M4.print();

	std::cout << "\nMultiplication:\n";

	UsualMatrix MUL;
	MUL = M3.mul(M4);
	MUL.print();

	/*std::cout << "\nTest 3:\n";
	SparseMatrix M;
	M.setElem(2, 1, 1);
	M.setElem(2, 1, 1);
	M.setElem(2, 1, 1);    
	M.print()*/
	return 0;
}
