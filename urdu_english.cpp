#include <iostream>
#include <conio.h>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <fstream>
using namespace std;
void creatingFile(void);
void creatingSecondFile();
char* takingInputFile(void);
char* takingSecondInputFile();
char* toLower(char*);
char** tokenizer(char* mainString, int& wordCountMain);
void urduConverter(char* inputString, char* urduString);

int main()
{
	urduConverter(takingInputFile(), takingSecondInputFile());

}// --------------------------------------------------------------END MAIN-------------------------------------------------------------

void creatingFile()
{
	ofstream fout;
	fout.open("Shtupid.txt");
	fout << "It was Friday and sunny day. I went to a garden. The air was so cool and fresh there. I felt\n";
	fout << "very good after walking for 10 minutes. There were very beautiful flowers there as well. I\n";
	fout << "saw a butterfly on one flower with yellow color. I decided to visit the place often after this beautiful experience.";
	fout.close();
}//--------------------------------------------------------Creates sample input file----------------------------------------------------

void creatingSecondFile()
{
	ofstream fout;
	fout.open("ShtupidDictionary.txt");
	fout << "friday jumma day din garden bagh air hawa cool thanda fresh taza good acha walking chalna beautiful khubsoorat flower phool\n";
	fout << "saw dekha butterfly tittli one aik yello peela color rang place jagah mine mera you tum mad pagal chair kursi table maiz love pyaar\n";
	fout << "floor zameen home ghar work kaam electricity bijli road sarak mat kaleen food khana blood khoon hit marna kill qatal door darwaza\n";
	fout << "bag basta peace aman rest araam cry rona scream cheekhna suicide khudkushi water paani metal dhaat humble ajiz wood lakri\n";
	fout << "fan pankha potato aloo book kitab book kitab ocean samandar weak kamzor weakness kamzori";
	fout.close();
}//--------------------------------------------------------Creates dictionary input file----------------------------------------------------

char* takingInputFile(void)
{
	ifstream fin;
	ofstream fout;
	fin.open("Shtupid.txt");
	if (!fin)                              //If the file could not be opened it creates a file with the sample input
	{
		creatingFile();
		fin.open("Shtupid.txt");
		if (!fin)                          //If the file still could not be opened the program exits
		{
			cout << "File could not be opened";
			exit(0);
		}
	}

	int lineCount = 0;
	int characterCount = 1;
	while (!fin.eof())                     //Checks the total number of lines and characters
	{
		char tempArray[1100] = "";
		fin.getline(tempArray, 1100);
		characterCount += strlen(tempArray);
		lineCount++;
	}
	fin.close();                           //Closes so I can start taking input from the file

	fin.open("Shtupid.txt");
	char* array1 = new char[characterCount + 1];
	array1[0] = { '\0' };
	for (int loop = 0; loop < lineCount; loop++) //Takes input from the file and adds a space after every line 
	{
		const char* spaceString = " ";
		char tempArray[1100] = "";
		fin.getline(tempArray, 1100);
		strcat_s(array1, strlen(array1) + strlen(tempArray) + 1, tempArray);
		strcat_s(array1, strlen(array1) + strlen(spaceString) + 1, spaceString);
	}
	return array1;
}//-------------------------------------------------------Gets the String from the file---------------------------------------------------------


char* takingSecondInputFile()
{
	ifstream fin;
	ofstream fout;
	fin.open("ShtupidDictionary.txt");
	if (!fin)                              //If the file could not be opened it creates a file with the sample input
	{
		creatingSecondFile();
		fin.open("ShtupidDictionary.txt");
		if (!fin)                          //If the file still could not be opened the program exits
		{
			cout << "File could not be opened";
			exit(0);
		}
	}

	int lineCount = 0;
	int characterCount = 1;
	while (!fin.eof())                     //Checks the total number of lines and characters
	{
		char tempArray[1100] = "";
		fin.getline(tempArray, 1100);
		characterCount += strlen(tempArray);
		lineCount++;
	}
	fin.close();                           //Closes so I can start taking input from the file

	fin.open("ShtupidDictionary.txt");
	char* array1 = new char[characterCount + 1];
	array1[0] = { '\0' };
	for (int loop = 0; loop < lineCount; loop++) //Takes input from the file and adds a space after every line 
	{
		const char* spaceString = " ";
		char tempArray[1100] = "";
		fin.getline(tempArray, 1100);
		strcat_s(array1, strlen(array1) + strlen(tempArray) + 1, tempArray);
		strcat_s(array1, strlen(array1) + strlen(spaceString) + 1, spaceString);
	}
	return array1;
}//-------------------------------------------------------Gets the String from the file---------------------------------------------------------

