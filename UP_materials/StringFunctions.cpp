//#include <iostream>
////string библиотека
//int myStrlen(const char* str)
//{
//	if (str == nullptr)
//		return 0;
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//void myStrcpy(char* dest, const char* source)
//{
//	if (dest == nullptr || source == nullptr)
//		return;
//	int iter = 0;
//	while (*source)
//	{
//		dest[iter] = source[iter];
//		iter++;
//	}
//	dest[iter] = '\0';
//}
//void myStrcat(char* dest, const char* source)
//{
//	if (dest == nullptr || source == nullptr)
//		return;
//	size_t len = myStrlen(dest);
//	dest += len;
//	myStrcpy(dest, source);
//}
//int myStrcmp(const char* str1, const char* str2)
//{
//	if (str1 == nullptr || str2 == nullptr)
//		return -2;
//	while (*str1 && *str2)
//	{
//		if (*str1 > *str2)
//			return 1;
//		else if (*str1 < *str2)
//			return -1;
//		str1++;
//		str2++;
//	}
//	if (*str1 == '\0' && *str2 == '\0')
//		return 0;
//	if (*str1 == '\0')
//		return -1;
//	else
//		return 1;
//}
//
////String фунцкии
//
////Дали дума е префикс на текст
//bool isPrefix(const char* txt, const char* word)
//{
//	while (*word && *txt)
//	{
//		if (*txt != *word)
//			return false;
//		txt++;
//		word++;
//	}
//	return !(*word);
//}
////Дали дума се среща в текст
//bool isInText(const char* txt, const char* word)
//{
//	while (*txt)
//	{
//		if (isPrefix(txt, word))
//			return true;
//		txt++;
//	}
//	return false;
//}
////Колко пъти дума се среща в текст
//int getCountInTxt(const char* txt, const char* word)
//{
//	int count = 0;
//	while (*txt)
//	{
//		if (isPrefix(txt, word))
//			count++;
//		txt++;
//	}
//	return count;
//}
////Намира и замества дума в текст
//char* findAndReplace(const char* txt, const char* toReplace, const char* replacement)
//{
//	size_t lenOfTxt = myStrlen(txt);
//	size_t lenOfToRepl = myStrlen(toReplace);
//	size_t lenOfReplacement = myStrlen(replacement);
//	char* res = new char[lenOfTxt + getCountInTxt(txt, toReplace) * (lenOfToRepl - lenOfToRepl) + 1];
//	int iter = 0;
//	while (*txt)
//	{
//		if (isPrefix(txt, toReplace))
//		{
//			*res = '\0';
//			myStrcat(res, replacement);
//			iter += lenOfReplacement;
//			txt += lenOfToRepl;
//		}
//		else
//		{
//			res[iter++] = *txt;
//			txt++;
//		}
//	}
//	res[iter] = '\0';
//	return res;
//}