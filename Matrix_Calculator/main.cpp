#include <fstream>
#include <iostream>

void MtxDisplay(float _Matrix[4][4]);


int main()
{
	float A[4][4], B[4][4]; // 4x4 matrix A and B 
	float scalarValue = 0;
	std::ifstream myfile ("Matrix.txt"); // load file
	
	if (myfile.is_open())
	{
		// setting the values of the matrix
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				myfile >> A[i][j];
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				myfile >> B[i][j];
			}
		}

		myfile >> scalarValue;

		myfile.close();

		// display matrix
		std::cout << "Matrix A \n";
		MtxDisplay(A);

		std::cout << "Matrix B \n";
		MtxDisplay(B);

		std::cout << "Scalar Value: " << scalarValue;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ERROR LOADING FILE!!! \n\n";
	}
	
	std::cout << "|A|\n";


	std::cout << "A^T\n";


	std::cout << "A^-1\n";


	std::cout << "A * Scalar\n";


	std::cout << "A + B\n";


	std::cout << "A - B\n";


	std::cout << "A * B\n";


	std::cout << "B * A\n";


	std::cout << "Identity matrix\n";

	system("PAUSE");

	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// matrix functions

//display matrix
void MtxDisplay(float _Matrix[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			std::cout << _Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
