#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


/// <summary>
/// Accepts values from the user for all shapes
/// </summary>
/// <param name="height">The height of the shape</param>
/// <param name="width">The width of the shape</param>
void absorptionOfTowerSizes(double& height, double& width)
{
	cout << "Please enter height and width:";
	cin >> height;
	cin >> width;
	if (height < 2)
		throw new exception("The tower height is illegal!");
}

/// <summary>
/// Action to handle the rectangle
/// </summary>
void rectangularTower()
{
	double height, width;
	absorptionOfTowerSizes(height, width);
	if ((abs(height - width)) > 5)
		cout << "The area of the tower: " << height * width << endl;
	else
		cout << "The perimeter of a tower: " << height * 2 + width * 2 << endl;
}

void printSrars(int number)
{
	for (int i = 0; i < number; i++)
		cout << "*";
	cout << endl;
}

void printSpaces(int number)
{
	for (int i = 0; i < number; i++)
		cout << " ";
}

/// <summary>
/// Action to handle the triangle
/// </summary>
void triangleTower()
{
	int choice;
	double height, width, hypotenuse, perimeter;
	absorptionOfTowerSizes(height, width);

	cout << "If you want to know the extent of the tower - press 1.\n If you want to see the image of the tower - press 2\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		// Use the Pythagorean theorem to calculate the length of the hypotenuse
		hypotenuse = sqrt(width * width + height * height);

		// Calculate the perimeter of the triangle
		perimeter = width + height + hypotenuse;
		cout << "The perimeter of a tower: " << perimeter << endl;
		break;
	}
	case 2:
	{
		int num = height * 2;
		if ((int)width % 2 == 0 || width > num)
			cout << "This triangle cannot be printed" << endl;
		else
		{
			int i, quantityOfEachWidth;

			//Given a specific width - saves how many different width types exist
			int countOfWidthes = (int)((width - 2) / 2);

			//The first star print
			printSpaces((width - 1) / 2);
			printSrars(1);

			//Calculating and printing the remainder of the division
			for (i = 0; i < fmod(height - 2, width / countOfWidthes); i++)
			{
				printSpaces((width - 3) / 2);
				printSrars(3);
			}

			//A computer with a few lines left for him to deal with
			height = height - 2 - i;

			//Calculates how many lines to print of the same width
			quantityOfEachWidth = height / countOfWidthes;
			int y = 1;
			while (height > 0)
			{
				y += 2;
				for (int k = 0; k < quantityOfEachWidth; k++)
				{
					printSpaces((width - y) / 2);
					printSrars(y);
				}
				height -= quantityOfEachWidth;
			}

			//Prints the row of asterisks in the desired width
			printSrars(width);
		}
		break;
	}
	default:
		break;
	}
}


int main()
{
	int option;
	cout << "please insert 1 for - rectangular\n or insert 2 for - triangle:";
	cin >> option;

	while (option != 3)
	{
		switch (option)
		{
		case 1:
		{
			rectangularTower();
			break;
		}

		case 2:
		{
			triangleTower();
			break;
		}
		default:
		{
			cout << "Incorrect number: " << option << " selection" << endl;
			break;
		}
		}
		cout << "please insert 1 for - rectangular\n or insert 2 for - triangle:";
		cin >> option;
	}
}

