#include <fstream>
#include <iostream>


void MtxDisplay(float _Matrix[4][4]);
float MtxDeterminant(float _FourMatrix[4][4]);
void MtxTranspose(float _Matrix[4][4]);
void MtxInverse(float _Matrix[4][4]);
void MtxScale(float _Matrix[4][4], float _Scale);
void IdentityMatrix();

int main()
{
	// 4x4 matrix A and B 
	float A[4][4], B[4][4], C[4][4], D[4][4]; //NOTE: Due to a bug i cant fix with given time matrix A is equal to matrix C and D
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
				C[i][j] = A[i][j];
				D[i][j] = A[i][j];
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
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << " ERROR LOADING FILE!!! \n\n";
	}
	
	std::cout << " |A|\n ";
	std::cout << MtxDeterminant(C) << std::endl << std::endl; // NOTE: C = A

	std::cout << " A^T\n";
	MtxTranspose(A);

	std::cout << " A^-1\n";
	MtxInverse(D); // NOTE: D = A

	std::cout << " A * Scalar\n";
	MtxScale(A, scalarValue);

	std::cout << " A + B\n";


	std::cout << " A - B\n";


	std::cout << " A * B\n";


	std::cout << " B * A\n";


	std::cout << " Identity matrix\n";
	IdentityMatrix();

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

