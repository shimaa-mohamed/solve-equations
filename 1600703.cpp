#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;
int found(string variables[], int number_variables, string variable)
{
	for (int i = 0; i < number_variables; i++)
	{
		if (variables[i] == variable)
		{
			return i + 1;
		}
	}
	return 0;
}
void swap(string&a, string&b)
{
	string temp = a;
	a = b;
	b = temp;

}
void order(string variables[], int start, int end)
{
	for (int i = start; i < end; i++)
	{
		for (int j = i + 1; j < end; j++)
		{
			if (variables[i] > variables[j])
			{
				swap(variables[i], variables[j]);
			}
		}
	}
}


void print_equation(double coefficients[100][100], int number_variables, int eq_num, string variables[100])
{
	string str;
	ostringstream ss;
	for (int i = 0; i < number_variables; i++)
	{
		if (i != 0 && (coefficients[eq_num - 1][i + 1] > 0))
		{
			cout << "+";
			ss << coefficients[eq_num - 1][i + 1];
			str = ss.str();
			cout << str << variables[i];
			str.clear();
		}
		else if (i != 0 && (coefficients[eq_num - 1][i + 1] < 0))
		{
			cout << "-";
			ss << coefficients[eq_num - 1][i + 1];
			str = ss.str();
			cout << str << variables[i];
			str.clear();
		}
		else if (i == 0 && (coefficients[eq_num - 1][i + 1] > 0))
		{
			ss << coefficients[eq_num - 1][i + 1];
			str = ss.str();
			cout << str << variables[i];
			str.clear();
		}
		if (i == 0 && (coefficients[eq_num - 1][i + 1] < 0))
		{
			cout << "-";
			ss << coefficients[eq_num - 1][i + 1];
			str = ss.str();
			cout << str << variables[i];
			str.clear();
		}
		str.clear();
		ss.str("");
		ss.clear();

	}
	cout << "=";
	ss << coefficients[eq_num - 1][0];
	str = ss.str();
	cout << str;
	cout << endl;
}
void column(double coefficient[100][100], int location, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << coefficient[i][location] << endl;
	}
}
void add(double coefficients[100][100], int number_variables, int eq1, int eq2, string variables[100], double addcoff[100])
{
	for (int i = 0; i < number_variables + 1; i++)
	{
		addcoff[i] = coefficients[eq1 - 1][i] + coefficients[eq2 - 1][i];
	}

	for (int i = 0; i < number_variables; i++)
	{
		if (i != 0 && (addcoff[i + 1] > 0))
		{
			if (addcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << "+";
				cout << addcoff[i + 1] << variables[i];
			}
		}
		else if (i != 0 && (addcoff[i + 1] < 0))
		{
			if (addcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addcoff[i + 1] << variables[i];
			}
		}
		else if (i == 0 && (addcoff[i + 1] > 0))
		{
			if (addcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addcoff[i + 1] << variables[i];
			}
		}
		if (i == 0 && (addcoff[i + 1] < 0))
		{
			if (addcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addcoff[i + 1] << variables[i];
			}
		}



	}
	cout << "=";
	cout << addcoff[0];
	cout << endl;
}
void subtract(double coefficients[100][100], int number_variables, int eq1, int eq2, string variables[100], double subtractcoff[100])
{
	for (int i = 0; i < number_variables + 1; i++)
	{
		subtractcoff[i] = coefficients[eq1 - 1][i] - coefficients[eq2 - 1][i];
	}

	for (int i = 0; i < number_variables; i++)
	{
		if (i != 0 && (subtractcoff[i + 1] > 0))
		{
			if (subtractcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (subtractcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << "+";
				cout << subtractcoff[i + 1] << variables[i];
			}
		}
		else if (i != 0 && (subtractcoff[i + 1] < 0))
		{
			if (subtractcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (subtractcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << subtractcoff[i + 1] << variables[i];
			}
		}
		else if (i == 0 && (subtractcoff[i + 1] > 0))
		{
			if (subtractcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (subtractcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << subtractcoff[i + 1] << variables[i];
			}
		}
		if (i == 0 && (subtractcoff[i + 1] < 0))
		{
			if (subtractcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (subtractcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << subtractcoff[i + 1] << variables[i];
			}
		}



	}
	cout << "=";
	cout << subtractcoff[0];
	cout << endl;
}
void substitute(double coefficient[100][100], int number_variables, int eq1, double substcoff[100], string variables[100], double addsubcoff[100])
{
	for (int i = 0; i < number_variables + 1; i++)
	{
		addsubcoff[i] = coefficient[eq1 - 1][i] + substcoff[i];
	}

	for (int i = 0; i < number_variables; i++)
	{


		if (i != 0 && (addsubcoff[i + 1] > 0))
		{
			if (addsubcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addsubcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << "+";
				cout << addsubcoff[i + 1] << variables[i];
			}
		}
		else if (i != 0 && (addsubcoff[i + 1] < 0))
		{
			if (addsubcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addsubcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addsubcoff[i + 1] << variables[i];
			}
		}
		else if (i == 0 && (addsubcoff[i + 1] > 0))
		{
			if (addsubcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addsubcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addsubcoff[i + 1] << variables[i];
			}
		}
		if (i == 0 && (addsubcoff[i + 1] < 0))
		{
			if (addsubcoff[i + 1] == -1)
			{
				cout << "-" << variables[i];
			}
			else if (addsubcoff[i + 1] == 1)
			{
				cout << variables[i];
			}
			else
			{
				cout << addsubcoff[i + 1] << variables[i];
			}
		}
	}






	cout << "=";
	cout << addsubcoff[0];
	cout << endl;
}
void D(double coefficient[100][100], int n, int number_variables)
{
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < number_variables; j++)
		{
			cout << coefficient[i][j + 1] << "\t";
		}
		cout << endl;
	}
}
void Dx(double coefficient[100][100], int n, int number_variables, int loc)
{
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < number_variables; j++)
		{
			if (j + 1 != loc)
			{
				cout << coefficient[i][j + 1] << "\t";
			}
			else if (j + 1 == loc)
			{
				cout << coefficient[i][0] << "\t";
			}
		}
		cout << endl;
	}
}
int D_value(double coefficient[100][100])
{
	return (coefficient[0][1] * coefficient[1][2]) - (coefficient[0][2] * coefficient[1][1]);
}
int main()
{
	string equations[100], variables[100];
	double coefficient[100][100];
	string variable = "", num = "";
	int n, number_variables = 0;
	double number;
	bool variable_exist = 0, after_equal = 0;
	int position;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> equations[i];
	}
	cin.ignore();
	string operation;
	getline(cin, operation);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < equations[i].length(); j++)
		{
			if ((equations[i][j] >= 'a'&&equations[i][j] <= 'z') || (equations[i][j] >= 'A'&&equations[i][j] <= 'Z'))
			{
				while (equations[i][j] != '+'&& equations[i][j] != '-' && equations[i][j] != '='&&j < equations[i].length())
				{
					variable = variable + equations[i][j];
					j++;
				}
				if (!found(variables, number_variables, variable))
				{
					variables[number_variables] = variable;
					number_variables += 1;
				}
				variable.clear();
			}
		}
	}

	order(variables, 0, number_variables);
	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j < number_variables + 1; j++)
		{
			coefficient[i][j] = 0;
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < equations[i].length(); j++)
		{
			if ((equations[i][j] >= '0'&&equations[i][j] <= '9') || equations[i][j] == '.')
			{
				while (equations[i][j] != '+'&& equations[i][j] != '-' && equations[i][j] != '='&&j < equations[i].length())
				{
					if ((equations[i][j] > 'a'&&equations[i][j] <= 'z') || (equations[i][j] > 'A'&&equations[i][j] <= 'Z') || variable_exist)
					{
						variable = variable + equations[i][j];
						variable_exist = 1;
					}
					if (j != 0 && (equations[i][j - 1] == '+' || equations[i][j - 1] == '-'))
					{
						num = num + equations[i][j - 1];
					}
					num = num + equations[i][j];
					j++;
				}
				number = atof(num.c_str());
				if (after_equal)
				{
					number *= -1;
				}
				variable_exist = 0;
			}
			if ((equations[i][j] > 'a'&&equations[i][j] <= 'z') || (equations[i][j] > 'A'&&equations[i][j] <= 'Z'))
			{
				if ((j != 0 && equations[i][j - 1]) == '-')
				{
					number = -1;
				}
				if ((j != 0 && equations[i][j]) == '+' || j == 0)
				{
					number = 1;
				}
				while (equations[i][j] != '+'&& equations[i][j] != '-' && equations[i][j] != '='&&j < equations[i].length())
				{
					variable = equations[i][j];
					j++;
				}
			}
			else if (equations[i][j] == '+' || equations[i][j] == '-' || equations[i][j] == '=' || j == equations[i].length())
			{
				position = found(variables, number_variables, variable);
				if (!position)
				{
					number *= -1;
				}
				coefficient[i][position] += number;
				if (equations[i][j] == '=')
				{
					after_equal = 1;
					if (equations[i][j + 1] == '-')
					{
						j++;
					}
				}
				variable.clear();
				num.clear();
				number = 0;
			}
		}
		after_equal = 0;
	}
	//
	//cout << "num_vars=" << number_variables << endl;
	string op_value = "", op_variable = "";
	int eq_num;
	string eq_num1 = "", eq_num2 = "";
	int eq1 = 0, eq2 = 0;
	double substcoff[100];
	double addsubcoff[100];
	string var;
	int eq_sub1 = 0, eq_sub2 = 0;


	if (operation == "num_vars")
	{
		cout << number_variables << endl;
	}
	else if (operation[0] == 'e')
	{
		for (int i = 9; i < operation.length(); i++)
		{
			op_value += operation[i];
		}
		eq_num = atof(op_value.c_str());
		print_equation(coefficient, number_variables, eq_num, variables);
	}
	else if (operation[0] == 'c')
	{
		for (int i = 7; i < operation.length(); i++)
		{
			op_variable += operation[i];
		}

		int location = found(variables, number_variables, op_variable);
		column(coefficient, location, n);
		op_variable.clear();
	}
	else if (operation[0] == 'a')
	{

		for (int i = 4; i < operation.length() + 1; i++)
		{
			if (operation[i - 2] == 'd' && operation[i - 1] == ' ')
			{
				while (operation[i] != ' ') {
					eq_num1 += operation[i];
					i++;
				}
			}

			i++;
			while (i < operation.length() + 1)
			{
				eq_num2 += operation[i];
				i++;
			}

		}
		eq1 = atof(eq_num1.c_str());
		eq2 = atof(eq_num2.c_str());
		double addcoff[100];
		for (int i = 0; i < number_variables + 1; i++)
		{
			addcoff[i] = 0;
		}
		add(coefficient, number_variables, eq1, eq2, variables, addcoff);
		eq_num1.clear();
		eq_num2.clear();
		eq1 = 0;
		eq2 = 0;
	}

	else if (operation[0] == 's'&&operation[3] == 't')
	{

		for (int i = 9; i < operation.length() + 1; i++)
		{
			if (operation[i - 2] == 't' && operation[i - 1] == ' ')
			{
				while (operation[i] != ' ') {
					eq_num1 += operation[i];
					i++;
				}
			}

			i++;
			while (i < operation.length() + 1)
			{
				eq_num2 += operation[i];
				i++;
			}

		}
		double subtractcoff[100];
		for (int i = 0; i < number_variables + 1; i++)
		{
			subtractcoff[i] = 0;
		}
		eq1 = atof(eq_num1.c_str());
		eq2 = atof(eq_num2.c_str());
		subtract(coefficient, number_variables, eq1, eq2, variables, subtractcoff);


		eq_num1.clear();
		eq_num2.clear();
		eq1 = 0;
		eq2 = 0;
	}
	else if (operation[0] == 'D'&& operation.length() == 1)
	{
		D(coefficient, n, number_variables);
	}
	else if (operation[0] == 'D'&& operation[2] == 'x')
	{
		string matcoff;
		for (int i = 2; i < operation.length(); i++)
		{
			matcoff += operation[i];

		}
		int loc = found(variables, number_variables, matcoff);
		Dx(coefficient, n, number_variables, loc);
	}
	else if (operation[0] == 's' && operation[3] == 's')
	{
		int i = 11;
		while (operation[i] != ' ')
		{
			op_variable += operation[i];
			i++;
		}
		i++;
		int start = i;
		for (int j = start; j < operation.length() + 1; j++)
		{
			if ((operation[j - 2] >= '0'&&operation[j - 2] <= '9') && operation[j - 1] == ' ')
			{
				while (operation[j] != ' ') {
					eq_num1 += operation[j];
					j++;
				}
			}

			j++;
			while (j < operation.length() + 1)
			{
				eq_num2 += operation[j];
				j++;
			}
		}
		eq_sub1 = atof(eq_num1.c_str());
		eq_sub2 = atof(eq_num2.c_str());
		int loc = found(variables, number_variables, op_variable);
		for (int i = 0; i < number_variables + 1; i++)
		{
			substcoff[i] = -1 * coefficient[eq_sub1 - 1][i];
		}
		for (int i = 0; i < number_variables + 1; i++)
		{
			substcoff[i] = (substcoff[i] / coefficient[eq_sub1 - 1][loc])*(coefficient[eq_sub2 - 1][loc]);
		}



		substitute(coefficient, number_variables, eq_sub2, substcoff, variables, addsubcoff);
	}
	else if (operation[0] == 'D'&&operation[1] == '_')
	{
		int sol = D_value(coefficient);
		cout << sol << endl;
	}








	return 0;
}