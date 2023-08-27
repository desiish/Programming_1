#include <iostream>
/*Да се напише функция, която приема като параметри масив и дължината му,
и връща дали масива може да бъде разделен на 2 части с равни суми на елементите*/
int getSumOfArr(const int* arr, size_t size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	return sum;
}
bool analyze(const int* arr, size_t size)
{
	int sumOfAll = getSumOfArr(arr, size);
	int partialSum = 0;
	for (int i = 0; i < size; i++)
	{
		partialSum += arr[i];
		if (partialSum == sumOfAll - partialSum)
			return true;
	}
	return false;
}

/*Да се напише функция на С++, със сигнатура int CheckStr(char[]), която проверява, дали символите на входния масив,
който трябва да е с дължина поне 2 символа, може да се пренаредят така, че той да стане палиндром.
Функцията да връща -1, при невалидни входни данни.*/

int getSymbolOccurences(const char* str, char ch)
{
	int count = 0;
	while (*str)
	{
		if (*str == ch)
			count++;
		str++;
	}
	return count;
}
int checkStr(const char* str)
{
	bool hasFoundLetterWithOddOccurences = false;
	for (int i = 0; i < 26; i++)
	{
		int occurences = getSymbolOccurences(str, 'a' + i);
		if (occurences % 2 != 0)
		{
			if (!hasFoundLetterWithOddOccurences)
				hasFoundLetterWithOddOccurences = true;
			else
				return false;
		}
	}
	return true;
}

/* Да се напише функция на C++, със сигнатура void ConvertNum(long &),
която преобразува подаденото като параметър число в същото число, но прочетено наобратно.*/
void convertNum(long& num)
{
	int res = 0;
	int copyOfNum = num;
	while (copyOfNum)
	{
		res += copyOfNum & 10;
		copyOfNum /= 10;
	}
	num = res;
}

/*Да се напише функция на С++, със сигнатура int CheckTimeStr(char[]),
която да проверява дали входния параметър е коректнo изписан час във формат HH:MM:SS
(HH - час е във формат 0-24, MM - минути, SS - секунди).
Функцията да връща -1, при некоректни входни данни.*/
bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}
int fromCharToDigit(char ch)
{
	if (!isDigit(ch))
		return -1;
	return ch - '0';
}
int myStrlen(const char* str)
{
	if (str == nullptr)
		return 0;
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}
int CheckTimeStr(const char* str)
{
	size_t len = myStrlen(str);
	if (len != 8)
		return -1;
	if (str[2] != ':' || str[5] != ':')
		return 0;
	if (!isDigit(str[0]) || !isDigit(str[1]) || !isDigit(str[3]) || !isDigit(str[4]) || !isDigit(str[6]) || !isDigit(str[7]))
		return 0;
	int hours = 10 * fromCharToDigit(str[0]) + fromCharToDigit(str[1]);
	int mins = 10 * fromCharToDigit(str[3]) + fromCharToDigit(str[4]);
	int seconds = 10 * fromCharToDigit(str[6]) + fromCharToDigit(str[7]);
	if (hours >= 24 || mins >= 60 || seconds >= 60)
		return false;
	return true;

}

/*Да се напише функция на С++, със сигнатура char * CheckStr(char []),
която връща масив, който съдържа всички повтарящи се символи във входящия масив.*/
int getCountOfRepeatedLetters(const char* str)
{
	int count = 0;
	for (int i = 1; i < 256; i++)
	{
		int occurences = getSymbolOccurences(str, i);
		if (occurences > 1)
			count++;
	}
	return count;
}
bool isInStr(const char* str, char ch)
{
	while (*str)
	{
		if (*str == ch)
			return true;
		str++;
	}
	return false;

}
char* CheckStr(const char* str)
{
	int count = getCountOfRepeatedLetters(str);
	char* res = new char[count + 1] {0};
	int iter = 0;
	while (*str)
	{
		if (getSymbolOccurences(str, *str) > 1 && !isInStr(res, *str))
			res[iter++] = *str;
		str++;
	}
	return res;
}
/*Да се напише функция на C++, със сигнатура int calculateMatrix(int** matr, int m),
която приема като параметър квадратна матрица с размерност m и връща като резултат сумата на елементите
които са по двата ѝ диагонала.*/
int calculateMatrix(const int* const* matrix, int m)
{
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (i = m - i - 1)
			sum += matrix[i][i];
		else
			sum += matrix[i][i] + matrix[m - 1 - i][m - 1 - i];
	}
	return sum;
}

/* Да се напише функция на C++, със сигнатура char* GetWord(char str[]),
която връща като резултат най-дългата дума в масива str. За дума се счита всяка
последователност от символи, която е отделена отляво и отдясно с един или няколко
интервала и/или табулации, а също и началото и края на низа.*/

int getLenOfWord(const char* str)
{
	int len = 0;
	while (*str != ' ' && *str != '\t')
	{
		len++;
		str++;
	}
	return len;
}
char* getWord(const char* str)
{
	size_t lenOfTxt = myStrlen(str);
	int begin = 0;
	int end = 0;
	int maxLen = 0;
	for (int i = 0; i < lenOfTxt; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			int len = getLenOfWord(str + i);
			if (len > maxLen)
			{
				maxLen = len;
				begin = i;
				end = i + len;
			}
			i += len - 1;
		}
	}
	char* res = new char[maxLen + 1];
	int resIter = 0;
	std::cout << begin << " " << end;
	for (int i = begin; i <= end; i++)
		res[resIter++] = str[i];
	res[resIter] = '\0';
	return res;
}
/*Да се напише функция, която сортира цифрите на число без масив.*/
int getDigitCountInNum(int num, int digit)
{
	if (num == 0 && digit == 0)
		return 1;
	int count = 0;
	while (num)
	{
		if (num % 10 == digit)
			count++;
		num /= 10;
	}
	return count;
}
int numberWithSameDigits(int digit, int count)
{
	int res = 0;
	for (int i = 0; i < count; i++)
	{
		res *= 10;
		res += digit;
	}
	return res;

}
int powOfTen(int k)
{
	int res = 1;
	for (int i = 0; i < k; i++)
		res *= 10;
	return res;
}
int sortedNum(int n)
{
	int res = 0;
	for (int i = 0; i <= 9; i++)
	{
		int count = getDigitCountInNum(n, i);
		if (count != 0)
		{
			res *= powOfTen(count);
			res += numberWithSameDigits(i, count);
		}
	}
	return res;
}