// determinant of a mnatrix
float MtxDeterminant(float _Matrix[4][4])
{
	float c, determinant = 1;

	for (int i = 0; i < 4; i++) 
	{
		for (int j = i + 1; j < 4; j++) 
		{
			c = _Matrix[j][i] / _Matrix[i][i];

			for (int k = i; k < 4; k++)
			{
				_Matrix[j][k] = _Matrix[j][k] - c * _Matrix[i][k];
			}	
		}
	}

	for (int i = 0; i < 4; i++)
	{
		determinant = determinant * _Matrix[i][i];
	}
		
	return determinant;
}

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
void MtxInverse(float _Matrix[4][4])
{
	float determinant = MtxDeterminant(_Matrix);
	float inverse[4][4];

	if (determinant != 0)
	{
		inverse[0][0] = _Matrix[1][1] * _Matrix[2][2] * _Matrix[3][3] + _Matrix[1][2] * _Matrix[2][3] * _Matrix[3][1] + _Matrix[1][3] * _Matrix[2][1] * _Matrix[3][2]
			- _Matrix[1][1] * _Matrix[2][3] * _Matrix[3][2] - _Matrix[1][2] * _Matrix[2][1] * _Matrix[3][3] - _Matrix[1][3] * _Matrix[2][2] * _Matrix[3][1];

		inverse[0][1] = _Matrix[0][1] * _Matrix[2][3] * _Matrix[3][2] + _Matrix[0][2] * _Matrix[2][1] * _Matrix[3][3] + _Matrix[0][3] * _Matrix[2][2] * _Matrix[3][1]
			- _Matrix[0][1] * _Matrix[2][2] * _Matrix[3][3] - _Matrix[0][2] * _Matrix[2][3] * _Matrix[3][1] - _Matrix[1][3] * _Matrix[2][1] * _Matrix[3][2];

		inverse[0][2] = _Matrix[0][1] * _Matrix[1][2] * _Matrix[3][3] + _Matrix[0][2] * _Matrix[1][3] * _Matrix[3][1] + _Matrix[0][3] * _Matrix[1][1] * _Matrix[3][2]
			- _Matrix[0][1] * _Matrix[1][3] * _Matrix[3][2] - _Matrix[0][2] * _Matrix[1][1] * _Matrix[3][3] - _Matrix[0][3] * _Matrix[1][2] * _Matrix[3][1];

		inverse[0][3] = _Matrix[0][1] * _Matrix[1][3] * _Matrix[2][2] + _Matrix[0][2] * _Matrix[1][1] * _Matrix[2][3] + _Matrix[0][3] * _Matrix[1][2] * _Matrix[2][1]
			- _Matrix[0][1] * _Matrix[1][2] * _Matrix[2][3] - _Matrix[0][2] * _Matrix[1][3] * _Matrix[2][1] - _Matrix[0][3] * _Matrix[1][1] * _Matrix[2][2];

		inverse[1][0] = _Matrix[1][0] * _Matrix[2][3] * _Matrix[3][2] + _Matrix[1][2] * _Matrix[2][0] * _Matrix[3][3] + _Matrix[1][3] * _Matrix[2][2] * _Matrix[3][0]
			- _Matrix[1][0] * _Matrix[2][2] * _Matrix[3][3] - _Matrix[1][2] * _Matrix[2][3] * _Matrix[3][0] - _Matrix[1][3] * _Matrix[2][0] * _Matrix[3][2];

		inverse[1][1] = _Matrix[0][0] * _Matrix[2][2] * _Matrix[3][3] + _Matrix[0][2] * _Matrix[2][3] * _Matrix[3][0] + _Matrix[0][3] * _Matrix[2][0] * _Matrix[3][2]
			- _Matrix[0][0] * _Matrix[2][3] * _Matrix[3][2] - _Matrix[0][2] * _Matrix[2][0] * _Matrix[3][3] - _Matrix[0][3] * _Matrix[2][2] * _Matrix[3][0];

		inverse[1][2] = _Matrix[0][0] * _Matrix[1][3] * _Matrix[3][2] + _Matrix[0][2] * _Matrix[1][0] * _Matrix[3][3] + _Matrix[0][3] * _Matrix[1][2] * _Matrix[3][0]
			- _Matrix[0][0] * _Matrix[1][2] * _Matrix[3][3] - _Matrix[0][2] * _Matrix[1][3] * _Matrix[3][0] - _Matrix[0][3] * _Matrix[1][0] * _Matrix[3][2];

		inverse[1][3] = _Matrix[0][0] * _Matrix[1][2] * _Matrix[2][3] + _Matrix[0][2] * _Matrix[1][3] * _Matrix[2][0] + _Matrix[0][3] * _Matrix[1][0] * _Matrix[2][2]
			- _Matrix[0][0] * _Matrix[1][3] * _Matrix[2][2] - _Matrix[0][2] * _Matrix[1][0] * _Matrix[2][3] - _Matrix[0][3] * _Matrix[1][2] * _Matrix[2][0];

		inverse[2][0] = _Matrix[1][0] * _Matrix[2][1] * _Matrix[3][3] + _Matrix[1][1] * _Matrix[2][3] * _Matrix[3][0] + _Matrix[1][3] * _Matrix[2][0] * _Matrix[3][1]
			- _Matrix[1][0] * _Matrix[2][3] * _Matrix[3][2] - _Matrix[1][1] * _Matrix[2][0] * _Matrix[3][3] - _Matrix[1][3] * _Matrix[2][1] * _Matrix[3][0];

		inverse[2][1] = _Matrix[0][0] * _Matrix[2][3] * _Matrix[3][1] + _Matrix[0][1] * _Matrix[2][0] * _Matrix[3][3] + _Matrix[0][3] * _Matrix[2][1] * _Matrix[3][0]
			- _Matrix[0][0] * _Matrix[2][1] * _Matrix[3][3] - _Matrix[0][1] * _Matrix[2][3] * _Matrix[3][0] - _Matrix[0][3] * _Matrix[2][0] * _Matrix[3][1];

		inverse[2][2] = _Matrix[0][0] * _Matrix[1][1] * _Matrix[3][3] + _Matrix[0][1] * _Matrix[1][3] * _Matrix[3][0] + _Matrix[0][3] * _Matrix[1][0] * _Matrix[3][1]
			- _Matrix[0][0] * _Matrix[1][3] * _Matrix[3][1] - _Matrix[0][1] * _Matrix[1][0] * _Matrix[3][3] - _Matrix[0][3] * _Matrix[1][1] * _Matrix[3][0];

		inverse[2][3] = _Matrix[0][0] * _Matrix[1][3] * _Matrix[2][1] + _Matrix[0][1] * _Matrix[1][0] * _Matrix[2][3] + _Matrix[0][3] * _Matrix[1][1] * _Matrix[2][0]
			- _Matrix[0][0] * _Matrix[1][1] * _Matrix[2][3] - _Matrix[0][1] * _Matrix[1][3] * _Matrix[2][0] - _Matrix[0][3] * _Matrix[1][0] * _Matrix[2][1];

		inverse[3][0] = _Matrix[1][0] * _Matrix[2][2] * _Matrix[3][1] + _Matrix[1][1] * _Matrix[2][0] * _Matrix[3][2] + _Matrix[1][2] * _Matrix[2][1] * _Matrix[3][0]
			- _Matrix[1][0] * _Matrix[2][1] * _Matrix[3][2] - _Matrix[1][1] * _Matrix[2][2] * _Matrix[3][0] - _Matrix[1][2] * _Matrix[2][0] * _Matrix[3][1];

		inverse[3][1] = _Matrix[0][0] * _Matrix[2][1] * _Matrix[3][2] + _Matrix[0][1] * _Matrix[2][2] * _Matrix[3][0] + _Matrix[0][2] * _Matrix[2][0] * _Matrix[3][1]
			- _Matrix[0][0] * _Matrix[1][1] * _Matrix[3][1] - _Matrix[0][1] * _Matrix[2][0] * _Matrix[3][2] - _Matrix[0][2] * _Matrix[2][1] * _Matrix[3][0];

		inverse[3][2] = _Matrix[0][0] * _Matrix[1][2] * _Matrix[3][1] + _Matrix[0][1] * _Matrix[1][0] * _Matrix[3][2] + _Matrix[0][2] * _Matrix[1][1] * _Matrix[3][2]
			- _Matrix[0][0] * _Matrix[1][1] * _Matrix[3][2] - _Matrix[0][1] * _Matrix[1][2] * _Matrix[3][0] - _Matrix[0][2] * _Matrix[1][0] * _Matrix[3][1];

		inverse[3][3] = _Matrix[0][0] * _Matrix[1][1] * _Matrix[2][2] + _Matrix[0][1] * _Matrix[1][2] * _Matrix[2][0] + _Matrix[0][2] * _Matrix[1][0] * _Matrix[2][1]
			- _Matrix[0][0] * _Matrix[1][2] * _Matrix[2][1] - _Matrix[0][1] * _Matrix[1][0] * _Matrix[2][2] - _Matrix[0][2] * _Matrix[1][1] * _Matrix[2][0];

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				inverse[i][j] = inverse[i][j] / determinant;
			}
		}

		MtxDisplay(inverse);
	}
	else
	{
		std::cout << "There is no Inverse for the matrix\n";
	}
}

// scale matrix
void MtxScale(float _Matrix[4][4], float _Scale)
{
	float result[4][4];

	// scalar * Matrix
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			result[i][j] = _Matrix[i][j] * _Scale; 
		}
	}

	MtxDisplay(result);
}

// 4x4 Identity Matrix
void IdentityMatrix()
{
	float identityMatrix[4][4];

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == j)
			{
				identityMatrix[i][j] = 1;
			}
			else
			{
				identityMatrix[i][j] = 0;
			}
		}
	}

	MtxDisplay(identityMatrix);
}