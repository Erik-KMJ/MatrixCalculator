#include <fstream>
#include <iostream>

void MtxDisplay(float _Matrix[4][4]);
float TwoMtxDeterminant(float _TwoMatrix[2][2]);
float ThreeMtxDeterminant(float _ThreeMatrix[3][3]);
float FourMtxDeterminant(float _FourMatrix[4][4]);
void MtxTranspose(float _Matrix[4][4]);
void MtxInverse(float _Matrix[4][4]);
void MtxScale(float _Matrix[4][4], float _Scale);

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
		std::cout << " Matrix A \n";
		MtxDisplay(A);

		std::cout << " Matrix B \n";
		MtxDisplay(B);

		std::cout << " Scalar Value: " << scalarValue;
		std::cout << std::endl;
	}
	else
	{
		std::cout << " ERROR LOADING FILE!!! \n\n";
	}
	
	std::cout << " |A|\n";


	std::cout << " A^T\n";
	MtxTranspose(A);

	std::cout << " A^-1\n";


	std::cout << " A * Scalar\n";
	MtxScale(A, scalarValue);


	std::cout << " A + B\n";


	std::cout << " A - B\n";


	std::cout << " A * B\n";


	std::cout << " B * A\n";


	std::cout << " Identity matrix\n";

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
			if (_Matrix[i][j] < 10)
			{
				std::cout << " ";
			}
			std::cout << _Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

////determinants of a matrix
//float TwoMtxDeterminant(float _TwoMatrix[2][2])
//{
//	// ad – bc
//	
//}
//float ThreeMtxDeterminant(float _ThreeMatrix[3][3])
//{
//	// a(ei – fh) – b(di – fg) + c(dh – eg)
//	
//}
//float FourMtxDeterminant(float _FourMatrix[4][4])
//{
//
//}

// Transpose of a matrix
void MtxTranspose(float _Matrix[4][4])
{
	float result[4][4];

	// swap column and row
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[j][i] = _Matrix[i][j];
		}
	}

	MtxDisplay(result);
}

// inverse of matrix
//void MtxInverse(float _Matrix[4][4])
//{
//	
//}

// scale matrix
void MtxScale(float _Matrix[4][4], float _Scale)
{
	float result[4][4];

	// c * Matrix
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = _Matrix[i][j] * _Scale; 
		}
	}

	MtxDisplay(result);
}