char* toLower(char* myString)
{
	char* tempString = new char[strlen(myString) + 1];
	strcpy_s(tempString, strlen(myString) + 1, myString);
	for (char loop = 'A'; loop <= 'Z'; loop++)
	{
		for (int loop2 = 0; loop2 < strlen(tempString); loop2++)
		{
			if (tempString[loop2] == loop)
			{
				tempString[loop2] += 32;
			}
		}
	}
	return tempString;
}//-------------------------------------------------------Converts the string to lower case--------------------------------------------------

char** tokenizer(char* mainString, int& wordCountMain)
{
	char* copyString = new char[strlen(mainString) + 1];    //Makes two copy Strings for me to brutalize :)
	char* copyString2 = new char[strlen(mainString) + 1];
	strcpy_s(copyString, strlen(mainString) + 1, mainString);
	strcpy_s(copyString2, strlen(mainString) + 1, mainString);

	int wordCount = 0;
	char* token;
	char* nextToken;
	const char* delimeters = " \n.,";
	token = strtok_s(copyString, delimeters, &nextToken);
	while (token != NULL)             //Gets me the word count of the input
	{
		if (token != NULL)
		{
			token = strtok_s(NULL, delimeters, &nextToken);
			wordCount++;
		}
	}

	char** wordArray = new char* [wordCount];      //Storing the words in an array for me to work on later
	int* counterArray = new int[wordCount];
	wordArray[0] = strtok_s(copyString2, delimeters, &nextToken);
	for (int loop = 1; loop < wordCount; loop++)
	{
		wordArray[loop] = strtok_s(NULL, delimeters, &nextToken);
	}
	wordCountMain = wordCount;
	return wordArray;
}//--------------------------------------------------------Tokenizes a String--------------------------------------------------------

