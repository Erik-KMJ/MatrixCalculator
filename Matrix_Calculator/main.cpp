#include <fstream>
#include <iostream>


void MtxDisplay(float _Matrix[4][4]);
float MtxDeterminant(float _FourMatrix[4][4]);
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
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << " ERROR LOADING FILE!!! \n\n";
	}
	
	std::cout << " |A|\n ";
	std::cout << MtxDeterminant(A) << std::endl << std::endl;

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
	float cofactor[4][4];

	float a = _Matrix[0][0], b = _Matrix[0][1], c = _Matrix[0][2], d = _Matrix[0][3],
		e = _Matrix[1][0], f = _Matrix[1][1], g = _Matrix[1][2], h = _Matrix[1][3],
		i = _Matrix[2][0], j = _Matrix[2][1], k = _Matrix[2][2], l = _Matrix[2][3],
		m = _Matrix[3][0], n = _Matrix[3][1], o = _Matrix[3][2], p = _Matrix[3][3];

	if (determinant != 0)
	{
		/*cofactor[0][0] = ;
		cofactor[0][1] = ;
		cofactor[0][2] = ;
		cofactor[0][3] = ;
		cofactor[1][0] = ;
		cofactor[1][1] = ;
		cofactor[1][2] = ;
		cofactor[1][3] = ;
		cofactor[2][0] = ;
		cofactor[2][1] = ;
		cofactor[2][2] = ;
		cofactor[2][3] = ;
		cofactor[3][0] = ;
		cofactor[3][1] = ;
		cofactor[3][2] = ;
		cofactor[3][3] = ;*/
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