void urduConverter(char* inputString, char* urduString)
{
	int urduStringWordCount = 0;
	char** urduStringTokenized = tokenizer(urduString, urduStringWordCount); //Tokenize the string to get me word count and words

	char* copyString = new char[strlen(inputString) + 1];          //Create copy strings for me to have a reference later on
	char* copyString2 = new char[strlen(inputString) + 1];
	strcpy_s(copyString, strlen(inputString) + 1, inputString);
	strcpy_s(copyString2, strlen(inputString) + 1, inputString);

	int wordCount = 0;
	char* token;
	char* nextToken;
	const char* delimeters = " \n.,";
	token = strtok_s(copyString, delimeters, &nextToken);         //Tokenize to only get me the word count and first word
	char* firstTokenCheck = new char[strlen(token) + 1];
	strcpy_s(firstTokenCheck, strlen(token) + 1, token);
	while (token != NULL)             //Gets me the word count of the input
	{
		if (token != NULL)
		{
			token = strtok_s(NULL, delimeters, &nextToken);
			wordCount++;
		}
	}

	char** wordArray = new char* [wordCount];      //Storing the words in an array for me to work on later

	int indexPosition = 0;
	indexPosition += strlen(firstTokenCheck);      //Index parallel of the original string
	char* tokenLower = toLower(firstTokenCheck);
	bool check = true;
	for (int loop = 0; loop < urduStringWordCount; loop += 2)
	{
		if (!strcmp(tokenLower, urduStringTokenized[loop]))            //Checks the first word with every word in the dictionary and replaces
		{
			wordArray[0] = new char[strlen(urduStringTokenized[loop + 1]) + 1000];
			strcpy_s(wordArray[0], strlen(urduStringTokenized[loop + 1]) + 1, urduStringTokenized[loop + 1]);
			while (1)                              //Checks how many times the delimeters occur and add them at their appropriate positions
			{
				bool checkerist = true;
				if (inputString[indexPosition] == ' ')
				{
					const char* tempString = " ";
					strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == '\n')
				{
					const char* tempString = "\n";
					strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == ',')
				{
					const char* tempString = ",";
					strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == '.')
				{
					const char* tempString = ".";
					strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				if (checkerist)
				{
					break;
				}
			}

			check = false;
			break;
		}
	}
	if (check)                                         //If no urdu words were replaced then just add the english word
	{
		wordArray[0] = new char[strlen(firstTokenCheck) + 100];
		strcpy_s(wordArray[0], strlen(firstTokenCheck) + 1, firstTokenCheck);
		while (1)                              //Checks how many times the delimeters occur and add them at their appropriate positions
		{
			bool checkerist = true;
			if (inputString[indexPosition] == ' ')
			{
				const char* tempString = " ";
				strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
				indexPosition += 1;
				checkerist = false;
			}
			else if (inputString[indexPosition] == '\n')
			{
				const char* tempString = "\n";
				strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
				indexPosition += 1;
				checkerist = false;
			}
			else if (inputString[indexPosition] == ',')
			{
				const char* tempString = ",";
				strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
				indexPosition += 1;
				checkerist = false;
			}
			else if (inputString[indexPosition] == '.')
			{
				const char* tempString = ".";
				strcat_s(wordArray[0], strlen(wordArray[0]) + 2, tempString);
				indexPosition += 1;
				checkerist = false;
			}
			if (checkerist)
			{
				break;
			}
		}
	}

	strtok_s(copyString2, delimeters, &nextToken);

	for (int loop = 1; loop < wordCount; loop++)        //Check the remaining words against the dictionary
	{
		char* firstTokenCheck2;
		char* tokenLower2;
		firstTokenCheck2 = strtok_s(NULL, delimeters, &nextToken);
		indexPosition += strlen(firstTokenCheck2);
		tokenLower2 = toLower(firstTokenCheck2);
		bool check2 = true;
		for (int loop2 = 0; loop2 < urduStringWordCount; loop2 += 2)
		{
			if (!strcmp(tokenLower2, urduStringTokenized[loop2]))       //Does the same checking and replacing as above
			{
				wordArray[loop] = new char[strlen(urduStringTokenized[loop2 + 1]) + 100];
				strcpy_s(wordArray[loop], strlen(urduStringTokenized[loop2 + 1]) + 1, urduStringTokenized[loop2 + 1]);
				while (1)                              //Checks how many times the delimeters occur and add them at their appropriate positions
				{
					bool checkerist = true;
					if (inputString[indexPosition] == ' ')
					{
						const char* tempString = " ";
						strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
						indexPosition += 1;
						checkerist = false;
					}
					else if (inputString[indexPosition] == '\n')
					{

						const char* tempString = "\n";
						strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
						indexPosition += 1;
						checkerist = false;
					}
					else if (inputString[indexPosition] == ',')
					{
						const char* tempString = ",";
						strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
						indexPosition += 1;
						checkerist = false;
					}
					else if (inputString[indexPosition] == '.')
					{
						const char* tempString = ".";
						strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
						indexPosition += 1;
						checkerist = false;
					}
					if (checkerist)
					{
						break;
					}
				}

				check2 = false;
				break;
			}
		}
		if (check2)                                   //Does the same copying of english word as above
		{
			wordArray[loop] = new char[strlen(firstTokenCheck2) + 100];
			strcpy_s(wordArray[loop], strlen(firstTokenCheck2) + 1, firstTokenCheck2);
			while (1)                         //Checks how many times the delimeters occur and add them at their appropriate positions
			{
				bool checkerist = true;
				if (inputString[indexPosition] == ' ')
				{
					const char* tempString = " ";
					strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == '\n')
				{

					const char* tempString = "\n";
					strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == ',')
				{
					const char* tempString = ",";
					strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				else if (inputString[indexPosition] == '.')
				{
					const char* tempString = ".";
					strcat_s(wordArray[loop], strlen(wordArray[loop]) + 2, tempString);
					indexPosition += 1;
					checkerist = false;
				}
				if (checkerist)
				{
					break;
				}
			}
		}
	}
	ofstream fout;
	fout.open("ShtupidDictionaryOutput.txt");
	if (!fout)
	{
		cout << "Could not open file";
		exit(0);
	}
	for (int loop = 0; loop < wordCount; loop++)
	{
		cout << wordArray[loop];
		fout << wordArray[loop];
	}
	fout.close();
	for (int loop = 0; loop < wordCount; loop++)
	{
		delete[] wordArray[loop];
	}
	delete[] wordArray, copyString, copyString2, firstTokenCheck;
}//------------------------------------------------------Replaces English with Urdu--------------------------------------------------------
